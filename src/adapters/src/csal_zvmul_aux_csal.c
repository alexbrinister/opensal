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
        csal_zvmul_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

void  PREFIX( _csal_zvmul )( SAL_zf32 *A, SAL_i32 I,
                             SAL_zf32 *B, SAL_i32 J,
                             SAL_zf32 *C, SAL_i32 K, SAL_ui32 N, SAL_i32 F )
{
    SAL_ui32  n;
    SAL_f32  ar, ai, br, bi, cr, ci;
    SAL_f32  *Arp, *Aip, *Brp, *Bip, *Crp, *Cip;

    Arp = A->realp;
    Aip = A->imagp;

    if ( F >= 0 )
    {
        Brp = B->realp;
        Bip = B->imagp;
        Crp = C->realp;
        Cip = C->imagp;
    }
    else
    {
        Brp = B->imagp;
        Bip = B->realp;
        Crp = C->imagp;
        Cip = C->realp;
    }

    for ( n = 0; n < N; n++ )
    {
        ar = Arp[n*I];
        ai = Aip[n*I];
        br = Brp[n*J];
        bi = Bip[n*J];
        cr = ar * br - ai * bi;
        ci = ar * bi + ai * br;
        Crp[n*K] = cr;
        Cip[n*K] = ci;
    }

    SAL_SET_PATH_CSAL();
}
