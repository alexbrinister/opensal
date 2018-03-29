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
        fft_zbitr_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

void  PREFIX( _csal_fft_zbitr )( SAL_zf32  *C, SAL_i32  K, SAL_ui32  LOG2N )
{
    SAL_i32 i, j, k, nK;
    SAL_f32 ftempr, ftempi;
    SAL_f32 *Cr, *Ci;

    Cr = C->realp;
    Ci = C->imagp;

    nK = ( 1 << LOG2N ) * K;

    j = 0;

    for ( i = K; i < ( nK - K ); i += K )
    {
        k = ( nK >> 1 );

        while ( k <= j )
        {
            j -= k;
            k >>= 1;
        }

        j += k;

        if ( i < j )
        {
            ftempr = Cr[i];
            ftempi = Ci[i];
            Cr[i] = Cr[j];
            Ci[i] = Ci[j];
            Cr[j] = ftempr;
            Ci[j] = ftempi;
        }
    }

    SAL_SET_PATH_CSAL();
}
