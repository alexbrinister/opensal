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
        fft2d_ripx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fft2d_ripx_csal )(
    FFT_setup *SETUPP,
    SAL_f32 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_ui32 LOG2NC,
    SAL_ui32 LOG2NR,
    SAL_i32 FLAG,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_ui32  i;
    SAL_f32  half;

    SAL_zf32 split_c;

    if ( !KC )
        KC = KR << LOG2NC;

    if ( FLAG > 0 )
    {
        split_c.realp = C;
        split_c.imagp = C + KR;

        for ( i = 0; i < ( SAL_ui32 )( 1 << LOG2NR ); i++ )
        {
            PREFIX( _csal_fft_z )( &split_c, ( KR << 1 ), ( LOG2NC - 1 ), FLAG, SETUPP );
            PREFIX( _csal_fft_zrp )( &split_c, ( KR << 1 ), &split_c, ( KR << 1 ), LOG2NC,
                                     FLAG, SETUPP );
            split_c.realp += KC;
            split_c.imagp += KC;
        }

        half = 0.5;

        split_c.realp = C;
        split_c.imagp = C + KC;

        for ( i = 0; i < 2; i++ )
        {
            PREFIX( _csal_fft_z )( &split_c, ( KC << 1 ), ( LOG2NR - 1 ), FLAG, SETUPP );
            PREFIX( _csal_fft_zrp )( &split_c, ( KC << 1 ), &split_c, ( KC << 1 ), LOG2NR,
                                     FLAG, SETUPP );

            PREFIX( vsmulx )( split_c.realp, ( SAL_i32 )KC, &half, split_c.realp, ( SAL_i32 )KC,
                              ( SAL_i32 )( 1 << LOG2NR ), 0 );

            split_c.realp += KR;
            split_c.imagp += KR;
        }

        split_c.imagp = split_c.realp + KR;

        for ( i = 1; i < ( SAL_ui32 )( 1 << ( LOG2NC - 1 ) ); i++ )
        {
            PREFIX( _csal_fft_z )( &split_c, KC, LOG2NR, FLAG, SETUPP );
            split_c.realp += ( KR << 1 );
            split_c.imagp += ( KR << 1 );
        }
    }

    else
    {
        split_c.realp = C;
        split_c.imagp = C + KC;

        for ( i = 0; i < 2; i++ )
        {
            PREFIX( _csal_fft_zrp )( &split_c, ( KC << 1 ), &split_c, ( KC << 1 ), LOG2NR,
                                     FLAG, SETUPP );
            PREFIX( _csal_fft_z )( &split_c, ( KC << 1 ), ( LOG2NR - 1 ), FLAG, SETUPP );
            split_c.realp += KR;
            split_c.imagp += KR;
        }

        split_c.imagp = split_c.realp + KR;

        for ( i = 1; i < ( SAL_ui32 )( 1 << ( LOG2NC - 1 ) ); i++ )
        {
            PREFIX( _csal_fft_z )( &split_c, KC, LOG2NR, FLAG, SETUPP );
            split_c.realp += ( KR << 1 );
            split_c.imagp += ( KR << 1 );
        }

        split_c.realp = C;
        split_c.imagp = C + KR;

        for ( i = 0; i < ( SAL_ui32 )( 1 << LOG2NR ); i++ )
        {
            PREFIX( _csal_fft_zrp )( &split_c, ( KR << 1 ), &split_c, ( KR << 1 ), LOG2NC,
                                     FLAG, SETUPP );
            PREFIX( _csal_fft_z )( &split_c, ( KR << 1 ), ( LOG2NC - 1 ), FLAG, SETUPP );
            split_c.realp += KC;
            split_c.imagp += KC;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
