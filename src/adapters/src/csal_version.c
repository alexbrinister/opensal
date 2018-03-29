/*
----------------------------------------------------------------------------

    OpenSAL is an Open Source Scientific Algorithms Library consisting
    of an API for several hundred math functions. The Library is
    composed of a C source code reference implementation. Commercial
    versions of this library are used as performance accelerators in
    HPEC applications.

    Copyright (C) 2010 Mercury Computer Systems, Inc.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/

----------------------------------------------------------------------------

    Filename:
        csal_version.c

----------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include "csal_internal.h"

#define SAL_COPYRIGHT_STR \
    "(c) Copyright Mercury Computer Systems, Inc. 1984-2011"

#if defined(BUILD_CSAL)
#if defined(BUILD_CNTR)
#define SAL_LANG_STR  " CC-Open"
#else
#define SAL_LANG_STR  " C-Open"
#endif
#else
#define SAL_LANG_STR  " Open"
#if !defined(SAL_VERSION_STR)
#define SAL_VERSION_STR "SAL-1.0.0"
#endif
#if !defined(SAL_ARCH)
#define SAL_ARCH "Unknown Architecture"
#endif
#endif

#define SAL_TMP_STR_LEN (128)

#define SAL_MK_VER_STR(new_str,s0,s1,s2,str_len) \
    strncpy(new_str,"@(#)" s0 "" s1 " (" s2 ")",str_len);

void PREFIX( print_csal_version )( SAL_i32 x )
{
    SAL_ui32 i;

    SAL_char version_str[SAL_TMP_STR_LEN];

    ( void )x;

    for ( i = 0; i < SAL_TMP_STR_LEN; i++ )
    {
        version_str[i] = '\0';
    }

    SAL_MK_VER_STR( version_str,
                    SAL_LANG_STR,
                    SAL_VERSION_STR,
                    SAL_ARCH,
                    ( unsigned long ) SAL_TMP_STR_LEN );

    printf( "\n\n  %s\n  %s %s %s\n\n",
            SAL_COPYRIGHT_STR,
            &( version_str[4] ),
            __DATE__,
            __TIME__ );

    SAL_SET_PATH_CSAL();

    return;
}

