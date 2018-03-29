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
        medfdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( medfdx_csal )(
    SAL_f64 *A,
    SAL_i32 I,
    SAL_f64 *C,
    SAL_i32 N,
    SAL_i32 P,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32     i, j, k, q;
    SAL_f64  *ap, *med_ptr, *med_tab;
    SAL_f64   new, old;

    if ( ( N == 0 ) || ( P == 0 ) )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
        goto ERROR_LABEL;
    }

    med_tab = malloc( ( unsigned long )( P << 3 ) );

    if ( !med_tab )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
        goto ERROR_LABEL;
    }

    med_ptr = med_tab + ( P >> 1 );

    if ( I == 1 )
    {
        ap = A;

        for ( q = 0; q < P; q++ )
            med_tab[q] = *ap++;

        PREFIX( _csal_heap_sortd )( med_tab, P );
        old = *A;
        *C++ = *med_ptr;

        for ( i = 1; i < N; i++ )
        {
            new = A[P];

            for ( j = 0; j < P; j++ )
            {
                if ( old == med_tab[j] )
                    break;
            }

            for ( k = 0; k < P; k++ )
            {
                if ( new <= med_tab[k] )
                    break;
            }

            if ( j > k )
            {
                for ( q = j; q > k; q-- )
                    med_tab[q] = med_tab[q-1];
            }
            else if ( j < k )
            {
                --k;

                for ( q = j; q < k; q++ )
                    med_tab[q] = med_tab[q+1];
            }

            med_tab[k] = new;
            old = *++A;
            *C++ = *med_ptr;
        }
    }

    else
    {
        for ( i = 0; i < N; i++ )
        {
            ap = A;

            for ( q = 0; q < P; q++ )
                med_tab[q] = *ap++;

            PREFIX( _csal_heap_sortd )( med_tab, P );
            *C++ = *med_ptr;
            A += I;
        }
    }

    free( med_tab );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;

ERROR_LABEL:
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
