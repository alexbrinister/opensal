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
        fftcom_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

SAL_f32 PREFIX( fft_tbuf[2048] );

void PREFIX( _csal_cfftsm )( c, stride, n, f, brflag )
SAL_f32 *c;
SAL_i32    stride;
SAL_i32    n;
SAL_i32    f;
SAL_i32    brflag;

{

    SAL_i32   i, j, k, log2n, log2m, log2mvn;
    SAL_i32   loopcnt, passcnt;
    SAL_i32   coff, maskc, maskw, stcoff, winc, woff;
    SAL_f32 *tptr, *w, *wptr;
    SAL_f32 a0r, a0i, a1r, a1i, a2r, a2i, a3r, a3i, a4r, a4i, a5r, a5i, a6r, a6i, a7r, a7i;
    SAL_f32 d1r, d1i, d2r, d2i;
    SAL_f32 em4r, em4i, em7r, em7i;
    SAL_f32 m2r, m2i, m3r, m3i, m5r, m5i;
    SAL_f32 p1r, p1i, p2r, p2i;
    SAL_f32 s1r, s1i, s2r, s2i, s3r, s3i, s4r, s4i;
    SAL_f32 t1r, t1i, t2r, t2i, t3r, t3i, t4r, t4i, t5r, t5i, t6r, t6i, t7r, t7i, t8r, t8i;
    SAL_f32 rr1, ii1, ri1, ir1, rr2, ii2, ri2, ir2, rr3, ii3, ri3, ir3;
    SAL_f32 w1r, w1i, w2r, w2i, w3r, w3i;
    SAL_f32 x1r, x1i, x2r, x2i, x3r, x3i;
    SAL_f32 y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    SAL_f32 rad2v2 = ( SAL_f32 )0.70710678118654752440;

    j = 0;
    k = 0;

    for ( i = 0; i < n; i++ )
    {
        PREFIX( fft_tbuf[j] ) = c[k];
        PREFIX( fft_tbuf[j+1] ) = c[k+1];
        j += 2;
        k += stride;
    }

    log2n = 0;
    i = n >> 1;

    while ( i )
    {
        ++log2n;
        i >>= 1;
    }

    log2m = PREFIX( fftwts_tab.LOG2_m );
    log2mvn = log2m - log2n;
    coff = n >> 1;
    maskc = n + coff;
    w = ( SAL_f32 * ) PREFIX( fftwts_tab.c );
    maskw = coff << log2mvn;
    winc = 2 << log2mvn;
    passcnt = ( log2n >> 1 ) - 1;
    loopcnt = n >> 2;

    for ( i = 0; i < passcnt; i++ )
    {
        stcoff = 0;
        woff = 0;

        for ( j = 0; j < loopcnt; j++ )
        {
            tptr = PREFIX( fft_tbuf );
            a0r = *( tptr += stcoff );
            a0i = *( tptr + 1 );
            a1r = *( tptr += coff );
            a1i = *( tptr + 1 );
            a2r = *( tptr += coff );
            a2i = *( tptr + 1 );
            a3r = *( tptr += coff );
            a3i = *( tptr + 1 );
            m2r = a0r - a2r;
            m2i = a0i - a2i;
            t1r = a0r + a2r;
            t1i = a0i + a2i;
            t2r = a1r + a3r;
            t2i = a1i + a3i;

            if ( f == 1 )
            {
                m3r = a1i - a3i;
                m3i = a3r - a1r;
            }
            else
            {
                m3r = a3i - a1i;
                m3i = a1r - a3r;
            }

            y0r = t1r + t2r;
            y0i = t1i + t2i;
            x1r = m2r + m3r;
            x1i = m2i + m3i;
            x2r = t1r - t2r;
            x2i = t1i - t2i;
            x3r = m2r - m3r;
            x3i = m2i - m3i;
            wptr = w;
            w1r = *( wptr += woff );
            w1i = *( wptr + 1 );
            w2r = *( wptr += woff );
            w2i = *( wptr + 1 );
            w3r = *( wptr += woff );
            w3i = *( wptr + 1 );
            rr1 = w1r * x1r;
            ii1 = w1i * x1i;
            ri1 = w1r * x1i;
            ir1 = w1i * x1r;
            rr2 = w2r * x2r;
            ii2 = w2i * x2i;
            ri2 = w2r * x2i;
            ir2 = w2i * x2r;
            rr3 = w3r * x3r;
            ii3 = w3i * x3i;
            ri3 = w3r * x3i;
            ir3 = w3i * x3r;

            if ( f == 1 )
            {
                y1r = rr1 + ii1;
                y1i = ri1 - ir1;
                y2r = rr2 + ii2;
                y2i = ri2 - ir2;
                y3r = rr3 + ii3;
                y3i = ri3 - ir3;
            }
            else
            {
                y1r = rr1 - ii1;
                y1i = ri1 + ir1;
                y2r = rr2 - ii2;
                y2i = ri2 + ir2;
                y3r = rr3 - ii3;
                y3i = ri3 + ir3;
            }

            tptr = PREFIX( fft_tbuf );
            *( tptr += stcoff ) = y0r;
            *( tptr + 1 ) = y0i;
            *( tptr += coff ) = y2r;
            *( tptr + 1 ) = y2i;
            *( tptr += coff ) = y1r;
            *( tptr + 1 ) = y1i;
            *( tptr += coff ) = y3r;
            *( tptr + 1 ) = y3i;

            stcoff |= maskc;
            stcoff += 2;
            stcoff &= ~maskc;
            woff += winc;
            woff &= ~maskw;
        }

        coff >>= 2;
        maskc >>= 2;
        winc <<= 2;
    }

    if ( coff == 2 )
    {
        stcoff = 0;

        for ( j = 0; j < loopcnt; j++ )
        {
            tptr = PREFIX( fft_tbuf );
            a0r = *( tptr += stcoff );
            a0i = *( tptr + 1 );
            a1r = *( tptr += 2 );
            a1i = *( tptr + 1 );
            a2r = *( tptr += 2 );
            a2i = *( tptr + 1 );
            a3r = *( tptr += 2 );
            a3i = *( tptr + 1 );
            m2r = a0r - a2r;
            m2i = a0i - a2i;
            t1r = a0r + a2r;
            t1i = a0i + a2i;
            t2r = a1r + a3r;
            t2i = a1i + a3i;

            if ( f == 1 )
            {
                m3r = a1i - a3i;
                m3i = a3r - a1r;
            }
            else
            {
                m3r = a3i - a1i;
                m3i = a1r - a3r;
            }

            y0r = t1r + t2r;
            y0i = t1i + t2i;
            y1r = m2r + m3r;
            y1i = m2i + m3i;
            y2r = t1r - t2r;
            y2i = t1i - t2i;
            y3r = m2r - m3r;
            y3i = m2i - m3i;
            tptr = PREFIX( fft_tbuf );
            *( tptr += stcoff ) = y0r;
            *( tptr + 1 ) = y0i;
            *( tptr += 2 ) = y2r;
            *( tptr + 1 ) = y2i;
            *( tptr += 2 ) = y1r;
            *( tptr + 1 ) = y1i;
            *( tptr += 2 ) = y3r;
            *( tptr + 1 ) = y3i;

            stcoff += 8;
        }
    }
    else
    {
        stcoff = 0;
        loopcnt >>= 1;

        for ( j = 0; j < loopcnt; j++ )
        {
            tptr = PREFIX( fft_tbuf );
            a0r = *( tptr += stcoff );
            a0i = *( tptr + 1 );
            a1r = *( tptr += 2 );
            a1i = *( tptr + 1 );
            a2r = *( tptr += 2 );
            a2i = *( tptr + 1 );
            a3r = *( tptr += 2 );
            a3i = *( tptr + 1 );
            a4r = *( tptr += 2 );
            a4i = *( tptr + 1 );
            a5r = *( tptr += 2 );
            a5i = *( tptr + 1 );
            a6r = *( tptr += 2 );
            a6i = *( tptr + 1 );
            a7r = *( tptr += 2 );
            a7i = *( tptr + 1 );
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

            if ( f == 1 )
            {
                m5r = t3i - t5i;
                m5i = t5r - t3r;
            }
            else
            {
                m5r = t5i - t3i;
                m5i = t3r - t5r;
            }

            y0r = t7r + t8r;
            y0i = t7i + t8i;
            y4r = t7r - t8r;
            y4i = t7i - t8i;
            y2r = m2r + m5r;
            y2i = m2i + m5i;
            y6r = m2r - m5r;
            y6i = m2i - m5i;

            if ( f == 1 )
            {
                t4r = a5r - a1r;
                t4i = a1i - a5i;
                t6r = a7r - a3r;
                t6i = a3i - a7i;
            }
            else
            {
                t4r = a1r - a5r;
                t4i = a5i - a1i;
                t6r = a3r - a7r;
                t6i = a7i - a3i;
            }

            d1r = a0r - a4r;
            d1i = a0i - a4i;

            if ( f == 1 )
            {
                em4r = t6r - t4r;
                em4i = t4i - t6i;
                d2r = a6r - a2r;
                d2i = a2i - a6i;
            }
            else
            {
                em4r = t4r - t6r;
                em4i = t6i - t4i;
                d2r = a2r - a6r;
                d2i = a6i - a2i;
            }

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
            y5r = s2r + s4r;
            y5i = s2i + s4i;
            y3r = s2r - s4r;
            y3i = s2i - s4i;
            y7r = s1r - s3r;
            y7i = s1i - s3i;
            tptr = PREFIX( fft_tbuf );
            *( tptr += stcoff ) = y0r;
            *( tptr + 1 ) = y0i;
            *( tptr += 2 ) = y4r;
            *( tptr + 1 ) = y4i;
            *( tptr += 2 ) = y2r;
            *( tptr + 1 ) = y2i;
            *( tptr += 2 ) = y6r;
            *( tptr + 1 ) = y6i;
            *( tptr += 2 ) = y1r;
            *( tptr + 1 ) = y1i;
            *( tptr += 2 ) = y5r;
            *( tptr + 1 ) = y5i;
            *( tptr += 2 ) = y3r;
            *( tptr + 1 ) = y3i;
            *( tptr += 2 ) = y7r;
            *( tptr + 1 ) = y7i;

            stcoff += 16;
        }
    }

    if ( brflag )
    {
        tptr = PREFIX( fft_tbuf );
        PREFIX( _csal_bitr )( tptr, log2n );
    }

    j = 0;
    k = 0;

    for ( i = 0; i < n; i++ )
    {
        c[k] = PREFIX( fft_tbuf[j] );
        c[k+1] = PREFIX( fft_tbuf[j+1] );
        j += 2;
        k += stride;
    }

    SAL_SET_PATH_CSAL();
}

void PREFIX( _csal_bitr )( c, log2n )
SAL_f32 *c;
SAL_i32    log2n;
{
    SAL_i32   i, j, k, n, nm1;
    SAL_f32 tempr, tempi;

    n = 1 << log2n;
    nm1 = ( n - 1 ) << 1;
    j = 0;

    for ( i = 2; i < nm1; i += 2 )
    {
        k = n;

        while ( k <= j )
        {
            j -= k;
            k >>= 1;
        }

        j += k;

        if ( i < j )
        {
            tempr = c[i];
            tempi = c[i+1];
            c[i] = c[j];
            c[i+1] = c[j+1];
            c[j] = tempr;
            c[j+1] = tempi;
        }
    }

    SAL_SET_PATH_CSAL();
}

void PREFIX( _csal_freal )( n, top, bot, w, winc )
SAL_i32    n;
SAL_f32 *top;
SAL_f32 *bot;
SAL_f32 *w;
SAL_i32    winc;

{
    SAL_i32   i, j, k, woff;
    SAL_f32 ar, ai, br, bi, gr, gi, hr, hi;
    SAL_f32 wr, wi, wrgr, wigi, wrgi, wigr;
    SAL_f32 tr, ti, xr, xi, yr, yi;

    j = 0;
    k = 0;
    woff = 0;

    for ( i = 0; i < n; i++ )
    {
        ar = top[j];
        ai = top[j+1];
        br = bot[k];
        bi = bot[k+1];
        gr = ai + bi;
        gi = br - ar;
        hr = ar + br;
        hi = ai - bi;
        wr = w[woff];
        wi = w[woff+1];
        wrgr = wr * gr;
        wigi = wi * gi;
        wrgi = wr * gi;
        wigr = wi * gr;
        tr = wrgr + wigi;
        ti = wrgi - wigr;
        xr = hr + tr;
        xi = hi + ti;
        yr = hr - tr;
        yi = ti - hi;
        bot[k] = yr;
        bot[k+1] = yi;
        top[j] = xr;
        top[j+1] = xi;
        woff += winc;
        j += 2;
        k -= 2;
    }

    SAL_SET_PATH_CSAL();
}

void PREFIX( _csal_ireal )( n, top, bot, w, winc )
SAL_i32    n;
SAL_f32 *top;
SAL_f32 *bot;
SAL_f32 *w;
SAL_i32    winc;

{
    SAL_i32   i, j, k, woff;
    SAL_f32 ar, ai, br, bi, gr, gi, hr, hi;
    SAL_f32 wr, wi, wrgr, wigi, wrgi, wigr;
    SAL_f32 tr, ti, xr, xi, yr, yi;

    j = 0;
    k = 0;
    woff = 0;

    for ( i = 0; i < n; i++ )
    {
        ar = top[j];
        ai = top[j+1];
        br = bot[k];
        bi = bot[k+1];
        gr = ai + bi;
        gi = ar - br;
        hr = ar + br;
        hi = ai - bi;
        wr = w[woff];
        wi = w[woff+1];
        wrgr = wr * gr;
        wigi = wi * gi;
        wrgi = wr * gi;
        wigr = wi * gr;
        tr = wrgr + wigi;
        ti = wrgi - wigr;
        xr = hr - tr;
        xi = hi + ti;
        yr = hr + tr;
        yi = ti - hi;
        bot[k] = yr;
        bot[k+1] = yi;
        top[j] = xr;
        top[j+1] = xi;
        woff += winc;
        j += 2;
        k -= 2;
    }

    SAL_SET_PATH_CSAL();
}
