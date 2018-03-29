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
        fir2x_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( fir2x_csal )(
    SAL_f32 *A,
    SAL_f32 *W,
    SAL_f32 *Psum,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 Sflag,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32 i;
    SAL_f32 *aptr;
    SAL_f32 w0, w1;
    SAL_f32 sum, temp;

    w0 = *W++;
    w1 = *W++;
    aptr = A;

    for ( i = 0; i < N; i++ )
    {
        if ( Sflag != 1 )
            sum = 0;
        else
            sum = Psum[i];

        temp = *aptr;
        sum += ( w0 * temp );

        if ( Sflag == 2 )
            Psum[i] = temp;

        temp = *( aptr + 1 );
        sum += ( w1 * temp );

        C[i * K] = sum;
        aptr++;
    }

    if ( Sflag == 2 )
        Psum[i] = *aptr;

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
