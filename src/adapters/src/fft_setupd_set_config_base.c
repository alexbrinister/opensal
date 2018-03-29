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
        fft_setupd_set_config_base.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "adapters.h"
#include "fft_internal.h"

SAL_i32 PREFIX( fft_setupd_set_config_base )(
    const SAL_ui32 fft_type,
    const SAL_ui32 fft_type_flags,
    const SAL_i32 log2m,
    const SAL_i32 log2n,
    const SAL_i32 opt_flag,
    FFT_setupd *p_setup,
    SAL__return_info *r_info
)
{
    SAL__fft_setup_config_base *config;
    unsigned long alloc_size;

    if ( !( ( *p_setup )->fft_setup_config_base ) )
    {
        alloc_size = sizeof( SAL__fft_setup_config_base );
        ( *p_setup )->fft_setup_config_base =
            ( SAL__fft_setup_config_base * ) calloc( alloc_size, sizeof( SAL_char ) );

        if ( !( ( *p_setup )->fft_setup_config_base ) )
        {
            SAL_RINFO_SET_CODE( r_info, SAL_NOT_ENOUGH_MEMORY );
            SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
            SAL_RINFO_PTR_RETURN_INT( r_info );
        }
    }

    config = ( *p_setup )->fft_setup_config_base;

    if ( fft_type )
    {
        config->fft_type = fft_type;
    }

    if ( fft_type_flags )
    {
        config->fft_type_flags = fft_type_flags;
    }
    else if ( fft_type )
    {
        config->fft_type_flags = fft_type_flag_lookup( fft_type );
    }

    config->log2m = log2m;
    config->log2n = log2n;

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_PTR_RETURN_INT( r_info );
}

