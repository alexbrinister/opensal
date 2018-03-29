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
        vscalx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( vscalx_csal )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_f32 *r_B,
    SAL_i32 *C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 NB,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    e, i, itemp, m;
    SAL_f32  power;
    SAL_i32    *B;

    SAL_un_32 un_32;

    B = ( SAL_i32 * ) ( ( void * ) r_B );

    e = *B;
    e = ( e & 0x7f800000 ) >> 23;
    e = e - 126;
    m = NB - e - 1;
    itemp = ( m + 127 ) << 23;
    un_32.m_s32 = itemp;
    power = un_32.m_f32;

    for ( i = 0; i < N; i++ )
    {
        *C = ( SAL_i32 ) ( ( *A ) * power );
        A += I;
        C += K;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
