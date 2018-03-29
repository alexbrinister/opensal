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
        zmmovx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zmmovx_csal )(
    SAL_zf32 *pSrc,
    SAL_i32 stride_x_src,
    SAL_i32 stride_y_src,
    SAL_zf32 *pDst,
    SAL_i32 stride_x_dst,
    SAL_i32 stride_y_dst,
    SAL_i32 x_len,
    SAL_i32 y_len,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_i32 x, y, src_idx, dst_idx;

    ( void )xflag;

    if ( stride_x_src == 0 )
        stride_x_src = y_len * stride_y_src;

    if ( stride_y_src == 0 )
        stride_y_src = x_len * stride_x_src;

    if ( stride_x_dst == 0 )
        stride_x_dst = y_len * stride_y_dst;

    if ( stride_y_src == 0 )
        stride_y_dst = x_len * stride_x_dst;

    for ( y = 0; y < y_len; y++ )
    {
        for ( x = 0; x < x_len; x++ )
        {
            src_idx = ( y * stride_y_src ) + ( x * stride_x_src );
            dst_idx = ( y * stride_y_dst ) + ( x * stride_x_dst );

            pDst->realp[dst_idx] = pSrc->realp[src_idx];
            pDst->imagp[dst_idx] = pSrc->imagp[src_idx];
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
