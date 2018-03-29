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
        zconv2dx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zconv2dx_csal )(
    SAL_zf32 *A,
    SAL_i32 TCA,
    SAL_zf32 *B,
    SAL_zf32 *C,
    SAL_i32 TCC,
    SAL_i32 DSX,
    SAL_i32 DSY,
    SAL_i32 NCB,
    SAL_i32 NRB,
    SAL_i32 NCC,
    SAL_i32 NRC,
    SAL_i32 FLAG,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_f32 *Arp, *Aip, *Brp, *Bip, *Crp, *Cip;
    SAL_i32   i, j, k, l;
    SAL_f32 ar, ai, br, bi, cr, ci;
    SAL_f32 A_conj_factor;

    ( void )X;

    if ( TCA == 0 ) TCA = ( ( NCC - 1 ) * DSX ) + NCB;

    if ( TCC == 0 ) TCC = NCC;

    Arp = A->realp;
    Aip = A->imagp;
    Brp = B->realp;
    Bip = B->imagp;
    Crp = C->realp;
    Cip = C->imagp;

    if ( FLAG & SAL_CONJUGATE )
        A_conj_factor = ( SAL_f32 ) - 1.0;
    else
        A_conj_factor = ( SAL_f32 ) 1.0;

    for ( i = 0; i < NRC; i++ )
    {
        for ( j = 0; j < NCC; j++ )
        {
            cr = ci = 0.0;

            for ( k = 0; k < NRB; k++ )
            {
                for ( l = 0; l < NCB; l++ )
                {
                    ar = Arp[ ( ( i * DSY ) + k ) * TCA + ( ( j * DSX ) + l ) ];
                    ai = Aip[ ( ( i * DSY ) + k ) * TCA + ( ( j * DSX ) + l ) ];
                    ai *= A_conj_factor;
                    br = Brp[ ( k * NCB ) + l ];
                    bi = Bip[ ( k * NCB ) + l ];
                    cr += ( ( ar * br ) - ( ai * bi ) );
                    ci += ( ( ar * bi ) + ( ai * br ) );
                }
            }

            Crp[ ( i * TCC ) + j ] = cr;
            Cip[ ( i * TCC ) + j ] = ci;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
