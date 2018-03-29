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
        zvrot2nc_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_internal.h"

void PREFIX( _csal_zvrot2nc )( SAL_zf32 *v0, SAL_zf32 *v1, SAL_f32 *Pret, SAL_i32 n, SAL_i32 swap_rows )
{
    SAL_f32 sar, sai;
    SAL_f32 c, temp0rp, temp0ip, temp1rp, temp1ip;
    SAL_i32 i;
    SAL_f32 *v0rp, *v0ip, *v1rp, *v1ip;

    c = Pret[0];
    sar = Pret[2];
    sai = Pret[3];
    v0rp = v0->realp;
    v0ip = v0->imagp;
    v1rp = v1->realp;
    v1ip = v1->imagp;

    if ( swap_rows )
    {
        for ( i = 0; i < n; i++ )
        {
            temp1rp = c * v0rp[i] + sar * v1rp[i] - sai * v1ip[i];
            temp1ip = c * v0ip[i] + sar * v1ip[i] + sai * v1rp[i];
            temp0rp = -sar * v0rp[i] - sai * v0ip[i] + c * v1rp[i];
            v0ip[i] = sai * v0rp[i] - sar * v0ip[i] + c * v1ip[i];
            v1rp[i] = temp1rp;
            v1ip[i] = temp1ip;
            v0rp[i] = temp0rp;
        }
    }
    else
    {
        for ( i = 0; i < n; i++ )
        {
            temp0rp = c * v0rp[i] + sar * v1rp[i] - sai * v1ip[i];
            temp0ip = c * v0ip[i] + sar * v1ip[i] + sai * v1rp[i];
            v1rp[i] = -sar * v0rp[i] - sai * v0ip[i] + c * v1rp[i];
            v1ip[i] = sai * v0rp[i] - sar * v0ip[i] + c * v1ip[i];
            v0rp[i] = temp0rp;
            v0ip[i] = temp0ip;
        }
    }
}
