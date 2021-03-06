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
        conv2dx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( conv2dx_csal )(
    SAL_f32 *A,
    SAL_i32 TCA,
    SAL_f32 *B,
    SAL_f32 *C,
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
    SAL_i32   i, j, k, l;
    SAL_f32 av, bv, cv;

    ( void ) FLAG;
    ( void ) X;

    if ( TCA == 0 ) TCA = ( ( NCC - 1 ) * DSX ) + NCB;

    if ( TCC == 0 ) TCC = NCC;

    for ( i = 0; i < NRC; i++ )
    {
        for ( j = 0; j < NCC; j++ )
        {
            cv = 0.0;

            for ( k = 0; k < NRB; k++ )
            {
                for ( l = 0; l < NCB; l++ )
                {
                    av = A[ ( ( ( i * DSY ) + k ) * TCA ) + ( ( j * DSX ) + l ) ];
                    bv = B[ ( k * NCB ) + l ];
                    cv += ( av * bv );
                }
            }

            C[ ( i * TCC ) + j ] = cv;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
