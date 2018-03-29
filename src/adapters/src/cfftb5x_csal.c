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
        cfftb5x_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_fft_internal.h"

void PREFIX( cfftb5x_csal )(
    SAL_cf32 *A,
    SAL_cf32 *W5,
    SAL_cf32 *C,
    SAL_i32 M,
    SAL_i32 F,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_f32 fft5_b1 = ( SAL_f32 )FFT5_B1;
    SAL_f32 fft5_b2 = ( SAL_f32 )FFT5_B2;
    SAL_f32 fft5_b3 = ( SAL_f32 )FFT5_B3;
    SAL_f32 fft5_b4 = ( SAL_f32 )FFT5_B4;
    SAL_f32 fft5_b5 = ( SAL_f32 )FFT5_B5;
    SAL_cf32  imag = { 0.0, 1.0 };
    SAL_i32  m2, m3, m4;

    m2 = M << 1;
    m3 = M + m2;
    m4 = M << 2;

    PREFIX( cvadd )( A + M, 2, A + m4, 2, C, 2, M );
    PREFIX( cvadd )( A + m2, 2, A + m3, 2, C + M, 2, M );
    PREFIX( cvsub )( A + m3, 2, A + m2, 2, C + m4, 2, M );
    PREFIX( cvsub )( A + M, 2, A + m4, 2, A + M, 2, M );
    PREFIX( cvsub )( C, 2, C + M, 2, C + m2, 2, M );
    PREFIX( cvadd )( C, 2, C + M, 2, C + M, 2, M );
    PREFIX( cvadd )( C + m4, 2, A + M, 2, C + m3, 2, M );
    PREFIX( cvadd )( A, 2, C + M, 2, C, 2, M );

    PREFIX( vsmul )( ( SAL_f32 * )( C + M ), 1, &fft5_b1,
                     ( SAL_f32 * )( C + M ), 1, m2 );
    PREFIX( vsmul )( ( SAL_f32 * )( C + m2 ), 1, &fft5_b2,
                     ( SAL_f32 * )( C + m2 ), 1, m2 );
    PREFIX( vsmul )( ( SAL_f32 * )( C + m3 ), 1, &fft5_b3,
                     ( SAL_f32 * )( C + m3 ), 1, m2 );
    PREFIX( vsmul )( ( SAL_f32 * )( C + m4 ), 1, &fft5_b4,
                     ( SAL_f32 * )( C + m4 ), 1, m2 );
    PREFIX( vsmul )( ( SAL_f32 * )( A + M ), 1, &fft5_b5,
                     ( SAL_f32 * )( A + M ), 1, m2 );

    PREFIX( cvadd )( C, 2, C + M, 2, A, 2, M );
    PREFIX( cvadd )( C + m3, 2, A + M, 2, A + m2, 2, M );
    PREFIX( cvsub )( C + m3, 2, C + m4, 2, A + M, 2, M );
    PREFIX( cvadd )( A, 2, C + m2, 2, A + m3, 2, M );
    PREFIX( cvsub )( A, 2, C + m2, 2, A + m4, 2, M );
    PREFIX( cvcsml )( A + M, 2, &imag, A + M, 2, M );
    PREFIX( cvcsml )( A + m2, 2, &imag, A + m2, 2, M );

    if ( F == 1 )
    {
        PREFIX( cvsub )( A + m3, 2, A + M, 2, C + M, 2, M );
        PREFIX( cvsub )( A + m4, 2, A + m2, 2, C + m2, 2, M );
        PREFIX( cvadd )( A + m4, 2, A + m2, 2, C + m3, 2, M );
        PREFIX( cvadd )( A + m3, 2, A + M, 2, C + m4, 2, M );
    }
    else
    {
        PREFIX( cvadd )( A + m3, 2, A + M, 2, C + M, 2, M );
        PREFIX( cvadd )( A + m4, 2, A + m2, 2, C + m2, 2, M );
        PREFIX( cvsub )( A + m4, 2, A + m2, 2, C + m3, 2, M );
        PREFIX( cvsub )( A + m3, 2, A + M, 2, C + m4, 2, M );
    }

    PREFIX( cvmul )( W5, 2, C + M, 2, C + M, 2, m4, -F );

    PREFIX( cfftb )( C, A, M, F );
    PREFIX( cfftb )( C + M, A + M, M, F );
    PREFIX( cfftb )( C + m2, A + m2, M, F );
    PREFIX( cfftb )( C + m3, A + m3, M, F );
    PREFIX( cfftb )( C + m4, A + m4, M, F );

    PREFIX( cvmov )( A, 2, C, 10, M );
    PREFIX( cvmov )( A + M, 2, C + 1, 10, M );
    PREFIX( cvmov )( A + m2, 2, C + 2, 10, M );
    PREFIX( cvmov )( A + m3, 2, C + 3, 10, M );
    PREFIX( cvmov )( A + m4, 2, C + 4, 10, M );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
