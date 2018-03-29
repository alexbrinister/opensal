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
        fixpixadx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( fixpixadx_csal )(
    SAL_f64 *A,
    SAL_i32 I,
    SAL_ui8 *C,
    SAL_i32 N,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_f64  ftemp;
    SAL_i32    i;
    SAL_ui8     itemp8;

    N >>= 1;
    A -= I;
    C -= 1;

    for ( i = 0; i < N; i++ )
    {
        ftemp = *( A += I );
        itemp8 = ( SAL_ui8 ) ftemp;
        *( C + 1 ) = itemp8;
        ftemp = *( A += I );
        itemp8 = ( SAL_ui8 ) ftemp;
        *( C += 2 ) = itemp8;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
