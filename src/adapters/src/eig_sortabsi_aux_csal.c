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
        eig_sortabsi_aux_csal.c

----------------------------------------------------------------------------
*/

#include <math.h>
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( _csal_sortabsi )( SAL_f32 *Eval,
                               SAL_i32 *Ind_v, SAL_i32 N )
{
    SAL_f32 ffmax;
    SAL_i32 i, j, kmax, ktmp;
    SAL_i32 kmloc, icur;

    for ( i = 0; i < N; i++ )
    {
        Ind_v[ i ] = i;
    }

    for ( i = 0; i < N - 1; i++ )
    {
        kmax = Ind_v[ i ];
        ffmax = Eval[ kmax ];
        kmloc = i;

        for ( j = i + 1; j < N; j++ )
        {
            icur = Ind_v[ j ];

            if ( fabs( Eval[ icur ] ) > fabs( ffmax ) )
            {
                kmloc = j;
                ffmax = Eval[icur];
            }
        }

        ktmp = Ind_v[ kmloc ];
        Ind_v[ kmloc ] = kmax;
        Ind_v[ i ] = ktmp;
    }

    return;
}

