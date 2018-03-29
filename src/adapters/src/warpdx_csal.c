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
        warpdx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( warpdx_csal )(
    SAL_f64 *A,
    SAL_f64 *B,
    SAL_f64 *C,
    SAL_i32 INC,
    SAL_i32 INR,
    SAL_i32 ONC,
    SAL_i32 ONR,
    SAL_i32 F,
    SAL_f64 *V,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i, j, maxc, maxr;
    SAL_i32    intx, inty, offset;
    SAL_f64  a, e, b, f, c, g, d, h;
    SAL_f64  xbeg, ybeg, xcinc, ycinc, x, y, xint, yint, xfrac, yfrac;
    SAL_f64  a00, a01, a10, a11;
    SAL_f64  fillv, out, temp1, temp2, temp3, xyfrac, zero;
    SAL_f64  *aptr;

    if ( F )
        fillv = *V;
    else
        fillv = 0.0;

    a = *B++;
    e = *B++;
    b = *B++;
    f = *B++;
    c = *B++;
    g = *B++;
    d = *B++;
    h = *B++;

    zero = 0.0;
    maxc = INC - 2;
    maxr = INR - 2;

    xbeg = a;
    ybeg = e;
    xcinc = b;
    ycinc = f;

    for ( i = 0; i < ONR; i++ )
    {
        x = xbeg;
        y = ybeg;

        for ( j = 0; j < ONC; j++ )
        {
            if ( ( x < zero ) || ( y < zero ) )
            {
                if ( F )
                    *C++ = fillv;
                else
                    C++;
            }
            else
            {
                intx = ( SAL_i32 ) x;
                inty = ( SAL_i32 ) y;

                if ( ( intx > maxc ) || ( inty > maxr ) )
                {
                    if ( F )
                        *C++ = fillv;
                    else
                        C++;
                }
                else
                {
                    xint = ( SAL_f64 ) intx;
                    yint = ( SAL_f64 ) inty;
                    xfrac = x - xint;
                    yfrac = y - yint;
                    offset = inty * INC;
                    offset = offset + intx;
                    aptr = A + offset;
                    a00 = *aptr;
                    a01 = *( aptr + 1 );
                    a10 = *( aptr += INC );
                    a11 = *( aptr + 1 );
                    xyfrac = xfrac * yfrac;
                    temp1 = a01 - a00;
                    temp2 = a10 - a00;
                    temp3 = a11 - a10;
                    out = xfrac * temp1;
                    temp2 = yfrac * temp2;
                    out = out + a00;
                    temp3 = temp3 - temp1;
                    out = out + temp2;
                    temp1 = xyfrac * temp3;
                    out = out + temp1;
                    *C++ = out;
                }
            }

            x = x + xcinc;
            y = y + ycinc;
        }

        xbeg = xbeg + c;
        ybeg = ybeg + g;
        xcinc = xcinc + d;
        ycinc = ycinc + h;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
