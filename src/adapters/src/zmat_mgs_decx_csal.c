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
        zmat_mgs_decx_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( zmat_mgs_decx_csal )(
    SAL_zf32 *AT,
    SAL_i32 ATtcols,

    SAL_zf32 *R,
    SAL_i32 Rtcols,
    SAL_i32 m,

    SAL_i32 n,

    SAL_f32 *rcond_est,
    SAL_zf32 *v,
    SAL_i32 flag,
    SAL_i32 X,
    SAL__return_info *r_info
)

{
    SAL_i32 i, j, k;
    SAL_f32 len_recip;
    SAL_f32 *ATrp, *ATip, *Rrp, *Rip;
    SAL_f32 *Qpivotrp, *Qpivotip, *Acolrp, *Acolip, *Rrowrp, *Rrowip;
    SAL_i32 Rtcols1 = Rtcols + 1;
    SAL_f32 dotrp, dotip;
    SAL_zf32 Rsave, Asave;
    SAL_f32 *Rsaverp, *Rsaveip, *Asaverp, *Asaveip;

    ( void ) X;

    ATrp = AT->realp;
    ATip = AT->imagp;
    Rrp = R->realp;
    Rip = R->imagp;

    Rsaverp = Rrp;
    Rsaveip = Rip;
    Asaverp = ATrp;
    Asaveip = ATip;
    Rsave.realp = Rsaverp;
    Rsave.imagp = Rsaveip;
    Asave.realp = Asaverp;
    Asave.imagp = Asaveip;

    for ( k = 0; k < n; k++ )
    {
        Qpivotrp = ATrp;
        Qpivotip = ATip;
        ATrp += ATtcols;
        ATip += ATtcols;
        Acolrp = ATrp;
        Acolip = ATip;
        Rrowrp = Rrp;
        Rrowip = Rip;

        len_recip = 0.0;

        for ( i = 0; i < m; i++ )
        {
            len_recip +=   Qpivotrp[i] * Qpivotrp[i]
                           + Qpivotip[i] * Qpivotip[i];
        }

        len_recip = 1.0 / sqrt( len_recip );

        for ( i = 0; i < m; i++ )
        {
            Qpivotrp[i] *= len_recip;
            Qpivotip[i] *= len_recip;
        }

        *Rrp = len_recip;
        *Rip = 0.0;

        Rrowrp = Rrp + 1;
        Rrowip = Rip + 1;

        for ( j = k + 1; j < n; j++ )
        {
            dotrp = dotip = 0.0;

            for ( i = 0; i < m; i++ )
            {
                dotrp +=   Qpivotrp[i] * Acolrp[i]
                           + Qpivotip[i] * Acolip[i];
                dotip +=   Qpivotrp[i] * Acolip[i]
                           - Qpivotip[i] * Acolrp[i];
            }

            *Rrowrp++ = dotrp;
            *Rrowip++ = dotip;

            for ( i = 0; i < m; i++ )
            {
                Acolrp[i] = Acolrp[i] - dotrp * Qpivotrp[i]
                            + dotip * Qpivotip[i];
                Acolip[i] = Acolip[i] - dotip * Qpivotrp[i]
                            - dotrp * Qpivotip[i];
            }

            Acolrp += ATtcols;
            Acolip += ATtcols;
        }

        Rrp += Rtcols1;
        Rip += Rtcols1;
    }

    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < i; j++ )
        {
            Rsave.realp[i*Rtcols + j] = Rsave.realp[j*Rtcols + i];
            Rsave.imagp[i*Rtcols + j] = Rsave.imagp[j*Rtcols + i];
        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
