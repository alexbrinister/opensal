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
        cexpmulx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( cexpmulx_csal )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_f32 *F,
    SAL_f32 *P,
    SAL_cf32 *C,
    SAL_i32 K,
    SAL_cf32 *CEXPTAB,
    SAL_i32 LOG2M,
    SAL_i32 N,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_ui32 bfreq, bphase, i, index, shift;
    SAL_f64       freq, phase;
    SAL_f32        cos_val, sin_val;

    ( void ) X;

    freq = ( SAL_f64 ) * F;
    phase = ( SAL_f64 ) * P;

    phase *= ( SAL_f64 ) TWO_PI_RECP;
    phase -= ( SAL_f64 ) ( ( SAL_i32 ) phase );

    if ( phase < 0.0 )
        phase += 1.0;

    bphase = ( SAL_ui32 ) ( ( phase * ( SAL_f64 ) POW2_32 ) + ( SAL_f64 ) 0.5 );
    bphase += ( 1 << ( 31 - LOG2M ) );

    freq *= ( SAL_f64 ) TWO_PI_RECP;
    freq -= ( SAL_f64 ) ( ( SAL_i32 ) freq );

    if ( freq < 0.0 )
        freq += 1.0;

    bfreq = ( SAL_ui32 ) ( ( freq * ( SAL_f64 ) POW2_32 ) + ( SAL_f64 ) 0.5 );

    shift = 32 - LOG2M;
    K >>= 1;

    for ( i = 0; i < ( SAL_ui32 ) N; i++ )
    {
        index = bphase >> shift;
        cos_val = CEXPTAB[index].real;
        sin_val = CEXPTAB[index].imag;
        cos_val *= *A;
        sin_val *= *A;
        C->real = cos_val;
        C->imag = sin_val;
        bphase += bfreq;

        A += I;
        C += K;
    }

    phase = ( SAL_f64 ) ( bphase - ( 1 << ( 31 - LOG2M ) ) ) * ( SAL_f64 ) TWO_PI_V_POW2_32;
    *P = ( SAL_f32 ) phase;

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
