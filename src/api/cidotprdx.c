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
        cidotprdx.c

    Description:
        Vector Conjugate (Inner) Dot Product

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "cidotprdx_selector.h"

SAL_STATUS PREFIX( cidotprd )(
    SAL_cf64 *A,
    SAL_i32 I,
    SAL_cf64 *B,
    SAL_i32 J,
    SAL_cf64 *S,
    SAL_i32 N
)
{
    SAL_CALL_RETURN( PREFIX( cidotprdx )( A, I, B, J, S, N, SAL_NX ) );
}

SAL_STATUS PREFIX( cidotprdx )(
    SAL_cf64 *c_A,
    SAL_i32 I,
    SAL_cf64 *c_B,
    SAL_i32 J,
    SAL_cf64 *c_S,
    SAL_i32 N,
    SAL_i32 XFLAG
)
{
    cidotprdx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( cidotprdx_selector )( c_A, I, c_B, J, c_S, N, XFLAG, &func );

    ( * func )( c_A, I, c_B, J, c_S, N, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

