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
        vconvert_endian4x_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( vconvert_endian4x_csal )(
    SAL_ui8* p_src,
    SAL_i32 stride_src,
    SAL_ui8* p_dst,
    SAL_i32 stride_dst,
    SAL_i32 n_elems,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    ( void ) xflag;

    SAL_i32 n, b;
    SAL_i32 n_bytes_elem = 4;

    for ( n = 0; n < n_elems; n++ )
    {
        for ( b = 0; b < n_bytes_elem; b++ )
        {
            p_dst [ b ] = p_src [ n_bytes_elem - b - 1 ];
        }

        p_src += ( n_bytes_elem * stride_src );
        p_dst += ( n_bytes_elem * stride_dst );
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
