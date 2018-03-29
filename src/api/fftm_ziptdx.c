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
        fftm_ziptdx.c

    Description:
        Multiple In-place Split Complex Fourier Transform

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fftm_ziptdx_selector.h"

SAL_STATUS PREFIX( fftm_ziptd )(
    SAL_fft64 *SETUPP,
    SAL_zf64 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_zf64 *T,
    SAL_ui32 LOG2N,
    SAL_ui32 M,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( fftm_ziptdx )( SETUPP, C, KR, KC, T, LOG2N, M, FLAG, SAL_NN ) );
}

SAL_STATUS PREFIX( fftm_ziptdx )(
    SAL_fft64 *SETUPP,
    SAL_zf64 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_zf64 *T,
    SAL_ui32 LOG2N,
    SAL_ui32 M,
    SAL_i32 FLAG,
    SAL_i32 X
)
{
    fftm_ziptdx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fftm_ziptdx_selector )( SETUPP, C, KR, KC, T, LOG2N, M, FLAG, X, &func );

    ( * func )( SETUPP, C, KR, KC, T, LOG2N, M, FLAG, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

