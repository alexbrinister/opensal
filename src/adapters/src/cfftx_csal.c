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
        cfftx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_fft_internal.h"

void PREFIX( cfftx_csal )(
    SAL_cf32 *c_c,
    SAL_i32 n,
    SAL_i32 f,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32     i, j, log2m, log2n, log2n1, log2n2, log2mvn, n1, n2;
    SAL_i32     findex, mindex, windex;
    SAL_f32  *w, *c;

    c = ( SAL_f32 * ) c_c;

    if ( n <= 1024 )
    {
        PREFIX( _csal_cfftsm )( c, 2, n, f, 1 );
    }

    else
    {
        switch ( n )
        {
            case 2048:
                log2n1 = 5;
                log2n2 = 6;
                break;
            case 4096:
                log2n1 = 6;
                log2n2 = 6;
                break;
            case 8192:
                log2n1 = 6;
                log2n2 = 7;
                break;
            case 16384:
                log2n1 = 7;
                log2n2 = 7;
                break;
            case 32768:
                log2n1 = 8;
                log2n2 = 7;
                break;
            case 65536:
                log2n1 = 8;
                log2n2 = 8;
                break;
            case 131072:
                log2n1 = 10;
                log2n2 = 7;
                break;
            case 262144:
                log2n1 = 9;
                log2n2 = 9;
                break;
            case 524288:
                log2n1 = 10;
                log2n2 = 9;
                break;
            case 1048576:
                log2n1 = 10;
                log2n2 = 10;
                break;
            default:
            {
                SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
                goto ERROR_LABEL;
            }

        }

        log2n = log2n1 + log2n2;
        n1 = 1 << log2n1;
        n2 = 1 << log2n2;
        w = ( SAL_f32 * ) PREFIX( fftwts_tab.c );
        log2m = PREFIX( fftwts_tab.LOG2_m );
        log2mvn = log2m - log2n;

        findex = 0;

        for ( i = 0; i < n2; i++ )
        {
            PREFIX( _csal_cfftsm )( &c[findex], ( n2 << 1 ), n1, f, 0 );
            findex += 2;
        }

        mindex = 0;
        windex = 0;

        for ( i = 0; i < n1; i++ )
        {
            if ( i > 0 )
            {
                mindex += ( n2 << 1 );
                j = n1 << log2mvn;

                while ( j <= windex )
                {
                    windex -= j;
                    j >>= 1;
                }

                windex += j;
            }

            PREFIX( cvmul )( ( SAL_cf32 * ) w, windex,
                             ( SAL_cf32 * ) &c[mindex], 2,
                             ( SAL_cf32 * ) &c[mindex], 2, n2, -f );
            PREFIX( _csal_cfftsm )( &c[mindex], 2, n2, f, 0 );
        }

        PREFIX( _csal_bitr )( c, log2n );
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;

ERROR_LABEL:
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
