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
        zmat_lud_solx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zmat_lud_solx_csal )(
    SAL_zf32 *A,
    SAL_i32 Atcols,
    SAL_i32 *D,
    SAL_zf32 *b,
    SAL_zf32 *w,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag,
    SAL__return_info *r_info
)
{
    SAL_i32 i, j;
    SAL_f32 sumrp, sumip, diagrp, diagip;
    SAL_f32 temprp, tempip;
    SAL_f32 *Arp, *Aip, *brp, *bip, *wrp, *wip;

    ( void ) xflag;

    Arp = A->realp;
    Aip = A->imagp;
    brp = b->realp;
    bip = b->imagp;
    wrp = w->realp;
    wip = w->imagp;

    if ( flag & SAL_TRANSPOSE_SOLVER )
    {
        for ( i = 0; i < n; i++ )
        {
            wrp[i] = brp[i];
            wip[i] = bip[i];
        }

        for ( i = 0; i < n; i++ )
        {
            sumrp = brp[i];
            sumip = bip[i];

            for ( j = 0; j < i; j++ )
            {
                sumrp -= Arp[j*Atcols + i] * brp[j] + Aip[j*Atcols + i] * bip[j];
                sumip -= Arp[j*Atcols + i] * bip[j] - Aip[j*Atcols + i] * brp[j];
            }

            diagrp = Arp[i * Atcols + i];
            diagip = -Aip[i * Atcols + i];
            brp[i] = ( sumrp * diagrp - sumip * diagip );
            bip[i] = ( sumrp * diagip + sumip * diagrp );
        }

        for ( i = n - 1; i >= 0; i-- )
        {
            sumrp = brp[i];
            sumip = bip[i];

            for ( j = i + 1; j < n; j++ )
            {
                sumrp -= Arp[j*Atcols + i] * brp[j] + Aip[j*Atcols + i] * bip[j];
                sumip -= Arp[j*Atcols + i] * bip[j] - Aip[j*Atcols + i] * brp[j];
            }

            brp[i] = sumrp;
            bip[i] = sumip;
        }

        for ( i = 0; i < n; i++ )
        {
            wrp[D[i]] = brp[i];
            wip[D[i]] = bip[i];
        }
    }
    else
    {
        for ( i = 0; i < n; i++ )
        {
            sumrp = brp[D[i]];
            sumip = bip[D[i]];

            for ( j = 0; j < i; j++ )
            {
                sumrp -= Arp[i*Atcols + j] * wrp[j] - Aip[i*Atcols + j] * wip[j];
                sumip -= Arp[i*Atcols + j] * wip[j] + Aip[i*Atcols + j] * wrp[j];
            }

            wrp[i] = sumrp;
            wip[i] = sumip;
        }

        for ( i = n - 1; i >= 0; i-- )
        {
            sumrp = wrp[i];
            sumip = wip[i];

            for ( j = i + 1; j < n; j++ )
            {
                sumrp -= Arp[i*Atcols + j] * wrp[j] - Aip[i*Atcols + j] * wip[j];
                sumip -= Arp[i*Atcols + j] * wip[j] + Aip[i*Atcols + j] * wrp[j];
            }

            diagrp = Arp[i * Atcols + i];
            diagip = Aip[i * Atcols + i];
            temprp = ( sumrp * diagrp - sumip * diagip );
            tempip = ( sumrp * diagip + sumip * diagrp );
            wrp[i] = temprp;
            wip[i] = tempip;
        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
