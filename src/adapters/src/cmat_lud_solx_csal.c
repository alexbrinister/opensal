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
        cmat_lud_solx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( cmat_lud_solx_csal )(
    SAL_cf32 *c_A,
    SAL_i32 Atcols,
    SAL_i32 *D,
    SAL_cf32 *c_b,
    SAL_cf32 *c_w,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_f32 *A, *b, *w;
    SAL_i32 i, j;
    SAL_f32 sumrp, sumip, diagrp, diagip;
    SAL_f32 temprp, tempip;

    ( void ) xflag;

    A = ( SAL_f32 * ) c_A;
    b = ( SAL_f32 * ) c_b;
    w = ( SAL_f32 * ) c_w;

    if ( flag & SAL_TRANSPOSE_SOLVER )
    {
        for ( i = 0; i < n; i++ )
        {
            w[( i )*2] = b[( i )*2];
            w[( i )*2 + 1] = b[( i )*2 + 1];
        }

        for ( i = 0; i < n; i++ )
        {
            sumrp = b[( i )*2];
            sumip = b[( i )*2 + 1];

            for ( j = 0; j < i; j++ )
            {
                sumrp -= A[( j*Atcols + i )*2] * b[( j )*2] + A[( j*Atcols + i )*2 + 1] * b[( j )*2 + 1];
                sumip -= A[( j*Atcols + i )*2] * b[( j )*2 + 1] - A[( j*Atcols + i )*2 + 1] * b[( j )*2];
            }

            diagrp = A[( i * Atcols + i )*2];
            diagip = -A[( i * Atcols + i )*2 + 1];
            b[( i )*2] = ( sumrp * diagrp - sumip * diagip );
            b[( i )*2 + 1] = ( sumrp * diagip + sumip * diagrp );
        }

        for ( i = n - 1; i >= 0; i-- )
        {
            sumrp = b[( i )*2];
            sumip = b[( i )*2 + 1];

            for ( j = i + 1; j < n; j++ )
            {
                sumrp -= A[( j*Atcols + i )*2] * b[( j )*2] + A[( j*Atcols + i )*2 + 1] * b[( j )*2 + 1];
                sumip -= A[( j*Atcols + i )*2] * b[( j )*2 + 1] - A[( j*Atcols + i )*2 + 1] * b[( j )*2];
            }

            b[( i )*2] = sumrp;
            b[( i )*2 + 1] = sumip;
        }

        for ( i = 0; i < n; i++ )
        {
            w[( D[i] )*2] = b[( i )*2];
            w[( D[i] )*2 + 1] = b[( i )*2 + 1];
        }
    }
    else
    {
        for ( i = 0; i < n; i++ )
        {
            sumrp = b[( D[i] ) * 2];
            sumip = b[( D[i] ) * 2 + 1];

            for ( j = 0; j < i; j++ )
            {
                sumrp -= A[( i*Atcols + j )*2] * w[( j )*2] - A[( i*Atcols + j )*2 + 1] * w[( j )*2 + 1];
                sumip -= A[( i*Atcols + j )*2] * w[( j )*2 + 1] + A[( i*Atcols + j )*2 + 1] * w[( j )*2];
            }

            w[( i )*2] = sumrp;
            w[( i )*2 + 1] = sumip;
        }

        for ( i = n - 1; i >= 0; i-- )
        {
            sumrp = w[( i )*2];
            sumip = w[( i )*2 + 1];

            for ( j = i + 1; j < n; j++ )
            {
                sumrp -= A[( i*Atcols + j )*2] * w[( j )*2] - A[( i*Atcols + j )*2 + 1] * w[( j )*2 + 1];
                sumip -= A[( i*Atcols + j )*2] * w[( j )*2 + 1] + A[( i*Atcols + j )*2 + 1] * w[( j )*2];
            }

            diagrp = A[( i * Atcols + i )*2];
            diagip = A[( i * Atcols + i )*2 + 1];
            temprp = ( sumrp * diagrp - sumip * diagip );
            tempip = ( sumrp * diagip + sumip * diagrp );
            w[( i )*2] = temprp;
            w[( i )*2 + 1] = tempip;
        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
