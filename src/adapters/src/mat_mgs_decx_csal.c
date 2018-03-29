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
        mat_mgs_decx_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( mat_mgs_decx_csal )(
    SAL_f32 *AT,
    SAL_i32 ATtcols,

    SAL_f32 *R,
    SAL_i32 Rtcols,
    SAL_i32 m,

    SAL_i32 n,

    SAL_f32 *rcond_est,
    SAL_f32 *v,
    SAL_i32 flag,
    SAL_i32 X,
    SAL__return_info *r_info
)

{
    SAL_i32 i, j, k;
    SAL_f32 len_recip, dot;
    SAL_f32 *Qpivot, *Acol;
    SAL_f32 *Rrow, *Rsave;
    SAL_i32 Rtcols1 = Rtcols + 1;
    ( void ) X;

    Rsave = R;

    for ( k = 0; k < n; k++ )
    {
        Qpivot = AT;
        AT += ATtcols;
        Acol = AT;
        Rrow = R;
        R += Rtcols1;

        dot = 0.0;

        for ( i = 0; i < m; i++ )
        {
            dot += Qpivot[i] * Qpivot[i];
        }

        len_recip = 1.0 / sqrt( dot );

        for ( i = 0; i < m; i++ )
        {
            Qpivot[i] *= len_recip;
        }

        *Rrow++ = len_recip;

        for ( j = k + 1; j < n; j++ )
        {
            dot = 0.0;

            for ( i = 0; i < m; i++ )
            {
                dot += Qpivot[i] * Acol[i];
            }

            *Rrow++ = dot;

            for ( i = 0; i < m; i++ )
            {
                Acol[i] = Acol[i] - dot * Qpivot[i];
            }

            Acol += ATtcols;
        }

    }

    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < i; j++ )
        {
            Rsave[i*Rtcols + j] = Rsave[j*Rtcols + i];
        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}

