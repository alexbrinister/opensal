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
        fft_coptdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fft_coptdx_csal )(
    FFT_setupd *SETUPP,
    SAL_cf64 *A,
    SAL_i32 I,
    SAL_cf64 *C,
    SAL_i32 K,
    SAL_cf64 *T,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_zf64 split_a,
    split_c,
    split_t;

    split_a.realp = &( A->real );
    split_a.imagp = &( A->imag );

    split_c.realp = &( C->real );
    split_c.imagp = &( C->imag );

    split_t.realp = &( T->real );
    split_t.imagp = &( T->imag );

    PREFIX( _csal_fft_zbd )( &split_a, I, &split_t, ( SAL_i32 )2, &split_c, K,
                             LOG2N, FLAG, SETUPP );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
