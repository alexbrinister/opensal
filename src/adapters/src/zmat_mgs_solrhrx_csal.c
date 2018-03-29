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
        zmat_mgs_solrhrx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zmat_mgs_solrhrx_csal )(
    SAL_zf32 *R,
    SAL_i32 R_tcols,
    SAL_zf32 *B,
    SAL_zf32 *X,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_i32 i, j;
    SAL_f32 sumrp, sumip;
    SAL_f32 *Rrp, *Rip, *Brp, *Bip, *Xrp, *Xip;

    ( void ) xflag;

    Rrp = R->realp;
    Rip = R->imagp;
    Brp = B->realp;
    Bip = B->imagp;
    Xrp = X->realp;
    Xip = X->imagp;

    if ( flag == SAL_TRANSPOSE_SOLVER )
    {
        for ( i = n - 1; i >= 0; i-- )
        {
            sumrp = Brp[i];
            sumip = Bip[i];

            for ( j = i + 1; j < n; j++ )
            {
                sumrp -= Rrp[i * R_tcols + j] * Xrp[j] - Rip[i * R_tcols + j] * Xip[j];
                sumip -= Rrp[i * R_tcols + j] * Xip[j] + Rip[i * R_tcols + j] * Xrp[j];
            }

            Xrp[i] = sumrp * Rrp[i * R_tcols + i];
            Xip[i] = sumip * Rrp[i * R_tcols + i];

        }

        for ( i = 0; i < n; i++ )
        {
            sumrp = Xrp[i];
            sumip = Xip[i];

            for ( j = 0; j < i; j++ )
            {
                sumrp -= Rrp[j * R_tcols + i] * Xrp[j] + Rip[j * R_tcols + i] * Xip[j];
                sumip -= Rrp[j * R_tcols + i] * Xip[j] - Rip[j * R_tcols + i] * Xrp[j];
            }

            Xrp[i] = sumrp * Rrp[i * R_tcols + i];
            Xip[i] = sumip * Rrp[i * R_tcols + i];
        }
    }
    else
    {
        for ( i = 0; i < n; i++ )
        {
            sumrp = Brp[i];
            sumip = Bip[i];

            for ( j = 0; j < i; j++ )
            {
                sumrp -= Rrp[j * R_tcols + i] * Xrp[j] + Rip[j * R_tcols + i] * Xip[j];
                sumip -= Rrp[j * R_tcols + i] * Xip[j] - Rip[j * R_tcols + i] * Xrp[j];
            }

            Xrp[i] = sumrp * Rrp[i * R_tcols + i];
            Xip[i] = sumip * Rrp[i * R_tcols + i];

        }

        for ( i = n - 1; i >= 0; i-- )
        {
            sumrp = Xrp[i];
            sumip = Xip[i];

            for ( j = i + 1; j < n; j++ )
            {
                sumrp -= Rrp[i * R_tcols + j] * Xrp[j] - Rip[i * R_tcols + j] * Xip[j];
                sumip -= Rrp[i * R_tcols + j] * Xip[j] + Rip[i * R_tcols + j] * Xrp[j];
            }

            Xrp[i] = sumrp * Rrp[i * R_tcols + i];
            Xip[i] = sumip * Rrp[i * R_tcols + i];

        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}

