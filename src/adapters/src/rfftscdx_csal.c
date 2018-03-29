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
        rfftscdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_fft_internal.h"

void PREFIX( rfftscdx_csal )(
    SAL_f64 *C,
    SAL_i32 N,
    SAL_i32 F,
    SAL_i32 FS,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    m;
    SAL_f64  fm, one, onevm, ftemp;

    if ( N == 0 )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
        goto ERROR_LABEL;
    }

    if ( FS > 0 )
        m = N << 1;
    else
        m = N << 2;

    if ( FS )
    {
        one = 1.0;
        fm = ( SAL_f64 ) m;
        onevm = one / fm;
        PREFIX( vsmuld )( C, 1, &onevm, C, 1, N );
    }

    if ( ( F == 2 ) || ( F == -2 ) )
    {
        C[1] = 0.0;
    }
    else if ( F == 3 )
    {
        C[N] = C[1];
        C[1] = 0.0;
        C[N+1] = 0.0;
    }
    else if ( F == -3 )
    {
        ftemp = C[N];

        if ( FS )
            ftemp = onevm * ftemp;

        C[1] = ftemp;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;

ERROR_LABEL:
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
