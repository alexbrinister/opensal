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
        eig_zhtridi_aux_csal.c

----------------------------------------------------------------------------
*/

#include <math.h>
#include "csal_internal.h"

void PREFIX( _csal_zhtridi )( SAL_zf32 *A,
                              SAL_i32 Atcols,
                              SAL_f32 *D,
                              SAL_f32 *E,
                              SAL_f32 *Tau,
                              SAL_i32 N )
{
    SAL_f32 f, g, h, hh, si, scale;
    SAL_f32 gi;
    SAL_f32 fi;
    SAL_f32 *Are, *Aim;
    SAL_f32 *Aire, *Aiim;
    SAL_f32 *Ajre, *Ajim;
    SAL_f32 *Akre, *Akim;
    SAL_f32 *Ajresav, *Ajimsav;

    SAL_i32 i, id;
    SAL_i32 k;
    SAL_i32 j, l;

    SAL_f32 *Tauim;

    Tauim = Tau + N;
    i = N - 1;

    Are = A->realp;
    Aim = A->imagp;

    Tau[ i ] = 1.;
    Tauim[ i ] = 0.;

    for ( id = 0; id < N; id++ ) D[id] = Are[ id * ( Atcols + 1 )];

    Aire = Are + i * Atcols;
    Aiim = Aim + i * Atcols;

    for ( ; i >= 0; i-- )
    {
        l = i - 1;

        h = 0.;
        scale = 0.;

        if ( l < 0 ) goto br_130;

        for ( k = 0; k < i; k++ )
            scale += ( fabs( Are[i * Atcols + k] ) + fabs( Aim[i * Atcols + k] ) );

        if ( !scale )
        {
            Tau[ l ] = 1.;
            Tauim[ l ] = 0.;

br_130:
            E[ i ] = 0.;
            hh = D[ i ];
            D[ i ] = Aire[ i * Atcols + i ];

            Aire[ i ] = hh;

            Aiim[ i ] = scale * sqrt( h );
            continue;
        }

        for ( k = 0; k < i; k++ )
        {
            Aire[ k ] /= scale;
            Aiim[ k ] /= scale;
            h += Aire[ k ] * Aire[ k ] + Aiim[ k ] * Aiim[ k ];
        }

        g = sqrt( h );
        E[ i ] = scale * g;

        f = sqrt( Aire[ l ] * Aire[ l ] + Aiim[ l ] * Aiim[ l ] );

        if ( f == 0. )
        {
            Tau[ l ] = -Tau[ i ];
            si = Tauim[ i ];
            Aire[ l ] = g;
        }

        else
        {
            Tau[ l ] = ( Aiim[ l ] * Tauim[ i ] - Aire[ l ] * Tau[ i ] ) / f;
            si = ( Aire[ l ] * Tauim[ i ] + Aiim[ l ] * Tau[ i ] ) / f;

            h += f * g;
            g = 1. + g / f;

            Aire[ l ] *= g;
            Aiim[ l ] *= g;

            if ( l == 0 ) goto br_270;

        }

        f = 0.;

        Ajre = A->realp;
        Ajim = A->imagp;

        Ajresav = Ajre;
        Ajimsav = Ajim;

        for ( j = 0; j < i; j++ )
        {
            g = 0.;
            gi = 0.;

            for ( k = 0; k <= j; k++ )
            {
                g += ( Ajre[ k ] * Aire[ k ] + Ajim[ k ] * Aiim[ k ] );
                gi -= ( Ajre[ k ] * Aiim[ k ] - Ajim[ k ] * Aire[ k ] );
            }

            Akre = Ajre + Atcols;
            Akim = Ajim + Atcols;

            for ( k = j + 1; k < i; k++ )
            {
                g += ( Akre[ j ] * Aire[ k ] - Akim[ j ] * Aiim[ k ] );
                gi -= ( Akre[ j ] * Aiim[ k ] + Akim[ j ] * Aire[ k ] );
                Akre += Atcols;
                Akim += Atcols;
            }

            E[ j ] = g / h;
            Tauim[ j ] = gi / h;
            Ajresav += Atcols;
            Ajimsav += Atcols;

            f += ( E[ j ] * Aire[ j ] - Tauim[ j ] * Aiim[ j ] );
            Ajre = Ajresav;
            Ajim = Ajimsav;
        }

        hh = f / ( h + h );
        Ajre = A->realp;
        Ajim = A->imagp;

        for ( j = 0; j < i; j++ )
        {
            fi = -Aiim[ j ];
            f = Aire[ j ];
            gi = Tauim[ j ] - hh * fi;
            g = E[ j ] - hh * f;
            Tauim[ j ] = -gi;
            E[ j ] = g;

            for ( k = 0; k <= j; k++ )
            {
                Ajre[ k ] -= ( f * E[ k ] + g * Aire[ k ] -
                               fi * Tauim[ k ] - gi * Aiim[ k ] );
                Ajim[ k ] -= ( f * Tauim[ k ] + g * Aiim[ k ] +
                               fi * E[ k ] + gi * Aire[ k ] );
            }

            Ajre += Atcols;
            Ajim += Atcols;
        }

br_270:

        for ( k = 0; k < i; k++ )
        {
            Aire[ k ] *= scale;
            Aiim[ k ] *= scale;
        }

        Tauim[ l ] = -si;

        hh = D[ i ];
        D[ i ] = Aire[ i ];
        Aire[ i ] = hh;
        Aire -= Atcols;
        Aiim[ i ] = scale * sqrt( h );
        Aiim -= Atcols;
    }
}
