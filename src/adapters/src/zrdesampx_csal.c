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
        zrdesampx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zrdesampx_csal )(
    SAL_zf32 *A,
    SAL_i32 I,
    SAL_f32 *B,
    SAL_zf32 *C,
    SAL_i32 N,
    SAL_i32 P,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_i32   i, j;
    SAL_f32 rsum, isum, *arptr, *aiptr, *bptr;
    SAL_f32 *Arp, *Aip, *Crp, *Cip;

    ( void ) X;

    Arp = A->realp;
    Aip = A->imagp;
    Crp = C->realp;
    Cip = C->imagp;

    for ( i = 0; i < N; i++ )
    {
        rsum = 0;
        isum = 0;
        arptr = Arp;
        aiptr = Aip;
        bptr = B;

        for ( j = 0; j < P; j++ )
        {
            rsum += ( *arptr ) * ( *bptr );
            isum += ( *aiptr ) * ( *bptr );
            arptr++;
            aiptr++;
            bptr++;
        }

        *Crp = rsum;
        *Cip = isum;
        Crp++;
        Cip++;
        Arp += I;
        Aip += I;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
