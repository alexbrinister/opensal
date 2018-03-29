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
        qksortif_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_internal.h"

void PREFIX( qksortif )( SAL_f32 v[], SAL_ui32 vi[], SAL_ui32 n );
void PREFIX( qksortif )( SAL_f32 v[], SAL_ui32 vi[], SAL_ui32 n )
{
    SAL_ui32 ln, rn, ikeyi, t;
    SAL_f32 ikey, piv;
    SAL_i32 i, j;

    while ( n > 10 )
    {
        if ( v[vi[n/2]] > v[vi[0]] ) SWAP( vi[n/2], vi[0] );

        if ( v[vi[n/2]] > v[vi[n-1]] ) SWAP( vi[n/2], vi[n-1] );

        if ( v[vi[0]] > v[vi[n-1]] ) SWAP( vi[0], vi[n-1] );

        piv = v[vi[0]];

        for ( i = 0, j = n; ; )
        {
            do --j;

            while ( v[vi[j]] > piv );

            do ++i;

            while ( i < j && v[vi[i]] < piv );

            if ( i >= j ) break;

            SWAP( vi[i], vi[j] );
        }

        SWAP( vi[j], vi[0] );

        ln = j;
        rn = n - ++j;

        if ( ln < rn )
        {
            PREFIX( qksortif )( v, &vi[0], ln );
            vi += j;
            n = rn;
        }
        else
        {
            PREFIX( qksortif )( v, &vi[j], rn );
            n = ln;
        }
    }

    if ( n > 1 )
    {
        for ( i = 0; i < ( SAL_i32 )( n - 1 ); i++ )
        {
            if ( v[vi[i]] <= v[vi[i+1]] ) continue;

            ikey = v[vi[i+1]];
            ikeyi = vi[i+1];
            vi[i+1] = vi[i];

            for ( j = i - 1; j >= 0; j-- )
            {
                if ( v[vi[j]] <= ikey ) break;

                vi[j+1] = vi[j];
            }

            vi[j+1] = ikeyi;
        }
    }
}
