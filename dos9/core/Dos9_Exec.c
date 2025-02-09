/*
 *
 *   Dos9 - A Free, Cross-platform command prompt - The Dos9 project
 *   Copyright (C) 2010-2016 Romain GARBI
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifndef WIN32
#include <sys/wait.h>
#include <unistd.h>
#endif

#include "../../config.h"
#ifdef DOS9_USE_LIBCU8
#include <libcu8.h>
#endif

#include "Dos9_Core.h"
#include "../init/Dos9_Init.h"


int Dos9_ExecuteFile(EXECINFO* info)
{
    int error = 0,
                ret;

    /* first try RunFile() */
    ret = Dos9_RunFile(info, &error);

    #if defined(WIN32)

    if (error) {

        error = 0;
        ret = Dos9_StartFile(info, &error);

    }

    #else


    if (Dos9_GetEnv(lpeEnv, "DOS9_START_SCRIPT") == NULL) {

        /* If we have neither windows nor a decent start script,
         * well try to fallback and start the thing in the same console */

        if (info->flags & DOS9_EXEC_SEPARATE_WINDOW) {

            if (error) {

                error = 0;

                info->flags &= ~DOS9_EXEC_SEPARATE_WINDOW;
                ret = Dos9_RunFile(info, &error);

            }
        }

    } else {

        /* If we have a startscript then try the script */
        if (error) {

            error = 0;
            ret = Dos9_StartFile(info, &error);

        }

    }

    #endif

    if (error) {

        Dos9_ShowErrorMessage(DOS9_COMMAND_ERROR, info->file, 0);
        ret = DOS9_COMMAND_ERROR;

    }



    return ret;
}




#ifdef WIN32
#ifndef DOS9_USE_LIBCU8

int Dos9_RunFile(EXECINFO* info, int* error)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    void* envblock;
    int status = 0;
    size_t size;
    DWORD dwFlags;

    envblock = Dos9_GetEnvBlock(lpeEnv, &size);

    ZeroMemory(&si, sizeof(si));

    si.cb = sizeof(si);

    /* It is very important to serialize calls to run functions since
       several process may call it at once, and since fds might simultaneously
       be set to inheritable, interference can appear between processes */
    if (Dos9_LockMutex(&mRunFile))
        Dos9_ShowErrorMessage(DOS9_LOCK_MUTEX_ERROR,
                              __FILE__ ":Dos9_ExecuteFile()" , -1);

    if (!(info->flags & DOS9_EXEC_SEPARATE_WINDOW)) {

        Dos9_SetFdInheritance(fileno(fInput), 1);
        Dos9_SetFdInheritance(fileno(fOutput), 1);
        Dos9_SetFdInheritance(fileno(fError), 1);



        si.dwFlags = STARTF_USESTDHANDLES;
        si.hStdInput = _get_osfhandle(fileno(fInput));
        si.hStdOutput = _get_osfhandle(fileno(fOutput));
        si.hStdError = _get_osfhandle(fileno(fError));

    }

    si.lpTitle = info->title;

    dwFlags = ((info->flags & DOS9_EXEC_SEPARATE_WINDOW) ?
            CREATE_NEW_CONSOLE : 0);

    if (!CreateProcessA(info->file,
                        info->cmdline,
                        NULL,
                        NULL,
                        (info->flags & DOS9_EXEC_SEPARATE_WINDOW)
                            ? FALSE : TRUE,
                        dwFlags,
                        envblock,
                        info->dir,
                        &si,
                        &pi))
        *error = 1;

    Dos9_SetFdInheritance(fileno(fInput), 0);
    Dos9_SetFdInheritance(fileno(fOutput), 0);
    Dos9_SetFdInheritance(fileno(fError), 0);

    if (Dos9_ReleaseMutex(&mRunFile))
        Dos9_ShowErrorMessage(DOS9_RELEASE_MUTEX_ERROR,
                              __FILE__ ":Dos9_ExecuteFile()" , -1);

    if (info->flags & DOS9_EXEC_WAIT) {

        WaitForSingleObject(pi.hProcess, INFINITE);
        GetExitCodeProcess(pi.hProcess, &status);

    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    free(envblock);

    return status;
}

#else

int Dos9_RunFile(EXECINFO* info, int* error)
{
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;
    void* envblock;
    int status=0;
    size_t size;
    size_t ret;
    DWORD dwFlags;

    wchar_t *wfullline,
            *wfilename,
            *wcurrdir,
            *wenvblock;

    envblock = Dos9_GetEnvBlock(lpeEnv, &size);

    if (!(wfullline = libcu8_xconvert(LIBCU8_TO_U16, info->cmdline,
                                        strlen(info->cmdline) + 1, &ret))
        || !(wfilename = libcu8_xconvert(LIBCU8_TO_U16, info->file,
                                            strlen(info->file) + 1, &ret))
        || !(wcurrdir = libcu8_xconvert(LIBCU8_TO_U16, info->dir,
                                            strlen(info->dir) + 1, &ret))
        || !(wenvblock = libcu8_xconvert(LIBCU8_TO_U16, envblock, size, &ret)))
        Dos9_ShowErrorMessage(DOS9_FAILED_ALLOCATION | DOS9_PRINT_C_ERROR,
                                __FILE__ "/Dos9_RunExternalFile()", -1);

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    if (info->title &&
        !(si.lpTitle = libcu8_xconvert(LIBCU8_TO_U16, info->title,
                                      strlen(info->title) + 1, &ret)))
        Dos9_ShowErrorMessage(DOS9_FAILED_ALLOCATION | DOS9_PRINT_C_ERROR,
                                __FILE__ "/Dos9_RunExternalFile()", -1);

    /* It is very important to serialize calls to Dos9_ExecuteFile() since
       several process may call it at once, and since fds might simultaneously
       be set to inheritable, interference can appear between processes */
    if (Dos9_LockMutex(&mRunFile))
        Dos9_ShowErrorMessage(DOS9_LOCK_MUTEX_ERROR,
                              __FILE__ ":Dos9_ExecuteFile()" , -1);


    if (!(info->flags & DOS9_EXEC_SEPARATE_WINDOW)) {

        Dos9_SetFdInheritance(fileno(fInput), 1);
        Dos9_SetFdInheritance(fileno(fOutput), 1);
        Dos9_SetFdInheritance(fileno(fError), 1);



        si.dwFlags = STARTF_USESTDHANDLES;
        si.hStdInput = _get_osfhandle(fileno(fInput));
        si.hStdOutput = _get_osfhandle(fileno(fOutput));
        si.hStdError = _get_osfhandle(fileno(fError));
    }

    dwFlags = CREATE_UNICODE_ENVIRONMENT
        | ((info->flags & DOS9_EXEC_SEPARATE_WINDOW) ?
            CREATE_NEW_CONSOLE : 0);

    if (!CreateProcessW(wfilename,
                        wfullline,
                        NULL,
                        NULL,
                        (info->flags & DOS9_EXEC_SEPARATE_WINDOW)
                            ? FALSE : TRUE,
                        dwFlags,
                        wenvblock,
                        wcurrdir,
                        &si,
                        &pi))
        *error = 1;

    Dos9_SetFdInheritance(fileno(fInput), 0);
    Dos9_SetFdInheritance(fileno(fOutput), 0);
    Dos9_SetFdInheritance(fileno(fError), 0);

    if (Dos9_ReleaseMutex(&mRunFile))
        Dos9_ShowErrorMessage(DOS9_RELEASE_MUTEX_ERROR,
                              __FILE__ ":Dos9_ExecuteFile()" , -1);

    if (info->flags & DOS9_EXEC_WAIT) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        GetExitCodeProcess(pi.hProcess, &status);
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    free(envblock);
    free(wfullline);
    free(wfilename);
    free(wcurrdir);
    free(wenvblock);

    if (si.lpTitle)
        free(si.lpTitle);

    return status;
}
#endif

#elif !defined(WIN32)

int Dos9_RunFile(EXECINFO* info, int* error)
{
	pid_t iPid;
	int fds[2];
	char c;

	int iResult = 0;

	if (info->flags & DOS9_EXEC_SEPARATE_WINDOW) {

        /* We do not support separate windows, just got to start */
        *error = 1;
        return -1;

	}

	if (pipe(fds) == -1)
        Dos9_ShowErrorMessage(DOS9_CREATE_PIPE | DOS9_PRINT_C_ERROR,
                                __FILE__ "/Dos9_RunFile()",
                                -1);

    Dos9_SetFdInheritance(fds[1], 0);
    Dos9_SetFdInheritance(fds[0], 0);

	iPid=fork();

	if (iPid == 0 ) {
		/* if we are in the son */
        Dos9_ApplyEnv(lpeEnv); /* set internal variable */
        Dos9_ApplyStreams(lppsStreamStack);
        chdir(info->dir);

        close(fds[0]); /* close read end */

		if ( execv(info->file, info->args) == -1) {

			/* if we got here, we can't set ERRORLEVEL
			   variable anymore.

			   This is problematic because if fork do not fail (that
			   is the usual behaviour) command line such as

			        batbox || goto error

			   will not work as expected. However, during search in the
			   path, command found exist, so the risk of such a
			   dysfunction is limited.

			   For more safety, we return -1, along with a pipe message
               so that the given value will be reported anyway*/

			write(fds[1], "x", 1);
			close(fds[1]);

			exit(-1);


		}

	} else {
		/* if we are in the father */
		close(fds[1]);

		if (iPid == (pid_t)-1) {
			/* the execution failed */

			*error = 1;
			close(fds[0]);

			return -1;

		} else {

            if (read(fds[0], &c, sizeof(c)) != 0) {

                close(fds[0]);

                *error = 1;
                return -1;
            }

            close(fds[0]);

			if (info->flags & DOS9_EXEC_WAIT)
                waitpid(iPid, &iResult, 0);

		}

	}

	return WEXITSTATUS(iResult);

}

#endif



#if defined(WIN32)

#include <windows.h>
#include <shellapi.h>

#define SEE_MASK_NOASYNC 0x00000100

#if defined(DOS9_USE_LIBCU8)
#include <libcu8.h>

int Dos9_StartFile(EXECINFO* info, int* error)
{
	SHELLEXECUTEINFOW shinfo;
	wchar_t *chr;
	size_t cvt;
	int status = 0;

	memset(&shinfo, 0, sizeof(shinfo));
	shinfo.cbSize = sizeof(shinfo);
	shinfo.fMask =  SEE_MASK_NOASYNC ;
	shinfo.lpVerb = NULL;
	shinfo.lpDirectory = NULL;
	shinfo.lpParameters = NULL;
	shinfo.nShow = SW_SHOW;

    if (!(shinfo.lpFile = libcu8_xconvert(LIBCU8_TO_U16, info->file,
                                        strlen(info->file) + 1, &cvt))
        || !(shinfo.lpParameters = libcu8_xconvert(LIBCU8_TO_U16, info->cmdline,
                                                    strlen(info->cmdline)+1, &cvt))) {

            Dos9_ShowErrorMessage(DOS9_FAILED_ALLOCATION, "libcu8_xconvert()", FALSE);
            status = DOS9_FAILED_ALLOCATION;

            goto error;
    }

    if (info->dir) {

        if  (!(shinfo.lpDirectory = libcu8_xconvert(LIBCU8_TO_U16, info->dir,
                                                    strlen(info->dir)+1, &cvt))) {

            Dos9_ShowErrorMessage(DOS9_FAILED_ALLOCATION, "libcu8_xconvert()", FALSE);
            status = DOS9_FAILED_ALLOCATION;

            goto error;

        }

        for (chr = shinfo.lpDirectory;*chr;chr ++) {
            if (*chr == L'/')
                *chr = L'\\';
        }

    }

    /* shellexecute seem to have trouble to handle forward slashes */
    for (chr = shinfo.lpFile;*chr;chr ++) {
        if (*chr == L'/')
            *chr = L'\\';
    }

    if (Dos9_LockMutex(&mThreadLock))
        Dos9_ShowErrorMessage(DOS9_LOCK_MUTEX_ERROR,
                                __FILE__ "/Dos9_StartFile()",
                                    -1);
    Dos9_ApplyEnv(lpeEnv);
    Dos9_ApplyStreams(lppsStreamStack);
	status = !ShellExecuteExW(&shinfo);
	Dos9_UnApplyStreams(lppsStreamStack);
    Dos9_UnApplyEnv(lpeEnv);

    if (Dos9_ReleaseMutex(&mThreadLock))
        Dos9_ShowErrorMessage(DOS9_RELEASE_MUTEX_ERROR,
                                __FILE__ "/Dos9_StartFile()",
                                    -1);

	if (status)
        *error = 1;

	if (info->flags & DOS9_EXEC_WAIT) {
		WaitForSingleObject(shinfo.hProcess, INFINITE);
		GetExitCodeProcess(shinfo.hProcess, &status);
	}

	CloseHandle(shinfo.hProcess);


error:
    if (shinfo.lpFile)
        free(shinfo.lpFile);

    if (shinfo.lpParameters)
        free(shinfo.lpParameters);

    if (shinfo.lpDirectory)
        free(shinfo.lpDirectory);

	return status;
}


#else
int Dos9_StartFile(EXECINFO* info, int* error)
{
	SHELLEXECUTEINFO shinfo;
	char buf[FILENAME_MAX],
         *chr;
    int status = 0;

	memset(&shinfo, 0, sizeof(shinfo));
	shinfo.cbSize = sizeof(shinfo);
	shinfo.fMask =  SEE_MASK_NOASYNC;
	shinfo.lpVerb = NULL;
	shinfo.lpDirectory = info->dir;
	shinfo.nShow = SW_SHOW;

    snprintf(buf, sizeof(buf), "%s", info->file);

        /* shellexecute seem to have trouble to handle forward slashes */
    for (chr = buf;*chr;chr ++) {
        if (*chr == '/')
            *chr = '\\';
    }

    shinfo.lpDirectory = info->dir;
    shinfo.lpParameters = info->cmdline;
    shinfo.lpFile = buf;


    if (Dos9_LockMutex(&mThreadLock))
        Dos9_ShowErrorMessage(DOS9_LOCK_MUTEX_ERROR,
                                __FILE__ "/Dos9_StartFile()",
                                    -1);

    /* apply Dos9 internal environment variables */
	Dos9_ApplyEnv(lpeEnv);
	Dos9_ApplyStreams(lppsStreamStack);
	status = !ShellExecuteExA(&shinfo);
	Dos9_UnApplyStreams(lppsStreamStack);
    Dos9_UnApplyEnv(lpeEnv);

    if (Dos9_ReleaseMutex(&mThreadLock))
        Dos9_ShowErrorMessage(DOS9_RELEASE_MUTEX_ERROR,
                                __FILE__ "/Dos9_StartFile()",
                                    -1);


	if (info->flags & DOS9_EXEC_WAIT) {
		WaitForSingleObject(shinfo.hProcess, INFINITE);
		GetExitCodeProcess(shinfo.hProcess, &status);
	}

	CloseHandle(shinfo.hProcess);

	return status;
}
#endif
#else /* !defined(WIN32)  */

int Dos9_StartFile(EXECINFO* info, int* error)
{
    pid_t pid;

    ESTR* tmp;
    char **arg, *script;
    int status=0, i;

    script = Dos9_GetEnv(lpeEnv, "DOS9_START_SCRIPT");

    if (!script)
        script = START_SCRIPT;

    pid = fork();

    if (pid == 0) {

        /* we are in the son */
        if (info->dir && chdir(info->dir) == -1) {
            Dos9_ShowErrorMessage(DOS9_DIRECTORY_ERROR | DOS9_PRINT_C_ERROR,
                                    info->dir,
                                    -1);

        }

        i = 0;

        while (info->args[i])
            i ++;

        if (!(arg = malloc(sizeof(char*)*(i+2))))
            Dos9_ShowErrorMessage(DOS9_FAILED_ALLOCATION | DOS9_PRINT_C_ERROR,
                                    __FILE__ "/Dos9_StartFile()",
                                    -1);

        arg[0] = script;
        arg[1] = info->file;

        i=1;

        while (info->args[i] != NULL) {
            arg[i + 1] = info->args[i];
            i ++;
        }

        arg[i + 1] = NULL;

        lppsStreamStack = Dos9_OpenOutput(lppsStreamStack, "/dev/null",
                                                   DOS9_STDOUT, 0);

        /* apply Dos9 internal environment variables */
        Dos9_ApplyEnv(lpeEnv);
        Dos9_ApplyStreams(lppsStreamStack);

        if (execv(script, arg) == -1) {
            Dos9_ShowErrorMessage(DOS9_COMMAND_ERROR | DOS9_PRINT_C_ERROR,
                                    script,
                                    -1);

        }

    } else if (pid == -1) {

        Dos9_ShowErrorMessage(DOS9_FAILED_FORK | DOS9_PRINT_C_ERROR,
                        __FILE__ "/Dos9_StartFile()",
                        FALSE);
        *error = 1;
        return DOS9_FAILED_FORK ;

    } else {

        if  (info->flags & DOS9_EXEC_WAIT)
            waitpid(pid, &status, 0);

    }

    return status;

}

#endif /* !defined(win32) */
