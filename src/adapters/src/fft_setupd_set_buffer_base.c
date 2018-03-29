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
        fft_setupd_set_buffer_base.c

----------------------------------------------------------------------------
*/

#include "adapters.h"
#include "fft_internal.h"

SAL_i32 PREFIX( fft_setupd_set_buffer_base )(
    FFT_setupd *p_setup,
    void *buffer,
    const SAL_i32 nbytes,
    const SAL_i32 flag,
    SAL__return_info *r_info
)
{
    SAL_ui32 fft_type = 0;
    SAL_ui32 fft_type_flags = 0;
    unsigned long alloc_size = 0;
    SAL_i32 needed_size = 0;
    SAL__fft_setup_config_base * config_base = NULL;

    config_base = ( *p_setup )->fft_setup_config_base;

    if ( p_setup && *p_setup && config_base )
    {
        fft_type = config_base->fft_type;
    }

    fft_type_flags = fft_type_flag_lookup( fft_type );

    if ( !( p_setup && *p_setup ) )
    {
        alloc_size = sizeof( SAL__fft_setup );
        *p_setup = ( FFT_setupd )calloc( alloc_size, sizeof( SAL_char ) );

        if ( !( *p_setup ) )
        {
            SAL_RINFO_SET_CODE( r_info, SAL_NOT_ENOUGH_MEMORY );
            SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
            SAL_RINFO_PTR_RETURN_INT( r_info );
        }
    }

    needed_size = ( *p_setup )->fft_setup_config_base->nbytes;

    if ( needed_size > nbytes )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_NOT_ENOUGH_MEMORY );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_PTR_RETURN_INT( r_info );
    }

    config_base->alloc_addr = buffer;

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_PTR_RETURN_INT( r_info );
}

