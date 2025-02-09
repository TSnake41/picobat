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

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 700
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include <libDos9.h>

#include "../core/Dos9_Core.h"

#include "Dos9_Type.h"

#include "../lang/Dos9_Lang.h"
#include "../lang/Dos9_ShowHelp.h"

// #define DOS9_DBG_MODE
#include "../core/Dos9_Debug.h"

#include "../errors/Dos9_Errors.h"

/* TYPE file

   Type the file 'file'

*/

void Dos9_TypeFileF(FILE* pFile)
{
    char buf[1024];
    size_t size;

    while ((size = fread(buf, 1, sizeof(buf), pFile)))
        fwrite(buf, 1, size, fOutput);

    if (isatty(fileno(pFile)))
        clearerr(pFile);
}

int Dos9_TypeFile(char* lpFileName)
{
    FILE* pFile;
    char buf[1024];
    size_t size;

    if (!(pFile=fopen(lpFileName, "rb"))) {

        Dos9_ShowErrorMessage(DOS9_FILE_ERROR | DOS9_PRINT_C_ERROR,
                                lpFileName,
                                FALSE
                                );

        return DOS9_FILE_ERROR;
    }

    while ((size = fread(buf, 1, sizeof(buf), pFile)))
        fwrite(buf, 1, size, fOutput);

    fclose(pFile);

    return 0;
}

int Dos9_CmdType(char* lpLine)
{
	ESTR* lpEsParam=Dos9_EsInit();

	FILELIST *pBegin=NULL,
             *pTmp=NULL,
             *pEnd;

    int status=0, nSize;
    char *buf;


    lpLine += 4;

    /* adjust buffering size to get maximum performances */
    if (isatty(fileno(fOutput))) {

        if ((buf = malloc(8192)) == NULL) {

            Dos9_ShowErrorMessage(DOS9_FAILED_ALLOCATION | DOS9_PRINT_C_ERROR,
                                    __FILE__ "/Dos9_CmdType()",
                                    0);
            status = DOS9_FAILED_ALLOCATION;
            goto end;

        }

        setvbuf(fOutput, buf, _IOFBF, 8192);

    }

    while ((lpLine = Dos9_GetNextParameterEs(lpLine, lpEsParam))) {

        if (!strcmp(Dos9_EsToChar(lpEsParam), "/?")) {

            Dos9_ShowInternalHelp(DOS9_HELP_TYPE);

            goto end;

        } else  {

            /* Get a list of files that matches the argument */
            if (!(pTmp = Dos9_GetMatchFileList(Dos9_EsToFullPath(lpEsParam),
                                                    DOS9_SEARCH_DEFAULT))) {

                Dos9_ShowErrorMessage(DOS9_NO_MATCH,
                                       Dos9_EsToChar(lpEsParam),
                                       FALSE
                                       );

                status = DOS9_NO_MATCH;
                goto end;

            }

            if (!pBegin)
                pBegin = (pEnd = pTmp);
            else
                pEnd->lpflNext = pTmp; /* catenate the lists */

        }

    }

    if (pTmp == NULL) {
        /* If the command has no parameter */
        Dos9_TypeFileF(fInput);

    } else {

        /* remove directories from input */
        Dos9_AttributesSplitFileList(DOS9_ATTR_NO_DIR,
                                        pBegin,
                                        &pBegin,
                                        &pTmp
                                        );

        if (pTmp)
            Dos9_FreeFileList(pTmp);

        pEnd = pBegin;

        while (pEnd && pEnd->lpflNext)
            pEnd = pEnd->lpflNext;

        if (!pBegin) {

            Dos9_ShowErrorMessage(DOS9_NO_VALID_FILE,
                                    "TYPE",
                                    FALSE
                                    );

            status = DOS9_NO_VALID_FILE;
            goto end;

        }

        if (pEnd == pBegin) {

            /* only one file matching */
            status = Dos9_TypeFile(pBegin->lpFileName);

        } else {

            /* several files matching */
            pTmp = pBegin;

            while (pTmp) {

                fprintf(fOutput, "---------- %s" DOS9_NL , pTmp->lpFileName);
                status |= Dos9_TypeFile(pTmp->lpFileName);

                pTmp = pTmp->lpflNext;

            }

        }
    }

end:

    if (isatty(fileno(fOutput))) {

        fflush(fOutput);
        setvbuf(fOutput, NULL, _IONBF, 0);

        free(buf);

    }

    if (pBegin)
        Dos9_FreeFileList(pBegin);

    Dos9_EsFree(lpEsParam);

    return status;
}
