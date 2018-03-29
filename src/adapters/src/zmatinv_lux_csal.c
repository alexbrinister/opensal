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
        zmatinv_lux_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( zmatinv_lux_csal )(
    SAL_zf32 *C,
    SAL_zf32 *D,
    SAL_i32 *IP,
    SAL_i32 N,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_zf32 D_tmp;
    SAL_zf32 tmp_vec0;
    SAL_zf32 tmp_vec1;
    SAL_i32 j;

    SAL_f32 *tmp_rvec0 = ( SAL_f32 * ) malloc( N * sizeof( SAL_f32 ) );
    SAL_f32 *tmp_ivec0 = ( SAL_f32 * ) malloc( N * sizeof( SAL_f32 ) );
    SAL_f32 *tmp_rvec1 = ( SAL_f32 * ) malloc( N * sizeof( SAL_f32 ) );
    SAL_f32 *tmp_ivec1 = ( SAL_f32 * ) malloc( N * sizeof( SAL_f32 ) );
    SAL_f32 *rcip_rvec = ( SAL_f32 * ) malloc( N * sizeof( SAL_f32 ) );
    SAL_f32 *rcip_ivec = ( SAL_f32 * ) malloc( N * sizeof( SAL_f32 ) );

    ( void )X;

    D_tmp = *D;
    tmp_vec0.realp = tmp_rvec0;
    tmp_vec0.imagp = tmp_ivec0;
    tmp_vec1.realp = tmp_rvec1;
    tmp_vec1.imagp = tmp_ivec1;

    PREFIX( zmat_lud_dec )( C, N, IP, N, NULL, NULL, SAL_RESERVED_FLAG );

    PREFIX( vclr )( tmp_vec0.realp, 1, N );
    PREFIX( vclr )( tmp_vec0.imagp, 1, N );
    tmp_vec0.realp[0] = 1.0;

    for ( j = 0; j < N; j++ )
    {
        PREFIX( zmat_lud_sol )( C, N, IP,
                                &tmp_vec0,
                                &tmp_vec1,
                                N, SAL_NORMAL_SOLVER );

        D_tmp.realp = D->realp + j;
        D_tmp.imagp = D->imagp + j;
        PREFIX( zvmov )( &tmp_vec1, 1, &D_tmp, N, N );

        tmp_vec0.realp[j] = 0.0;

        if ( j < ( N - 1 ) )
            tmp_vec0.realp[j+1] = 1.0;
    }

    free( tmp_rvec0 );
    free( tmp_ivec0 );
    free( tmp_rvec1 );
    free( tmp_ivec1 );
    free( rcip_rvec );
    free( rcip_ivec );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
