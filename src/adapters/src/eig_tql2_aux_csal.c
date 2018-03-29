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
        eig_tql2_aux_csal.c

----------------------------------------------------------------------------
*/

#include <math.h>
#include "csal_internal.h"

#define SIGN(a,b) ((b)<0 ? -fabs(a) : fabs(a))

SAL_i32 PREFIX( _csal_tql2 )( SAL_f32 *D, SAL_f32 *E, SAL_f32 *Zre, SAL_i32 Ztcols, SAL_i32 N )
{
    SAL_f32 c, c2, c3, dl1, el1, f, g, h, p, r, s, s2, tst1, tst2;
    SAL_i32 i, j, k, l, m, ii, l1, l2, mml, IERR;

    SAL_f32 *Zretmp, *Zr, *Zr1;

    IERR = SAL_SUCCESS;

    c3 = 0.0;
    s2 = 0.0;

    if ( Zre )
    {
        Zretmp = Zre;

        for ( i = 0; i < N; i++ )
        {
            for ( j = 0; j < N; j++ )
            {
                Zretmp[ j ]  = 0.;
            }

            Zretmp[ i ] = 1.;
            Zretmp += Ztcols;
        }
    }

    for ( i = 1; i < N; i++ ) E[i-1] = E[i];

    E[ N - 1 ] = 0.;

    f = 0.;
    tst1 = 0.;

    for ( l = 0; l < N; l++ )
    {
        j = 30;

        h = fabs( D[ l ] ) + fabs( E[ l ] );

        if ( tst1 < h ) tst1 = h;

        m = l - 1;

        do
        {
            tst2 = tst1 + fabs( E[ ++m ] );
        }
        while ( tst2 != tst1 );

        if ( m == l ) goto br_220;

br_130:

        if ( !j )
        {
            IERR = SAL_SUCCESS + 1;
            goto br_1000;
        }

        l1 = l + 1;
        l2 = l + 2;

        g = D[ l ];
        p = ( D[ l1 ] - g ) / ( 2. * E[ l ] );

        r = sqrt( p * p + 1. );

        D[ l ] = E[ l ] / ( p + SIGN( r, p ) );
        dl1 = E[ l ] * ( p + SIGN( r, p ) );
        h = g - D[ l ];
        D[ l1 ] =  dl1;

        for ( i = l2; i < N; i++ ) D[ i ] -= h;

        f += h;
        p = D[ m ];
        c = 1.;
        el1 = E[ l1 ];
        c2 = 1.;
        s = 0.;
        mml = m - l;

        i = m;

        for ( ii = 0; ii < mml; ii++ )
        {
            i--;
            s2 = s;
            c3 = c2;
            h = c * p;
            c2 = c;
            g = c * E[ i ];
            r = sqrt( p * p + E[ i ] * E[ i ] );

            E[i+1] = s * r;
            s = E[ i ] / r;
            c = p / r;

            p = c * D[ i ] - s * g;

            D[ i + 1 ] = h + s * ( c * g + s * D[ i ] );

            if ( Zre )
            {
                Zr = Zre + i * Ztcols;
                Zr1 = Zr + Ztcols;

                for ( k = 0; k < N; k++ )
                {
                    h = Zr1[ k ];
                    Zr1[ k ] = s * Zr[ k ] + c * h;
                    Zr[ k ] = c * Zr[ k ] - s * h;
                }
            }
        }

        p = -s * s2 * c3 * el1 * E[ l ] / dl1;
        E[ l ] = s * p;
        D[ l ] = c * p;

        tst2 = tst1 +  fabs( E[ l ] );
        --j;

        if ( tst2 > tst1 ) goto br_130;

br_220:
        D[ l ] += f;
    }

br_1000:
    return( IERR );
}
