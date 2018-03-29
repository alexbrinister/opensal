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
        fft_zvmagsx.c

    Description:
        Fourier Transform and Square Magnitudes

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fft_zvmagsx_selector.h"

SAL_STATUS PREFIX( fft_zvmags )(
    SAL_fft32 *SETUPP,
    SAL_zf32 *A,
    SAL_i32 I,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( fft_zvmagsx )( SETUPP, A, I, C, K, LOG2N, FLAG, SAL_N ) );
}

SAL_STATUS PREFIX( fft_zvmagsx )(
    SAL_fft32 *SETUPP,
    SAL_zf32 *A,
    SAL_i32 I,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG,
    SAL_i32 X
)
{
    fft_zvmagsx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fft_zvmagsx_selector )( SETUPP, A, I, C, K, LOG2N, FLAG, X, &func );

    ( * func )( SETUPP, A, I, C, K, LOG2N, FLAG, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

