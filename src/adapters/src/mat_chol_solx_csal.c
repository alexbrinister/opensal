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
        mat_chol_solx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( mat_chol_solx_csal )(
    SAL_f32 *LDU,
    SAL_i32 LDUtcols,
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
    SAL_f32 *y;

    ( void ) flag;
    ( void ) xflag;

    PREFIX( _csal_malloc_mat_float )( &y, n, 1 );

    y[0] = b[0];

    for ( i = 1; i < n; i++ )
    {
        sum = b[i];

        for ( j = 0; j < i; j++ )
        {
            sum -= LDU[i * LDUtcols + j] * y[j];
        }

        y[i] = sum;
    }

    w[n-1] = LDU[( n-1 )*LDUtcols + ( n-1 )] * y[n-1];

    for ( i = n - 2; i >= 0; i-- )
    {
        sum = LDU[i*LDUtcols + i] * y[i];

        for ( j = i + 1; j < n; j++ )
        {
            sum -= LDU[i*LDUtcols + j] * w[j];

        }

        w[i] = sum;
    }

    free( y );

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
