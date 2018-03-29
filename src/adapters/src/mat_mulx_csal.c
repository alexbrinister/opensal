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
        mat_mulx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "mat_mulx_aux_csal.h"

void PREFIX( mat_mulx_csal )(
    SAL_f32 *pA,
    SAL_i32 Atcols,
    SAL_f32 *pB,
    SAL_i32 Btcols,
    SAL_f32 *pC,
    SAL_i32 Ctcols,
    SAL_i32 nr_c,
    SAL_i32 nc_c,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_i32 rc;

    switch ( flag & SAL__MASK_TRANSPOSE )
    {
        case ( SAL_TRANSPOSE_LEFT | SAL_TRANSPOSE_RIGHT ):
            rc = PREFIX( mat_mul_tt )( pA,
                                       Atcols,
                                       pB,
                                       Btcols,
                                       pC,
                                       Ctcols,
                                       nr_c,
                                       nc_c,
                                       N,
                                       flag,
                                       xflag );
            break;
        case SAL_TRANSPOSE_LEFT:
            rc = PREFIX( mat_mul_tn )( pA,
                                       Atcols,
                                       pB,
                                       Btcols,
                                       pC,
                                       Ctcols,
                                       nr_c,
                                       nc_c,
                                       N,
                                       flag,
                                       xflag );
            break;
        case SAL_TRANSPOSE_RIGHT:
            rc = PREFIX( mat_mul_nt )( pA,
                                       Atcols,
                                       pB,
                                       Btcols,
                                       pC,
                                       Ctcols,
                                       nr_c,
                                       nc_c,
                                       N,
                                       flag,
                                       xflag );
            break;
        default:
            rc = PREFIX( mat_mul_nn )( pA,
                                       Atcols,
                                       pB,
                                       Btcols,
                                       pC,
                                       Ctcols,
                                       nr_c,
                                       nc_c,
                                       N,
                                       flag,
                                       xflag );
            break;
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    SAL_RINFO_SET_CODE( r_info, rc );
    return;
}
