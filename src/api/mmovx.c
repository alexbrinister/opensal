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
        mmovx.c

    Description:
        Matrix or Submatrix Move or Transpose

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "mmovx_selector.h"

SAL_STATUS PREFIX( mmov )(
    SAL_f32 *pSrc,
    SAL_i32 stride_x_src,
    SAL_i32 stride_y_src,
    SAL_f32 *pDst,
    SAL_i32 stride_x_dst,
    SAL_i32 stride_y_dst,
    SAL_i32 x_len,
    SAL_i32 y_len
)
{
    SAL_CALL_RETURN( PREFIX( mmovx )( pSrc, stride_x_src, stride_y_src, pDst, stride_x_dst, stride_y_dst, x_len, y_len, SAL_NN ) );
}

SAL_STATUS PREFIX( mmovx )(
    SAL_f32 *pSrc,
    SAL_i32 stride_x_src,
    SAL_i32 stride_y_src,
    SAL_f32 *pDst,
    SAL_i32 stride_x_dst,
    SAL_i32 stride_y_dst,
    SAL_i32 x_len,
    SAL_i32 y_len,
    SAL_i32 xflag
)
{
    mmovx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( mmovx_selector )( pSrc, stride_x_src, stride_y_src, pDst, stride_x_dst, stride_y_dst, x_len, y_len, xflag, &func );

    ( * func )( pSrc, stride_x_src, stride_y_src, pDst, stride_x_dst, stride_y_dst, x_len, y_len, xflag, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

