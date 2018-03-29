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
        fft_cipx.c

    Description:
        In-place Interleaved Complex Fourier Transform

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fft_cipx_selector.h"

SAL_STATUS PREFIX( fft_cip )(
    SAL_fft32 *SETUPP,
    SAL_cf32 *C,
    SAL_i32 K,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG
)
{
    SAL_CALL_RETURN( PREFIX( fft_cipx )( SETUPP, C, K, LOG2N, FLAG, SAL_NX ) );
}

SAL_STATUS PREFIX( fft_cipx )(
    SAL_fft32 *SETUPP,
    SAL_cf32 *C,
    SAL_i32 K,
    SAL_ui32 LOG2N,
    SAL_i32 FLAG,
    SAL_i32 XFLAG
)
{
    fft_cipx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fft_cipx_selector )( SETUPP, C, K, LOG2N, FLAG, XFLAG, &func );

    ( * func )( SETUPP, C, K, LOG2N, FLAG, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

