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
        zrmixerx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zrmixerx_csal )(
    SAL_f32 *A,
    SAL_i32 sA,
    SAL_f64 *F,
    SAL_f64 *P,
    SAL_zf32 *C,
    SAL_i32 sC,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 eflag,
    SAL__return_info *r_info
)
{
    SAL_i32    i;
    SAL_f32  *Ap, *Crp, *Cip;
    SAL_f64 osgn;

    ( void ) eflag;

    Ap = A;
    Crp = C->realp;
    Cip = C->imagp;

    if ( flag & SAL_CONJUGATE_OSCILLATOR )
        osgn = -1;
    else
        osgn = 1;

    for ( i = 0; i < N; i++ )
    {
        *Crp = cos( *P ) * ( *Ap );
        *Cip = osgn * sin( *P ) * ( *Ap );
        *P += *F;
        Crp += sC;
        Cip += sC;
        Ap += sA;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
