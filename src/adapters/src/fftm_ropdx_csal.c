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
        fftm_ropdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fftm_ropdx_csal )(
    FFT_setupd *SETUPP,
    SAL_f64 *A,
    SAL_i32 IR,
    SAL_i32 IC,
    SAL_f64 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_ui32 LOG2N,
    SAL_ui32 M,
    SAL_i32 FLAG,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_ui32  i;

    SAL_zf64 split_a,
    split_c;

    if ( !IC )
        IC = IR << LOG2N;

    if ( !KC )
        KC = KR << LOG2N;

    split_a.realp = A;
    split_a.imagp = A + IR;

    split_c.realp = C;
    split_c.imagp = C + KR;

    if ( FLAG > 0 )
    {
        for ( i = 0; i < M; i++ )
        {
            PREFIX( _csal_fft_zbd )( &split_a, ( IR << 1 ), &split_a, ( IR << 1 ),
                                     &split_c, ( KR << 1 ), ( LOG2N - 1 ), FLAG, SETUPP );

            PREFIX( _csal_fft_zrpd )( &split_c, ( KR << 1 ), &split_c, ( KR << 1 ), LOG2N,
                                      FLAG, SETUPP );
            split_a.realp += IC;
            split_a.imagp += IC;

            split_c.realp += KC;
            split_c.imagp += KC;
        }
    }
    else
    {
        for ( i = 0; i < M; i++ )
        {
            PREFIX( _csal_fft_zrpd )( &split_a, ( IR << 1 ), &split_c, ( KR << 1 ), LOG2N,
                                      FLAG, SETUPP );

            PREFIX( _csal_fft_zd )( &split_c, ( KR << 1 ), ( LOG2N - 1 ), FLAG, SETUPP );

            split_a.realp += IC;
            split_a.imagp += IC;

            split_c.realp += KC;
            split_c.imagp += KC;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
