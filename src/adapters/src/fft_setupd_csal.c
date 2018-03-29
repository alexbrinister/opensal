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
        fft_setupd_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fft_internal.h"
#include "sal_interface_internal.h"

#include <stdlib.h>

static void PREFIX( _fft_setupd_common )( SAL_ui32 LOG2M,
        SAL_i32 FLAG,
        FFT_setupd *SETUPP,
        SAL_ui32 *NBYTESP );

void PREFIX( sal_get_fft_setup_by_rankd_ )( FFT_setupd *SETUPP,
        SAL_ui32 *RANK,
        FFT_setupd *WSETUPP )
{
    sal_get_fft_setup_by_rankd( SETUPP, *RANK, WSETUPP );
}

void PREFIX( sal_get_fft_setup_by_rankd )( FFT_setupd *SETUPP,
        SAL_ui32 RANK,
        FFT_setupd *WSETUPP )
{
    ( void )RANK;
    ( *WSETUPP ) = ( *SETUPP );
    return;
}

void PREFIX( fft_setup_thread_safed_ ) ( SAL_ui32 *LOG2M,
        SAL_i32 *FLAG,
        FFT_setupd *SETUPP,
        SAL_ui32 *NBYTESP,
        void *BUFFERP,
        SAL_ui32 *NTHREADS )
{
    PREFIX( fft_setup_thread_safed )( *LOG2M, *FLAG, SETUPP, NBYTESP, BUFFERP, *NTHREADS );
}

void PREFIX( fft_setup_thread_safed ) ( SAL_ui32 LOG2M,
                                        SAL_i32 FLAG,
                                        FFT_setupd *SETUPP,
                                        SAL_ui32 *NBYTESP,
                                        void *BUFFERP,
                                        SAL_ui32 NTHREADS )
{
    ( void )NTHREADS;

    if ( BUFFERP )
        fft_setup_user_allocd( LOG2M, FLAG, SETUPP, BUFFERP );
    else
        fft_setupd( LOG2M, FLAG, SETUPP, NBYTESP );

    return;
}

void PREFIX( fft_setupd_csal )(
    const SAL_ui32 fft_type,
    const SAL_ui32 LOG2M,
    const SAL_ui32 log2n,
    const SAL_i32          opt_flag,
    FFT_setupd         *SETUPP,
    SAL__return_info  *r_info )
{
    ( void ) log2n;
    ( void ) opt_flag;
    SAL_ui32 NBYTES;

    PREFIX( _fft_setupd_common )( LOG2M, fft_type, SETUPP, &NBYTES );
}

void PREFIX( _fft_setupd_common )( SAL_ui32 LOG2M,
                                   SAL_i32 FLAG,
                                   FFT_setupd *setupp,
                                   SAL_ui32 *NBYTESP )
{
    void *handle;

    void  *buffer;
    SAL_ui32  m, ntwids, alloc_size;

    m = 1 << LOG2M;
    ntwids = m - ( m >> 2 );

    if ( FLAG & FFT_RADIX3 )
        ntwids += ( m << 1 );

    if ( FLAG & FFT_RADIX5 )
        ntwids += ( m << 2 );

    alloc_size = ( SAL_ui32 )sizeof( SAL__fft_setupd ) +
                 ( 2 * FFT_SETUP_STRUCT_ALIGN ) +
                 ( ntwids * sizeof ( SAL_cf64 ) ) +
                 ( 7 * 128 );

    if ( ( handle = ( void * )malloc( ( unsigned long )alloc_size ) ) == NULL )
    {
        goto err_ret;
    }

    buffer = ( void * )ROUND_UP_POW2( handle, FFT_SETUP_STRUCT_ALIGN );

    PREFIX( fft_setup_user_allocd ) ( LOG2M, FLAG, setupp, buffer );

    ( *setupp )->csal_fft_setup->handle = ( void * )handle;

    if ( NBYTESP )
        *NBYTESP = alloc_size;

    ( *setupp )->csal_fft_setup->NBYTESP = alloc_size;

    SAL_SET_PATH_CSAL();

    return;

err_ret:
    if ( handle )
        free ( handle );

    ( *setupp )->csal_fft_setup =
        ( void * )calloc( ( unsigned long ) sizeof( SAL__fft_setupd_csal ), sizeof( SAL_char ) );

    ( *setupp )->csal_fft_setup->NBYTESP = 0;

    if ( NBYTESP )
        *NBYTESP = 0;

    return;
}

