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
        zmtrans2dx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zmtrans2dx_csal )(
    SAL_zf64 *A,
    SAL_zf64 *C,
    SAL_i32 NC,
    SAL_i32 NR,
    SAL_i32 TCA,
    SAL_i32 TCC,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_i32    i, j, tca, tcadif, tcc;
    SAL_f64 *Arx, *Aix, *Ary, *Aiy, *crptr, *ciptr;
    SAL_f64 *Arp, *Aip, *Crp, *Cip;

    ( void )X;

    Arp = A->realp;
    Aip = A->imagp;
    Crp = C->realp;
    Cip = C->imagp;

    if ( A == C )
    {
        tca = TCA;

        for ( i = 1; i < NR; i++ )
        {
            Ary = Arx = Arp;
            Aiy = Aix = Aip;

            for ( j = i; j < NR; j++ )
            {
                *Ary = *( Arx += 1 );
                *Aiy = *( Aix += 1 );
                *Arx = *( Ary += tca );
                *Aix = *( Aiy += tca );
            }

            Arp += ( tca + 1 );
            Aip += ( tca + 1 );
        }
    }

    else
    {
        tcadif = ( TCA - NC );
        tcc = TCC;

        for ( i = 0; i < NR; i++ )
        {
            crptr = Crp;
            ciptr = Cip;

            for ( j = 0; j < NC; j++ )
            {
                *crptr = *Arp;
                *ciptr = *Aip;
                Arp += 1;
                Aip += 1;
                crptr += tcc;
                ciptr += tcc;
            }

            Arp += tcadif;
            Aip += tcadif;
            Crp += 1;
            Cip += 1;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
