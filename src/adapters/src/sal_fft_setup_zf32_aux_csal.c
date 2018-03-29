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
        sal_fft_setup_zf32_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"
#include "sal.h"
#include <math.h>

void sal__fft_setup_aux_zf32( SAL_i32 Ln,
                              SAL_i32 Lnx,
                              SAL_ui32 *nbytesp,
                              SAL_zf32 *twidsp )
{
    SAL_i32  i, j, k;
    SAL_i32  LNx, LNy, NX, NY;
    SAL_f64 freq, a;
    SAL_f64 cosa, sina;
    SAL_f32 *wrp, *wip;
    SAL_f32 *Wxyp_real, *Wxyp_imag;

    LNx = Lnx;
    LNy = Ln - LNx;

    NX = 1 << LNx;
    NY = 1 << LNy;

    if ( twidsp )
    {
        Wxyp_real = twidsp->realp;
        Wxyp_imag = twidsp->imagp;

        freq = TWOPI_CONSTANT / ( SAL_f64 )( NX * NY );

        for ( i = 0; i < NY; i += 8 )
        {
            for ( k = 0; k < 8; k++ )
            {
                wrp = Wxyp_real + k;
                wip = Wxyp_imag + k;

                for ( j = 0; j < NX; j++ )
                {
                    a = ( SAL_f64 )( ( i + k ) * j ) * freq;
                    cosa = cos( a );
                    sina = sin( a );

                    *wrp = ( SAL_f32 )cosa;
                    *wip = ( SAL_f32 )sina;
                    wrp += 8;
                    wip += 8;
                }
            }

            Wxyp_real += ( 8 * NX );
            Wxyp_imag += ( 8 * NX );
        }
    }

    if ( nbytesp )
    {
        ( *nbytesp ) = 2 * ( NY * NX * sizeof( SAL_f32 ) );
    }

    return;
}

