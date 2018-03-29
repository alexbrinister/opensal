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
        fft_cvmagsx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fft_cvmagsx_csal )(
    FFT_setup *SETUPP,
    SAL_cf32 *A,
    SAL_i32 I,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_i32    i, N;
    SAL_f32  tempr, tempi;
    SAL_f32  *Arp, *Aip;
    SAL_zf32  split_a;

    ( void )X;

    Arp = split_a.realp = &( A->real );
    Aip = split_a.imagp = &( A->imag );

    PREFIX( _csal_fft_z )( &split_a, I, LOG2N, FLAG, SETUPP );

    N = 1 << LOG2N;
    Arp -= I;
    Aip -= I;
    C -= K;

    for ( i = 0; i < N; i++ )
    {
        tempr = *( Arp += I );
        tempi = *( Aip += I );
        tempr = tempr * tempr;
        tempi = tempi * tempi;
        tempr += tempi;
        *( C += K ) = tempr;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
