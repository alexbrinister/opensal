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
        vconvert_f32_u8x_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( vconvert_f32_u8x_csal )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_ui8 *C,
    SAL_i32 K,
    SAL_f32 *SCALE,
    SAL_f32 *BIAS,
    SAL_i32 N,
    SAL_i32 FLAG,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32              i;
    SAL_f32            scale, bias, f32;
    SAL_ui32  i32;

    scale = SCALE ? *SCALE : 1.0;
    bias = BIAS ? *BIAS : 0.0;

    for ( i = 0; i < N; i++ )
    {
        f32 = ( scale * ( *A ) ) + bias;

        if ( f32 > ( SAL_f32 ) MAX_U32 )
            i32 = MAX_U32;

        else if ( f32 < ( SAL_f32 )MIN_U32 )
            i32 = MIN_U32;

        else
        {
            switch ( FLAG & SAL_ROUND_MASK )
            {
                case SAL_ROUND_NEAREST:
                    F32_FIX_NEAREST_UNSIGNED( f32, SAL_ui32, i32 )
                    break;

                case SAL_ROUND_UP:
                    F32_FIX_UP_UNSIGNED( f32, SAL_ui32, i32 )
                    break;

                case SAL_ROUND_DOWN:
                    F32_FIX_DOWN_UNSIGNED( f32, SAL_ui32, i32 )
                    break;

                case SAL_ROUND_ZERO:
                default:
                    F32_FIX_ZERO( f32, SAL_ui32, i32 )
                    break;
            }
        }

        if ( ( FLAG & SAL_FIELD_MASK ) == SAL_FIELD_SATURATE )
        {
            SATURATE_U8( i32 )
            *C = ( SAL_ui8 )i32;
        }
        else
            *C = ( SAL_ui8 )( ( i32 << 24 ) >> 24 );

        A += I;
        C += K;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
