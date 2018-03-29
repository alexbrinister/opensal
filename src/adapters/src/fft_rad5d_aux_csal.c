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
        fft_rad5d_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

void PREFIX( _csal_fft_rad5d )( A, I, C, K, N, FLAG )
SAL_zf64 *A;
SAL_i32                  I;
SAL_zf64 *C;
SAL_i32                  K;
SAL_ui32                 N;
SAL_i32                  FLAG;
{
    SAL_ui32  i;

    SAL_f64 m2r, m2i;
    SAL_f64 fft5_b1, fft5_b2, fft5_b3, fft5_b4, fft5_b5;
    SAL_f64 a0r, a0i, a1r, a1i, a2r, a2i, a3r, a3i, a4r, a4i;
    SAL_f64 y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, y4r, y4i;
    SAL_f64 t0r, t0i, t1r, t1i, t2r, t2i, t3r, t3i, t4r, t4i, t5r, t5i;
    SAL_f64 *av0rp, *av0ip, *av1rp, *av1ip, *av2rp, *av2ip, *av3rp, *av3ip, *av4rp, *av4ip;
    SAL_f64 *cv0rp, *cv0ip, *cv1rp, *cv1ip, *cv2rp, *cv2ip, *cv3rp, *cv3ip, *cv4rp, *cv4ip;

    fft5_b1 = ( SAL_f64 )FFT5_B1;
    fft5_b2 = ( SAL_f64 )FFT5_B2;

    if ( FLAG == FFT_FORWARD )
    {
        fft5_b3 = ( SAL_f64 )FFT5_B3;
        fft5_b4 = ( SAL_f64 )FFT5_B4;
        fft5_b5 = ( SAL_f64 )FFT5_B5;
    }
    else
    {
        fft5_b3 = -( SAL_f64 )FFT5_B3;
        fft5_b4 = -( SAL_f64 )FFT5_B4;
        fft5_b5 = -( SAL_f64 )FFT5_B5;
    }

    av0rp = A->realp;
    av0ip = A->imagp;
    av1rp = av0rp + ( I * N );
    av1ip = av0ip + ( I * N );
    av2rp = av1rp + ( I * N );
    av2ip = av1ip + ( I * N );
    av3rp = av2rp + ( I * N );
    av3ip = av2ip + ( I * N );
    av4rp = av3rp + ( I * N );
    av4ip = av3ip + ( I * N );

    cv0rp = C->realp;
    cv0ip = C->imagp;
    cv1rp = cv0rp + ( K * N );
    cv1ip = cv0ip + ( K * N );
    cv2rp = cv1rp + ( K * N );
    cv2ip = cv1ip + ( K * N );
    cv3rp = cv2rp + ( K * N );
    cv3ip = cv2ip + ( K * N );
    cv4rp = cv3rp + ( K * N );
    cv4ip = cv3ip + ( K * N );

    for ( i = 0; i < N; i++ )
    {
        a0r = *av0rp;
        a0i = *av0ip;
        a1r = *av1rp;
        a1i = *av1ip;
        a2r = *av2rp;
        a2i = *av2ip;
        a3r = *av3rp;
        a3i = *av3ip;
        a4r = *av4rp;
        a4i = *av4ip;

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
        y0r = a0r + t1r;
        y0i = a0i + t1i;

        t1r = fft5_b1 * t1r;
        t1i = fft5_b1 * t1i;
        m2r = fft5_b2 * t2r;
        m2i = fft5_b2 * t2i;
        t3r = fft5_b3 * t3r;
        t3i = fft5_b3 * t3i;
        t4r = fft5_b4 * t4r;
        t4i = fft5_b4 * t4i;
        t5r = fft5_b5 * t5r;
        t5i = fft5_b5 * t5i;

        t0r = y0r + t1r;
        t0i = y0i + t1i;
        t1r = t3r + t4r;
        t1i = t3i + t4i;
        t2r = t3r + t5r;
        t2i = t3i + t5i;
        t3r = t0r + m2r;
        t3i = t0i + m2i;
        t4r = t0r - m2r;
        t4i = t0i - m2i;

        y1r = t3r + t1i;
        y1i = t3i - t1r;
        y2r = t4r + t2i;
        y2i = t4i - t2r;
        y3r = t4r - t2i;
        y3i = t4i + t2r;
        y4r = t3r - t1i;
        y4i = t3i + t1r;

        *cv0rp = y0r;
        *cv0ip = y0i;
        *cv1rp = y1r;
        *cv1ip = y1i;
        *cv2rp = y2r;
        *cv2ip = y2i;
        *cv3rp = y3r;
        *cv3ip = y3i;
        *cv4rp = y4r;
        *cv4ip = y4i;

        av0rp += I;
        av0ip += I;
        av1rp += I;
        av1ip += I;
        av2rp += I;
        av2ip += I;
        av3rp += I;
        av3ip += I;
        av4rp += I;
        av4ip += I;

        cv0rp += K;
        cv0ip += K;
        cv1rp += K;
        cv1ip += K;
        cv2rp += K;
        cv2ip += K;
        cv3rp += K;
        cv3ip += K;
        cv4rp += K;
        cv4ip += K;

    }

    SAL_SET_PATH_CSAL();
}

