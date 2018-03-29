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
        vamergx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( vamergx_csal )(
    SAL_f32 *A,
    SAL_i32 I,
    SAL_i32 NA,
    SAL_f32 *B,
    SAL_i32 J,
    SAL_i32 NB,
    SAL_f32 *C,
    SAL_i32 K,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    N, i, p, q;
    SAL_f32  a_cur, b_cur;

    C -= K;

    if ( NA == 0 )
    {
        B -= J;

        for ( p = 0; p < NB; p++ )
            *( C += K ) = *( B += J );

        goto ret;
    }

    if ( NB == 0 )
    {
        A -= I;

        for ( p = 0; p < NA; p++ )
            *( C += K ) = *( A += I );

        goto ret;
    }

    N = NA + NB;
    i = 0;
    a_cur = *A;
    b_cur = *B;

    for ( p = 0; p < N; p++ )
    {
        if ( a_cur >= b_cur )
        {
            *( C += K ) = a_cur;

            if ( ++i < NA )
                a_cur = *( A += I );
            else
            {
                *( C += K ) = b_cur;

                for ( q = ( p + 2 ); q < N; q++ )
                    *( C += K ) = *( B += J );

                goto ret;
            }
        }
        else
        {
            *( C += K ) = b_cur;

            if ( ++i < NB )
                b_cur = *( B += J );
            else
            {
                *( C += K ) = a_cur;

                for ( q = ( p + 2 ); q < N; q++ )
                    *( C += K ) = *( A += I );

                goto ret;
            }
        }
    }

ret:

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
