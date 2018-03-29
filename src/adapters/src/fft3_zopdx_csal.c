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
        fft3_zopdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fft3_zopdx_csal )(
    FFT_setupd *setupp,
    SAL_zf64 *A,
    SAL_i32 I,
    SAL_zf64 *C,
    SAL_i32 K,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL__fft_setupd_csal **SETUPP = &( ( *setupp )->csal_fft_setup );

    SAL_i32 i,
    ix,
    mul_flag;

    SAL_f64 *v0rp, *v0ip, *v1rp, *v1ip, *v2rp, *v2ip;

    SAL_zf64 weights,
    splitp_a,
    splitp_b,
    splitp_c;

    ( void )X;

    PREFIX( _csal_fft_rad3d )( A, I, A, I, ( SAL_ui32 )( 1 << LOG2N ), FLAG );

    v0rp = A->realp;
    v0ip = A->imagp;
    v1rp = v0rp + ( I << LOG2N );
    v1ip = v0ip + ( I << LOG2N );
    v2rp = v1rp + ( I << LOG2N );
    v2ip = v1ip + ( I << LOG2N );

    mul_flag = ( FLAG > 0 ) ? 1 : -1;

    ix = 2 << ( ( *SETUPP )->log2m - LOG2N );

    weights.realp = &( ( *SETUPP )->radix3_twidp_0->real );
    weights.imagp = &( ( *SETUPP )->radix3_twidp_0->imag );

    splitp_a.realp = v1rp;
    splitp_a.imagp = v1ip;

    zvmuldx( &weights, ix, &splitp_a, I, &splitp_a, I, ( 1 << LOG2N ), -mul_flag, 0 );

    weights.realp = &( ( *SETUPP )->radix3_twidp_1->real );
    weights.imagp = &( ( *SETUPP )->radix3_twidp_1->imag );

    splitp_a.realp = v2rp;
    splitp_a.imagp = v2ip;

    zvmuldx( &weights, ix, &splitp_a, I, &splitp_a, I, ( 1 << LOG2N ), -mul_flag, 0 );

    v0rp = A->realp;
    v0ip = A->imagp;
    v1rp = C->realp;
    v1ip = C->imagp;

    for ( i = 0; i < 3; i++ )
    {
        PREFIX( _csal_fft_zbd )( PASS_DOUBLE_COMPLEX_SPLIT( &splitp_a, v0rp, v0ip ), I,
                                 PASS_DOUBLE_COMPLEX_SPLIT( &splitp_b, v0rp, v0ip ), I,
                                 PASS_DOUBLE_COMPLEX_SPLIT( &splitp_c, v1rp, v1ip ),
                                 ( 3*K ), LOG2N, FLAG, setupp );
        v0rp += ( I << LOG2N );
        v0ip += ( I << LOG2N );
        v1rp += K;
        v1ip += K;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
