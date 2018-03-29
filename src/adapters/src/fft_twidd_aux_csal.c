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
        fft_twidd_aux_csal.c

----------------------------------------------------------------------------
*/

#include <math.h>
#include "csal_fft_internal.h"

void PREFIX( _csal_fft_twiddlesd )( SAL_f64 *WR, SAL_f64 *WI, SAL_ui32 LOG2M )
{
    SAL_ui32  i, j, k, m;
    SAL_f64 angle, twopivm;

    m = 1 << LOG2M;
    twopivm = ( SAL_f64 )TWO_PI / ( SAL_f64 )m;

    for ( i = 0; i < m / 4; i++ )
    {
        for ( j = 0; j < 3; j++ )
        {
            k = i * ( j + 1 );

            if ( k == 0 )
            {
                WR[3*i + j] = ( SAL_f64 )1.0;
                WI[3*i + j] = ( SAL_f64 )0.0;
            }
            else if ( 4*k == m )
            {
                WR[3*i + j] = ( SAL_f64 )0.0;
                WI[3*i + j] = ( SAL_f64 )1.0;
            }
            else if ( 2*k == m )
            {
                WR[3*i + j] = ( SAL_f64 ) - 1.0;
                WI[3*i + j] = ( SAL_f64 )0.0;
            }
            else
            {
                angle = ( SAL_f64 )( k ) * twopivm;
                WR[3*i + j] = ( SAL_f64 )cos( angle );
                WI[3*i + j] = ( SAL_f64 )sin( angle );
            }
        }
    }

    SAL_SET_PATH_CSAL();
}

void PREFIX( _csal_fft_twiddles3d )( SAL_cf64 *W0, SAL_cf64 *W1,
                                     SAL_ui32 LOG2M )
{
    SAL_ui32  i, m, m3;
    SAL_f64 angle, twopivm3;

    m = 1 << LOG2M;
    m3 = 3 * m;
    twopivm3 = ( SAL_f64 )TWO_PIV3 / ( SAL_f64 )m;

    for ( i = 0; i < m; i++ )
    {
        if ( i == 0 )
        {
            W0[i].real = ( SAL_f64 )1.0;
            W0[i].imag = ( SAL_f64 )0.0;
        }
        else if ( 4*i == m3 )
        {
            W0[i].real = ( SAL_f64 )0.0;
            W0[i].imag = ( SAL_f64 )1.0;
        }
        else
        {
            angle = ( SAL_f64 )( i ) * twopivm3;
            W0[i].real = ( SAL_f64 )cos( angle );
            W0[i].imag = ( SAL_f64 )sin( angle );
        }

        if ( i == 0 )
        {
            W1[i].real = ( SAL_f64 )1.0;
            W1[i].imag = ( SAL_f64 )0.0;
        }
        else if ( 8*i == m3 )
        {
            W1[i].real = ( SAL_f64 )0.0;
            W1[i].imag = ( SAL_f64 )1.0;
        }
        else if ( 4*i == m3 )
        {
            W1[i].real = ( SAL_f64 ) - 1.0;
            W1[i].imag = ( SAL_f64 )0.0;
        }
        else
        {
            angle = ( SAL_f64 )( 2 * i ) * twopivm3;
            W1[i].real = ( SAL_f64 )cos( angle );
            W1[i].imag = ( SAL_f64 )sin( angle );
        }
    }

    SAL_SET_PATH_CSAL();
}

void PREFIX( _csal_fft_twiddles5d )( SAL_cf64 *W0, SAL_cf64 *W1,
                                     SAL_ui32 LOG2M )
{
    SAL_ui32  i, m, m5;
    SAL_f64 angle, twopivm5;

    m = 1 << LOG2M;
    m5 = 5 * m;
    twopivm5 = ( SAL_f64 )TWO_PIV5 / ( SAL_f64 )m;

    for ( i = 0; i < m; i++ )
    {
        if ( i == 0 )
        {
            W0[i].real = ( SAL_f64 )1.0;
            W0[i].imag = ( SAL_f64 )0.0;
        }
        else
        {
            angle = ( SAL_f64 )( i ) * twopivm5;
            W0[i].real = ( SAL_f64 )cos( angle );
            W0[i].imag = ( SAL_f64 )sin( angle );
        }

        if ( i == 0 )
        {
            W0[m+i].real = ( SAL_f64 )1.0;
            W0[m+i].imag = ( SAL_f64 )0.0;
        }
        else if ( 8*i == m5 )
        {
            W0[m+i].real = ( SAL_f64 )0.0;
            W0[m+i].imag = ( SAL_f64 )1.0;
        }
        else
        {
            angle = ( SAL_f64 )( 2 * i ) * twopivm5;
            W0[m+i].real = ( SAL_f64 )cos( angle );
            W0[m+i].imag = ( SAL_f64 )sin( angle );
        }

        if ( i == 0 )
        {
            W1[i].real = ( SAL_f64 )1.0;
            W1[i].imag = ( SAL_f64 )0.0;
        }
        else
        {
            angle = ( SAL_f64 )( 3 * i ) * twopivm5;
            W1[i].real = ( SAL_f64 )cos( angle );
            W1[i].imag = ( SAL_f64 )sin( angle );
        }

        if ( i == 0 )
        {
            W1[m+i].real = ( SAL_f64 )1.0;
            W1[m+i].imag = ( SAL_f64 )0.0;
        }
        else if ( 16*i == m5 )
        {
            W1[m+i].real = ( SAL_f64 )0.0;
            W1[m+i].imag = ( SAL_f64 )1.0;
        }
        else if ( 8*i == m5 )
        {
            W1[m+i].real = ( SAL_f64 ) - 1.0;
            W1[m+i].imag = ( SAL_f64 )0.0;
        }
        else if ( 16*i == 3*m5 )
        {
            W1[m+i].real = ( SAL_f64 )0.0;
            W1[m+i].imag = ( SAL_f64 ) - 1.0;
        }
        else
        {
            angle = ( SAL_f64 )( 4 * i ) * twopivm5;
            W1[m+i].real = ( SAL_f64 )cos( angle );
            W1[m+i].imag = ( SAL_f64 )sin( angle );
        }
    }

    SAL_SET_PATH_CSAL();
}
