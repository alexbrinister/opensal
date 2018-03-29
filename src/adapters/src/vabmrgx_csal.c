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
        vabmrgx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( vabmrgx_csal )(
    SAL_f32 *A,
    SAL_f32 *B,
    SAL_f32 *C,
    SAL_i32 F,
    SAL_i32 M,
    SAL_i32 NA,
    SAL_i32 NB,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    N, i, j, p, q, r;
    SAL_f32  a_cur, b_cur;

    if ( M == 0 )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
        goto ERROR_LABEL;
    }

    if ( NA == 0 )
    {
        for ( p = 0; p < NB; p++ )
        {
            for ( q = 0; q < M; q++ )
                *C++ = *B++;
        }

        goto ret;
    }

    if ( NB == 0 )
    {
        for ( p = 0; p < NA; p++ )
        {
            for ( q = 0; q < M; q++ )
                *C++ = *A++;
        }

        goto ret;
    }

    N = NA + NB;
    i = j = 0;
    a_cur = *( A + F );
    b_cur = *( B + F );

    for ( p = 0; p < N; p++ )
    {
        if ( a_cur >= b_cur )
        {
            for ( q = 0; q < M; q++ )
                *C++ = *A++;

            if ( ++i < NA )
                a_cur = *( A + F );
            else
            {
                for ( q = ( p + 1 ); q < N; q++ )
                {
                    for ( r = 0; r < M; r++ )
                        *C++ = *B++;
                }

                goto ret;
            }
        }
        else
        {
            for ( q = 0; q < M; q++ )
                *C++ = *B++;

            if ( ++j < NB )
                b_cur = *( B + F );
            else
            {
                for ( q = ( p + 1 ); q < N; q++ )
                {
                    for ( r = 0; r < M; r++ )
                        *C++ = *A++;
                }

                goto ret;
            }
        }
    }

ret:

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;

ERROR_LABEL:
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
