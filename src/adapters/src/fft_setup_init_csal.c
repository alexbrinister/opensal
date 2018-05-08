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
        fft_setup_init_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "adapters.h"
#include "fft_internal.h"

#define ROUNDUP_64( value ) \
    (((SAL_ui32 )(value) + 63U) & ~63U)

#define ROUNDUP_64L( value ) \
    (((unsigned long)(value) + 63UL) & ~63UL)

SAL_i32 PREFIX( fft_setup_init_csal ) (
    FFT_setup            *setupp,
    const SAL_i32             flag,
    SAL__return_info     *r_info
)
{
    SAL_ui32  LOG2M;
    SAL_i32 FLAG;
    void *BUFFERP;
    SAL__fft_setup_csal  *SETUP;

    SAL__fft_setup_config_base * config;

    config = ( *setupp )->fft_setup_config_base;

    LOG2M = MAX( config->log2m, config->log2n );

    if ( LOG2M < 2 )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_INVALID_SIZE );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_PTR_RETURN_INT( r_info );
    }

    FLAG = config->fft_type_flags;
    BUFFERP = config->alloc_addr;

    void  *handle = NULL;

    void *temp = NULL;

    SAL_f32  *twidp = NULL;
    SAL_ui32  m, ntwids, alloc_size;

    if ( FLAG & FFT_RADIX9 )
        FLAG |= FFT_RADIX3;

    m = 1 << LOG2M;
    ntwids = m - ( m >> 2 );

    if ( FLAG & FFT_RADIX3 )
        ntwids += ( m << 1 );

    if ( FLAG & FFT_RADIX5 )
        ntwids += ( m << 2 );

    if ( FLAG & FFT_RADIX9 )
        ntwids += ( 6 * m );

    SETUP = NULL;

    alloc_size = config->nbytes;

    if ( BUFFERP )
    {

        temp = ( void * )ROUND_UP_POW2( BUFFERP, FFT_SETUP_STRUCT_ALIGN );
        SETUP = ( SAL__fft_setup_csal * ) temp;

        SETUP->handle = ( void * )0;

    }
    else
    {

        handle = ( void * )calloc( ( unsigned long ) alloc_size, sizeof( SAL_char ) );

        if ( !handle ) goto err_ret;

        temp = ( void * )ROUND_UP_POW2( handle, FFT_SETUP_STRUCT_ALIGN );

        SETUP = ( SAL__fft_setup_csal * )temp;
        SETUP->handle = ( void * )handle;
    }

    ( *setupp )->csal_fft_setup = SETUP;

    SETUP->log2m = LOG2M;

    twidp = ( SAL_f32 * )( ( SAL_char * )SETUP +
                           ( SAL_ui32 )sizeof( SAL__fft_setup_csal ) );
    twidp = ( SAL_f32 * )ROUND_UP_POW2( twidp, 16 );

    SETUP->twids.realp = twidp;
    twidp += ( m - ( m >> 2 ) );

    SETUP->twids.imagp = twidp;
    twidp += ( m - ( m >> 2 ) );

    PREFIX( _csal_fft_twiddles ) ( SETUP->twids.realp,
                                   SETUP->twids.imagp, LOG2M );

    if ( FLAG & FFT_RADIX3 )
    {
        SETUP->radix3_twids.realp = twidp;
        twidp += ( m << 1 );

        SETUP->radix3_twids.imagp = twidp;
        twidp += ( m << 1 );

        PREFIX( _csal_fft_twiddles3 ) ( SETUP->radix3_twids.realp,
                                        SETUP->radix3_twids.imagp, LOG2M );
    }

    if ( FLAG & FFT_RADIX5 )
    {
        SETUP->radix5_twids.realp = twidp;
        twidp += ( m << 2 );

        SETUP->radix5_twids.imagp = twidp;
        twidp += ( m << 2 );

        PREFIX( _csal_fft_twiddles5 ) ( SETUP->radix5_twids.realp,
                                        SETUP->radix5_twids.imagp, LOG2M );
    }

    if ( FLAG & FFT_RADIX9 )
    {
        SETUP->radix9_twids.realp = twidp;
        twidp += ( 6 * m );

        SETUP->radix9_twids.imagp = twidp;
        twidp += ( 6 * m );

        PREFIX( _csal_fft_twiddles9 ) ( SETUP->radix9_twids.realp,
                                        SETUP->radix9_twids.imagp, LOG2M );
    }

    SETUP->NBYTESP = alloc_size;

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_PTR_RETURN_INT( r_info );

err_ret:

    ( *setupp )->csal_fft_setup =
        ( void * )calloc( ( unsigned long ) sizeof( SAL__fft_setup_csal ), sizeof( SAL_char ) );
    ( *setupp )->csal_fft_setup->NBYTESP = 0;

    return 1;
}
