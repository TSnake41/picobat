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

#include "libDos9.h"
#include "Dos9_Core.h"
#include "../../config.h"

int iMainThreadId;
char* lpInitVar[]= {
	"DOS9_VERSION", DOS9_VERSION,
	"DOS9_OS", DOS9_OS,
	NULL, NULL, /* DOS9_PATH is dinamically generated */
    "DOS9_OS_TYPE", DOS9_OS_TYPE,
    "NUL", NUL,
    "CON", CON,
    "COM", COM,
    "PRN", PRN,
    "LPT", LPT,
	NULL, NULL
};

void(*pErrorHandler)(void)=NULL;
int fdStdin;
int fdStdout;
int fdStderr;
MUTEX mDuppedStream;


__thread int bDelayedExpansion=FALSE;
__thread int bUseFloats=FALSE;
__thread int bEchoOn=TRUE;
__thread int iErrorLevel=0;
__thread int bIsScript;
__thread int bCmdlyCorrect=FALSE;

__thread int bAbortCommand=FALSE;
__thread LPCOMMANDLIST lpclCommands;
__thread LOCAL_VAR_BLOCK* lpvLocalVars;
    /* use a distinct local block for command arguments

        %1-%9 : arguments
        %* : full line
        %+ : remaning args */
__thread LOCAL_VAR_BLOCK* lpvArguments;
__thread LPSTREAMSTACK lppsStreamStack;
__thread COLOR colColor=DOS9_COLOR_DEFAULT;
__thread FILE* fInput; /* current thread input stream */
__thread FILE* fOutput; /* current thread output stream */
__thread FILE* fError; /* current thread error stream */

__thread ENVBUF* lpeEnv;
__thread INPUT_FILE ifIn;
__thread char lpCurrentDir[FILENAME_MAX];

#ifdef WIN32
#define environ _environ
#else
extern char** environ;
#endif

__thread jmp_buf jbBreak;
