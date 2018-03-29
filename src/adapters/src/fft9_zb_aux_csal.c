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
        fft9_zb_aux_csal.c

----------------------------------------------------------------------------
*/

#include "fft_internal.h"

void  PREFIX( _csal_fft9_zb )( SAL_zf32 *A, SAL_i32 I,
                               SAL_zf32 *B, SAL_i32 J,
                               SAL_zf32 *C, SAL_i32 K,
                               SAL_ui32 LOG2N, SAL_i32 FLAG,
                               FFT_setup *setupp )
{
    SAL__fft_setup_csal **SETUPP = &( ( *setupp )->csal_fft_setup );

    SAL_i32  mul_flag, twid_stride;
    SAL_ui32  i, n3;
    SAL_zf32  B_work, C_work;

    n3 = 3 << LOG2N;

    twid_stride = ( SAL_i32 )( 1 << ( ( *SETUPP )->log2m - LOG2N ) );

    mul_flag = ( FLAG == FFT_FORWARD ) ? -1 : 1;

    PREFIX( _csal_fft_rad3 )( A, I, B, J, n3, FLAG );

    B_work.realp = B->realp + ( J * n3 );
    B_work.imagp = B->imagp + ( J * n3 );

    PREFIX( _csal_zvmul )( &( *SETUPP )->radix9_twids, twid_stride,
                           &B_work, J, &B_work, J,
                           ( 2 * n3 ), mul_flag );

    B_work = *B;
    C_work = *C;

    for ( i = 0; i < 3; i++ )
    {
        PREFIX( _csal_fft3_zb )( &B_work, J, &B_work, J, &C_work, ( 3 * K ),
                                 LOG2N, FLAG, setupp );
        B_work.realp += ( J * n3 );
        B_work.imagp += ( J * n3 );
        C_work.realp += K;
        C_work.imagp += K;
    }

    SAL_SET_PATH_CSAL();
}
