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
        fft3_small_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

void PREFIX( _csal_fft3_small )( SAL_f32 *Ar, SAL_f32 *Ai, SAL_i32 I,
                                 SAL_f32 *Cr, SAL_f32 *Ci, SAL_i32 K,
                                 SAL_ui32 LOG2N, SAL_i32 FI_FLAG )
{
    SAL_f32  a0r, a0i, a1r, a1i, a2r, a2i;
    SAL_f32  a3r, a3i, a4r, a4i, a5r, a5i;
    SAL_f32  t0r, t0i, t1r, t1i;
    SAL_f32  *tp;

    SAL_f32 fft3_b1 = ( SAL_f32 )FFT3_B1;
    SAL_f32 fft3_b2 = ( SAL_f32 )FFT3_B2;
    SAL_f32 fft6_c1 = ( SAL_f32 )FFT6_C1;
    SAL_f32 fft6_s1 = ( SAL_f32 )FFT6_S1;
    SAL_f32 fft6_c2 = ( SAL_f32 )FFT6_C2;
    SAL_f32 fft6_s2 = ( SAL_f32 )FFT6_S2;

    if ( FI_FLAG < 0 )
    {
        tp = Ar;
        Ar = Ai;
        Ai = tp;
        tp = Cr;
        Cr = Ci;
        Ci = tp;
    }

    if ( LOG2N == 1 )
    {
        a0r = *Ar;
        a0i = *Ai;
        a1r = *( Ar += I );
        a1i = *( Ai += I );
        a2r = *( Ar += I );
        a2i = *( Ai += I );
        a3r = *( Ar += I );
        a3i = *( Ai += I );
        a4r = *( Ar += I );
        a4i = *( Ai += I );
        a5r = *( Ar += I );
        a5i = *( Ai += I );

        t0r = a2r + a4r;
        t0i = a2i + a4i;
        t1r = a2r - a4r;
        t1i = a2i - a4i;
        a0r = a0r + t0r;
        a0i = a0i + t0i;

        t0r = a0r + ( fft3_b1 * t0r );
        t0i = a0i + ( fft3_b1 * t0i );
        a2r = t0r + ( fft3_b2 * t1i );
        a2i = t0i - ( fft3_b2 * t1r );
        a4r = t0r - ( fft3_b2 * t1i );
        a4i = t0i + ( fft3_b2 * t1r );

        t0r = a3r + a5r;
        t0i = a3i + a5i;
        t1r = a3r - a5r;
        t1i = a3i - a5i;
        a1r = a1r + t0r;
        a1i = a1i + t0i;

        t0r = a1r + ( fft3_b1 * t0r );
        t0i = a1i + ( fft3_b1 * t0i );
        a3r = t0r + ( fft3_b2 * t1i );
        a3i = t0i - ( fft3_b2 * t1r );
        a5r = t0r - ( fft3_b2 * t1i );
        a5i = t0i + ( fft3_b2 * t1r );

        t0r = a0r + a1r;
        t0i = a0i + a1i;
        a1r = a0r - a1r;
        a1i = a0i - a1i;

        t1r = fft6_c1 * a3r;
        t1i = fft6_c1 * a3i;
        t1r = t1r + ( fft6_s1 * a3i );
        t1i = t1i - ( fft6_s1 * a3r );

        a3r = a2r - t1r;
        a3i = a2i - t1i;
        a2r = a2r + t1r;
        a2i = a2i + t1i;

        t1r = fft6_c2 * a5r;
        t1i = fft6_c2 * a5i;
        t1r = t1r + ( fft6_s2 * a5i );
        t1i = t1i - ( fft6_s2 * a5r );

        a5r = a4r - t1r;
        a5i = a4i - t1i;
        a4r = a4r + t1r;
        a4i = a4i + t1i;

        *Cr = t0r;
        *Ci = t0i;
        *( Cr += K ) = a2r;
        *( Ci += K ) = a2i;
        *( Cr += K ) = a4r;
        *( Ci += K ) = a4i;
        *( Cr += K ) = a1r;
        *( Ci += K ) = a1i;
        *( Cr += K ) = a3r;
        *( Ci += K ) = a3i;
        *( Cr += K ) = a5r;
        *( Ci += K ) = a5i;
    }

    else
    {
        a0r = *Ar;
        a0i = *Ai;
        a1r = *( Ar += I );
        a1i = *( Ai += I );
        a2r = *( Ar += I );
        a2i = *( Ai += I );

        t0r = a1r + a2r;
        t0i = a1i + a2i;
        t1r = a1r - a2r;
        t1i = a1i - a2i;
        a0r = a0r + t0r;
        a0i = a0i + t0i;

        t0r = a0r + ( fft3_b1 * t0r );
        t0i = a0i + ( fft3_b1 * t0i );
        a1r = t0r + ( fft3_b2 * t1i );
        a1i = t0i - ( fft3_b2 * t1r );
        a2r = t0r - ( fft3_b2 * t1i );
        a2i = t0i + ( fft3_b2 * t1r );

        *Cr = a0r;
        *Ci = a0i;
        *( Cr += K ) = a1r;
        *( Ci += K ) = a1i;
        *( Cr += K ) = a2r;
        *( Ci += K ) = a2i;
    }

    SAL_SET_PATH_CSAL();
}
