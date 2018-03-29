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
        wienerx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( wienerx_csal )(
    SAL_i32 L,
    SAL_f32 *A,
    SAL_f32 *C,
    SAL_f32 *F,
    SAL_f32 *P,
    SAL_i32 IFLG,
    SAL_i32 *IERR,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_f32 V, D, Q;
    SAL_f32 HOLD;
    SAL_i32 L0, L1, L2, L3, J, K, I;

    ( void )IFLG;

    *IERR = 0;

    V = *( A + 0 );
    D = *( A + 1 );
    *( P + 0 ) = 1;
    *( F + 0 ) = *( C + 0 ) / V;
    Q = ( *( F + 0 ) ) * ( *( A + 1 ) );

    if ( L == 1 )
        goto ret;

    for ( L0 = 1; L0 < L; L0++ )
    {
        *( P + L0 ) = -D / V;

        if ( L0 != 1 )
        {
            L1 = ( L0 - 1 ) / 2;
            L2 = L1 + 1;

            if ( L2 > 1 )
            {
                for ( J = 1; J < L2; J++ )
                {
                    HOLD = *( P + J );
                    K = L0 - J;
                    *( P + J ) = *( P + J ) + ( *( P + L0 ) ) * ( *( P + K ) );
                    *( P + K ) = *( P + K ) + ( *( P + L0 ) ) * ( HOLD );
                }
            }

            if ( ( 2*L1 ) != ( L0 - 1 ) )
            {
                *( P + L2 + 0 ) = *( P + L2 + 0 ) + ( *( P + L0 ) ) * ( *( P + L2 + 0 ) );
            }
        }

        V = V + ( *( P + L0 ) ) * D;
        *( F + L0 ) = ( ( *( C + L0 ) ) - Q ) / V;
        L3 = L0 - 1;

        for ( J = 0; J <= L3; J++ )
        {
            K = L0 - J;
            *( F + J ) = *( F + J ) + ( *( F + L0 ) ) * ( *( P + K ) );
        }

        if ( L0 + 1 == L )
            goto ret;

        D = 0.0;
        Q = 0.0;

        for ( I = 0; I <= L0; I++ )
        {
            K = L0 - I + 1;
            D = D + ( *( P + I ) ) * ( *( A + K ) );
            Q = Q + ( *( F + I ) ) * ( *( A + K ) );
        }
    }

ret:

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
