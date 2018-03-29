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
        fft_setupd_get_n_bytes_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fft_internal.h"
#include "sal_interface_internal.h"

#define ROUNDUP_64L( value ) \
      (((unsigned long)(value) + 63UL) & ~63UL)


void PREFIX( fft_setupd_get_n_bytes_csal )(
    FFT_setup           *p_setup,
    SAL_i32                 *p_nbytes,
    const SAL_i32            flag,
    SAL__return_info    *r_info
)
{
    SAL_ui32 log2m;
    SAL_ui32 fft_type_flags;

    SAL_ui32  m, ntwids, alloc_size;

    SAL__fft_setup_config_base * config;

    config = ( *p_setup )->fft_setup_config_base;

    if ( config->nbytes )
    {
        *p_nbytes = config->nbytes;
        return;
    }

    fft_type_flags = config->fft_type_flags;

    log2m = MAX( config->log2m, config->log2n );

    m = 1 << log2m;
    ntwids = m - ( m >> 2 );

    if ( fft_type_flags & FFT_RADIX3 )
        ntwids += ( m << 1 );

    if ( fft_type_flags & FFT_RADIX5 )
        ntwids += ( m << 2 );

    alloc_size = ( SAL_ui32 )sizeof( SAL__fft_setupd ) +
                 ( 2 * FFT_SETUP_STRUCT_ALIGN ) +
                 ( ntwids * sizeof ( SAL_cf64 ) ) +
                 ( 7 * 128 );

    alloc_size = ROUNDUP_64L( alloc_size );
    *p_nbytes = alloc_size;
    config->nbytes = alloc_size;

    return;
}

