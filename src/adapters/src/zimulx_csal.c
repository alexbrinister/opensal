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
        zimulx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zimulx_csal )(
    SAL_zf32 *A,
    SAL_zf32 *B,
    SAL_zf32 *C,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_i32 F,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_f32  ar, ai, br, bi;
    SAL_i32    i, j;
    SAL_f32  *Arp, *Aip, *Brp, *Bip, *Crp, *Cip;

    ( void )X;

    Arp = A->realp;
    Aip = A->imagp;
    Brp = B->realp;
    Bip = B->imagp;
    Crp = C->realp;
    Cip = C->imagp;

    if ( F >= 0 )
    {
        for ( i = 0; i < 2; i++ )
        {
            ar = *Arp;
            ai = *Aip;
            br = *Brp;
            bi = *Bip;
            *Crp = ar * br;
            *Cip = ai * bi;

            Arp++;
            Aip++;
            Brp++;
            Bip++;
            Crp++;
            Cip++;

            for ( j = 1; j < NC; j++ )
            {
                ar = *Arp;
                ai = *Aip;
                br = *Brp;
                bi = *Bip;

                *Crp = ( ar * br ) - ( ai * bi );
                *Cip = ( ai * br ) + ( ar * bi );

                Arp++;
                Aip++;
                Brp++;
                Bip++;
                Crp++;
                Cip++;
            }
        }

        for ( i = 2; i < NR; i++ )
        {
            if ( !( i & 1 ) )
            {
                ar = *Arp;
                ai = *( Arp + NC );
                br = *Brp;
                bi = *( Brp + NC );

                *Crp = ( ar * br ) - ( ai * bi );
                *( Crp + NC ) = ( ai * br ) + ( ar * bi );

                ar = *Aip;
                ai = *( Aip + NC );
                br = *Bip;
                bi = *( Bip + NC );

                *Cip = ( ar * br ) - ( ai * bi );
                *( Cip + NC ) = ( ai * br ) + ( ar * bi );

                Arp++;
                Aip++;
                Brp++;
                Bip++;
                Crp++;
                Cip++;
            }
            else
            {
                Arp++;
                Aip++;
                Brp++;
                Bip++;
                Crp++;
                Cip++;
            }

            for ( j = 1; j < NC; j++ )
            {
                ar = *Arp;
                ai = *Aip;
                br = *Brp;
                bi = *Bip;

                *Crp = ( ar * br ) - ( ai * bi );
                *Cip = ( ai * br ) + ( ar * bi );

                Arp++;
                Aip++;
                Brp++;
                Bip++;
                Crp++;
                Cip++;
            }
        }
    }

    else
    {
        for ( i = 0; i < 2; i++ )
        {
            ar = *Arp;
            ai = *Aip;
            br = *Brp;
            bi = *Bip;

            *Crp = ar * br;
            *Cip = ai * bi;

            Arp++;
            Aip++;
            Brp++;
            Bip++;
            Crp++;
            Cip++;

            for ( j = 1; j < NC; j++ )
            {
                ar = *Arp;
                ai = *Aip;
                br = *Brp;
                bi = *Bip;

                *Crp = ( ar * br ) + ( ai * bi );
                *Cip = ( ai * br ) - ( ar * bi );

                Arp++;
                Aip++;
                Brp++;
                Bip++;
                Crp++;
                Cip++;
            }
        }

        for ( i = 2; i < NR; i++ )
        {
            if ( !( i & 1 ) )
            {
                ar = *Arp;
                ai = *( Arp + NC );
                br = *Brp;
                bi = *( Brp + NC );

                *Crp = ( ar * br ) + ( ai * bi );
                *( Crp + NC ) = ( ai * br ) - ( ar * bi );

                ar = *Aip;
                ai = *( Aip + NC );
                br = *Bip;
                bi = *( Bip + NC );

                *Cip = ( ar * br ) + ( ai * bi );
                *( Cip + NC ) = ( ai * br ) - ( ar * bi );

                Arp++;
                Aip++;
                Brp++;
                Bip++;
                Crp++;
                Cip++;
            }

            else
            {
                Arp ++;
                Aip ++;
                Brp ++;
                Bip ++;
                Crp ++;
                Cip ++;
            }

            for ( j = 1; j < NC; j++ )
            {
                ar = *Arp;
                ai = *Aip;
                br = *Brp;
                bi = *Bip;

                *Crp = ( ar * br ) + ( ai * bi );
                *Cip = ( ai * br ) - ( ar * bi );

                Arp++;
                Aip++;
                Brp++;
                Bip++;
                Crp++;
                Cip++;
            }
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
