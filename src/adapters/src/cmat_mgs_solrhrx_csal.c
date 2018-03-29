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
        cmat_mgs_solrhrx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( cmat_mgs_solrhrx_csal )(
    SAL_cf32 *c_R,
    SAL_i32 R_tcols,
    SAL_cf32 *c_B,
    SAL_cf32 *c_X,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_i32 i, j;
    SAL_f32 sumrp, sumip;
    SAL_f32 *R, *B, *X;

    ( void ) xflag;

    R = ( SAL_f32 * ) c_R;
    B = ( SAL_f32 * ) c_B;
    X = ( SAL_f32 * ) c_X;

    if ( flag == SAL_TRANSPOSE_SOLVER )
    {
        for ( i = n - 1; i >= 0; i-- )
        {
            sumrp = B[i*2];
            sumip = B[i*2 + 1];

            for ( j = i + 1; j < n; j++ )
            {
                sumrp -= R[( i * R_tcols + j )*2] * X[j*2] - R[( i * R_tcols + j )*2 + 1] * X[j*2 + 1];
                sumip -= R[( i * R_tcols + j )*2] * X[j*2 + 1] + R[( i * R_tcols + j )*2 + 1] * X[j*2];
            }

            X[i*2] = sumrp * R[( i * R_tcols + i )*2];
            X[i*2 + 1] = sumip * R[( i * R_tcols + i )*2];

        }

        for ( i = 0; i < n; i++ )
        {
            sumrp = X[i*2];
            sumip = X[i*2 + 1];

            for ( j = 0; j < i; j++ )
            {
                sumrp -= R[( j * R_tcols + i )*2] * X[j*2] + R[( j * R_tcols + i )*2 + 1] * X[j*2 + 1];
                sumip -= R[( j * R_tcols + i )*2] * X[j*2 + 1] - R[( j * R_tcols + i )*2 + 1] * X[j*2];
            }

            X[i*2] = sumrp * R[( i * R_tcols + i )*2];
            X[i*2 + 1] = sumip * R[( i * R_tcols + i )*2];
        }
    }
    else
    {
        for ( i = 0; i < n; i++ )
        {
            sumrp = B[i*2];
            sumip = B[i*2 + 1];

            for ( j = 0; j < i; j++ )
            {
                sumrp -= R[( j * R_tcols + i )*2] * X[j*2] + R[( j * R_tcols + i )*2 + 1] * X[j*2 + 1];
                sumip -= R[( j * R_tcols + i )*2] * X[j*2 + 1] - R[( j * R_tcols + i )*2 + 1] * X[j*2];
            }

            X[i*2] = sumrp * R[( i * R_tcols + i )*2];
            X[i*2 + 1] = sumip * R[( i * R_tcols + i )*2];
        }

        for ( i = n - 1; i >= 0; i-- )
        {
            sumrp = X[i*2];
            sumip = X[i*2 + 1];

            for ( j = i + 1; j < n; j++ )
            {
                sumrp -= R[( i * R_tcols + j )*2] * X[j*2] - R[( i * R_tcols + j )*2 + 1] * X[j*2 + 1];
                sumip -= R[( i * R_tcols + j )*2] * X[j*2 + 1] + R[( i * R_tcols + j )*2 + 1] * X[j*2];
            }

            X[i*2] = sumrp * R[( i * R_tcols + i )*2];
            X[i*2 + 1] = sumip * R[( i * R_tcols + i )*2];

        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}

