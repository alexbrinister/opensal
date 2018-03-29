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
        vscaldx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

#if (BIGENDIAN == 1)

#define LOW 1
#define HIGH 0

#else

#define LOW 0
#define HIGH 1

#endif

void PREFIX( vscaldx_csal )(
    SAL_f64 *A,
    SAL_i32 I,
    SAL_f64 *d_B,
    SAL_i32 *C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 NB,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    e, i, itemp[2], m;
    SAL_f64 power;
    SAL_i32    *B;

    SAL_un_64 un_64;

    B = ( SAL_i32 * ) ( ( void * ) d_B );

    e = *( B + HIGH );
    e = ( e & 0x7ff00000 ) >> 20;
    e = e - 1022;
    m = NB - e - 1;
    itemp[HIGH] = ( m + 1023 ) << 20;
    itemp[LOW] = 0;
    un_64.m_s32[LOW] = itemp[LOW];
    un_64.m_s32[HIGH] = itemp[HIGH];
    power = un_64.m_f64;

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
