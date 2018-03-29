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
        f3x3x_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( f3x3x_csal )(
    SAL_f32 *A,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_f32 *B,
    SAL_f32 *C,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i, j;
    SAL_f32  *p0, *p1, *p2;
    SAL_f32  w0, w1, w2, w3, w4, w5, w6, w7, w8;
    SAL_f32  sum, temp1, temp2, zero;

    w0 = *B++;
    w1 = *B++;
    w2 = *B++;
    w3 = *B++;
    w4 = *B++;
    w5 = *B++;
    w6 = *B++;
    w7 = *B++;
    w8 = *B++;

    zero = 0.0;

    for ( i = 0; i < NC; i++ )
        *C++ = zero;

    p0 = A - 3;
    p1 = p0 + NC;
    p2 = p1 + NC;

    for ( i = 1; i <= ( NR - 2 ); i++ )
    {
        p0 += 2;
        p1 += 2;
        p2 += 2;

        *C++ = zero;

        for ( j = 1; j <= ( NC - 2 ); j++ )
        {
            temp1 = *( p0 += 1 );
            sum = w0 * temp1;
            temp1 = *( p0 + 1 );
            temp2 = w1 * temp1;
            sum = sum + temp2;
            temp1 = *( p0 + 2 );
            temp2 = w2 * temp1;
            sum = sum + temp2;

            temp1 = *( p1 += 1 );
            temp2 = w3 * temp1;
            sum = sum + temp2;
            temp1 = *( p1 + 1 );
            temp2 = w4 * temp1;
            sum = sum + temp2;
            temp1 = *( p1 + 2 );
            temp2 = w5 * temp1;
            sum = sum + temp2;

            temp1 = *( p2 += 1 );
            temp2 = w6 * temp1;
            sum = sum + temp2;
            temp1 = *( p2 + 1 );
            temp2 = w7 * temp1;
            sum = sum + temp2;
            temp1 = *( p2 + 2 );
            temp2 = w8 * temp1;
            sum = sum + temp2;

            *C++ = sum;
        }

        *C++ = zero;
    }

    for ( i = 0; i < NC; i++ )
        *C++ = zero;

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
