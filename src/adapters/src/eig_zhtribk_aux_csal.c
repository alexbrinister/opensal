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
        eig_zhtribk_aux_csal.c

----------------------------------------------------------------------------
*/

#include <math.h>
#include "csal_internal.h"

void PREFIX( _csal_zhtribk )( SAL_zf32 *A,
                              SAL_zf32 *Z,
                              SAL_f32 *Tau,
                              SAL_i32 Atcols,
                              SAL_i32 Ztcols,
                              SAL_i32 N )
{
    SAL_f32 h, sr, si;
    SAL_i32 i, j, k;
    SAL_f32 *Zjre, *Zjim, *Tauim, *Are, *Aim;

    Tauim = Tau + N;

    Zjre = Z->realp;
    Zjim = Z->imagp;

    for ( j = 0; j < N; j++ )
    {
        for ( k = 0; k < N; k++ )
        {
            Zjim[ k ] = -Zjre[ k ] * Tauim[ k ];
            Zjre[ k ] = Zjre[ k ] * Tau[ k ];
        }

        Zjim += Ztcols;
        Zjre += Ztcols;
    }

    Are = A->realp;
    Aim = A->imagp;

    for ( i = 1; i < N; i++ )
    {
        Aim += Atcols;
        Are += Atcols;
        h = Aim[ i ];

        Zjre = Z->realp;
        Zjim = Z->imagp;

        if ( h != 0. )
        {
            for ( j = 0; j < N; j++ )
            {
                sr = 0.;
                si = 0.;

                for ( k = 0; k < i; k++ )
                {
                    sr += ( Are[ k ] * Zjre[ k ] - Aim[ k ] * Zjim[ k ] );
                    si += ( Are[ k ] * Zjim[ k ] + Aim[ k ] * Zjre[ k ] );
                }

                sr = sr / h / h;
                si = si / h / h;

                for ( k = 0; k < i; k++ )
                {
                    Zjre[ k ] -= ( sr * Are[ k ] + si * Aim[ k ] );
                    Zjim[ k ] -= ( si * Are[ k ] - sr * Aim[ k ] );
                }

                Zjre += Ztcols;
                Zjim += Ztcols;
            }
        }
    }
}
