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
        fft_setupd_init_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "fft_internal.h"
#include "adapters.h"

#define ROUNDUP_64( value ) \
    (((SAL_ui32 )(value) + 63U) & ~63U)

#define ROUNDUP_64L( value ) \
    (((unsigned long)(value) + 63UL) & ~63UL)

SAL_i32 PREFIX( fft_setupd_init_csal ) (
    FFT_setupd           *p_setup,
    const SAL_i32             flag,
    SAL__return_info     *r_info
)
{
    SAL__fft_setup_config_base * config;

    config = ( *p_setup )->fft_setup_config_base;

    if ( ( config->log2m < 2 ) && ( config->log2n < 2 ) )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_INVALID_SIZE );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_PTR_RETURN_INT( r_info );
    }

    {
        void *buffer;
        SAL_i32 FLAG;
        unsigned long alloc_size;
        void  *handle = NULL;
        SAL_ui32  log2m;

        FLAG = config->fft_type_flags;
        log2m = MAX( config->log2m, config->log2n );
        alloc_size = config->nbytes;

        if ( ( handle = ( void * )malloc( ( unsigned long )alloc_size ) ) == NULL )
        {
            goto err_ret;
        }

        buffer = ( void * )ROUND_UP_POW2( handle, FFT_SETUP_STRUCT_ALIGN );

        PREFIX( fft_setup_user_allocd ) ( log2m, FLAG, p_setup, buffer );

        ( *p_setup )->csal_fft_setup->handle = ( void * )handle;

        ( *p_setup )->csal_fft_setup->NBYTESP = alloc_size;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_PTR_RETURN_INT( r_info );

err_ret:

    ( *p_setup )->csal_fft_setup =
        ( void * )calloc( ( unsigned long ) sizeof( SAL__fft_setupd_csal ), sizeof( SAL_char ) );

    if ( !( ( *p_setup )->csal_fft_setup ) )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_NOT_ENOUGH_MEMORY );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_PTR_RETURN_INT( r_info );
    }

    ( *p_setup )->csal_fft_setup->NBYTESP = 0;

    return 1;
}
