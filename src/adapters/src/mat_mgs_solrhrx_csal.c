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
        mat_mgs_solrhrx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( mat_mgs_solrhrx_csal )(
    SAL_f32 *R,
    SAL_i32 R_tcols,
    SAL_f32 *B,
    SAL_f32 *X,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_i32 i, j;
    SAL_f32 sum;

    ( void ) xflag;

    if ( flag == SAL_TRANSPOSE_SOLVER )
    {
        for ( i = n - 1; i >= 0; i-- )
        {
            sum = B[i];

            for ( j = i + 1; j < n; j++ )
            {
                sum -= R[i * R_tcols + j] * X[j];
            }

            X[i] = sum * R[i * R_tcols + i];

        }

        for ( i = 0; i < n; i++ )
        {
            sum = X[i];

            for ( j = 0; j < i; j++ )
            {
                sum -= R[j * R_tcols + i] * X[j];
            }

            X[i] = sum * R[i * R_tcols + i];
        }
    }
    else
    {
        for ( i = 0; i < n; i++ )
        {
            sum = B[i];

            for ( j = 0; j < i; j++ )
            {
                sum -= R[j * R_tcols + i] * X[j];
            }

            X[i] = sum * R[i * R_tcols + i];
        }

        for ( i = n - 1; i >= 0; i-- )
        {
            sum = X[i];

            for ( j = i + 1; j < n; j++ )
            {
                sum -= R[i * R_tcols + j] * X[j];
            }

            X[i] = sum * R[i * R_tcols + i];
        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}

