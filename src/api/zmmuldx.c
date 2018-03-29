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
        zmmuldx.c

    Description:
        Matrix Multiply

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "zmmuldx_selector.h"

SAL_STATUS PREFIX( zmmuld )(
    SAL_zf64 *A,
    SAL_i32 I,
    SAL_zf64 *B,
    SAL_i32 J,
    SAL_zf64 *C,
    SAL_i32 K,
    SAL_i32 MC,
    SAL_i32 NC,
    SAL_i32 NA
)
{
    SAL_CALL_RETURN( PREFIX( zmmuldx )( A, I, B, J, C, K, MC, NC, NA, SAL_NNN ) );
}

SAL_STATUS PREFIX( zmmuldx )(
    SAL_zf64 *A,
    SAL_i32 I,
    SAL_zf64 *B,
    SAL_i32 J,
    SAL_zf64 *C,
    SAL_i32 K,
    SAL_i32 MC,
    SAL_i32 NC,
    SAL_i32 NA,
    SAL_i32 X
)
{
    zmmuldx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( zmmuldx_selector )( A, I, B, J, C, K, MC, NC, NA, X, &func );

    ( * func )( A, I, B, J, C, K, MC, NC, NA, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

