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
        zmat_chol_decx_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zmat_chol_decx_csal )(
    SAL_zf32 *A,
    SAL_i32 Atcols,
    SAL_zf32 *LDU,
    SAL_i32 LDUtcols,
    SAL_i32 n,
    SAL_f32 *rcond_est,
    SAL_zf32 *v,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_f32  *Arp, *Aip, *LDUrp, *LDUip;
    SAL_f32  tr, ti;
    SAL_i32  i, j, k;
    ( void ) xflag;

    Arp = A->realp;
    Aip = A->imagp;
    LDUrp = LDU->realp;
    LDUip = LDU->imagp;

    if ( n < 2 )
    {
        if ( n == 1 )
        {
            LDUrp[ 0 ] = ( SAL_f32 )1.0 / Arp[ 0 ];
            LDUip[ 0 ] = 0.0;

            SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
            SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
            return;
        }
        else
        {
            SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
            SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS + 1 );
            return;
        }
    }

    for ( i = 0; i < n; i++ )
    {
        LDUrp[0] = 1.0 / Arp[0];
        LDUip[0] = 0.0;

        for ( j = 1; j < ( n - i ); j++ )
        {
            LDUrp[j*LDUtcols] = Arp[j];
            LDUip[j*LDUtcols] = Aip[j];
            LDUrp[j] = Arp[j] * LDUrp[0];
            LDUip[j] = Aip[j] * LDUrp[0];
        }

        for ( j = 1; j < ( n - i ); j++ )
        {
            for ( k = j; k < ( n - i ); k++ )
            {
                tr = LDUrp[j*LDUtcols] * LDUrp[k] + LDUip[j*LDUtcols] * LDUip[k];
                ti = LDUrp[j*LDUtcols] * LDUip[k] - LDUip[j*LDUtcols] * LDUrp[k];
                LDUrp[j*LDUtcols + k] = Arp[j*Atcols + k] - tr;
                LDUip[j*LDUtcols + k] = Aip[j*Atcols + k] - ti;
            }

            LDUrp[j*LDUtcols] = LDUrp[j];
            LDUip[j*LDUtcols] = -LDUip[j];
        }

        LDUrp += ( LDUtcols + 1 );
        LDUip += ( LDUtcols + 1 );
        Arp = LDUrp;
        Aip = LDUip;
        Atcols = LDUtcols;
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
