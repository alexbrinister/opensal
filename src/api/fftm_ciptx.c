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
        fftm_ciptx.c

    Description:
        Multiple In-place Interleaved Complex Fourier Transform

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fftm_ciptx_selector.h"

SAL_STATUS PREFIX( fftm_cipt )(
    SAL_fft32 *SETUPP,
    SAL_cf32 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_cf32 *T,
    SAL_ui32 LOG2N,
    SAL_ui32 M,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( fftm_ciptx )( SETUPP, C, KR, KC, T, LOG2N, M, FLAG, SAL_NX ) );
}

SAL_STATUS PREFIX( fftm_ciptx )(
    SAL_fft32 *SETUPP,
    SAL_cf32 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_cf32 *T,
    SAL_ui32 LOG2N,
    SAL_ui32 M,
    SAL_i32 FLAG,
    SAL_i32 XFLAG
)
{
    fftm_ciptx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fftm_ciptx_selector )( SETUPP, C, KR, KC, T, LOG2N, M, FLAG, XFLAG, &func );

    ( * func )( SETUPP, C, KR, KC, T, LOG2N, M, FLAG, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

