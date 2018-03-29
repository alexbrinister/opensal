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
        cmat_mgs_decx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( cmat_mgs_decx_csal )(
    SAL_cf32 *c_AT,
    SAL_i32 ATtcols,

    SAL_cf32 *c_R,
    SAL_i32 Rtcols,
    SAL_i32 m,

    SAL_i32 n,

    SAL_f32 *rcond_est,
    SAL_cf32 *c_v,
    SAL_i32 flag,
    SAL_i32 X,
    SAL__return_info *r_info
)

{
    SAL_i32 i, j, k;
    SAL_f32 len_recip;
    SAL_f32 *R;
    SAL_f32 *Rrow;
    SAL_cf32 *c_Qpivot, *c_Acol;
    SAL_i32 Rtcols1 = Rtcols + 1;
    SAL_f32 dotrp, dotip;

    SAL_cf32 *c_Rsave;
    SAL_f32 *Rsave;

    ( void ) X;

    R = ( SAL_f32 * ) c_R;

    Rsave = R;
    c_Rsave = ( SAL_cf32 * ) Rsave;

    for ( k = 0; k < n; k++ )
    {
        c_Qpivot = c_AT;
        c_AT += ATtcols;
        c_Acol = c_AT;

        Rrow = R;

        len_recip = 0.0;

        for ( i = 0; i < m; i++ )
        {
            len_recip +=   c_Qpivot[i].real * c_Qpivot[i].real
                           + c_Qpivot[i].imag * c_Qpivot[i].imag;
        }

        len_recip = 1.0 / sqrt( len_recip );

        for ( i = 0; i < m; i++ )
        {
            c_Qpivot[i].real *= len_recip;
            c_Qpivot[i].imag *= len_recip;
        }

        *Rrow = len_recip;
        *( Rrow + 1 ) = 0.0;

        Rrow = R + 2;

        for ( j = k + 1; j < n; j++ )
        {
            dotrp = dotip = 0.0;

            for ( i = 0; i < m; i++ )
            {
                dotrp +=   c_Qpivot[i].real * c_Acol[i].real
                           + c_Qpivot[i].imag * c_Acol[i].imag;
                dotip +=   c_Qpivot[i].real * c_Acol[i].imag
                           - c_Qpivot[i].imag * c_Acol[i].real;
            }

            *Rrow++ = dotrp;
            *Rrow++ = dotip;

            for ( i = 0; i < m; i++ )
            {
                c_Acol[i].real = c_Acol[i].real - dotrp * c_Qpivot[i].real
                                 + dotip * c_Qpivot[i].imag;
                c_Acol[i].imag = c_Acol[i].imag - dotip * c_Qpivot[i].real
                                 - dotrp * c_Qpivot[i].imag;
            }

            c_Acol += ATtcols;
        }

        R += Rtcols1 * 2;
    }

    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < i; j++ )
        {
            c_Rsave[i*Rtcols + j].real = c_Rsave[j*Rtcols + i].real;
            c_Rsave[i*Rtcols + j].imag = c_Rsave[j*Rtcols + i].imag;
        }
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    return;
}
