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
        fftwts3x_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_fft_internal.h"

void PREFIX( fftwts3x_csal )(
    SAL_cf32 *W3,
    SAL_i32 M,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32       i, j, k;
    SAL_f32     angle, arg, one, step, twopivp, zero;

    twopivp = ( SAL_f32 )( ( SAL_f64 )TWO_PI / ( SAL_f64 )( M + ( M << 1 ) ) );

    zero = 0.0;
    one = 1.0;

    step = one;
    k = 0;

    for ( i = 1; i < 3; i++ )
    {
        W3[k].real = one;
        W3[k].imag = zero;
        ++k;
        angle = step;

        for ( j = 1; j < M; j++ )
        {
            arg = angle * twopivp;
            W3[k].real = ( SAL_f32 )cos( arg );
            W3[k].imag = ( SAL_f32 )sin( arg );
            ++k;
            angle += step;
        }

        step += one;
    }

    W3[M-( M>>2 )].real = zero;
    W3[M-( M>>2 )].imag = one;
    W3[M+( M>>2 )+( M>>3 )].real = zero;
    W3[M+( M>>2 )+( M>>3 )].imag = one;
    W3[( M<<1 )-( M>>2 )].real = -one;
    W3[( M<<1 )-( M>>2 )].imag = zero;

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
