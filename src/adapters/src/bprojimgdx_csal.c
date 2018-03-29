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
        bprojimgdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "bprojimgdx_aux_csal.h"

void PREFIX( bprojimgdx_csal )(
    SAL_f64 *PROJECTION,
    SAL_f64 *IMAGE,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_i32 *ROW_START,
    SAL_i32 *ROW_COUNT,
    SAL_f64 *PROJ_START,
    SAL_f64 *PROJ_DELTA,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i;
    SAL_f64 *rowp;

    for ( i = 0; i < NR; i++ )
    {
        if ( ROW_COUNT[i] )
        {
            rowp = IMAGE + ROW_START[i];
            PREFIX( _csal_rhvbpd )( ROW_COUNT[i], &PROJ_START[i],
                                    PROJ_DELTA, PROJECTION, rowp );
        }

        IMAGE += NC;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
