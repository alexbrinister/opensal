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
        vconvert_cs32_zf32x_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( vconvert_cs32_zf32x_csal )(
    SAL_ci32 *A,
    SAL_i32 I,
    SAL_zf32 *C,
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
    ( void ) FLAG;

    SAL_i32    *Ap;
    SAL_f32  *Cr, *Ci;
    SAL_i32    i;
    SAL_f32  scale, bias;

    scale = SCALE ? *SCALE : 1.0;
    bias = BIAS ? *BIAS : 0.0;

    Ap = ( SAL_i32 * )A;
    Cr = C->realp;
    Ci = C->imagp;

    for ( i = 0; i < N; i++ )
    {
        *Cr  = ( scale * ( SAL_f32 ) ( *Ap ) ) + bias;
        *Ci  = ( scale * ( SAL_f32 ) ( *( Ap + 1 ) ) ) + bias;
        Ap += I;
        Cr += K;
        Ci += K;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
