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
        vtabidx.c

    Description:
        Vector Interpolation, Table Lookup

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "vtabidx_selector.h"

SAL_STATUS PREFIX( vtabid )(
    SAL_f64 *A,
    SAL_i32 I,
    SAL_f64 *S1,
    SAL_f64 *S2,
    SAL_f64 *C,
    SAL_i32 M,
    SAL_f64 *D,
    SAL_i32 L,
    SAL_i32 N
)
{
    SAL_CALL_RETURN( PREFIX( vtabidx )( A, I, S1, S2, C, M, D, L, N, SAL_NX ) );
}

SAL_STATUS PREFIX( vtabidx )(
    SAL_f64 *A,
    SAL_i32 I,
    SAL_f64 *S1,
    SAL_f64 *S2,
    SAL_f64 *C,
    SAL_i32 M,
    SAL_f64 *D,
    SAL_i32 L,
    SAL_i32 N,
    SAL_i32 XFLAG
)
{
    vtabidx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( vtabidx_selector )( A, I, S1, S2, C, M, D, L, N, XFLAG, &func );

    ( * func )( A, I, S1, S2, C, M, D, L, N, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

