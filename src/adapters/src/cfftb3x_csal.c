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
        cfftb3x_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_fft_internal.h"

void PREFIX( cfftb3x_csal )(
    SAL_cf32 *A,
    SAL_cf32 *W3,
    SAL_cf32 *C,
    SAL_i32 M,
    SAL_i32 F,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_f32 fft3_b1 = ( SAL_f32 )FFT3_B1;
    SAL_f32 fft3_b2 = ( SAL_f32 )FFT3_B2;
    SAL_cf32  imag = { 0.0, 1.0 };
    SAL_i32  m2;

    m2 = M << 1;

    PREFIX( cvsub )( A + M, 2, A + m2, 2, C + m2, 2, M );
    PREFIX( cvadd )( A + M, 2, A + m2, 2, C + M, 2, M );
    PREFIX( cvadd )( A, 2, C + M, 2, C, 2, M );

    PREFIX( vsmul )( ( SAL_f32 * )( C + M ), 1, &fft3_b1, ( SAL_f32 * )( A + M ), 1, m2 );
    PREFIX( vsmul )( ( SAL_f32 * )( C + m2 ), 1, &fft3_b2, ( SAL_f32 * )( A + m2 ), 1, m2 );

    PREFIX( cvadd )( C, 2, A + M, 2, A, 2, M );
    PREFIX( cvcsml )( A + m2, 2, &imag, A + M, 2, M );

    if ( F == 1 )
    {
        PREFIX( cvsub )( A, 2, A + M, 2, C + M, 2, M );
        PREFIX( cvadd )( A, 2, A + M, 2, C + m2, 2, M );
    }
    else
    {
        PREFIX( cvadd )( A, 2, A + M, 2, C + M, 2, M );
        PREFIX( cvsub )( A, 2, A + M, 2, C + m2, 2, M );
    }

    PREFIX( cvmul )( W3, 2, C + M, 2, C + M, 2, m2, -F );

    PREFIX( cfftb )( C, A, M, F );
    PREFIX( cfftb )( C + M, A + M, M, F );
    PREFIX( cfftb )( C + m2, A + m2, M, F );

    PREFIX( cvmov )( A, 2, C, 6, M );
    PREFIX( cvmov )( A + M, 2, C + 1, 6, M );
    PREFIX( cvmov )( A + m2, 2, C + 2, 6, M );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
