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
        cmtrans2dx.c

    Description:
        Submatrix Transpose

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "cmtrans2dx_selector.h"

SAL_STATUS PREFIX( cmtrans2d )(
    SAL_cf64 *A,
    SAL_cf64 *C,
    SAL_i32 NC,
    SAL_i32 NR,
    SAL_i32 TCA,
    SAL_i32 TCC
)
{
    SAL_CALL_RETURN( PREFIX( cmtrans2dx )( A, C, NC, NR, TCA, TCC, SAL_NX ) );
}

SAL_STATUS PREFIX( cmtrans2dx )(
    SAL_cf64 *c_A,
    SAL_cf64 *c_C,
    SAL_i32 NC,
    SAL_i32 NR,
    SAL_i32 TCA,
    SAL_i32 TCC,
    SAL_i32 XFLAG
)
{
    cmtrans2dx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( cmtrans2dx_selector )( c_A, c_C, NC, NR, TCA, TCC, XFLAG, &func );

    ( * func )( c_A, c_C, NC, NR, TCA, TCC, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}
