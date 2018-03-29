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
        fft5_small_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

void PREFIX( _csal_fft5_small )( SAL_f32 *Ar, SAL_f32 *Ai, SAL_i32 I,
                                 SAL_f32 *Cr, SAL_f32 *Ci, SAL_i32 K,
                                 SAL_ui32 LOG2N, SAL_i32 FI_FLAG )
{
    SAL_f32  a0r, a0i, a1r, a1i, a2r, a2i, a3r, a3i, a4r, a4i;
    SAL_f32  a5r, a5i, a6r, a6i, a7r, a7i, a8r, a8i, a9r, a9i;
    SAL_f32  t0r, t0i, t1r, t1i, t2r, t2i, t3r, t3i, t4r, t4i, t5r, t5i;
    SAL_f32  *tp;

    SAL_f32 fft5_b1 = ( SAL_f32 )FFT5_B1;
    SAL_f32 fft5_b2 = ( SAL_f32 )FFT5_B2;
    SAL_f32 fft5_b3 = ( SAL_f32 )FFT5_B3;
    SAL_f32 fft5_b4 = ( SAL_f32 )FFT5_B4;
    SAL_f32 fft5_b5 = ( SAL_f32 )FFT5_B5;
    SAL_f32 fft10_c1 = ( SAL_f32 )FFT10_C1;
    SAL_f32 fft10_s1 = ( SAL_f32 )FFT10_S1;
    SAL_f32 fft10_c2 = ( SAL_f32 )FFT10_C2;
    SAL_f32 fft10_s2 = ( SAL_f32 )FFT10_S2;
    SAL_f32 fft10_c3 = ( SAL_f32 )FFT10_C3;
    SAL_f32 fft10_s3 = ( SAL_f32 )FFT10_S3;
    SAL_f32 fft10_c4 = ( SAL_f32 )FFT10_C4;
    SAL_f32 fft10_s4 = ( SAL_f32 )FFT10_S4;

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
        a6r = *( Ar += I );
        a6i = *( Ai += I );
        a7r = *( Ar += I );
        a7i = *( Ai += I );
        a8r = *( Ar += I );
        a8i = *( Ai += I );
        a9r = *( Ar += I );
        a9i = *( Ai += I );

        t0r = a2r + a8r;
        t0i = a2i + a8i;
        t1r = a4r + a6r;
        t1i = a4i + a6i;
        t4r = a6r - a4r;
        t4i = a6i - a4i;
        t5r = a2r - a8r;
        t5i = a2i - a8i;

        t2r = t0r - t1r;
        t2i = t0i - t1i;
        t1r = t0r + t1r;
        t1i = t0i + t1i;
        t3r = t4r + t5r;
        t3i = t4i + t5i;
        a0r = a0r + t1r;
        a0i = a0i + t1i;

        t3r = fft5_b3 * t3r;
        t3i = fft5_b3 * t3i;

        t0r = a0r + ( fft5_b1 * t1r );
        t0i = a0i + ( fft5_b1 * t1i );
        t1r = t3r + ( fft5_b4 * t4r );
        t1i = t3i + ( fft5_b4 * t4i );
        t3r = t3r + ( fft5_b5 * t5r );
        t3i = t3i + ( fft5_b5 * t5i );
        t4r = t0r + ( fft5_b2 * t2r );
        t4i = t0i + ( fft5_b2 * t2i );
        t2r = t0r - ( fft5_b2 * t2r );
        t2i = t0i - ( fft5_b2 * t2i );

        a2r = t4r + t1i;
        a2i = t4i - t1r;
        a4r = t2r + t3i;
        a4i = t2i - t3r;
        a6r = t2r - t3i;
        a6i = t2i + t3r;
        a8r = t4r - t1i;
        a8i = t4i + t1r;

        t0r = a3r + a9r;
        t0i = a3i + a9i;
        t1r = a5r + a7r;
        t1i = a5i + a7i;
        t4r = a7r - a5r;
        t4i = a7i - a5i;
        t5r = a3r - a9r;
        t5i = a3i - a9i;

        t2r = t0r - t1r;
        t2i = t0i - t1i;
        t1r = t0r + t1r;
        t1i = t0i + t1i;
        t3r = t4r + t5r;
        t3i = t4i + t5i;
        a1r = a1r + t1r;
        a1i = a1i + t1i;

        t3r = fft5_b3 * t3r;
        t3i = fft5_b3 * t3i;

        t0r = a1r + ( fft5_b1 * t1r );
        t0i = a1i + ( fft5_b1 * t1i );
        t1r = t3r + ( fft5_b4 * t4r );
        t1i = t3i + ( fft5_b4 * t4i );
        t3r = t3r + ( fft5_b5 * t5r );
        t3i = t3i + ( fft5_b5 * t5i );
        t4r = t0r + ( fft5_b2 * t2r );
        t4i = t0i + ( fft5_b2 * t2i );
        t2r = t0r - ( fft5_b2 * t2r );
        t2i = t0i - ( fft5_b2 * t2i );

        a3r = t4r + t1i;
        a3i = t4i - t1r;
        a5r = t2r + t3i;
        a5i = t2i - t3r;
        a7r = t2r - t3i;
        a7i = t2i + t3r;
        a9r = t4r - t1i;
        a9i = t4i + t1r;

        t0r = a0r + a1r;
        t0i = a0i + a1i;
        a1r = a0r - a1r;
        a1i = a0i - a1i;

        t1r = fft10_c1 * a3r;
        t1i = fft10_c1 * a3i;
        t1r = t1r + ( fft10_s1 * a3i );
        t1i = t1i - ( fft10_s1 * a3r );

        a3r = a2r - t1r;
        a3i = a2i - t1i;
        a2r = a2r + t1r;
        a2i = a2i + t1i;

        t1r = fft10_c2 * a5r;
        t1i = fft10_c2 * a5i;
        t1r = t1r + ( fft10_s2 * a5i );
        t1i = t1i - ( fft10_s2 * a5r );

        a5r = a4r - t1r;
        a5i = a4i - t1i;
        a4r = a4r + t1r;
        a4i = a4i + t1i;

        t1r = fft10_c3 * a7r;
        t1i = fft10_c3 * a7i;
        t1r = t1r + ( fft10_s3 * a7i );
        t1i = t1i - ( fft10_s3 * a7r );

        a7r = a6r - t1r;
        a7i = a6i - t1i;
        a6r = a6r + t1r;
        a6i = a6i + t1i;

        t1r = fft10_c4 * a9r;
        t1i = fft10_c4 * a9i;
        t1r = t1r + ( fft10_s4 * a9i );
        t1i = t1i - ( fft10_s4 * a9r );

        a9r = a8r - t1r;
        a9i = a8i - t1i;
        a8r = a8r + t1r;
        a8i = a8i + t1i;

        *Cr = t0r;
        *Ci = t0i;
        *( Cr += K ) = a2r;
        *( Ci += K ) = a2i;
        *( Cr += K ) = a4r;
        *( Ci += K ) = a4i;
        *( Cr += K ) = a6r;
        *( Ci += K ) = a6i;
        *( Cr += K ) = a8r;
        *( Ci += K ) = a8i;
        *( Cr += K ) = a1r;
        *( Ci += K ) = a1i;
        *( Cr += K ) = a3r;
        *( Ci += K ) = a3i;
        *( Cr += K ) = a5r;
        *( Ci += K ) = a5i;
        *( Cr += K ) = a7r;
        *( Ci += K ) = a7i;
        *( Cr += K ) = a9r;
        *( Ci += K ) = a9i;
    }

    else
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

        t0r = a1r + a4r;
        t0i = a1i + a4i;
        t1r = a2r + a3r;
        t1i = a2i + a3i;
        t4r = a3r - a2r;
        t4i = a3i - a2i;
        t5r = a1r - a4r;
        t5i = a1i - a4i;

        t2r = t0r - t1r;
        t2i = t0i - t1i;
        t1r = t0r + t1r;
        t1i = t0i + t1i;
        t3r = t4r + t5r;
        t3i = t4i + t5i;
        a0r = a0r + t1r;
        a0i = a0i + t1i;

        t3r = fft5_b3 * t3r;
        t3i = fft5_b3 * t3i;

        t0r = a0r + ( fft5_b1 * t1r );
        t0i = a0i + ( fft5_b1 * t1i );
        t1r = t3r + ( fft5_b4 * t4r );
        t1i = t3i + ( fft5_b4 * t4i );
        t3r = t3r + ( fft5_b5 * t5r );
        t3i = t3i + ( fft5_b5 * t5i );
        t4r = t0r + ( fft5_b2 * t2r );
        t4i = t0i + ( fft5_b2 * t2i );
        t2r = t0r - ( fft5_b2 * t2r );
        t2i = t0i - ( fft5_b2 * t2i );

        a1r = t4r + t1i;
        a1i = t4i - t1r;
        a2r = t2r + t3i;
        a2i = t2i - t3r;
        a3r = t2r - t3i;
        a3i = t2i + t3r;
        a4r = t4r - t1i;
        a4i = t4i + t1r;

        *Cr = a0r;
        *Ci = a0i;
        *( Cr += K ) = a1r;
        *( Ci += K ) = a1i;
        *( Cr += K ) = a2r;
        *( Ci += K ) = a2i;
        *( Cr += K ) = a3r;
        *( Ci += K ) = a3i;
        *( Cr += K ) = a4r;
        *( Ci += K ) = a4i;
    }

    SAL_SET_PATH_CSAL();
}
