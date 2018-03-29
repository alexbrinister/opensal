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
        fft3_copdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fft3_copdx_csal )(
    FFT_setupd *setupp,
    SAL_cf64 *A,
    SAL_i32 I,
    SAL_cf64 *C,
    SAL_i32 K,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    SAL__fft_setupd_csal **SETUPP = &( ( *setupp )->csal_fft_setup );

    ( void ) XFLAG;

    SAL_ui32  i,
    ix;

    SAL_i32 mul_flag;

    SAL_zf64 weights,
    split_a,
    split_c;

    SAL_f64 *v0rp, *v1rp, *v2rp,
    *v0ip, *v1ip, *v2ip;

    split_a.realp = &( A->real );
    split_a.imagp = &( A->imag );

    PREFIX( _csal_fft_rad3d )( &split_a, I, &split_a, I, ( SAL_ui32 )( 1 << LOG2N ), FLAG );

    v0rp = &( A->real );
    v0ip = &( A->imag );
    v1rp = v0rp + ( I << LOG2N );
    v1ip = v0ip + ( I << LOG2N );
    v2rp = v1rp + ( I << LOG2N );
    v2ip = v1ip + ( I << LOG2N );

    mul_flag = ( FLAG > 0 ) ? 1 : -1;

    ix = 2 << ( ( *SETUPP )->log2m - LOG2N );

    weights.realp = &( ( *SETUPP )->radix3_twidp_0->real );
    weights.imagp = &( ( *SETUPP )->radix3_twidp_0->imag );

    split_a.realp = v1rp;
    split_a.imagp = v1ip;

    PREFIX( zvmuldx )( &weights, ( SAL_i32 )ix, &split_a, I, &split_a, I,
                       ( 1 << LOG2N ), -mul_flag, 0 );

    weights.realp = &( ( *SETUPP )->radix3_twidp_1->real );
    weights.imagp = &( ( *SETUPP )->radix3_twidp_1->imag );

    split_a.realp = v2rp;
    split_a.imagp = v2ip;

    PREFIX( zvmuldx )( &weights, ( SAL_i32 )ix, &split_a, I, &split_a, I,
                       ( 1 << LOG2N ), -mul_flag, 0 );

    split_a.realp = &( A->real );
    split_a.imagp = &( A->imag );

    split_c.realp = &( C->real );
    split_c.imagp = &( C->imag );

    for ( i = 0; i < 3; i++ )
    {
        PREFIX( _csal_fft_zbd )( &split_a, I, &split_a, I, &split_c, ( 3*K ), LOG2N,
                                 FLAG, setupp );

        split_a.realp += ( I << LOG2N );
        split_a.imagp += ( I << LOG2N );

        split_c.realp += K;
        split_c.imagp += K;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
