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
        fft3_zrpd_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

void  PREFIX( _csal_fft3_zrpd )( SAL_zf64 *A,
                                 SAL_i32 I,
                                 SAL_zf64 *C,
                                 SAL_i32 K,
                                 SAL_ui32 LOG2N,
                                 SAL_ui32 LOG2M,
                                 SAL_f64 *WR,
                                 SAL_f64 *WI,
                                 SAL_i32  FLAG )
{
    SAL_zf64 Cp, Ap;

    SAL_ui32  l, loopcnt, idx, woff;

    SAL_f64 *Arbot, *Artop, *Crbot, *Crtop;
    SAL_f64 *Aibot, *Aitop, *Cibot, *Citop;
    SAL_f64 ar, ai, br, bi, gr, gi, hr, hi;
    SAL_f64 wr, wi, wrgr, wigi, wrgi, wigr;
    SAL_f64 tr, ti, xr, xi, yr, yi;

    Ap = *A;
    Cp = *C;

    Artop = Ap.realp;
    Aitop = Ap.imagp;
    Crtop = Cp.realp;
    Citop = Cp.imagp;

    ar = *Artop;
    Artop += I;
    ai = *Aitop;
    Aitop += I;

    if ( FLAG == FFT_FORWARD )
    {
        ar = ar + ar;
        ai = ai + ai;
    }

    xr = ar + ai;
    xi = ar - ai;

    *Crtop = xr;
    Crtop += K;
    *Citop = xi;
    Citop += K;

    Arbot = A->realp + ( ( I * ( ( 3 << LOG2N ) - 1 ) - I ) >> 1 );
    Aibot = A->imagp + ( ( I * ( ( 3 << LOG2N ) - 1 ) - I ) >> 1 );
    Crbot = C->realp + ( ( K * ( ( 3 << LOG2N ) - 1 ) - K ) >> 1 );
    Cibot = C->imagp + ( ( K * ( ( 3 << LOG2N ) - 1 ) - K ) >> 1 );

    woff = 2 << ( LOG2M - LOG2N );

    loopcnt = ( ( 3 << LOG2N ) >> 2 ) - 1;

    idx = woff;

    for ( l = 0; l < loopcnt; l++ )
    {
        ar = *Artop;
        Artop += I;
        ai = *Aitop;
        Aitop += I;
        bi = *Aibot;
        Aibot -= I;
        br = *Arbot;
        Arbot -= I;

        gr = ai + bi;
        hi = ai - bi;
        hr = ar + br;

        if ( FLAG == FFT_FORWARD )
            gi = br - ar;
        else
            gi = ar - br;

        wr = WR[idx];
        wi = WI[idx];
        idx += woff;

        wrgr = wr * gr;
        wigi = wi * gi;
        wrgi = wr * gi;
        wigr = wi * gr;

        tr = wrgr + wigi;
        ti = wrgi - wigr;

        if ( FLAG == FFT_FORWARD )
        {
            xr = hr + tr;
            yr = hr - tr;
        }
        else
        {
            yr = hr + tr;
            xr = hr - tr;
        }

        xi = ti + hi;
        yi = ti - hi;

        *Crtop = xr;
        Crtop += K;
        *Citop = xi;
        Citop += K;
        *Cibot = yi;
        Cibot -= K;
        *Crbot = yr;
        Crbot -= K;
    }

    ar = *Artop;
    ai = *Aitop;

    xr = ar + ar;
    xi = ai + ai;
    xi = -xi;

    *Crtop = xr;
    *Citop = xi;

    SAL_SET_PATH_CSAL();
}
