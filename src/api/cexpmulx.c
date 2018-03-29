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
        cexpmulx.c

    Description:
        Vector Multiply by Sine and Cosine, Real to Complex

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "cexpmulx_selector.h"

SAL_STATUS PREFIX( cexpmul )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_f32 *F,
    SAL_f32 *P,
    SAL_cf32 *C,
    SAL_i32 K,
    SAL_cf32 *CEXPTAB,
    SAL_i32 LOG2M,
    SAL_i32 N
)
{
    SAL_CALL_RETURN( PREFIX( cexpmulx )( A, I, F, P, C, K, CEXPTAB, LOG2M, N, SAL_NN ) );
}

SAL_STATUS PREFIX( cexpmulx )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_f32 *F,
    SAL_f32 *P,
    SAL_cf32 *C,
    SAL_i32 K,
    SAL_cf32 *CEXPTAB,
    SAL_i32 LOG2M,
    SAL_i32 N,
    SAL_i32 X
)
{
    cexpmulx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( cexpmulx_selector )( A, I, F, P, C, K, CEXPTAB, LOG2M, N, X, &func );

    ( * func )( A, I, F, P, C, K, CEXPTAB, LOG2M, N, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

