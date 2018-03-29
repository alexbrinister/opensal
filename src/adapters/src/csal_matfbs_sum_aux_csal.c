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
        csal_matfbs_sum_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_internal.h"

void PREFIX( _csal_matfbs_sum )( sum_addr, vec1_addr, stride1,
                                 vec2_addr, stride2, count )
SAL_f32 *sum_addr;
SAL_f32 *vec1_addr;
SAL_i32 stride1;
SAL_f32 *vec2_addr;
SAL_i32 stride2;
SAL_i32 count;
{
    SAL_f32 sum0, sum1, sum2, fcount;
    SAL_i32 loop_count, rem_count, i, k;

    fcount = ( SAL_f32 )count;
    loop_count = ( SAL_i32 )( fcount / 3.0 );
    rem_count = ( SAL_i32 )( fcount - ( ( SAL_f32 )loop_count * 3.0 ) );

    sum0 = 0.0;
    sum1 = 0.0;
    sum2 = 0.0;

    for ( i = k = 0; i < loop_count; i++, k += 3 )
    {
        sum0 += ( vec1_addr[k * stride1] * vec2_addr[k * stride2] );
        sum1 += ( vec1_addr[( k+1 ) * stride1] * vec2_addr[( k+1 ) * stride2] );
        sum2 += ( vec1_addr[( k+2 ) * stride1] * vec2_addr[( k+2 ) * stride2] );
    }

    if ( rem_count == 1 )
        sum0 += ( vec1_addr[k * stride1] * vec2_addr[k * stride2] );
    else if ( rem_count == 2 )
    {
        sum0 += ( vec1_addr[k * stride1] * vec2_addr[k * stride2] );
        sum1 += ( vec1_addr[( k+1 ) * stride1] * vec2_addr[( k+1 ) * stride2] );
    }

    *sum_addr -= sum0;
    sum1 += sum2;
    *sum_addr -= sum1;

    SAL_SET_PATH_CSAL();
}

