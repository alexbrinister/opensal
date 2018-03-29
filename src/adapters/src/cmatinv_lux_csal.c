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
        cmatinv_lux_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( cmatinv_lux_csal )(
    SAL_cf32 *c_C,
    SAL_cf32 *c_D,
    SAL_i32 *IP,
    SAL_i32 N,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32 j;
    SAL_f32  *C, *D;

    SAL_f32 *tmp_fvec0 = ( SAL_f32 * ) malloc( ( 2 * N ) * sizeof( SAL_f32 ) );
    SAL_f32 *tmp_fvec1 = ( SAL_f32 * ) malloc( ( 2 * N ) * sizeof( SAL_f32 ) );
    SAL_f32 *rcip_vec  = ( SAL_f32 * ) malloc( ( 2 * N ) * sizeof( SAL_f32 ) );

    C = ( SAL_f32 * ) c_C;
    D = ( SAL_f32 * ) c_D;

    PREFIX( cmat_lud_dec )( ( SAL_cf32 * ) C, N, IP, N,
                            NULL, NULL, SAL_RESERVED_FLAG );

    PREFIX( vclr )( &tmp_fvec0[0], 1, ( N << 1 ) );
    tmp_fvec0[0] = 1.0;

    for ( j = 0; j < N; j++ )
    {
        PREFIX( cmat_lud_sol )( ( SAL_cf32 * ) C, N, IP,
                                ( SAL_cf32 * ) &tmp_fvec0[0],
                                ( SAL_cf32 * ) &tmp_fvec1[0],
                                N, SAL_NORMAL_SOLVER );

        PREFIX( cvmov )( ( SAL_cf32 * ) &tmp_fvec1[0], 2,
                         ( SAL_cf32 * ) &D[j << 1], N << 1, N );

        tmp_fvec0[j << 1] = 0.0;

        if ( j < ( N - 1 ) )
            tmp_fvec0[( j+1 ) << 1] = 1.0;
    }

    free( tmp_fvec0 );
    free( tmp_fvec1 );
    free( rcip_vec );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
