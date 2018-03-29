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
        qksortr_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_internal.h"

void PREFIX( qksortr )( SAL_ui32 v[], SAL_ui32 n );
void PREFIX( qksortr )( SAL_ui32 v[], SAL_ui32 n )
{
    SAL_ui32 ln, rn, ikey, t;
    SAL_i32 i, j;

    while ( n > 10 )
    {
        if ( v[n/2] < v[0] ) SWAP( v[n/2], v[0] );

        if ( v[n/2] < v[n-1] ) SWAP( v[n/2], v[n-1] );

        if ( v[0] < v[n-1] ) SWAP( v[0], v[n-1] );

        for ( i = 0, j = n; ; )
        {
            do --j;

            while ( v[j] < v[0] );

            do ++i;

            while ( i < j && v[i] > v[0] );

            if ( i >= j ) break;

            SWAP( v[i], v[j] );
        }

        SWAP( v[j], v[0] );

        ln = j;
        rn = n - ++j;

        if ( ln < rn )
        {
            PREFIX( qksortr )( v, ln );
            v += j;
            n = rn;
        }
        else
        {
            PREFIX( qksortr )( v + j, rn );
            n = ln;
        }
    }

    if ( n > 1 )
    {
        for ( i = 0; i < ( SAL_i32 )( n - 1 ); i++ )
        {
            if ( v[i] >= v[i+1] ) continue;

            ikey = v[i+1];
            v[i+1] = v[i];

            for ( j = i - 1; j >= 0; j-- )
            {
                if ( v[j] >= ikey ) break;

                v[j+1] = v[j];
            }

            v[j+1] = ikey;
        }
    }
}
