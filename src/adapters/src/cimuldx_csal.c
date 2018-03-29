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
        cimuldx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( cimuldx_csal )(
    SAL_cf64 *c_A,
    SAL_cf64 *c_B,
    SAL_cf64 *c_C,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_i32 F,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_f64 ar, ai, br, bi, cr, ci;
    SAL_i32    i, j, xoffset;
    SAL_f64 *A, *B, *C;

    A = ( SAL_f64 * ) c_A;
    B = ( SAL_f64 * ) c_B;
    C = ( SAL_f64 * ) c_C;

    xoffset = NC << 1;

    if ( F >= 0 )
    {
        for ( i = 0; i < 2; i++ )
        {
            ar = *( A++ );
            ai = *( A++ );
            br = *( B++ );
            bi = *( B++ );
            *( C++ ) = ar * br;
            *( C++ ) = ai * bi;

            for ( j = 1; j < NC; j++ )
            {
                ar = *( A++ );
                ai = *( A++ );
                br = *( B++ );
                bi = *( B++ );
                cr = ar * br;
                cr -= ( ai * bi );
                ci = ai * br;
                ci += ( ar * bi );
                *( C++ ) = cr;
                *( C++ ) = ci;
            }
        }

        for ( i = 2; i < NR; i++ )
        {
            if ( !( i & 1 ) )
            {
                for ( j = 0; j < 2; j++ )
                {
                    ar = *A;
                    ai = *( A++ + xoffset );
                    br = *B;
                    bi = *( B++ + xoffset );
                    cr = ar * br;
                    cr -= ( ai * bi );
                    ci = ai * br;
                    ci += ( ar * bi );
                    *C = cr;
                    *( C++ + xoffset ) = ci;
                }
            }

            else
            {
                A += 2;
                B += 2;
                C += 2;
            }

            for ( j = 1; j < NC; j++ )
            {
                ar = *( A++ );
                ai = *( A++ );
                br = *( B++ );
                bi = *( B++ );
                cr = ar * br;
                cr -= ( ai * bi );
                ci = ai * br;
                ci += ( ar * bi );
                *( C++ ) = cr;
                *( C++ ) = ci;
            }
        }
    }

    else
    {
        for ( i = 0; i < 2; i++ )
        {
            ar = *( A++ );
            ai = *( A++ );
            br = *( B++ );
            bi = *( B++ );
            cr = ar * br;
            ci = ai * bi;
            *( C++ ) = cr;
            *( C++ ) = ci;

            for ( j = 1; j < NC; j++ )
            {
                ar = *( A++ );
                ai = *( A++ );
                br = *( B++ );
                bi = *( B++ );
                cr = ar * br;
                cr += ( ai * bi );
                ci = ai * br;
                ci -= ( ar * bi );
                *( C++ ) = cr;
                *( C++ ) = ci;
            }
        }

        for ( i = 2; i < NR; i++ )
        {
            if ( !( i & 1 ) )
            {
                for ( j = 0; j < 2; j++ )
                {
                    ar = *A;
                    ai = *( A++ + xoffset );
                    br = *B;
                    bi = *( B++ + xoffset );
                    cr = ar * br;
                    cr += ( ai * bi );
                    ci = ai * br;
                    ci -= ( ar * bi );
                    *C = cr;
                    *( C++ + xoffset ) = ci;
                }
            }

            else
            {
                A += 2;
                B += 2;
                C += 2;
            }

            for ( j = 1; j < NC; j++ )
            {
                ar = *( A++ );
                ai = *( A++ );
                br = *( B++ );
                bi = *( B++ );
                cr = ar * br;
                cr += ( ai * bi );
                ci = ai * br;
                ci -= ( ar * bi );
                *( C++ ) = cr;
                *( C++ ) = ci;
            }
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
