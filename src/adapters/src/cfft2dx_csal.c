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
        cfft2dx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_fft_internal.h"

void PREFIX( cfft2dx_csal )(
    SAL_cf32 *c_c,
    SAL_i32 nc,
    SAL_i32 nr,
    SAL_i32 f,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i;
    SAL_f32 *rowp, *colp;
    SAL_f32 *c;

    c = ( SAL_f32 * ) c_c;

    if ( f >= 0 )
    {
        rowp = c;

        for ( i = 0; i < nr; i++ )
        {
            PREFIX( _csal_cfftsm )( rowp, 2, nc, f, 1 );
            rowp += nc;
            rowp += nc;
        }

        colp = c;

        for ( i = 0; i < nc; i++ )
        {
            PREFIX( _csal_cfftsm )( colp, ( nc << 1 ), nr, f, 1 );
            colp += 2;
        }
    }

    else
    {
        colp = c;

        for ( i = 0; i < nc; i++ )
        {
            PREFIX( _csal_cfftsm )( colp, ( nc << 1 ), nr, f, 1 );
            colp += 2;
        }

        rowp = c;

        for ( i = 0; i < nr; i++ )
        {
            PREFIX( _csal_cfftsm )( rowp, 2, nc, f, 1 );
            rowp += nc;
            rowp += nc;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
