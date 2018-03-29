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
        convm_colsx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"
#include <stdio.h>

void PREFIX( convm_colsx_csal )(
    SAL_f32 **A,
    SAL_f32 *B,
    SAL_f32 **C,
    SAL_i32 Nc,
    SAL_i32 Nr,
    SAL_i32 Nb,
    SAL_i32 F,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i, j, k;
    SAL_f32  sum, av, tv, bv;
    SAL_f32  **ap, **aap, *app, *bp, **cp, *cpp;

    if ( ( Nc == 0 ) || ( Nr == 0 ) || ( Nb == 0 ) )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
        goto ERROR_LABEL;
    }

    for ( i = 0; i < Nc; i++ )
    {
        cp = C;
        ap = A;

        for ( j = 0; j < Nr; j++ )
        {
            bp = B;
            aap = ap;

            cpp = *cp;

            if ( F == 1 )
                sum = *( cpp + i );
            else
                sum = 0.0;

            for ( k = 0; k < Nb; k++ )
            {
                app = *aap;
                av = *( app + i );
                bv = *bp;
                tv = av * bv;
                sum = sum + tv;
                aap++;
                bp++;
            }

            *( cpp + i ) = sum;
            ap++;
            cp++;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;

ERROR_LABEL:
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
