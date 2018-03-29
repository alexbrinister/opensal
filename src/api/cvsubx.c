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
        cvsubx.c

    Description:
        Complex Vector Subtract

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "cvsubx_selector.h"

SAL_STATUS PREFIX( cvsub )(
    SAL_cf32 *A,
    SAL_i32 I,
    SAL_cf32 *B,
    SAL_i32 J,
    SAL_cf32 *C,
    SAL_i32 K,
    SAL_i32 N
)
{
    SAL_CALL_RETURN( PREFIX( cvsubx )( A, I, B, J, C, K, N, SAL_NX ) );
}

SAL_STATUS PREFIX( cvsubx )(
    SAL_cf32 *c_A,
    SAL_i32 I,
    SAL_cf32 *c_B,
    SAL_i32 J,
    SAL_cf32 *c_C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 XFLAG
)
{
    cvsubx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( cvsubx_selector )( c_A, I, c_B, J, c_C, K, N, XFLAG, &func );

    ( * func )( c_A, I, c_B, J, c_C, K, N, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

