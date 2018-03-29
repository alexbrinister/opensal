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
        vconvert_endian2x.c

    Description:

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "vconvert_endian2x_selector.h"

SAL_STATUS PREFIX( vconvert_endian2 )(
    SAL_ui8* p_src,
    SAL_i32 stride_src,
    SAL_ui8* p_dst,
    SAL_i32 stride_dst,
    SAL_i32 n_elems
)
{
    SAL_CALL_RETURN( PREFIX( vconvert_endian2x )( p_src, stride_src, p_dst, stride_dst, n_elems, SAL_NN ) );
}

SAL_STATUS PREFIX( vconvert_endian2x )(
    SAL_ui8* p_src,
    SAL_i32 stride_src,
    SAL_ui8* p_dst,
    SAL_i32 stride_dst,
    SAL_i32 n_elems,
    SAL_i32 xflag
)
{
    vconvert_endian2x_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( vconvert_endian2x_selector )( p_src, stride_src, p_dst, stride_dst, n_elems, xflag, &func );

    ( * func )( p_src, stride_src, p_dst, stride_dst, n_elems, xflag, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

