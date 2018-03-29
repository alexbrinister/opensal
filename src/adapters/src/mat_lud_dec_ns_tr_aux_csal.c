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
        mat_lud_dec_ns_tr_aux_csal.c

----------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "csal_internal.h"

#define ABS( a )         ( ( (a) >= (0) ) ? (a) : -(a) )
#define MIN( a, b ) (((a) < (b)) ? (a) : (b))

SAL_i32 PREFIX( mat_lud_dec_ns_tr )(
    SAL_f32 *CTp,
    SAL_i32 Tcc,
    SAL_f32 *Bp,
    SAL_i32 *Vpivp,
    SAL_i32 *ICp,
    SAL_i32 Nc,
    SAL_i32 Nr )
{
    SAL_i32 i, k, klimit;
    SAL_f32 max_elem;
    SAL_i32 max_index;
    SAL_i32 tmpi;
    SAL_f32 *Tp;

    for ( i = 0; i < Nr; i++ )
    {
        ICp[i] = i;
    }

    klimit = MIN( Nc, Nr - 1 );

    for ( k = 0; k < klimit ; k++ )
    {
        Tp = &CTp[k*Tcc];

        PREFIX( maxmgvix )( Tp + k, 1, &max_elem, &max_index, Nr - k, 0 );
        max_index = max_index + k;
        max_elem = Tp[max_index];

        Vpivp[k] = max_index;
        tmpi = ICp[k];
        ICp[k] = ICp[max_index];
        ICp[max_index] = tmpi;

        if ( ABS( max_elem ) > 0.0 )
        {
#if 1
            PREFIX( swap_cols )( CTp + k, CTp + max_index, Tcc, Nc );
#else

            if ( max_index != k )
            {
                for ( i = 0; i < Nc; i++ )
                {
                    temp = CTp[i*Tcc + k];
                    CTp[i*Tcc + k] = CTp[i*Tcc + max_index];
                    CTp[i*Tcc + max_index] = temp;
                }
            }

#endif

            if ( max_elem == 0.0 )
            {
                SAL_SET_PATH_CSAL();
                return( SAL_SUCCESS + 2 );
            }
            else
            {
                Tp[k] = 1.0 / max_elem;
            }

            PREFIX( vsmulx )( &Tp[k+1], 1, &Tp[k], &Tp[k+1], 1, Nr - k - 1, SAL_CC );

            if ( Nc - k - 1 > 0  &&  Nr - k - 1 > 0 )
            {
                for ( i = k + 1; i < Nc; i++ )
                {
                    Bp[i] = CTp[i*Tcc + k];

                }

                PREFIX( vnsmam4lud )( &Tp[k+1], &Bp[k+1], 1, &CTp[( k+1 )*Tcc + k + 1], Tcc, Nr - k - 1, Nc - k - 1 );
            }
        }

    }

    if ( Nr <= Nc )
    {
        k = Nr - 1;

        if ( CTp[k*Tcc + k] == 0.0 )
        {
            SAL_SET_PATH_CSAL();
            return( SAL_SUCCESS + 2 );
        }
        else
        {
            CTp[k*Tcc + k] = 1.0 / CTp[k*Tcc + k];
        }

    }

    SAL_SET_PATH_CSAL();
    return( SAL_SUCCESS );
}

void PREFIX( vnsmam4lud )( SAL_f32 *A, SAL_f32 *B, SAL_i32 bstride, SAL_f32 *C, SAL_i32 Ctcols, SAL_i32 n, SAL_i32 m )
{
    SAL_i32 i, j;
    SAL_f32 Bneg;

    ( void ) j;

    for ( i = 0; i < m; i++ )
    {
        Bneg = -B[i*bstride];
        vsmax( A, 1, &Bneg, &C[i*Ctcols], 1, &C[i*Ctcols], 1, n, SAL_NNN );
    }

    SAL_SET_PATH_CSAL();

    return;
}

void PREFIX( swap_cols )( SAL_f32 *col0, SAL_f32 *col1, SAL_i32 tcols, SAL_i32 nrows )
{
    SAL_i32 i;
    SAL_f32 temp;

    if ( col0 != col1 )
    {
        for ( i = 0; i < nrows; i++ )
        {
            temp = col0[i*tcols];
            col0[i*tcols] = col1[i*tcols];
            col1[i*tcols] = temp;
        }
    }

    return;
}
