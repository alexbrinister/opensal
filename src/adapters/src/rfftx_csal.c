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
        rfftx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_fft_internal.h"

void PREFIX( rfftx_csal )(
    SAL_f32 *c,
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
        PREFIX( cfft )( ( SAL_cf32 * ) c, ( n >> 1 ), f );
        ar = c[0];
        ai = c[1];
        gr = ar + ar;
        gi = ai + ai;
        xr = gr + gi;
        xi = gr - gi;
        c[0] = xr;
        c[1] = xi;
        PREFIX( _csal_freal )( ( n >> 2 ), &c[2], &c[n-2], &w[winc], winc );
    }
    else
    {
        ar = c[0];
        ai = c[1];
        xr = ar + ai;
        xi = ar - ai;
        c[0] = xr;
        c[1] = xi;
        PREFIX( _csal_ireal )( ( n >> 2 ), &c[2], &c[n-2], &w[winc], winc );
        PREFIX( cfft )( ( SAL_cf32 * ) c, ( n >> 1 ), f );
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
