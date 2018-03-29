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
        imgfirx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include "csal_internal.h"

void PREFIX( imgfirx_csal )(
    SAL_f32 *A,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_f32 *B,
    SAL_f32 *C,
    SAL_i32 M,
    SAL_i32 N,
    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32     i, j, k, l, ncsubn, nz_cols, nz_rows;
    SAL_f32   sum, temp1, temp2, temp3, temp4, zero;
    SAL_f32  *aptr, *bptr;

    zero = 0.0;

    ncsubn = NC - N;
    nz_rows = M >> 1;
    nz_cols = N >> 1;

    for ( i = 0; i < nz_rows; i++ )
    {
        for ( j = 0; j < NC; j++ )
            *C++ = zero;
    }

    for ( i = nz_rows; i < ( NR - nz_rows ); i++ )
    {
        for ( j = 0; j < nz_cols; j++ )
            *C++ = zero;

        for ( j = nz_cols; j < ( NC - nz_cols ); j++ )
        {
            aptr = A;
            bptr = B;
            sum = zero;

            for ( k = 0; k < M; k++ )
            {
                if ( k == 0 )
                {
                    temp1 = *aptr++;
                    temp2 = *bptr++;
                    sum = temp1 * temp2;
                }
                else
                {
                    temp1 = *aptr++;
                    temp2 = *bptr++;
                    temp1 *= temp2;
                    sum += temp1;
                }

                for ( l = 1; l < N; l += 2 )
                {
                    temp1 = *aptr++;
                    temp2 = *bptr++;
                    temp1 *= temp2;

                    temp3 = *aptr++;
                    temp4 = *bptr++;
                    temp3 *= temp4;

                    if ( NC > 20 )
                    {
                        temp1 += temp3;
                        sum += temp1;
                    }
                    else
                    {
                        sum += temp1;
                        sum += temp3;
                    }
                }

                aptr += ncsubn;
            }

            *C++ = sum;
            ++A;
        }

        for ( j = 0; j < nz_cols; j++ )
            *C++ = zero;

        A += ( N - 1 );
    }

    for ( i = 0; i < nz_rows; i++ )
    {
        for ( j = 0; j < NC; j++ )
            *C++ = zero;
    }

    SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS );
    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
}
