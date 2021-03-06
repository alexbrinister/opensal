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
        zconv2dx.c

    Description:
        2-D Convolution

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "zconv2dx_selector.h"

SAL_STATUS PREFIX( zconv2d )(
    SAL_zf32 *A,
    SAL_i32 TCA,
    SAL_zf32 *B,
    SAL_zf32 *C,
    SAL_i32 TCC,
    SAL_i32 DSX,
    SAL_i32 DSY,
    SAL_i32 NCB,
    SAL_i32 NRB,
    SAL_i32 NCC,
    SAL_i32 NRC,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( zconv2dx )( A, TCA, B, C, TCC, DSX, DSY, NCB, NRB, NCC, NRC, FLAG, SAL_NNN ) );
}

SAL_STATUS PREFIX( zconv2dx )(
    SAL_zf32 *A,
    SAL_i32 TCA,
    SAL_zf32 *B,
    SAL_zf32 *C,
    SAL_i32 TCC,
    SAL_i32 DSX,
    SAL_i32 DSY,
    SAL_i32 NCB,
    SAL_i32 NRB,
    SAL_i32 NCC,
    SAL_i32 NRC,
    SAL_i32 FLAG,
    SAL_i32 X
)
{
    zconv2dx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( zconv2dx_selector )( A, TCA, B, C, TCC, DSX, DSY, NCB, NRB, NCC, NRC, FLAG, X, &func );

    ( * func )( A, TCA, B, C, TCC, DSX, DSY, NCB, NRB, NCC, NRC, FLAG, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

