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
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#include <libDos9.h>

#include "../core/Dos9_Core.h"

#include "Dos9_Block.h"

#include "../lang/Dos9_Lang.h"
#include "../lang/Dos9_ShowHelp.h"

// #define DOS9_DBG_MODE
#include "../core/Dos9_Debug.h"

#include "../errors/Dos9_Errors.h"

int Dos9_CmdBlock(char* lpLine)
{
	BLOCKINFO bkCode;
	char* lpToken;
	ESTR* lpNextBlock=Dos9_EsInit();
	int status = DOS9_NO_ERROR;

	Dos9_GetNextBlockEs(lpLine, lpNextBlock);

	lpToken=Dos9_GetNextBlock(lpLine, &bkCode);

	if (!lpToken) {

		Dos9_ShowErrorMessage(DOS9_INVALID_TOP_BLOCK, lpLine, FALSE);
        status = DOS9_INVALID_TOP_BLOCK;

		goto error;

	}

	if (*lpToken!=')') {

		Dos9_ShowErrorMessage(DOS9_INVALID_TOP_BLOCK, lpLine, FALSE);
        status = DOS9_INVALID_TOP_BLOCK;

		goto error;

	}

	lpToken++;

	lpToken=Dos9_SkipBlanks(lpToken);


	if (*lpToken) {

		Dos9_ShowErrorMessage(DOS9_INVALID_TOP_BLOCK, lpLine, FALSE);
        status = DOS9_INVALID_TOP_BLOCK;

		goto error;

	}

	Dos9_RunBlock(&bkCode);

error:
	Dos9_EsFree(lpNextBlock);
	return status ? status : iErrorLevel;
}
