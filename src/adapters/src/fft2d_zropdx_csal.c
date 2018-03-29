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
        fft2d_zropdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fft2d_zropdx_csal )(
    FFT_setupd *SETUPP,
    SAL_zf64 *A,
    SAL_i32 IR,
    SAL_i32 IC,
    SAL_zf64 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_ui32 LOG2NC,
    SAL_ui32 LOG2NR,
    SAL_i32 FLAG,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_f64 half;

    SAL_zf64  Ap, Cp;

    SAL_ui32  i;

    ( void )X;

    if ( !IC )
        IC = IR << ( LOG2NC - 1 );

    if ( !KC )
        KC = KR << ( LOG2NC - 1 );

    Ap = *A;
    Cp = *C;

    if ( FLAG > 0 )
    {
        for ( i = 0; i < ( SAL_ui32 )( 1 << LOG2NR ); i++ )
        {
            PREFIX( _csal_fft_zbd )( &Ap, IR, &Ap, IR, &Cp, KR,
                                     ( LOG2NC - 1 ), FLAG, SETUPP );
            PREFIX( _csal_fft_zrpd )( &Cp, KR, &Cp, KR, LOG2NC, FLAG, SETUPP );
            Ap.realp += IC;
            Ap.imagp += IC;
            Cp.realp += KC;
            Cp.imagp += KC;
        }

        half = 0.5;
        Cp = *C;
        Cp.imagp = Cp.realp + KC;
        PREFIX( _csal_fft_zd )( &Cp, ( KC << 1 ), ( LOG2NR - 1 ), FLAG, SETUPP );
        PREFIX( _csal_fft_zrpd )( &Cp, ( KC << 1 ), &Cp, ( KC << 1 ),
                                  LOG2NR, FLAG, SETUPP );
        PREFIX( vsmuldx )( Cp.realp, KC, &half, Cp.realp, KC, ( 1 << LOG2NR ), 0 );

        Cp = *C;
        Cp.realp = Cp.imagp;
        Cp.imagp = Cp.realp + KC;
        PREFIX( _csal_fft_zd )( &Cp, ( KC << 1 ), ( LOG2NR - 1 ), FLAG, SETUPP );
        PREFIX( _csal_fft_zrpd )( &Cp, ( KC << 1 ), &Cp, ( KC << 1 ),
                                  LOG2NR, FLAG, SETUPP );
        PREFIX( vsmuldx )( Cp.realp, KC, &half, Cp.realp, KC, ( 1 << LOG2NR ), 0 );

        Cp = *C;
        Cp.realp += KR;
        Cp.imagp += KR;

        for ( i = 1; i < ( SAL_ui32 )( 1 << ( LOG2NC - 1 ) ); i++ )
        {
            PREFIX( _csal_fft_zd )( &Cp, KC, LOG2NR, FLAG, SETUPP );
            Cp.realp += KR;
            Cp.imagp += KR;
        }
    }

    else
    {
        Ap = *A;
        Ap.imagp = Ap.realp + IC;
        Cp = *C;
        Cp.imagp = Cp.realp + KC;
        PREFIX( _csal_fft_zrpd )( &Ap, ( IC << 1 ), &Ap, ( IC << 1 ),
                                  LOG2NR, FLAG, SETUPP );
        PREFIX( _csal_fft_zbd )( &Ap, ( IC << 1 ), &Ap, ( IC << 1 ),
                                 &Cp, ( KC << 1 ), ( LOG2NR - 1 ), FLAG, SETUPP );

        Ap = *A;
        Ap.realp = Ap.imagp;
        Ap.imagp = Ap.realp + IC;
        Cp = *C;
        Cp.realp = Cp.imagp;
        Cp.imagp = Cp.realp + KC;
        PREFIX( _csal_fft_zrpd )( &Ap, ( IC << 1 ), &Ap, ( IC << 1 ),
                                  LOG2NR, FLAG, SETUPP );
        PREFIX( _csal_fft_zbd )( &Ap, ( IC << 1 ), &Ap, ( IC << 1 ),
                                 &Cp, ( KC << 1 ), ( LOG2NR - 1 ), FLAG, SETUPP );

        Ap = *A;
        Ap.realp += IR;
        Ap.imagp += IR;
        Cp = *C;
        Cp.realp += KR;
        Cp.imagp += KR;

        for ( i = 1; i < ( SAL_ui32 )( 1 << ( LOG2NC - 1 ) ); i++ )
        {
            PREFIX( _csal_fft_zbd )( &Ap, IC, &Ap, IC, &Cp, KC, LOG2NR, FLAG,
                                     SETUPP );
            Ap.realp += IR;
            Ap.imagp += IR;
            Cp.realp += KR;
            Cp.imagp += KR;
        }

        Cp = *C;

        for ( i = 0; i < ( SAL_ui32 )( 1 << LOG2NR ); i++ )
        {
            PREFIX( _csal_fft_zrpd )( &Cp, KR, &Cp, KR, LOG2NC, FLAG, SETUPP );
            PREFIX( _csal_fft_zd )( &Cp, KR, ( LOG2NC - 1 ), FLAG, SETUPP );
            Cp.realp += KC;
            Cp.imagp += KC;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
