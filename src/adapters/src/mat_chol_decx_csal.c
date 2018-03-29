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
        mat_chol_decx_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( mat_chol_decx_csal )(
    SAL_f32 *A,
    SAL_i32 Atcols,
    SAL_f32 *LDU,
    SAL_i32 LDUtcols,
    SAL_i32 n,
    SAL_f32 *rcond_est,
    SAL_f32 *v,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_f32 Dj;
    SAL_f32 ftmp;
    SAL_i32 i, j, k;
    ( void ) xflag;

    if ( n < 2 )
    {
        if ( n == 1 )
        {
            LDU[ 0 ] = ( SAL_f32 )1.0 / A[ 0 ];

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

    Dj = A[ 0 ];
    LDU[ 0 ] = ( SAL_f32 )1.0 / Dj;

    for ( k = 1; k < n; k++ )
    {
        LDU[ k ] = A[ k ] * LDU[ 0 ];

        LDU[k * LDUtcols] = A[ k * Atcols ];

    }

    for ( j = 1; j < n; j++ )
    {
        Dj = A[ j * Atcols + j ];

        for ( i = 0; i < j ; i++ )
        {
            Dj -= LDU[ i * LDUtcols + j ] * LDU[ j * LDUtcols + i ];
            LDU[j * LDUtcols + i] = LDU[ i * LDUtcols + j ];

        }

        LDU[ j*LDUtcols + j ] = ( SAL_f32 )1.0 / Dj;

        for ( k = j + 1; k < n; k++ )
        {
            ftmp = A[ j * Atcols + k ];

            for ( i = 0; i < j; i++ )
                ftmp -= LDU[ k * LDUtcols + i ] * LDU[ j * LDUtcols + i ];

            LDU[ k * LDUtcols + j ] = ftmp;
            LDU[ j * LDUtcols + k ] = ftmp * LDU[ j*LDUtcols + j ];

        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
