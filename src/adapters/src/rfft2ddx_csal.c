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
        rfft2ddx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_fft_internal.h"

void PREFIX( rfft2ddx_csal )(
    SAL_f64 *c,
    SAL_i32 nc,
    SAL_i32 nr,
    SAL_i32 f,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i, j, k;
    SAL_f64 *tptr, *rowp, *colp;
    SAL_f64  half, val;

    tptr = malloc( ( unsigned long )( nr << 2 ) );

    if ( f >= 0 )
    {
        rowp = c;

        for ( i = 0; i < nr; i++ )
        {
            PREFIX( rfftd )( rowp, nc, f );
            rowp += nc;
        }

        colp = c + 2;

        for ( i = 0; i < ( nc >> 1 ) - 1; i++ )
        {
            PREFIX( _csal_cfftsmd )( colp, nc, nr, f, 1 );
            colp += 2;
        }

        half = 0.5;
        colp = c;

        for ( i = 0; i < 2; i++ )
        {
            k = 0;

            for ( j = 0; j < nr; j++ )
            {
                tptr[j] = colp[k];
                k += nc;
            }

            PREFIX( rfftd )( tptr, nr, f );
            k = 0;

            for ( j = 0; j < nr; j++ )
            {
                val = half * tptr[j];
                colp[k] = val;
                k += nc;
            }

            colp += 1;
        }
    }

    else
    {
        colp = c;

        for ( i = 0; i < 2; i++ )
        {
            k = 0;

            for ( j = 0; j < nr; j++ )
            {
                tptr[j] = colp[k];
                k += nc;
            }

            PREFIX( rfftd )( tptr, nr, f );
            k = 0;

            for ( j = 0; j < nr; j++ )
            {
                colp[k] = tptr[j];
                k += nc;
            }

            colp += 1;
        }

        colp = c + 2;

        for ( i = 0; i < ( nc >> 1 ) - 1; i++ )
        {
            PREFIX( _csal_cfftsmd )( colp, nc, nr, f, 1 );
            colp += 2;
        }

        rowp = c;

        for ( i = 0; i < nr; i++ )
        {
            PREFIX( rfftd )( rowp, nc, f );
            rowp += nc;
        }
    }

    free( tptr );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
