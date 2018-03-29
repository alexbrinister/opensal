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
        cmtrans2dx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( cmtrans2dx_csal )(
    SAL_cf64 *c_A,
    SAL_cf64 *c_C,
    SAL_i32 NC,
    SAL_i32 NR,
    SAL_i32 TCA,
    SAL_i32 TCC,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32     i, j, tcadif2, tcc2;
    SAL_f64  *cptr;
    SAL_f64  *A, *C;

    A = ( SAL_f64 * ) c_A;
    C = ( SAL_f64 * ) c_C;

    tcadif2 = ( TCA - NC ) << 1;
    tcc2 = TCC << 1;

    for ( i = 0; i < NR; i++ )
    {
        cptr = C;

        for ( j = 0; j < NC; j++ )
        {
            *cptr = *A;
            *( cptr + 1 ) = *( A + 1 );

            A += 2;
            cptr += tcc2;
        }

        A += tcadif2;
        C += 2;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
