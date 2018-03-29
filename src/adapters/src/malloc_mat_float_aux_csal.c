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
        malloc_mat_float_aux_csal.c

----------------------------------------------------------------------------
*/

#if 0
#include <stdio.h>
#endif

#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( _csal_malloc_mat_float )( SAL_f32 **Y, SAL_i32 nrows, SAL_i32 ncols )
{
    SAL_ui32 nbytes;

    nbytes = nrows * ncols * sizeof( SAL_f32 );
    *Y = ( SAL_f32 * ) malloc( ( unsigned long )nbytes );

    if ( !*Y )
    {
#if 0
        printf( "\n***Error : %s(%d) : malloc(%lu) failed\n",
                __FILE__, __LINE__, nbytes );
#endif
        exit( 1 );
    }
}
