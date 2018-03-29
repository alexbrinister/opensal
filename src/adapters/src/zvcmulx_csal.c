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
        zvcmulx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zvcmulx_csal )(
    SAL_zf32 *A,
    SAL_i32 I,
    SAL_zf32 *B,
    SAL_i32 J,
    SAL_zf32 *C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_i32    i;
    SAL_f32  ar, ai, br, bi;
    SAL_f32  *Arp, *Aip, *Brp, *Bip, *Crp, *Cip;

    ( void )X;

    Arp = A->realp;
    Aip = A->imagp;
    Brp = B->realp;
    Bip = B->imagp;
    Crp = C->realp;
    Cip = C->imagp;

    for ( i = 0; i < N; i++ )
    {
        ar = *Arp;
        ai = *Aip;
        br = *Brp;
        bi = *Bip;
        *Crp = ( ar * br ) + ( ai * bi );
        *Cip = ( ar * bi ) - ( ai * br );
        Arp += I;
        Aip += I;
        Brp += J;
        Bip += J;
        Crp += K;
        Cip += K;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
