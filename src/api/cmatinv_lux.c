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
        cmatinv_lux.c

    Description:
        Matrix Invert

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "cmatinv_lux_selector.h"

SAL_STATUS PREFIX( cmatinv_lu )(
    SAL_cf32 *C,
    SAL_cf32 *D,
    SAL_i32 *IP,
    SAL_i32 N
)
{
    SAL_CALL_RETURN( PREFIX( cmatinv_lux )( C, D, IP, N, SAL_NX ) );
}

SAL_STATUS PREFIX( cmatinv_lux )(
    SAL_cf32 *c_C,
    SAL_cf32 *c_D,
    SAL_i32 *IP,
    SAL_i32 N,
    SAL_i32 XFLAG
)
{
    cmatinv_lux_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( cmatinv_lux_selector )( c_C, c_D, IP, N, XFLAG, &func );

    ( * func )( c_C, c_D, IP, N, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

