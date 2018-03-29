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
        fft_rad3_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

void PREFIX( _csal_fft_rad3 )( A, I, C, K, N, FLAG )
SAL_zf32 *A;
SAL_i32           I;
SAL_zf32 *C;
SAL_i32           K;
SAL_ui32          N;
SAL_i32           FLAG;
{
    SAL_ui32 i;

    SAL_f32  fft3_b1, fft3_b2;
    SAL_f32  a0r, a0i, a1r, a1i, a2r, a2i;
    SAL_f32  t0r, t0i, t1r, t1i, t2r, t2i;
    SAL_f32  y0r, y0i, y1r, y1i, y2r, y2i;
    SAL_f32  *av0rp, *av0ip, *av1rp, *av1ip, *av2rp, *av2ip;
    SAL_f32  *cv0rp, *cv0ip, *cv1rp, *cv1ip, *cv2rp, *cv2ip;

    fft3_b1 = ( SAL_f32 )FFT3_B1;

    if ( FLAG == FFT_FORWARD )
    {
        fft3_b2 = ( SAL_f32 )FFT3_B2;
    }
    else
    {
        fft3_b2 = -( SAL_f32 )FFT3_B2;
    }

    av0rp = A->realp;
    av0ip = A->imagp;
    av1rp = av0rp + ( I * N );
    av1ip = av0ip + ( I * N );
    av2rp = av1rp + ( I * N );
    av2ip = av1ip + ( I * N );

    cv0rp = C->realp;
    cv0ip = C->imagp;
    cv1rp = cv0rp + ( K * N );
    cv1ip = cv0ip + ( K * N );
    cv2rp = cv1rp + ( K * N );
    cv2ip = cv1ip + ( K * N );

    for ( i = 0; i < N; i++ )
    {
        a0r = *av0rp;
        a0i = *av0ip;
        a1r = *av1rp;
        a1i = *av1ip;
        a2r = *av2rp;
        a2i = *av2ip;

        t1r = a1r + a2r;
        t1i = a1i + a2i;
        t2r = a1r - a2r;
        t2i = a1i - a2i;
        y0r = a0r + t1r;
        y0i = a0i + t1i;

        t1r = fft3_b1  * t1r;
        t1i = fft3_b1  * t1i;
        t0r = y0r + t1r;
        t0i = y0i + t1i;
        t2r = fft3_b2  * t2r;
        t2i = fft3_b2  * t2i;

        y1r = t0r + t2i;
        y1i = t0i - t2r;
        y2r = t0r - t2i;
        y2i = t0i + t2r;

        *cv0rp = y0r;
        *cv0ip = y0i;
        *cv1rp = y1r;
        *cv1ip = y1i;
        *cv2rp = y2r;
        *cv2ip = y2i;

        av0rp += I;
        av0ip += I;
        av1rp += I;
        av1ip += I;
        av2rp += I;
        av2ip += I;

        cv0rp += K;
        cv0ip += K;
        cv1rp += K;
        cv1ip += K;
        cv2rp += K;
        cv2ip += K;
    }

    SAL_SET_PATH_CSAL();
}
