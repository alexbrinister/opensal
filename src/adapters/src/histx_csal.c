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
        histx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( histx_csal )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_f32 *C,
    SAL_i32 N,
    SAL_i32 NB,
    SAL_f32 *AMAX,
    SAL_f32 *AMIN,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i, j;
    SAL_f32  max, min, temp1, rbinw, binw;

    max = *AMAX;
    min = *AMIN;

    rbinw = ( SAL_f32 )NB / ( max - min );
    binw = ( max - min ) / ( SAL_f32 )NB;

    A -= I;

    for ( i = 0; i < N; i++ )
    {
        temp1 = *( A += I );

        if ( temp1 <= min )
            j = 0;
        else if ( temp1 >= ( max - ( binw * 0.5 ) ) )
            j = NB - 1;
        else
        {
            temp1 = temp1 - min;
            temp1 = temp1 * rbinw;
            j = ( SAL_i32 ) temp1;
        }

        C[j] += 1.0;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
