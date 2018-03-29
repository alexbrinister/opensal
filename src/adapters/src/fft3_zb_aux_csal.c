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
        fft3_zb_aux_csal.c

----------------------------------------------------------------------------
*/

#include "fft_internal.h"

void  PREFIX( _csal_fft3_zb )( SAL_zf32 *A, SAL_i32 I,
                               SAL_zf32 *B, SAL_i32 J,
                               SAL_zf32 *C, SAL_i32 K,
                               SAL_ui32 LOG2N, SAL_i32 FLAG,
                               FFT_setup *setupp )
{
    SAL__fft_setup_csal **SETUPP = &( ( *setupp )->csal_fft_setup );

    SAL_i32  i, mul_flag, twid_stride;
    SAL_zf32  B_work, C_work;

    if ( LOG2N < 2 )
    {
        PREFIX( _csal_fft3_small )( A->realp, A->imagp, I,
                                    C->realp, C->imagp, K,
                                    LOG2N, FLAG );
        return;
    }

    twid_stride = 1 << ( ( *SETUPP )->log2m - LOG2N );

    mul_flag = ( FLAG == FFT_FORWARD ) ? -1 : 1;

    PREFIX( _csal_fft_rad3 )( A, I, B, J, ( SAL_ui32 )( 1 << LOG2N ), FLAG );

    B_work.realp = B->realp + ( J << LOG2N );
    B_work.imagp = B->imagp + ( J << LOG2N );

    PREFIX( _csal_zvmul )( &( *SETUPP )->radix3_twids, twid_stride,
                           &B_work, J, &B_work, J,
                           ( SAL_ui32 )( 2 << LOG2N ), mul_flag );

    B_work = *B;
    C_work = *C;

    for ( i = 0; i < 3; i++ )
    {
        PREFIX( _csal_fft_zb )( &B_work, J, &B_work, J, &C_work, ( 3 * K ),
                                LOG2N, FLAG, setupp );
        B_work.realp += ( J << LOG2N );
        B_work.imagp += ( J << LOG2N );
        C_work.realp += K;
        C_work.imagp += K;
    }

    SAL_SET_PATH_CSAL();
}
