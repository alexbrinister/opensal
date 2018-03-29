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
        zmmuldx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zmmuldx_csal )(
    SAL_zf64 *A,
    SAL_i32 I,
    SAL_zf64 *B,
    SAL_i32 J,
    SAL_zf64 *C,
    SAL_i32 K,
    SAL_i32 MC,
    SAL_i32 NC,
    SAL_i32 NA,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_i32    i, j, k;
    SAL_i32    ncj;
    SAL_f64 sumi, sumr, ai, ar, bi, br;
    SAL_f64 *arptr, *aiptr, *brptr, *biptr;
    SAL_f64 *Arp, *Aip, *Brp, *Bip, *Crp, *Cip;

    Arp = A->realp;
    Aip = A->imagp;
    Brp = B->realp;
    Bip = B->imagp;
    Crp = C->realp;
    Cip = C->imagp;

    ( void ) X;

    if ( ( MC == 0 ) || ( NC == 0 ) || ( NA == 0 ) )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        return;
    }

    ncj = ( ( SAL_i32 ) NC ) * J;

    for ( i = 0; i < MC; i++ )
    {
        for ( j = 0; j < NC; j++ )
        {
            arptr = Arp;
            aiptr = Aip;
            brptr = Brp;
            biptr = Bip;
            sumr = 0.0;
            sumi = 0.0;

            for ( k = 0; k < NA; k++ )
            {
                ar = *arptr;
                ai = *aiptr;
                br = *brptr;
                bi = *biptr;
                sumr += ( ar * br );
                sumr -= ( ai * bi );
                sumi += ( ar * bi );
                sumi += ( ai * br );
                arptr += I;
                aiptr += I;
                brptr += ncj;
                biptr += ncj;
            }

            *Crp = sumr;
            *Cip = sumi;
            Brp += J;
            Bip += J;
            Crp += K;
            Cip += K;
        }

        Arp = arptr;
        Aip = aiptr;
        Brp -= ncj;
        Bip -= ncj;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
