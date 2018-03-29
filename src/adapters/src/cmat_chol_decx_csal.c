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
        cmat_chol_decx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( cmat_chol_decx_csal )(
    SAL_cf32 *c_A,
    SAL_i32 Atcols,
    SAL_cf32 *c_LDU,
    SAL_i32 LDUtcols,
    SAL_i32 n,
    SAL_f32 *rcond_est,
    SAL_cf32 *c_v,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_f32  *A, *LDU;
    SAL_f32  tr, ti;
    SAL_i32  i, j, k;

    ( void ) xflag;

    A = ( SAL_f32 * ) c_A;
    LDU = ( SAL_f32 * ) c_LDU;

    if ( n < 2 )
    {
        if ( n == 1 )
        {
            LDU[ 0 ] = ( SAL_f32 )1.0 / A[ 0 ];
            LDU[ 1 ] = 0.0;

            SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
            SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
            return;
        }
        else
        {
            SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
            SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS + 1 );
            return;
        }
    }

    for ( i = 0; i < n; i++ )
    {
        LDU[0] = 1.0 / A[0];
        LDU[1] = 0.0;

        for ( j = 1; j < ( n - i ); j++ )
        {
            LDU[( j*LDUtcols )*2] = A[( j )*2];
            LDU[( j*LDUtcols )*2 + 1] = A[( j )*2 + 1];
            LDU[( j )*2] = A[( j )*2] * LDU[( 0 )*2];
            LDU[( j )*2 + 1] = A[( j )*2 + 1] * LDU[0];
        }

        for ( j = 1; j < ( n - i ); j++ )
        {
            for ( k = j; k < ( n - i ); k++ )
            {
                tr = LDU[( j*LDUtcols )*2] * LDU[( k )*2] + LDU[( j*LDUtcols )*2 + 1] * LDU[( k )*2 + 1];
                ti = LDU[( j*LDUtcols )*2] * LDU[( k )*2 + 1] - LDU[( j*LDUtcols )*2 + 1] * LDU[( k )*2];
                LDU[( j*LDUtcols + k )*2] = A[( j*Atcols + k )*2] - tr;
                LDU[( j*LDUtcols + k )*2 + 1] = A[( j*Atcols + k )*2 + 1] - ti;
            }

            LDU[( j*LDUtcols )*2] = LDU[( j )*2];
            LDU[( j*LDUtcols )*2 + 1] = -LDU[( j )*2 + 1];
        }

        LDU += ( LDUtcols + 1 ) * 2;
        A = LDU;
        Atcols = LDUtcols;
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
