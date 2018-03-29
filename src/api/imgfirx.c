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
        imgfirx.c

    Description:
        Image Filter, m x n Convolution

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "imgfirx_selector.h"

SAL_STATUS PREFIX( imgfir )(
    SAL_f32 *A,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_f32 *B,
    SAL_f32 *C,
    SAL_i32 M,
    SAL_i32 N
)
{
    SAL_CALL_RETURN( PREFIX( imgfirx )( A, NR, NC, B, C, M, N, SAL_NX ) );
}

SAL_STATUS PREFIX( imgfirx )(
    SAL_f32 *A,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_f32 *B,
    SAL_f32 *C,
    SAL_i32 M,
    SAL_i32 N,
    SAL_i32 XFLAG
)
{
    imgfirx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( imgfirx_selector )( A, NR, NC, B, C, M, N, XFLAG, &func );

    ( * func )( A, NR, NC, B, C, M, N, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

