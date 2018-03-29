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
        fft2d_cipdx.c

    Description:
        In-Place Two-Dimensional Interleaved Complex Fourier Transform

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fft2d_cipdx_selector.h"

SAL_STATUS PREFIX( fft2d_cipd )(
    SAL_fft64 *SETUPP,
    SAL_cf64 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_ui32 LOG2NC,
    SAL_ui32 LOG2NR,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( fft2d_cipdx )( SETUPP, C, KR, KC, LOG2NC, LOG2NR, FLAG, SAL_NX ) );
}

SAL_STATUS PREFIX( fft2d_cipdx )(
    SAL_fft64 *SETUPP,
    SAL_cf64 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_ui32 LOG2NC,
    SAL_ui32 LOG2NR,
    SAL_i32 FLAG,
    SAL_i32 XFLAG
)
{
    fft2d_cipdx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fft2d_cipdx_selector )( SETUPP, C, KR, KC, LOG2NC, LOG2NR, FLAG, XFLAG, &func );

    ( * func )( SETUPP, C, KR, KC, LOG2NC, LOG2NR, FLAG, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

