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
        fcs_ciptx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fcs_ciptx_csal )(
    FFT_setup *SETUPP,
    SAL_cf32 *A,
    SAL_cf32 *C,
    SAL_i32 K,
    SAL_cf32 *T,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_ui32  N;
    SAL_zf32  split_a, split_c, split_t;

    ( void )X;

    N = 1 << LOG2N;

    split_a.realp = &( A->real );
    split_a.imagp = &( A->imag );
    split_c.realp = &( C->real );
    split_c.imagp = &( C->imag );
    split_t.realp = ( SAL_f32 * )T;
    split_t.imagp = ( SAL_f32 * )T + N;

    PREFIX( _csal_fft_zb )( &split_c, K, &split_t, ( SAL_i32 )1, &split_c, K,
                            LOG2N, FLAG, SETUPP );
    PREFIX( _csal_zvmul )( &split_c, K, &split_a, ( SAL_i32 )2, &split_c, K,
                           N, ( SAL_i32 )1 );
    PREFIX( _csal_fft_zb )( &split_c, K, &split_t, ( SAL_i32 )1, &split_c, K,
                            LOG2N, FFT_INVERSE, SETUPP );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
