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
        fft5_zrp_aux_csal.c

----------------------------------------------------------------------------
*/

#include "fft_internal.h"

void  PREFIX( _csal_fft5_zrp )( SAL_zf32 *A,
                                SAL_i32 I,
                                SAL_zf32 *C,
                                SAL_i32 K,
                                SAL_ui32 LOG2N,
                                SAL_i32  FLAG,
                                FFT_setup *setupp )
{
    SAL__fft_setup_csal **SETUPP = &( ( *setupp )->csal_fft_setup );

    SAL_i32  idx, offset, woff;
    SAL_ui32  i, l, loopcnt;

    SAL_f32 *Wrp, *Wip;
    SAL_f32 *Arbot, *Artop, *Crbot, *Crtop;
    SAL_f32 *Aibot, *Aitop, *Cibot, *Citop;
    SAL_f32 ar, ai, br, bi, gr, gi, hr, hi;
    SAL_f32 wr, wi, wrgr, wigi, wrgi, wigr;
    SAL_f32 tr, ti, xr, xi, yr, yi;

    Artop = A->realp;
    Aitop = A->imagp;
    Crtop = C->realp;
    Citop = C->imagp;

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

    offset = ( 5 << ( LOG2N - 1 ) ) - 1;
    Arbot = A->realp + I * offset;
    Aibot = A->imagp + I * offset;
    Crbot = C->realp + K * offset;
    Cibot = C->imagp + K * offset;

    Wrp = ( *SETUPP )->radix5_twids.realp;
    Wip = ( *SETUPP )->radix5_twids.imagp;
    woff = 1 << ( ( *SETUPP )->log2m - LOG2N );
    idx = 0;

    loopcnt = ( 5 << LOG2N ) >> 3;

    for ( i = 0; i < 2; i++ )
    {
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

            idx += woff;
            wr = Wrp[idx];
            wi = Wip[idx];

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

        Wrp = ( *SETUPP )->radix5_twids.imagp;
        Wip = ( *SETUPP )->radix5_twids.realp;
        woff = -woff;

        if ( LOG2N > 2 )
            --loopcnt;
        else
            idx -= woff;
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
