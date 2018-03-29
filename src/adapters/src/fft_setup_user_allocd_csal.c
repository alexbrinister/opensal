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
        fft_setup_user_allocd_csal.c

----------------------------------------------------------------------------
*/

#include "fft_internal.h"
#include <stdlib.h>

SAL_STATUS PREFIX( fft_setup_user_allocd_ )(
    SAL_ui32 *LOG2M,
    SAL_i32 *FLAG,
    FFT_setupd *SETUPP,
    void *BUFFER
)
{
    PREFIX( fft_setup_user_allocd )( *LOG2M, *FLAG, SETUPP, BUFFER );
}

SAL_STATUS PREFIX( fft_setup_user_allocd )(
    SAL_ui32 LOG2M,
    SAL_i32 FLAG,
    FFT_setupd *setupp,
    void *BUFFER
)
{
    SAL_f64  *ptr0, *ptr1;
    SAL_ui32  m, ntwids;

    SAL__fft_setupd_csal * SETUP = ( SAL__fft_setupd_csal * ) BUFFER;

    m = 1 << LOG2M;
    ntwids = m - ( m >> 2 );

    if ( FLAG & FFT_RADIX3 )
        ntwids += ( m << 1 );

    if ( FLAG & FFT_RADIX5 )
        ntwids += ( m << 2 );

    ptr0 = ( SAL_f64 * ) ( ( SAL_char * ) BUFFER + sizeof ( SAL__fft_setupd_csal ) );
    ptr0 = ( SAL_f64 * ) ( ( ( unsigned long ) ptr0 + 15UL ) & ~15UL );

    ptr1 = ptr0 + ntwids;
    ptr1 = ( SAL_f64 * ) ( ( ( unsigned long ) ptr1 + 15UL ) & ~15UL );

    PREFIX ( _csal_fft_twiddlesd ) ( ptr0, ptr1, LOG2M );

    SETUP->real_twidp = ptr0;
    SETUP->imag_twidp = ptr1;
    ptr0 += ( m - ( m >> 2 ) );
    ptr1 += ( m - ( m >> 2 ) );

    if ( FLAG & FFT_RADIX3 )
    {
        PREFIX ( _csal_fft_twiddles3d )( ( SAL_cf64 * )ptr0,
                                         ( SAL_cf64 * )ptr1, LOG2M );
        SETUP->radix3_twidp_0 = ( SAL_cf64 * )ptr0;
        SETUP->radix3_twidp_1 = ( SAL_cf64 * )ptr1;
        ptr0 += ( m << 1 );
        ptr1 += ( m << 1 );
    }

    if ( FLAG & FFT_RADIX5 )
    {
        PREFIX ( _csal_fft_twiddles5d )( ( SAL_cf64 * )ptr0,
                                         ( SAL_cf64 * )ptr1, LOG2M );
        SETUP->radix5_twidp_0 = ( SAL_cf64 * )ptr0;
        SETUP->radix5_twidp_1 = ( SAL_cf64 * )ptr1;
    }

    SETUP->handle = NULL;
    SETUP->m = m;
    SETUP->log2m = LOG2M;

    ( *setupp )->csal_fft_setup = SETUP;

    SAL_SET_PATH_CSAL();

    return;
}

