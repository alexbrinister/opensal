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
        mat_lud_decx_csal.c

----------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sal_internal.h"
#include "adapters.h"

#define ABS( a )         ( ( (a) >= (0) ) ? (a) : -(a) )

void PREFIX( vnsmam )( SAL_f32 *A, SAL_f32 *B, SAL_i32 bstride, SAL_f32 *C, SAL_i32 Ctcols, SAL_i32 n, SAL_i32 m );

void PREFIX( mat_lud_decx_csal )(
    SAL_f32 *A,
    SAL_i32 Atcols,
    SAL_i32 *VPerm,
    SAL_i32 n,
    SAL_f32 *rcond_est,

    SAL_f32 *v,

    SAL_i32 flag,

    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32 i, k;
    SAL_f32 max_elem, temp;
    SAL_i32 max_index;
    SAL_i32 tmpi;

    SAL_f32 *B;

    if ( n < 2 )
    {
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS + 1 );
        return;
    }

    B = ( SAL_f32 * ) malloc( ( size_t )( n * sizeof( SAL_f32 ) ) );

    if ( !B )
    {
        printf( "*** malloc failed for B\n" );
        exit( 1 );
    }

    for ( i = 0; i < n; i++ )
    {
        VPerm[i] = i;
    }

    for ( k = 0; k < n - 1 ; k++ )
    {

        for ( i = k; i < n; i++ )
        {
            B[i] = A[i*Atcols + k];
        }

        max_elem = B[k];
        max_index = k;

        for ( i = k + 1; i < n; i++ )
        {
            if ( ABS( B[i] ) > ABS( max_elem ) )
            {
                max_elem = B[i];
                max_index = i;
            }
        }

        tmpi = VPerm[k];
        VPerm[k] = VPerm[max_index];
        VPerm[max_index] = tmpi;

        if ( ABS( max_elem ) > 0.0 )
        {

            if ( max_index != k )
            {
                for ( i = 0; i < n; i++ )
                {
                    temp = A[k*Atcols + i];
                    A[k*Atcols + i] = A[max_index*Atcols + i];
                    A[max_index*Atcols + i] = temp;
                }

                temp = B[k];
                B[k] = B[max_index];
                B[max_index] = temp;
            }

            B[k] = A[k*Atcols + k] = 1.0 / max_elem;

            for ( i = k + 1; i < n; i++ )
            {
                B[i] *= B[k];
                A[i*Atcols + k] = B[i];
            }

            if ( n - k - 1 > 0  &&  n - k - 1 > 0 )
            {
                PREFIX( vnsmam )( &A[k*Atcols + k + 1], &B[k+1], 1, &A[( k+1 )*Atcols + k + 1], Atcols, n - k - 1, n - k - 1 );
            }
        }

    }

    k = n - 1;

    if ( A[k*Atcols + k] != 0.0 )
    {
        A[k*Atcols + k] = 1.0 / A[k*Atcols + k];
    }

    free( B );

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    SAL_RINFO_SET_CODE( r_info, 0 );
    return;
}

void PREFIX( vnsmam )( SAL_f32 *A, SAL_f32 *B, SAL_i32 bstride, SAL_f32 *C, SAL_i32 Ctcols, SAL_i32 n, SAL_i32 m )
{
    SAL_i32 i, j;

    for ( i = 0; i < m; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            C[i*Ctcols + j] = -A[j] * B[i*bstride] + C[i*Ctcols + j];
        }
    }

    return;
}
