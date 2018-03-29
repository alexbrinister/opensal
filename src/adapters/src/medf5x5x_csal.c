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
        medf5x5x_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( medf5x5x_csal )(
    SAL_f32 *A,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_f32 *C,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32     i, j;
    SAL_f32  *p0, *p1, *p2, *p3, *p4;
    SAL_f32   med_tab[25];
    SAL_f32   zero;

    zero = 0.0;

    for ( i = 0; i < NC; i++ )
    {
        *C++ = zero;
        *C++ = zero;
    }

    p0 = A - 5;
    p1 = p0 + NC;
    p2 = p1 + NC;
    p3 = p2 + NC;
    p4 = p3 + NC;

    for ( i = 2; i <= ( NR - 3 ); i++ )
    {
        p0 += 4;
        p1 += 4;
        p2 += 4;
        p3 += 4;
        p4 += 4;

        *C++ = zero;
        *C++ = zero;

        for ( j = 2; j <= ( NC - 3 ); j++ )
        {
            med_tab[0] = *( p0 += 1 );
            med_tab[1] = *( p0 + 1 );
            med_tab[2] = *( p0 + 2 );
            med_tab[3] = *( p0 + 3 );
            med_tab[4] = *( p0 + 4 );
            med_tab[5] = *( p1 += 1 );
            med_tab[6] = *( p1 + 1 );
            med_tab[7] = *( p1 + 2 );
            med_tab[8] = *( p1 + 3 );
            med_tab[9] = *( p1 + 4 );
            med_tab[10] = *( p2 += 1 );
            med_tab[11] = *( p2 + 1 );
            med_tab[12] = *( p2 + 2 );
            med_tab[13] = *( p2 + 3 );
            med_tab[14] = *( p2 + 4 );
            med_tab[15] = *( p3 += 1 );
            med_tab[16] = *( p3 + 1 );
            med_tab[17] = *( p3 + 2 );
            med_tab[18] = *( p3 + 3 );
            med_tab[19] = *( p3 + 4 );
            med_tab[20] = *( p4 += 1 );
            med_tab[21] = *( p4 + 1 );
            med_tab[22] = *( p4 + 2 );
            med_tab[23] = *( p4 + 3 );
            med_tab[24] = *( p4 + 4 );

            PREFIX( _csal_heap_sort )( med_tab, 25 );
            *C++ = med_tab[12];
        }

        *C++ = zero;
        *C++ = zero;
    }

    for ( i = 0; i < NC; i++ )
    {
        *C++ = zero;
        *C++ = zero;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
