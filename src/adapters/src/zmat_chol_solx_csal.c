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
        zmat_chol_solx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( zmat_chol_solx_csal )(
    SAL_zf32 *LDU,
    SAL_i32 LDUtcols,
    SAL_zf32 *b,
    SAL_zf32 *w,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_i32 i, j;
    SAL_f32 sumrp, sumip;
    SAL_f32 *LDUrp, *LDUip, *brp, *bip, *wrp, *wip, *yrp, *yip;

    ( void ) flag;
    ( void ) xflag;

    LDUrp = LDU->realp;
    LDUip = LDU->imagp;
    brp = b->realp;
    bip = b->imagp;
    wrp = w->realp;
    wip = w->imagp;

    PREFIX( _csal_malloc_mat_float )( &yrp, n, 1 );
    PREFIX( _csal_malloc_mat_float )( &yip, n, 1 );

    yrp[0] = brp[0];
    yip[0] = bip[0];

    for ( i = 1; i < n; i++ )
    {
        sumrp = brp[i];
        sumip = bip[i];

        for ( j = 0; j < i; j++ )
        {
            sumrp -= LDUrp[i * LDUtcols + j] * yrp[j]
                     - LDUip[i * LDUtcols + j] * yip[j];
            sumip -= LDUrp[i * LDUtcols + j] * yip[j]
                     + LDUip[i * LDUtcols + j] * yrp[j];
        }

        yrp[i] = sumrp;
        yip[i] = sumip;
    }

    wrp[n-1] = LDUrp[( n-1 )*LDUtcols + ( n-1 )] * yrp[n-1];
    wip[n-1] = LDUrp[( n-1 )*LDUtcols + ( n-1 )] * yip[n-1];

    for ( i = n - 2; i >= 0; i-- )
    {
        sumrp = LDUrp[i*LDUtcols + i] * yrp[i];
        sumip = LDUrp[i*LDUtcols + i] * yip[i];

        for ( j = i + 1; j < n; j++ )
        {
            sumrp -= LDUrp[i*LDUtcols + j] * wrp[j]
                     - LDUip[i*LDUtcols + j] * wip[j];
            sumip -= LDUrp[i*LDUtcols + j] * wip[j]
                     + LDUip[i*LDUtcols + j] * wrp[j];

        }

        wrp[i] = sumrp;
        wip[i] = sumip;
    }

    free( yip );
    free( yrp );

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
