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
        cmat_chol_solx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( cmat_chol_solx_csal )(
    SAL_cf32 *c_LDU,
    SAL_i32 LDUtcols,
    SAL_cf32 *c_b,
    SAL_cf32 *c_w,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_i32 i, j;
    SAL_f32 sumrp, sumip;
    SAL_f32 *LDU, *b, *w, *y;

    ( void ) flag;
    ( void ) xflag;

    LDU = ( SAL_f32 * ) c_LDU;
    b = ( SAL_f32 * ) c_b;
    w = ( SAL_f32 * ) c_w;

    PREFIX( _csal_malloc_mat_float )( &y, 2*n, 1 );

    y[0] = b[0];
    y[1] = b[1];

    for ( i = 1; i < n; i++ )
    {
        sumrp = b[( i )*2];
        sumip = b[( i )*2 + 1];

        for ( j = 0; j < i; j++ )
        {
            sumrp -= LDU[( i * LDUtcols + j )*2] * y[( j )*2]
                     - LDU[( i * LDUtcols + j )*2 + 1] * y[( j )*2 + 1];
            sumip -= LDU[( i * LDUtcols + j )*2] * y[( j )*2 + 1]
                     + LDU[( i * LDUtcols + j )*2 + 1] * y[( j )*2];
        }

        y[( i )*2] = sumrp;
        y[( i )*2 + 1] = sumip;
    }

    w[( n-1 )*2] = LDU[( ( n-1 )*LDUtcols + ( n-1 ) )*2] * y[( n-1 )*2];
    w[( n-1 )*2 + 1] = LDU[( ( n-1 )*LDUtcols + ( n-1 ) )*2] * y[( n-1 )*2 + 1];

    for ( i = n - 2; i >= 0; i-- )
    {
        sumrp = LDU[( i*LDUtcols + i )*2] * y[( i )*2];
        sumip = LDU[( i*LDUtcols + i )*2] * y[( i )*2 + 1];

        for ( j = i + 1; j < n; j++ )
        {
            sumrp -= LDU[( i*LDUtcols + j )*2] * w[( j )*2]
                     - LDU[( i*LDUtcols + j )*2 + 1] * w[( j )*2 + 1];
            sumip -= LDU[( i*LDUtcols + j )*2] * w[( j )*2 + 1]
                     + LDU[( i*LDUtcols + j )*2 + 1] * w[( j )*2];

        }

        w[( i )*2] = sumrp;
        w[( i )*2 + 1] = sumip;
    }

    free( y );

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
