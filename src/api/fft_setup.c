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
        fft_setup.c

    Description:
        Create Complex Exponentials for Fourier Transforms

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fft_setup_selector.h"

SAL_STATUS PREFIX( fft_setup )(
    SAL_ui32 LOG2M,
    SAL_i32 FLAG,
    FFT_setup *SETUPP,
    SAL_ui32 *NBYTESP
)
{
    fft_setup_func func;
    SAL__return_info r_info;

    SAL_ui32 LOG2N = 0;
    SAL_i32 OPT_FLAG = SAL_FFT_OPTIMIZE_RESERVED;

    SAL_RINFO_INIT( r_info );

    PREFIX( fft_setup_selector )( FLAG, LOG2M, LOG2N, OPT_FLAG, SETUPP, &func );
    ( * func )( FLAG, LOG2M, LOG2N, OPT_FLAG, SETUPP, &r_info );

    if (r_info.code == SAL_SUCCESS) {
      *NBYTESP = 1;
    } else {
      *NBYTESP = 0;
    }

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

