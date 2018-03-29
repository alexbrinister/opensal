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
        fftm_zropx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fftm_zropx_csal )(
    FFT_setup *SETUPP,
    SAL_zf32 *A,
    SAL_i32 IR,
    SAL_i32 IC,
    SAL_zf32 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_ui32 LOG2N,
    SAL_ui32 M,
    SAL_i32 FLAG,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_zf32 Ap, Cp;

    SAL_ui32  i;

    ( void )X;

    if ( !IC )
        IC = IR << ( LOG2N - 1 );

    if ( !KC )
        KC = KR << ( LOG2N - 1 );

    Ap = *A;
    Cp = *C;

    if ( FLAG == FFT_FORWARD )
    {
        for ( i = 0; i < M; i++ )
        {
            PREFIX( _csal_fft_zb )( &Ap, IR, &Ap, IR, &Cp, KR,
                                    ( LOG2N - 1 ), FLAG, SETUPP );
            PREFIX( _csal_fft_zrp )( &Cp, KR, &Cp, KR, LOG2N, FLAG, SETUPP );
            Ap.realp += IC;
            Ap.imagp += IC;
            Cp.realp += KC;
            Cp.imagp += KC;
        }
    }
    else
    {
        for ( i = 0; i < M; i++ )
        {
            PREFIX( _csal_fft_zrp )( &Ap, IR, &Cp, KR, LOG2N, FLAG, SETUPP );
            PREFIX( _csal_fft_z )( &Cp, KR, ( LOG2N - 1 ), FLAG, SETUPP );
            Ap.realp += IC;
            Ap.imagp += IC;
            Cp.realp += KC;
            Cp.imagp += KC;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
