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
        unwrap_phasex_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"
#include <stdlib.h>

void PREFIX( unwrap_phasex_csal )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_unwrap_phase_state *P,
    SAL_i32 F,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_i32 i;

    SAL_f64 delta, da, dc;

    SAL_f64 lastinputvalue,
    lastoutputvalue;

    ( void )X;

    if ( ( F & SAL_UNWRAP_PHASE_CONTINUE ) && ( P != NULL ) )
    {
        lastinputvalue = P->reserved [ 0 ];
        lastoutputvalue = P->reserved [ 1 ];
    }
    else
    {
        lastoutputvalue = lastinputvalue = A [ 0 ];
    }

    A -= I;
    C -= K;

    for ( i = 0; i < N; i++ )
    {
        da = ( SAL_f64 ) * ( A += I );
        delta = da - lastinputvalue;
        lastinputvalue = da;

        if ( delta >= ONE_PI )
        {
            delta -= TWO_PI;
        }
        else if ( delta < -ONE_PI )
        {
            delta += TWO_PI;
        }

        dc = lastoutputvalue + delta;
        *( C += K ) = ( SAL_f32 ) dc;
        lastoutputvalue = dc;
    }

    if ( P != NULL )
    {
        P->reserved [ 0 ] = lastinputvalue;
        P->reserved [ 1 ] = lastoutputvalue;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
