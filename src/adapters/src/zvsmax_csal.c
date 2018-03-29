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
        zvsmax_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zvsmax_csal )(
    SAL_zf32 *A,
    SAL_i32 I,
    SAL_zf32 *S,
    SAL_zf32 *C,
    SAL_i32 K,
    SAL_zf32 *D,
    SAL_i32 L,
    SAL_i32 N,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_i32    i;
    SAL_f32  ar, ai, cr, ci, sr, si;
    SAL_f32  *Arp, *Aip, *Srp, *Sip,  *Crp, *Cip, *Drp, *Dip;

    ( void )X;

    Arp = A->realp;
    Aip = A->imagp;
    Srp = S->realp;
    Sip = S->imagp;
    Crp = C->realp;
    Cip = C->imagp;
    Drp = D->realp;
    Dip = D->imagp;

    sr = *Srp;
    si = *Sip;

    for ( i = 0; i < N; i++ )
    {
        ar = *Arp;
        ai = *Aip;
        cr = *Crp;
        ci = *Cip;
        *Drp = ( sr * ar ) - ( si * ai ) + cr;
        *Dip = ( sr * ai ) + ( si * ar ) + ci;
        Arp += I;
        Aip += I;
        Crp += K;
        Cip += K;
        Drp += L;
        Dip += L;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
