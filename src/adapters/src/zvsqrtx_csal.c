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
        zvsqrtx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zvsqrtx_csal )(
    SAL_zf32 *A,
    SAL_i32 I,
    SAL_zf32 *C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_i32    i;
    SAL_f32  half, q, root, temp1, temp2, tempr, tempi;
    SAL_f32  *Arp, *Aip, *Crp, *Cip;

    ( void )X;

    Arp = A->realp;
    Aip = A->imagp;
    Crp = C->realp;
    Cip = C->imagp;

    half = 0.5;
    Arp -= I;
    Aip -= I;
    Crp -= K;
    Cip -= K;

    for ( i = 0; i < N; i++ )
    {
        tempr = *( Arp += I );
        tempi = *( Aip += I );

        if ( ( tempr == ( SAL_f32 )0.0 ) && ( tempi == ( SAL_f32 )0.0 ) )
        {
            *( Crp += K ) = ( SAL_f32 )0.0;
            *( Cip += K ) = ( SAL_f32 )0.0;
            continue;
        }

        temp1 = tempr * tempr;
        temp2 = tempi * tempi;
        temp1 = temp1 + temp2;
        temp2 = ( SAL_f32 )sqrt( temp1 );

        if ( tempr >= 0.0 )
            temp2 += tempr;
        else
            temp2 -= tempr;

        temp2 *= half;
        root = ( SAL_f32 )sqrt( temp2 );
        temp1 = root + root;
        q = tempi / temp1;

        if ( tempr >= 0.0 )
        {
            *( Crp += K ) = root;
            *( Cip += K ) = q;
        }
        else if ( tempi >= 0.0 )
        {
            *( Crp += K ) = q;
            *( Cip += K ) = root;
        }
        else
        {
            *( Crp += K ) = -q;
            *( Cip += K ) = -root;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
