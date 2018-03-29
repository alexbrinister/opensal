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
        fft_setup_get_n_bytes_base.c

----------------------------------------------------------------------------
*/

#include "adapters.h"
#include "fft_internal.h"

SAL_i32 PREFIX( fft_setup_get_n_bytes_base )(
    FFT_setup *p_setup,
    SAL_i32 *p_nbytes,
    const SAL_i32 flag,
    SAL__return_info *r_info
)
{
    SAL_i32 csal_nbytes = 0;

    if ( !( p_setup && *p_setup ) )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_INVALID_HANDLE );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_PTR_RETURN_INT( r_info );
    }

    fft_setup_get_n_bytes_csal( p_setup, &csal_nbytes, flag, r_info );

    ( *p_setup )->fft_setup_config_base->nbytes = csal_nbytes;

    *p_nbytes = csal_nbytes;

    SAL_RINFO_PTR_RETURN_INT( r_info );
}

