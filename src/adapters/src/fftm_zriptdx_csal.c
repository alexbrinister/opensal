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
        fftm_zriptdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fftm_zriptdx_csal )(
    FFT_setupd *SETUPP,
    SAL_zf64 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_zf64 *T,
    SAL_ui32 LOG2N,
    SAL_ui32 M,
    SAL_i32 FLAG,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_zf64 Cp, Tp;

    SAL_ui32  i;

    ( void )X;

    if ( !KC )
        KC = KR << ( LOG2N - 1 );

    Cp = *C;
    Tp = *T;

    if ( FLAG > 0 )
    {
        for ( i = 0; i < M; i++ )
        {
            PREFIX( _csal_fft_zbd )( &Cp, KR, &Cp, KR, T, ( SAL_i32 )1,
                                     ( LOG2N - 1 ), FLAG, SETUPP );
            PREFIX( _csal_fft_zrpd )( T, ( SAL_i32 )1, &Cp, KR, LOG2N, FLAG, SETUPP );
            Cp.realp += KC;
            Cp.imagp += KC;
        }
    }
    else
    {
        for ( i = 0; i < M; i++ )
        {
            PREFIX( _csal_fft_zrpd )( &Cp, KR, &Tp, ( SAL_i32 )1, LOG2N, FLAG, SETUPP );
            PREFIX( _csal_fft_zbd )( &Tp, ( SAL_i32 )1, &Tp, ( SAL_i32 )1, &Cp, KR,
                                     ( LOG2N - 1 ), FLAG, SETUPP );
            Cp.realp += KC;
            Cp.imagp += KC;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
