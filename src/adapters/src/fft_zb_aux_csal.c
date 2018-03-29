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
        fft_zb_aux_csal.c

----------------------------------------------------------------------------
*/

#include "fft_internal.h"

void  PREFIX( _csal_fft_zb )( SAL_zf32 *A, SAL_i32 I,
                              SAL_zf32 *B, SAL_i32 J,
                              SAL_zf32 *C, SAL_i32 K,
                              SAL_ui32 LOG2N, SAL_i32 FLAG,
                              FFT_setup *SETUPP )
{
    SAL__fft_setup_csal **setupp = &( ( *SETUPP )->csal_fft_setup );

    SAL_zf32 Ap, Bp, Cp;

    SAL_ui32 g, l, p, woff, idx;
    SAL_ui32 groupcnt, loopcnt, passcnt;
    SAL_ui32 inshift, log2_radix, outshift;

    SAL_i32 inbackoff, ingroupoff, inbutoff, inputx;
    SAL_i32 outbackoff, outbutoff, outputx, tempx;

    SAL_f32  rad2v2;
    SAL_f32 d1r, d1i, d2r, d2i;
    SAL_f32 p1r, p1i, p2r, p2i;
    SAL_f32 em4r, em4i, em7r, em7i;
    SAL_f32 m2r, m2i, m3r, m3i, m5r, m5i;
    SAL_f32 *Ar, *Ai, *Br, *Bi, *Cr, *Ci;
    SAL_f32 w1r, w1i, w2r, w2i, w3r, w3i;
    SAL_f32 s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
    SAL_f32 *inrp, *inputrp, *outputrp, *outrp, *temprp;
    SAL_f32 *inip, *inputip, *outputip, *outip, *tempip;
    SAL_f32 rr1, ii1, ri1, ir1, rr2, ii2, ri2, ir2, rr3, ii3, ri3, ir3;
    SAL_f32 y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    SAL_f32 a0r, a0i, a1r, a1i, a2r, a2i, a3r, a3i, a4r, a4i, a5r, a5i, a6r, a6i, a7r, a7i;
    SAL_f32 t1r, t1i, t2r, t2i, t3r, t3i, t4r, t4i, t5r, t5i, t6r, t6i, t7r, t7i, t8r, t8i;

    rad2v2 = ( SAL_f32 )SQRT2V2;

    Ap = *A;
    Bp = *B;
    Cp = *C;

    if ( FLAG > 0 )
    {
        Ar = Ap.realp;
        Ai = Ap.imagp;
        Br = Bp.realp;
        Bi = Bp.imagp;
        Cr = Cp.realp;
        Ci = Cp.imagp;
    }
    else
    {
        Ar = Ap.imagp;
        Ai = Ap.realp;
        Br = Bp.imagp;
        Bi = Bp.realp;
        Cr = Cp.imagp;
        Ci = Cp.realp;
    }

    inputrp = Ar;
    inputip = Ai;
    inputx = I;

    if ( LOG2N & 2 )
    {
        outputrp = Cr;
        outputip = Ci;
        outputx = K;
    }
    else
    {
        outputrp = Br;
        outputip = Bi;
        outputx = J;
    }

    log2_radix = ( LOG2N & 1 ) + 2;
    inshift = ( LOG2N - log2_radix );
    inbutoff = inputx << inshift;
    inbackoff = inputx - ( ( inbutoff << log2_radix ) - inbutoff );

    woff = 3 << ( ( *setupp )->log2m - log2_radix );

    outbutoff = outputx << inshift;
    outbackoff = outputx - ( ( outbutoff << log2_radix ) - outbutoff );
    loopcnt = 1 << inshift;
    inrp = inputrp;
    inip = inputip;
    outrp = outputrp;
    outip = outputip;

    if ( LOG2N & 1 )
    {
        for ( l = 0; l < loopcnt; l++ )
        {
            a0r = *inrp;
            a0i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a1r = *inrp;
            a1i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a2r = *inrp;
            a2i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a3r = *inrp;
            a3i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a4r = *inrp;
            a4i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a5r = *inrp;
            a5i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a6r = *inrp;
            a6i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a7r = *inrp;
            a7i = *inip;
            inrp += inbackoff;
            inip += inbackoff;

            t1r = a0r + a4r;
            t1i = a0i + a4i;
            t3r = a1r + a5r;
            t3i = a1i + a5i;
            t2r = a2r + a6r;
            t2i = a2i + a6i;
            t5r = a3r + a7r;
            t5i = a3i + a7i;

            t7r = t1r + t2r;
            t7i = t1i + t2i;
            t8r = t3r + t5r;
            t8i = t3i + t5i;
            m2r = t1r - t2r;
            m2i = t1i - t2i;
            m5r = t3i - t5i;
            m5i = t5r - t3r;

            y0r = t7r + t8r;
            y0i = t7i + t8i;

            y2r = m2r + m5r;
            y2i = m2i + m5i;

            y4r = t7r - t8r;
            y4i = t7i - t8i;

            y6r = m2r - m5r;
            y6i = m2i - m5i;

            t4r = a5r - a1r;
            t4i = a1i - a5i;
            t6r = a7r - a3r;
            t6i = a3i - a7i;
            d1r = a0r - a4r;
            d1i = a0i - a4i;
            em4r = t6r - t4r;
            em4i = t4i - t6i;
            d2r = a6r - a2r;
            d2i = a2i - a6i;

            p1r = rad2v2 * em4r;
            p1i = rad2v2 * em4i;
            em7r = t4i + t6i;
            em7i = t4r + t6r;
            s1r = d1r + p1r;
            s2r = d1r - p1r;
            p2r = rad2v2 * em7r;
            p2i = rad2v2 * em7i;
            s1i = d1i + p1i;
            s2i = d1i - p1i;
            s3r = d2i + p2r;
            s4r = d2i - p2r;
            s3i = d2r + p2i;
            s4i = d2r - p2i;

            y1r = s1r + s3r;
            y1i = s1i + s3i;
            y3r = s2r - s4r;
            y3i = s2i - s4i;
            y5r = s2r + s4r;
            y5i = s2i + s4i;
            y7r = s1r - s3r;
            y7i = s1i - s3i;

            *outrp = y0r;
            *outip = y0i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y1r;
            *outip = y1i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y2r;
            *outip = y2i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y3r;
            *outip = y3i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y4r;
            *outip = y4i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y5r;
            *outip = y5i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y6r;
            *outip = y6i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y7r;
            *outip = y7i;
            outrp += outbackoff;
            outip += outbackoff;
        }
    }

    else
    {
        for ( l = 0; l < loopcnt; l++ )
        {
            a0r = *inrp;
            a0i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a1r = *inrp;
            a1i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a2r = *inrp;
            a2i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a3r = *inrp;
            a3i = *inip;
            inrp += inbackoff;
            inip += inbackoff;

            m2r = a0r - a2r;
            m2i = a0i - a2i;
            t1r = a0r + a2r;
            t1i = a0i + a2i;
            t2r = a1r + a3r;
            t2i = a1i + a3i;
            m3r = a1i - a3i;
            m3i = a3r - a1r;

            y0r = t1r + t2r;
            y0i = t1i + t2i;

            y1r = m2r + m3r;
            y1i = m2i + m3i;

            y2r = t1r - t2r;
            y2i = t1i - t2i;

            y3r = m2r - m3r;
            y3i = m2i - m3i;

            *outrp = y0r;
            *outip = y0i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y1r;
            *outip = y1i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y2r;
            *outip = y2i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y3r;
            *outip = y3i;
            outrp += outbackoff;
            outip += outbackoff;
        }
    }

    if ( LOG2N & 2 )
    {
        inputrp = Br;
        inputip = Bi;
        inputx = J;
    }
    else
    {
        inputrp = Cr;
        inputip = Ci;
        inputx = K;
    }

    outshift = ( LOG2N - 2 );
    groupcnt = log2_radix - 1;

    passcnt = ( LOG2N >> 1 ) - 1;

    for ( p = 0; p < passcnt; p++ )
    {
        temprp = inputrp;
        tempip = inputip;
        inputrp = outputrp;
        inputip = outputip;
        outputrp = temprp;
        outputip = tempip;
        tempx = inputx;
        inputx = outputx;
        outputx = tempx;

        inshift -= 2;
        inbutoff = inputx << inshift;
        ingroupoff = ( inbutoff << 2 ) - inbutoff;
        inbackoff = inputx - ingroupoff;
        outbutoff = outputx << outshift;
        outbackoff = outputx - ( ( outbutoff << 2 ) - outbutoff );

        woff >>= 2;
        idx = woff;
        groupcnt <<= 2;
        loopcnt >>= 2;
        inrp = inputrp;
        inip = inputip;
        outrp = outputrp;
        outip = outputip;

        for ( l = 0; l < loopcnt; l++ )
        {
            a0r = *inrp;
            a0i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a1r = *inrp;
            a1i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a2r = *inrp;
            a2i = *inip;
            inrp += inbutoff;
            inip += inbutoff;
            a3r = *inrp;
            a3i = *inip;
            inrp += inbackoff;
            inip += inbackoff;

            m2r = a0r - a2r;
            m2i = a0i - a2i;
            t1r = a0r + a2r;
            t1i = a0i + a2i;
            t2r = a1r + a3r;
            t2i = a1i + a3i;
            m3r = a1i - a3i;
            m3i = a3r - a1r;

            y0r = t1r + t2r;
            y0i = t1i + t2i;

            y1r = m2r + m3r;
            y1i = m2i + m3i;

            y2r = t1r - t2r;
            y2i = t1i - t2i;

            y3r = m2r - m3r;
            y3i = m2i - m3i;

            *outrp = y0r;
            *outip = y0i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y1r;
            *outip = y1i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y2r;
            *outip = y2i;
            outrp += outbutoff;
            outip += outbutoff;
            *outrp = y3r;
            *outip = y3i;
            outrp += outbackoff;
            outip += outbackoff;
        }

        inrp += ingroupoff;
        inip += ingroupoff;

        for ( g = 1; g < groupcnt; g++ )
        {
            for ( l = 0; l < loopcnt; l++ )
            {
                a0r = *inrp;
                a0i = *inip;
                inrp += inbutoff;
                inip += inbutoff;
                a1r = *inrp;
                a1i = *inip;
                inrp += inbutoff;
                inip += inbutoff;
                a2r = *inrp;
                a2i = *inip;
                inrp += inbutoff;
                inip += inbutoff;
                a3r = *inrp;
                a3i = *inip;
                inrp += inbackoff;
                inip += inbackoff;

                w1r = ( *setupp )->twids.realp[idx];
                w2r = ( *setupp )->twids.realp[idx + 1];
                w3r = ( *setupp )->twids.realp[idx + 2];

                w1i = ( *setupp )->twids.imagp[idx];
                w2i = ( *setupp )->twids.imagp[idx + 1];
                w3i = ( *setupp )->twids.imagp[idx + 2];

                rr1 = w1r * a1r;
                ii1 = w1i * a1i;
                ri1 = w1r * a1i;
                ir1 = w1i * a1r;
                rr2 = w2r * a2r;
                ii2 = w2i * a2i;
                ri2 = w2r * a2i;
                ir2 = w2i * a2r;
                rr3 = w3r * a3r;
                ii3 = w3i * a3i;
                ri3 = w3r * a3i;
                ir3 = w3i * a3r;

                a1r = rr1 + ii1;
                a1i = ri1 - ir1;
                a2r = rr2 + ii2;
                a2i = ri2 - ir2;
                a3r = rr3 + ii3;
                a3i = ri3 - ir3;

                m2r = a0r - a2r;
                m2i = a0i - a2i;
                t1r = a0r + a2r;
                t1i = a0i + a2i;
                t2r = a1r + a3r;
                t2i = a1i + a3i;
                m3r = a1i - a3i;
                m3i = a3r - a1r;

                y0r = t1r + t2r;
                y0i = t1i + t2i;

                y1r = m2r + m3r;
                y1i = m2i + m3i;

                y2r = t1r - t2r;
                y2i = t1i - t2i;

                y3r = m2r - m3r;
                y3i = m2i - m3i;

                *outrp = y0r;
                *outip = y0i;
                outrp += outbutoff;
                outip += outbutoff;
                *outrp = y1r;
                *outip = y1i;
                outrp += outbutoff;
                outip += outbutoff;
                *outrp = y2r;
                *outip = y2i;
                outrp += outbutoff;
                outip += outbutoff;
                *outrp = y3r;
                *outip = y3i;
                outrp += outbackoff;
                outip += outbackoff;
            }

            inrp += ingroupoff;
            inip += ingroupoff;
            idx += woff;
        }
    }

    SAL_SET_PATH_CSAL();
}
