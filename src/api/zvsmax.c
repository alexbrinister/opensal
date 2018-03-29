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
        zvsmax.c

    Description:
        Complex Vector Multiply to Complex Scalar and Add

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "zvsmax_selector.h"

SAL_STATUS PREFIX( zvsma )(
    SAL_zf32 *A,
    SAL_i32 I,
    SAL_zf32 *S,
    SAL_zf32 *C,
    SAL_i32 K,
    SAL_zf32 *D,
    SAL_i32 L,
    SAL_i32 N
)
{
    SAL_CALL_RETURN( PREFIX( zvsmax )( A, I, S, C, K, D, L, N, SAL_NNN ) );
}

SAL_STATUS PREFIX( zvsmax )(
    SAL_zf32 *A,
    SAL_i32 I,
    SAL_zf32 *S,
    SAL_zf32 *C,
    SAL_i32 K,
    SAL_zf32 *D,
    SAL_i32 L,
    SAL_i32 N,
    SAL_i32 X
)
{
    zvsmax_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( zvsmax_selector )( A, I, S, C, K, D, L, N, X, &func );

    ( * func )( A, I, S, C, K, D, L, N, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

