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
        cmat_lud_decx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"
#include "sal_csal_common_internal.h"

#define MODSQR( z )    ( (z).real*(z).real + (z).imag*(z).imag )
#define COMPLEX_ASSIGN( w, z ) \
    (w).real = (z).real; \
    (w).imag = (z).imag;

void PREFIX( cvnsmam )( SAL_cf32 *A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 Ctcols, SAL_i32 n, SAL_i32 m );

void PREFIX( cmat_lud_decx_csal )(
    SAL_cf32 *A,
    SAL_i32 Atcols,
    SAL_i32 *VPerm,
    SAL_i32 n,
    SAL_f32 *rcond_est,

    SAL_cf32 *v,

    SAL_i32 flag,

    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32 i, k;
    SAL_f32 max_elem_modsqr, temp_modsqr;
    SAL_cf32 max_elem, temp;
    SAL_i32 max_index;
    SAL_i32 tmpi;
    SAL_cf32 *B;

    if ( n < 2 )
    {
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS + 1 );
        return;
    }

    B = ( SAL_cf32 * ) malloc( ( size_t )( n * sizeof( SAL_cf32 ) ) );

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
            COMPLEX_ASSIGN( B[i], A[i*Atcols + k] )
        }

        COMPLEX_ASSIGN( max_elem, B[k] )
        max_index = k;

        for ( i = k + 1; i < n; i++ )
        {
            if ( MODSQR ( B[i] )
                 > MODSQR ( max_elem ) )
            {
                COMPLEX_ASSIGN( max_elem, B[i] )
                max_index = i;
            }
        }

        tmpi = VPerm[k];
        VPerm[k] = VPerm[max_index];
        VPerm[max_index] = tmpi;

        max_elem_modsqr = MODSQR ( max_elem );

        if ( max_elem_modsqr > 0.0 )
        {

            if ( max_index != k )
            {
                for ( i = 0; i < n; i++ )
                {
                    COMPLEX_ASSIGN( temp, A[k*Atcols + i] )
                    COMPLEX_ASSIGN( A[k*Atcols + i], A[max_index*Atcols + i] )
                    COMPLEX_ASSIGN( A[max_index*Atcols + i], temp )
                }

                COMPLEX_ASSIGN( temp, B[k] )
                COMPLEX_ASSIGN( B[k], B[max_index] )
                COMPLEX_ASSIGN( B[max_index], temp )
            }

            B[k].real = A[k*Atcols + k].real = max_elem.real / max_elem_modsqr;
            B[k].imag = A[k*Atcols + k].imag = -max_elem.imag / max_elem_modsqr;

            for ( i = k + 1; i < n; i++ )
            {
                temp.real = B[i].real * B[k].real - B[i].imag * B[k].imag;
                B[i].imag = B[i].real * B[k].imag + B[i].imag * B[k].real;
                B[i].real = temp.real;
                COMPLEX_ASSIGN( A[i*Atcols + k], B[i] )
            }

            if ( n - k - 1 > 0  &&  n - k - 1 > 0 )
            {
                PREFIX( cvnsmam )( &A[k*Atcols + k + 1], &B[k+1], &A[( k+1 )*Atcols + k + 1], Atcols, n - k - 1, n - k - 1 );
            }
        }

    }

    k = n - 1;

    temp_modsqr = MODSQR( A[k*Atcols + k] );

    if ( temp_modsqr > 0.0 )
    {
        A[k*Atcols + k].real = A[k*Atcols + k].real / temp_modsqr;
        A[k*Atcols + k].imag = -A[k*Atcols + k].imag / temp_modsqr;
    }

    free( B );

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    SAL_RINFO_SET_CODE( r_info, 0 );
    return;
}

void PREFIX( cvnsmam )( SAL_cf32 *A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 Ctcols, SAL_i32 n, SAL_i32 m )
{
    SAL_i32 i, j;

    for ( i = 0; i < m; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            C[i*Ctcols + j].real = -( A[j].real * B[i].real - A[j].imag * B[i].imag ) + C[i*Ctcols + j].real;
            C[i*Ctcols + j].imag = -( A[j].real * B[i].imag + A[j].imag * B[i].real ) + C[i*Ctcols + j].imag;
        }
    }

    return;
}
