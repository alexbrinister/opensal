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
        vaintx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

#define THRESH 8388608.

void PREFIX( vaintx_csal )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

#define THRESH 8388608.

    union
    {
        SAL_ui32  ul;
        SAL_f32  f;
    }  ulf;

    SAL_i32    i;
    SAL_i32    itemp;
    SAL_f32  ftemp;

    A -= I;
    C -= K;

    for ( i = 0; i < N; i++ )
    {
        ftemp = *( A += I );

        if ( ftemp < THRESH && ftemp > -THRESH )
        {
            itemp = ( SAL_i32 ) ftemp;

            if ( ( itemp == 0 ) && ( ftemp < 0.0 ) )
            {
                ulf.ul = 0x80000000UL;
                ftemp = ulf.f;
            }
            else
                ftemp = ( SAL_f32 ) itemp;
        }

        *( C += K ) = ftemp;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
