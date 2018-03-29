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
        mat_lud_solx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( mat_lud_solx_csal )(
    SAL_f32 *LU,
    SAL_i32 LUtcols,
    SAL_i32 *D,
    SAL_f32 *b,
    SAL_f32 *w,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_i32 i, j;
    SAL_f32 sum;

    ( void ) xflag;

    if ( flag & SAL_TRANSPOSE_SOLVER )
    {
        for ( i = 0; i < n; i++ )
        {
            w[i] = b[i];
        }

        for ( i = 0; i < n; i++ )
        {
            sum = b[i];

            for ( j = 0; j < i; j++ )
            {
                sum -= LU[j * LUtcols + i] * b[j];
            }

            b[i] = sum * LU[i * LUtcols + i];
        }

        for ( i = n - 1; i >= 0; i-- )
        {
            sum = b[i];

            for ( j = i + 1; j < n; j++ )
            {
                sum -= LU[j * LUtcols + i] * b[j];
            }

            b[i] = sum;
        }

        for ( i = 0; i < n; i++ )
        {
            w[D[i]] = b[i];
        }
    }
    else
    {
        for ( i = 0; i < n; i++ )
        {
            sum = b[D[i]];

            for ( j = 0; j < i; j++ )
            {
                sum -= LU[i * LUtcols + j] * w[j];
            }

            w[i] = sum;
        }

        for ( i = n - 1; i >= 0; i-- )
        {
            sum = w[i];

            for ( j = i + 1; j < n; j++ )
            {
                sum -= LU[i * LUtcols + j] * w[j];
            }

            w[i] = sum * LU[i * LUtcols + i];
        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
