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
        fft2d_zroptx.c

    Description:
        Out-of-place Two-Dimensional Real Fourier Transform, Split Complex Format

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fft2d_zroptx_selector.h"

SAL_STATUS PREFIX( fft2d_zropt )(
    SAL_fft32 *SETUPP,
    SAL_zf32 *A,
    SAL_i32 IR,
    SAL_i32 IC,
    SAL_zf32 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_zf32 *T,
    SAL_ui32 LOG2NC,
    SAL_ui32 LOG2NR,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( fft2d_zroptx )( SETUPP, A, IR, IC, C, KR, KC, T, LOG2NC, LOG2NR, FLAG, SAL_NNN ) );
}

SAL_STATUS PREFIX( fft2d_zroptx )(
    SAL_fft32 *SETUPP,
    SAL_zf32 *A,
    SAL_i32 IR,
    SAL_i32 IC,
    SAL_zf32 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_zf32 *T,
    SAL_ui32 LOG2NC,
    SAL_ui32 LOG2NR,
    SAL_i32 FLAG,
    SAL_i32 X
)
{
    fft2d_zroptx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fft2d_zroptx_selector )( SETUPP, A, IR, IC, C, KR, KC, T, LOG2NC, LOG2NR, FLAG, X, &func );

    ( * func )( SETUPP, A, IR, IC, C, KR, KC, T, LOG2NC, LOG2NR, FLAG, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

