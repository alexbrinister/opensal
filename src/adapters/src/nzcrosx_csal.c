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
        nzcrosx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( nzcrosx_csal )(
    SAL_f32 *r_A,
    SAL_i32 I,
    SAL_i32 IN,
    SAL_i32 *IL,
    SAL_i32 *NF,
    SAL_i32 N,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32 cur_sign, i, num_zcros, sign, sign_bit;
    SAL_i32 offset;
    SAL_i32 *A;

    A = ( SAL_i32 * ) ( ( void * ) r_A );

    if ( ( IN == 0 ) || ( N < 2 ) )
    {
        *IL = 0;
        *NF = 0;
        {
            SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
            SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
            return;
        }
    }

    sign_bit = 0x80000000UL;
    *IL = offset = 0;
    num_zcros = 0;
    sign = A[0] & sign_bit;

    for ( i = 1; i < N; i++ )
    {
        offset += I;
        cur_sign = A[offset] & sign_bit;

        if ( cur_sign ^ sign )
        {
            if ( ++num_zcros == IN )
            {
                *IL = offset;
                break;
            }

            sign = cur_sign;
        }
    }

    *NF = num_zcros;

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
