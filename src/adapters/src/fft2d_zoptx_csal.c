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
        fft2d_zoptx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "fft_internal.h"

void PREFIX( fft2d_zoptx_csal )(
    FFT_setup *SETUPP,
    SAL_zf32 *A,
    SAL_i32 IR,
    SAL_i32 IC,
    SAL_zf32 *C,
    SAL_i32 KR,
    SAL_i32 KC,
    SAL_zf32 *T,
    SAL_ui32 LOG2NC,
    SAL_ui32 LOG2NR,
    SAL_i32 FLAG,
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_ui32  i;

    SAL_zf32 Ap, Cp, Tp;

    ( void )X;

    if ( !IC )
        IC = IR << LOG2NC;

    if ( !KC )
        KC = KR << LOG2NC;

    Ap = *A;
    Cp = *C;
    Tp = *T;

    for ( i = 0; i < ( SAL_ui32 )( 1 << LOG2NR ); i++ )
    {
        PREFIX( _csal_fft_zb )( &Ap, IR, &Tp, ( SAL_i32 )1, &Cp, KR, LOG2NC, FLAG,
                                SETUPP );
        Ap.realp += IC;
        Ap.imagp += IC;
        Cp.realp += KC;
        Cp.imagp += KC;
    }

    Cp = *C;
    Tp = *T;

    for ( i = 0; i < ( SAL_ui32 )( 1 << LOG2NC ); i++ )
    {
        PREFIX( _csal_fft_zb )( &Cp, KC, &Tp, ( SAL_i32 )1, &Cp, KC, LOG2NR, FLAG,
                                SETUPP );
        Cp.realp += KR;
        Cp.imagp += KR;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
