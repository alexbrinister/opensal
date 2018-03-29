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
        bprojrowx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

#define  FRAC_BITS      16
#define  TWO_FRAC_BITS  65536.0

void PREFIX( bprojrowx_csal )(
    SAL_f32 *ROW_START,
    SAL_f32 *PROJECTION,
    SAL_i32 PROJ_NUM,
    SAL_i32 PROJ_SIZE,
    SAL_i32 ROW_COUNT,
    SAL_f32 *PROJ_START,
    SAL_f32 *PROJ_DELTA,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32   i, j;
    SAL_i32   delta, float_index, offset;
    SAL_f32 fdelta, fstart, proj_val, row_val;
    SAL_f32 *rowp;

    for ( i = 0; i < PROJ_NUM; i++ )
    {
        rowp = ( SAL_f32 * ) ROW_START;
        fstart = ( SAL_f32 ) TWO_FRAC_BITS * ( *PROJ_START );
        PROJ_START++;
        offset = PREFIX( _csal_fixr_ieee )( &fstart );
        fdelta = ( SAL_f32 ) TWO_FRAC_BITS * ( *PROJ_DELTA );
        PROJ_DELTA++;
        delta = PREFIX( _csal_fixr_ieee )( &fdelta );

        for ( j = 0; j < ROW_COUNT; j++ )
        {
            float_index = offset >> FRAC_BITS;
            proj_val = PROJECTION[float_index];
            row_val = *rowp;
            row_val += proj_val;
            *rowp++ = row_val;
            rowp++;
            offset += delta;
        }

        PROJECTION += PROJ_SIZE;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    return;
}
