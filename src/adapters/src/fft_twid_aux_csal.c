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
        fft_twid_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

void PREFIX( _csal_fft_twiddles )( SAL_f32 *WR, SAL_f32 *WI, SAL_ui32 LOG2M )
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
                WR[3*i + j] = ( SAL_f32 )1.0;
                WI[3*i + j] = ( SAL_f32 )0.0;
            }
            else if ( 4*k == m )
            {
                WR[3*i + j] = ( SAL_f32 )0.0;
                WI[3*i + j] = ( SAL_f32 )1.0;
            }
            else if ( 2*k == m )
            {
                WR[3*i + j] = ( SAL_f32 ) - 1.0;
                WI[3*i + j] = ( SAL_f32 )0.0;
            }
            else
            {
                angle = ( SAL_f64 )( k ) * twopivm;
                WR[3*i + j] = ( SAL_f32 )cos( angle );
                WI[3*i + j] = ( SAL_f32 )sin( angle );
            }
        }
    }

    SAL_SET_PATH_CSAL();
}

void PREFIX( _csal_fft_twiddles3 )( SAL_f32 *WR, SAL_f32 *WI, SAL_ui32 LOG2M )
{
    SAL_ui32  i, j, k, m, m3;
    SAL_f64 angle, twopivm3;

    m = 1 << LOG2M;
    m3 = 3 * m;
    twopivm3 = ( SAL_f64 )TWO_PIV3 / ( SAL_f64 )m;

    for ( i = 0; i < 2; i++ )
    {
        for ( j = 0; j < m; j++ )
        {
            k = ( i + 1 ) * j;

            if ( k == 0 )
            {
                WR[i*m + j] = ( SAL_f32 )1.0;
                WI[i*m + j] = ( SAL_f32 )0.0;
            }
            else if ( 4*k == m3 )
            {
                WR[i*m + j] = ( SAL_f32 )0.0;
                WI[i*m + j] = ( SAL_f32 )1.0;
            }
            else if ( 2*k == m3 )
            {
                WR[i*m + j] = ( SAL_f32 ) - 1.0;
                WI[i*m + j] = ( SAL_f32 )0.0;
            }
            else
            {
                angle = ( SAL_f64 )( k ) * twopivm3;
                WR[i*m + j] = ( SAL_f32 )cos( angle );
                WI[i*m + j] = ( SAL_f32 )sin( angle );
            }
        }
    }

    SAL_SET_PATH_CSAL();
}

void PREFIX( _csal_fft_twiddles5 )( SAL_f32 *WR, SAL_f32 *WI, SAL_ui32 LOG2M )
{
    SAL_ui32  i, j, k, m, m5;
    SAL_f64 angle, twopivm5;

    m = 1 << LOG2M;
    m5 = 5 * m;
    twopivm5 = ( SAL_f64 )TWO_PIV5 / ( SAL_f64 )m;

    for ( i = 0; i < 4; i++ )
    {
        for ( j = 0; j < m; j++ )
        {
            k = ( i + 1 ) * j;

            if ( k == 0 )
            {
                WR[i*m + j] = ( SAL_f32 )1.0;
                WI[i*m + j] = ( SAL_f32 )0.0;
            }
            else if ( 4*k == m5 )
            {
                WR[i*m + j] = ( SAL_f32 )0.0;
                WI[i*m + j] = ( SAL_f32 )1.0;
            }
            else if ( 2*k == m5 )
            {
                WR[i*m + j] = ( SAL_f32 ) - 1.0;
                WI[i*m + j] = ( SAL_f32 )0.0;
            }
            else if ( 4*k == 3*m5 )
            {
                WR[i*m + j] = ( SAL_f32 )0.0;
                WI[i*m + j] = ( SAL_f32 ) - 1.0;
            }
            else
            {
                angle = ( SAL_f64 )( k ) * twopivm5;
                WR[i*m + j] = ( SAL_f32 )cos( angle );
                WI[i*m + j] = ( SAL_f32 )sin( angle );
            }
        }
    }

    SAL_SET_PATH_CSAL();
}

void PREFIX( _csal_fft_twiddles9 )( SAL_f32 *WR, SAL_f32 *WI, SAL_ui32 LOG2M )
{
    SAL_ui32  i, j, k, m, m3, m9;
    SAL_f64 angle, twopivm9;

    m = 1 << LOG2M;
    m3 = 3 << LOG2M;
    m9 = 9 << LOG2M;
    twopivm9 = ( SAL_f64 )TWO_PIV9 / ( SAL_f64 )m;

    for ( i = 0; i < 2; i++ )
    {
        for ( j = 0; j < m3; j++ )
        {
            k = ( i + 1 ) * j;

            if ( k == 0 )
            {
                WR[i*m3 + j] = ( SAL_f32 )1.0;
                WI[i*m3 + j] = ( SAL_f32 )0.0;
            }
            else if ( 4*k == m9 )
            {
                WR[i*m3 + j] = ( SAL_f32 )0.0;
                WI[i*m3 + j] = ( SAL_f32 )1.0;
            }
            else if ( 2*k == m9 )
            {
                WR[i*m3 + j] = ( SAL_f32 ) - 1.0;
                WI[i*m3 + j] = ( SAL_f32 )0.0;
            }
            else
            {
                angle = ( SAL_f64 )( k ) * twopivm9;
                WR[i*m3 + j] = ( SAL_f32 )cos( angle );
                WI[i*m3 + j] = ( SAL_f32 )sin( angle );
            }
        }
    }

    SAL_SET_PATH_CSAL();
}
