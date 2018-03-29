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
        spinx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

#define DP_STEP 1
#define SP_STEP 0

void PREFIX( spinx_csal )(
    SAL_f32 *A,
    SAL_f32 *B,
    SAL_f32 *C,
    SAL_i32 INC,
    SAL_i32 INR,
    SAL_i32 ONC,
    SAL_i32 ONR,
    SAL_i32 F,
    SAL_f32 *V,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32    i, j, offset, step_flag;
    SAL_i32    intx, inty;
    SAL_f32  s, c, ir, jr, xr, yr;
    SAL_f32  lowxy_in, lowxy_out;
    SAL_f32  highx_in, highx_out, highy_in, highy_out;
    SAL_f32  xint, yint, xfrac, yfrac;
    SAL_f32  a00, a01, a10, a11;
    SAL_f32  fillv, out, temp1, temp2, temp3, xyfrac;
    SAL_f32  *aptr;
    SAL_f32  x, y;
    SAL_f32  xbeg_sp = 0.0, ybeg_sp = 0.0, xstep_sp = 0.0, ystep_sp = 0.0;
    SAL_f64  xbeg = 0.0, ybeg = 0.0, xstep = 0.0, ystep = 0.0;

    if ( F )
        fillv = *V;
    else
        fillv = 0;

    s = *B++;
    c = *B++;
    ir = *B++;
    jr = *B++;
    xr = *B++;
    yr = *B++;

    step_flag = DP_STEP;

    if ( ( ( ( c*c ) + ( s*s ) ) <= 0 ) || ( ONC > 1020 ) )
        step_flag = SP_STEP;

    lowxy_in = 0.0;
    lowxy_out = -0.5;
    highx_in = ( SAL_f32 )( INC - 1 );
    highx_out = ( SAL_f32 )highx_in + ( SAL_f32 )0.5;
    highy_in = ( SAL_f32 )( INR - 1 );
    highy_out = ( SAL_f32 )highy_in + ( SAL_f32 )0.5;

    temp1 = s * jr;
    temp2 = c * ir;
    temp3 = xr - temp1;

    if ( step_flag == DP_STEP )
        xbeg = ( SAL_f64 )( temp3 - temp2 );
    else
        xbeg_sp = ( temp3 - temp2 );

    temp1 = s * ir;
    temp2 = c * jr;
    temp3 = yr + temp1;

    if ( step_flag == DP_STEP )
        ybeg = ( SAL_f64 )( temp3 - temp2 );
    else
        ybeg_sp = ( temp3 - temp2 );

    for ( i = 0; i < ONR; i++ )
    {
        if ( step_flag == DP_STEP )
        {
            xstep = xbeg;
            ystep = ybeg;
        }
        else
        {
            xstep_sp = xbeg_sp;
            ystep_sp = ybeg_sp;
        }

        for ( j = 0; j < ONC; j++ )
        {
            if ( step_flag == DP_STEP )
            {
                x = ( SAL_f32 )xstep;
                y = ( SAL_f32 )ystep;
            }
            else
            {
                x = xstep_sp;
                y = ystep_sp;
            }

            if ( ( x >= lowxy_in ) && ( x < highx_in ) &&
                 ( y >= lowxy_in ) && ( y < highy_in ) )
            {
                intx = ( SAL_i32 ) x;
                inty = ( SAL_i32 ) y;
                xint = ( SAL_f32 ) intx;
                yint = ( SAL_f32 ) inty;
                xfrac = x - xint;
                yfrac = y - yint;
                offset = inty * INC;
                offset += intx;
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
                temp2 *= yfrac;
                out += a00;
                temp3 -= temp1;
                out += temp2;
                temp1 = xyfrac * temp3;
                out += temp1;
                *C++ = out;
            }

            else if ( ( x < lowxy_out ) || ( x >= highx_out ) ||
                      ( y < lowxy_out ) || ( y >= highy_out ) )
            {
                if ( F )
                    *C++ = fillv;
                else
                    C++;
            }

            else if ( x < lowxy_in )
            {
                if ( y < lowxy_in )
                    *C++ = *A;
                else if ( y < highy_in )
                {
                    inty = ( SAL_i32 ) y;
                    yint = ( SAL_f32 ) inty;
                    yfrac = y - yint;
                    offset = inty * INC;
                    aptr = A + offset;
                    a00 = *aptr;
                    a10 = *( aptr += INC );
                    out = a10 - a00;
                    out *= yfrac;
                    out += a00;
                    *C++ = out;
                }
                else
                {
                    offset = ( INR - 1 ) * INC;
                    *C++ = *( A + offset );
                }
            }

            else if ( x >= highx_in )
            {
                if ( y < lowxy_in )
                    *C++ = *( A + INC - 1 );
                else if ( y < highy_in )
                {
                    inty = ( SAL_i32 ) y;
                    yint = ( SAL_f32 ) inty;
                    yfrac = y - yint;
                    offset = inty * INC;
                    offset += ( INC - 1 );
                    aptr = A + offset;
                    a00 = *aptr;
                    a10 = *( aptr += INC );
                    out = a10 - a00;
                    out *= yfrac;
                    out += a00;
                    *C++ = out;
                }
                else
                {
                    offset = ( INR * INC ) - 1;
                    *C++ = *( A + offset );
                }
            }

            else if ( y < lowxy_in )
            {
                intx = ( SAL_i32 ) x;
                xint = ( SAL_f32 ) intx;
                xfrac = x - xint;
                aptr = A + intx;
                a00 = *aptr++;
                a01 = *aptr;
                out = a01 - a00;
                out *= xfrac;
                out += a00;
                *C++ = out;
            }

            else if ( y >= highy_in )
            {
                intx = ( SAL_i32 ) x;
                xint = ( SAL_f32 ) intx;
                xfrac = x - xint;
                offset = ( INR - 1 ) * INC;
                offset += intx;
                aptr = A + offset;
                a00 = *aptr++;
                a01 = *aptr;
                out = a01 - a00;
                out *= xfrac;
                out += a00;
                *C++ = out;
            }

            if ( step_flag == DP_STEP )
            {
                xstep = xstep + ( SAL_f64 )c;
                ystep = ystep - ( SAL_f64 )s;
            }
            else
            {
                xstep_sp = xstep_sp + c;
                ystep_sp = ystep_sp - s;
            }
        }

        if ( step_flag == DP_STEP )
        {
            xbeg = xbeg + ( SAL_f64 )s;
            ybeg = ybeg + ( SAL_f64 )c;
        }
        else
        {
            xbeg_sp = xbeg_sp + s;
            ybeg_sp = ybeg_sp + c;
        }
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
