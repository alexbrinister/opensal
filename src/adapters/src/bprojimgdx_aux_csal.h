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
        bprojimgdx_aux_csal.h

----------------------------------------------------------------------------
*/

#ifndef BPROJIMGDX_AUX_CSAL_H
#define BPROJIMGDX_AUX_CSAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <csal_internal.h>

    void PREFIX( _csal_rhvbpd )(
        SAL_i32     n,
        SAL_f64  *proj_start,
        SAL_f64  *proj_deltax,
        SAL_f64  *proj_addr,
        SAL_f64  *image_row
    )
    {
        SAL_i32    i, remain;
        SAL_f64  finc1, finc2, finc3, finc4, finc5, finc6;
        SAL_f64  findex0, findex1, findex2, findex3, findex4, findex5;

        findex0 = *proj_start;
        finc1 = *proj_deltax;
        finc2 = finc1 + finc1;
        finc3 = finc1 + finc2;
        finc4 = finc2 + finc2;
        finc5 = finc2 + finc3;
        finc6 = finc2 + finc4;

        findex1 = findex0 + finc1;
        findex2 = findex1 + finc1;
        findex3 = findex0 + finc3;
        findex4 = findex0 + finc4;
        findex5 = findex0 + finc5;

        for ( i = 0; i < ( n / 6 ); i++ )
        {
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex0 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex1 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex2 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex3 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex4 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex5 ];
            findex0 += finc6;
            findex1 += finc6;
            findex2 += finc6;
            findex3 += finc6;
            findex4 += finc6;
            findex5 += finc6;
        }

        remain = n % 6;

        if ( remain == 1 )
        {
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex0 ];
        }

        else if ( remain == 2 )
        {
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex0 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex1 ];
        }

        else if ( remain == 3 )
        {
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex0 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex1 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex2 ];
        }

        else if ( remain == 4 )
        {
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex0 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex1 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex2 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex3 ];
        }

        else if ( remain == 5 )
        {
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex0 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex1 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex2 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex3 ];
            *( image_row++ ) += proj_addr[ ( SAL_i32 )findex4 ];
        }

        SAL_SET_PATH_CSAL();
    }

#ifdef __cplusplus
}
#endif

#endif

