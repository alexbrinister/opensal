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
        cvsqrtx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( cvsqrtx_csal )(
    SAL_cf32 *c_A,
    SAL_i32 I,
    SAL_cf32 *c_C,
    SAL_i32 K,
    SAL_i32 N,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i;
    SAL_f64 q, root, posAr;
    SAL_f32  *A, *C, rsq, isq;

    A = ( SAL_f32 * ) c_A;
    C = ( SAL_f32 * ) c_C;

    for ( i = 0; i < N; i++ )
    {
        if ( ( *A == 0.0 ) && ( *( A + 1 ) == 0 ) )
        {
            *C = 0.0;
            *( C + 1 ) = 0.0;
        }
        else
        {
            rsq = *A * *A;
            isq = *( A + 1 ) * *( A + 1 );
            posAr = ( *A > 0 ) ? *A : -*A;

            root = sqrt( ( sqrt( rsq + isq ) + posAr ) / 2 );
            q = *( A + 1 ) / ( 2 * root );

            if ( *A >= 0 )
            {
                *C = root;
                *( C + 1 ) = q;
            }
            else
            {
                if ( *( A + 1 ) >= 0 )
                {
                    *C = q;
                    *( C + 1 ) = root;
                }
                else
                {
                    *C =  -q;
                    *( C + 1 ) =  -root;
                }
            }
        }

        A += I;
        C += K;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}