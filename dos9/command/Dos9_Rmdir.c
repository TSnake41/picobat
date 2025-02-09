/*
 *
 *   Dos9 - A Free, Cross-platform command prompt - The Dos9 project
 *   Copyright (C) 2010-2015 DarkBatcher
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
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>


#include <libDos9.h>

#include "../core/Dos9_Core.h"

#include "Dos9_Commands.h"

#include "../lang/Dos9_Lang.h"
#include "../lang/Dos9_ShowHelp.h"

// #define DOS9_DBG_MODE
#include "../core/Dos9_Debug.h"

#include "../errors/Dos9_Errors.h"

#include "Dos9_Rmdir.h"
#include "Dos9_Del.h"

#include "Dos9_Ask.h"

/* RD [/S] [/Q] dir ...
   RMDIR [/S] [/Q] dir ...

   removes the 'dir' directory. It may also suppress severals directories specified in a row.

   /S : suppress subfolders and subfiles.
   /Q : Quiet for while browsing subfolders.

   */

int Dos9_CmdRmdir(char* lpLine)
{
	ESTR *lpEstr=Dos9_EsInit();

	int	mode=DOS9_SEARCH_DEFAULT | DOS9_SEARCH_NO_PSEUDO_DIR,
		param=DOS9_ASK_CONFIRMATION,
		choice=0,
		n=0,
		status = 0,
		i;

    char **name,
         **tmp;

    size_t namesize = 64;

    FILELIST *next,
             *dir,
             *files = NULL;

    if (!strnicmp(lpLine, "RD", 2)) {

        lpLine +=2; /* RD */

    } else {

        lpLine +=5; /* RMDIR */
    }

    if ((name = malloc(namesize * sizeof(char*))) == NULL) {

        Dos9_ShowErrorMessage(DOS9_FAILED_ALLOCATION,
                                        __FILE__ "/Dos9_CmdRmdir()", 0);
        status = DOS9_FAILED_ALLOCATION;

        goto end;

    }

	while ((lpLine=Dos9_GetNextParameterEs(lpLine, lpEstr))) {

		if (!strcmp(Dos9_EsToChar(lpEstr), "/?")) {

			Dos9_ShowInternalHelp(DOS9_HELP_RD);
			goto end;

		} else if (!stricmp(Dos9_EsToChar(lpEstr),"/S")) {

			/* FIXME : Empty the given directory and then try to suppress
			   the directory */

			mode|=DOS9_SEARCH_RECURSIVE;

		} else if (!stricmp(Dos9_EsToChar(lpEstr), "/Q")) {

			param = 0;
			choice = DOS9_ASK_ALL;

		} else {

            if (n  == namesize) {
                /* It is time to realloc name array, we ran out of space */
                namesize *= 2;

                if ((tmp = realloc(name, namesize * sizeof(char*))) == NULL) {

                    Dos9_ShowErrorMessage(DOS9_FAILED_ALLOCATION,
                                                    __FILE__ "/Dos9_CmdRmdir()", 0);
                    status = DOS9_FAILED_ALLOCATION;

                    goto end;

                }

                name = tmp;

            }

            if ((name[n] = Dos9_FullPathDup(lpEstr->str)) == NULL) {

                Dos9_ShowErrorMessage(DOS9_FAILED_ALLOCATION,
                                                __FILE__ "/Dos9_CmdRmdir()", 0);
                status = DOS9_FAILED_ALLOCATION;

                goto end;

            }

            n ++;

		}

	}

    if (!(mode & DOS9_SEARCH_RECURSIVE) && n == 1) {

        /* This is simple case where we just need to remove the dir */
        choice = DOS9_ASK_ALL;
        Dos9_CmdRmdirFile(name[0], param, &choice);

    } else if (n == 0) {

        Dos9_ShowErrorMessage(DOS9_EXPECTED_MORE, "RD/RMDIR", FALSE);
        status = DOS9_EXPECTED_MORE;

        goto end;

    } else {

        for (i=0; i < n; i++) {

            if (!(dir = Dos9_GetMatchFileList(name[i], mode))) {

                Dos9_ShowErrorMessage(DOS9_NO_MATCH,
                                        name[i],
                                        FALSE);
                status = DOS9_NO_MATCH;

                goto end;
            }

            if (files == NULL) {

                files = dir;
                next = dir;

            } else {

                next->lpflNext = dir;

            }

            while (next->lpflNext)
                next=next->lpflNext;

        }

        Dos9_AttributesSplitFileList(DOS9_CMD_ATTR_DIR,
                                        files,
                                        &dir,
                                        &files
                                        );

        next = files;

        while (next) {


            status |= Dos9_CmdDelFile(next->lpFileName, Dos9_GetFileMode(next),
                                                                    param, &choice);

            next = next->lpflNext;

        }

        next = dir;

        while (next) {

            status |= Dos9_CmdRmdirFile(next->lpFileName, param, &choice);
            next = next->lpflNext;

        }

        Dos9_FreeFileList(dir);
        Dos9_FreeFileList(files);

    }

end:
    if (name) {

        for (i=0;i < n; i++)
            free(name[i]);

        free(name);

    }

	Dos9_EsFree(lpEstr);
	return status;

}

int Dos9_CmdRmdirFile(char* dir, int param, int* choice)
{
    int res = *choice;

    if ((res == 0) && (param & DOS9_ASK_CONFIRMATION)) {

				res=Dos9_AskConfirmation(DOS9_ASK_YNA
				                             | DOS9_ASK_INVALID_REASK
				                             | DOS9_ASK_DEFAULT_N, NULL,
				                             lpRmdirConfirm,
				                             dir
				                            );
        if (res == DOS9_ASK_ALL)
            *choice = res;

    }

    if ((res == DOS9_ASK_ALL) || (res == DOS9_ASK_YES)) {

        return Dos9_Rmdir(dir);

    }

    return 0;

}

int Dos9_Rmdir(const char* dir)
{

    if (rmdir(dir)) {

        Dos9_ShowErrorMessage(DOS9_UNABLE_RMDIR
                                | DOS9_PRINT_C_ERROR, dir, 0);

        return DOS9_UNABLE_RMDIR;

    }

    return 0;

}
