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
        cmixerx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( cmixerx_csal )(
    SAL_cf32 *A,
    SAL_i32 sA,
    SAL_f64 *F,
    SAL_f64 *P,
    SAL_cf32 *C,
    SAL_i32 sC,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 eflag,
    SAL__return_info *r_info
)
{
    SAL_i32 i;
    SAL_f64 ar, ai, dc, ds;
    SAL_f64 osgn, ssgn;

    ( void ) eflag;

    ssgn = ( flag & SAL_CONJUGATE_SIGNAL ) ? -1 : 1;
    osgn = ( flag & SAL_CONJUGATE_OSCILLATOR ) ? -1 : 1;

    for ( i = 0; i < N; i++ )
    {
        ar = A[ i * ( sA >> 1 )].real;
        ai = ssgn * A[ i * ( sA >> 1 )].imag;
        dc = cos( *P );
        ds = osgn * sin( *P );
        C[ i * ( sC >> 1 )].real = ( SAL_f32 )( dc * ar - ds * ai );
        C[ i * ( sC >> 1 )].imag = ( SAL_f32 )( dc * ai + ds * ar );
        *P += *F;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
