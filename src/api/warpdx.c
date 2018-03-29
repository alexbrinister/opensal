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
        warpdx.c

    Description:
        Bilinear Warp with Bilinear Interpolation

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "warpdx_selector.h"

SAL_STATUS PREFIX( warpd )(
    SAL_f64 *A,
    SAL_f64 *B,
    SAL_f64 *C,
    SAL_i32 INC,
    SAL_i32 INR,
    SAL_i32 ONC,
    SAL_i32 ONR,
    SAL_i32 F,
    SAL_f64 *V
)
{
    SAL_CALL_RETURN( PREFIX( warpdx )( A, B, C, INC, INR, ONC, ONR, F, V, SAL_NX ) );
}

SAL_STATUS PREFIX( warpdx )(
    SAL_f64 *A,
    SAL_f64 *B,
    SAL_f64 *C,
    SAL_i32 INC,
    SAL_i32 INR,
    SAL_i32 ONC,
    SAL_i32 ONR,
    SAL_i32 F,
    SAL_f64 *V,
    SAL_i32 XFLAG
)
{
    warpdx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( warpdx_selector )( A, B, C, INC, INR, ONC, ONR, F, V, XFLAG, &func );

    ( * func )( A, B, C, INC, INR, ONC, ONR, F, V, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

