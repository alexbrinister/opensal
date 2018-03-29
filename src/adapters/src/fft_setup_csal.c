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
        fft_setup_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "sal_internal.h"
#include "fft_internal.h"
#include "adapters.h"
#include "sal_interface_internal.h"

#define ROUNDUP_64( value ) \
    (((SAL_ui32 )(value) + 63U) & ~63U)

#define ROUNDUP_64L( value ) \
    (((unsigned long)(value) + 63UL) & ~63UL)

static void PREFIX( _fft_setup_common )(
    SAL_ui32 LOG2M,
    SAL_i32 FLAG,
    FFT_setup *SETUPP,
    SAL_ui32 *NBYTESP,
    void *BUFFERP,
    SAL_ui32 NTHREADS
);

void PREFIX( sal_get_fft_setup_by_rank_ )(
    FFT_setup *SETUPP,
    SAL_ui32 *RANK,
    FFT_setup *WSETUPP
)
{
    sal_get_fft_setup_by_rank( SETUPP, *RANK, WSETUPP );
}

void PREFIX( sal_get_fft_setup_by_rank )(
    FFT_setup *SETUPP,
    SAL_ui32 RANK,
    FFT_setup *WSETUPP
)
{
    ( void )RANK;
    ( *WSETUPP ) = ( *SETUPP );
    return;
}

void PREFIX( fft_setup_csal )(
    const SAL_ui32 fft_type_flags,
    const SAL_i32 log2m,
    const SAL_i32 log2n,
    const SAL_i32 opt_flag,
    FFT_setup *p_setup,
    SAL__return_info *r_info
)
{
    ( void ) opt_flag;

    SAL_ui32 log2mn = log2m > log2n ? log2m : log2n;
    SAL_ui32 nbytes;

    PREFIX( _fft_setup_common )( log2mn, fft_type_flags,
                                 p_setup, &nbytes, ( void * )0, 1 );
}

SAL_STATUS PREFIX( fft_setup_user_alloc_ )(
    SAL_ui32 *LOG2M,
    SAL_i32 *FLAG,
    FFT_setup *SETUPP,
    void *BUFFERP
)
{
    PREFIX( _fft_setup_common )( *LOG2M, *FLAG, SETUPP, ( SAL_ui32 * )0, BUFFERP, 1 );
}

SAL_STATUS PREFIX( fft_setup_user_alloc )(
    SAL_ui32 LOG2M,
    SAL_i32 FLAG,
    FFT_setup *SETUPP,
    void *BUFFERP
)
{
    PREFIX( _fft_setup_common )( LOG2M, FLAG, SETUPP, ( SAL_ui32 * )0, BUFFERP, 1 );
}

void PREFIX( fft_setup_thread_safe_ )(
    SAL_ui32 *LOG2M,
    SAL_i32 *FLAG,
    FFT_setup *SETUPP,
    SAL_ui32 *NBYTESP,
    void *BUFFERP,
    SAL_ui32 *NTHREADS
)
{
    PREFIX( fft_setup_thread_safe )( *LOG2M, *FLAG, SETUPP, NBYTESP, BUFFERP, *NTHREADS );
}

void PREFIX( fft_setup_thread_safe )(
    SAL_ui32 LOG2M,
    SAL_i32 FLAG,
    FFT_setup *SETUPP,
    SAL_ui32 *NBYTESP,
    void *BUFFERP,
    SAL_ui32 NTHREADS
)
{
    PREFIX( _fft_setup_common )( LOG2M, FLAG, SETUPP, NBYTESP, BUFFERP, NTHREADS );
}

static void PREFIX( _fft_setup_common )(
    SAL_ui32 LOG2M,
    SAL_i32 FLAG,
    FFT_setup *setupp,
    SAL_ui32 *NBYTESP,
    void *BUFFERP,
    SAL_ui32 NTHREADS
)
{

    SAL__fft_setup_csal  *SETUP;

    void  *handle = NULL;

    void *temp = NULL;

    SAL_f32  *twidp = NULL;
    SAL_ui32  m, ntwids, alloc_size;

    SAL_ui32  top = 0;

    if ( FLAG & FFT_RADIX9 )
        FLAG |= FFT_RADIX3;

    if ( LOG2M < 2 )
    {
        SETUP = NULL;

        if ( NBYTESP )
        {
            if ( FLAG & ( FFT_RADIX3 | FFT_RADIX5 ) )
                *NBYTESP = 1;
            else
                *NBYTESP = 0;
        }

        goto done;
    }

    m = 1 << LOG2M;
    ntwids = m - ( m >> 2 );

    if ( FLAG & FFT_RADIX3 )
        ntwids += ( m << 1 );

    if ( FLAG & FFT_RADIX5 )
        ntwids += ( m << 2 );

    if ( FLAG & FFT_RADIX9 )
        ntwids += ( 6 * m );

    alloc_size = ( SAL_ui32 )sizeof( SAL__fft_setup_csal ) +
                 ( 2 * FFT_SETUP_STRUCT_ALIGN ) +
                 ( ntwids * sizeof ( SAL_cf32 ) ) +
                 ( 9 * 128 );

    SETUP = NULL;

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

        top = ( unsigned long )handle + alloc_size;

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

done:
    SAL_SET_PATH_CSAL();

    return;

err_ret:

    ( *setupp )->csal_fft_setup =
        ( void * )calloc( ( unsigned long ) sizeof( SAL__fft_setup_csal ), sizeof( SAL_char ) );
    ( *setupp )->csal_fft_setup->NBYTESP = 0;

    return;
}

