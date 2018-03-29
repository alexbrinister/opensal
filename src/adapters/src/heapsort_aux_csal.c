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
        heapsort_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_internal.h"

void PREFIX( _csal_heap_sort )( C, N )
SAL_f32  *C;
SAL_i32     N;

{
    SAL_i32    i, j, q;
    SAL_f32  key;

    PREFIX( _csal_create_heap )( C, N );
    q = N - 1;

    while ( q )
    {
        key = C[q];
        C[q] = C[0];
        C[0] = key;
        i = 0;
        j = 1;

        while ( j < q )
        {
            if ( ( ( j + 1 ) < q ) && ( C[j+1] > C[j] ) )
                ++j;

            if ( C[j] > key )
            {
                C[i] = C[j];
                i = j;
                j = ( i << 1 ) + 1;
            }
            else
                break;
        }

        C[i] = key;
        --q;
    }

    SAL_SET_PATH_CSAL();
}

void PREFIX( _csal_create_heap )( C, N )
SAL_f32  *C;
SAL_i32     N;

{
    SAL_i32    i, j, q;
    SAL_f32  key;

    for ( q = 1; q < N; q++ )
    {
        i = q;
        key = C[i];

        while ( i > 0 )
        {
            j = ( i - 1 ) >> 1;

            if ( key > C[j] )
            {
                C[i] = C[j];
                i = j;
            }
            else
                break;
        }

        C[i] = key;
    }

    SAL_SET_PATH_CSAL();
}
