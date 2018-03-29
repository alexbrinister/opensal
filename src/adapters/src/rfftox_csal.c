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
        rfftox_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_fft_internal.h"

void PREFIX( rfftox_csal )(
    SAL_f32 *c,
    SAL_f32 *t,
    SAL_f32 *d,
    SAL_i32 n,
    SAL_i32 f,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32   i, log2m, log2mvn, log2n, winc;
    SAL_f32 *w;
    SAL_f32 ar, ai, gr, gi, xr, xi;

    for ( i = 0; i < n; i++ )
        t[i] = c[i];

    log2n = 0;
    i = n >> 1;

    while ( i )
    {
        ++log2n;
        i >>= 1;
    }

    w = ( SAL_f32 * ) PREFIX( fftwts_tab.c );
    log2m = PREFIX( fftwts_tab.LOG2_m );
    log2mvn = log2m - log2n;
    winc = 2 << log2mvn;

    if ( f >= 0 )
    {
        PREFIX( cfftb )( ( SAL_cf32 * ) t, ( SAL_cf32 * ) d, ( n >> 1 ), f );
        ar = d[0];
        ai = d[1];
        gr = ar + ar;
        gi = ai + ai;
        xr = gr + gi;
        xi = gr - gi;
        d[0] = xr;
        d[1] = xi;
        PREFIX( _csal_freal )( ( n >> 2 ), &d[2], &d[n-2], &w[winc], winc );
    }
    else
    {
        ar = t[0];
        ai = t[1];
        xr = ar + ai;
        xi = ar - ai;
        t[0] = xr;
        t[1] = xi;
        PREFIX( _csal_ireal )( ( n >> 2 ), &t[2], &t[n-2], &w[winc], winc );
        PREFIX( cfftb )( ( SAL_cf32 * ) t, ( SAL_cf32 * ) d, ( n >> 1 ), f );
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
