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
        vsimpsx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( vsimpsx_csal )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_f32 *S,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32   i;
    SAL_f32 scale, Aprev1, Aprev2, Cprev1, Cprev2;

    if ( N == 0 )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        return;
    }

    *C = Cprev2 = 0.0;

    if ( N == 1 )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        return;
    }

    scale = ( ( SAL_f32 ) 0.333333333 ) * ( *S );

    Aprev2 = *A;
    A += I;
    Aprev1 = *A;

    Cprev1 = ( Aprev2 + Aprev1 ) * ( *S ) * 0.5;
    C += I;
    *C = Cprev1;

    for ( i = 2; i < N; i++ )
    {
        A += I;
        C += K;
        *C = ( 4.0 * Aprev1 ) + Aprev2;
        *C += *A;
        *C *= scale;
        *C += Cprev2;

        Aprev2 = Aprev1;
        Aprev1 = *A;
        Cprev2 = Cprev1;
        Cprev1 = *C;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
