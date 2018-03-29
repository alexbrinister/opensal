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
        fft_type_flag_lookup_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_fft_internal.h"

SAL_ui32 PREFIX( fft_type_flag_lookup )( const SAL_ui32 fft_type )
{
    SAL_ui32 fft_type_flag = 0;

    switch ( fft_type )
    {
        case SAL_FFT3_COPX:
        case SAL_FFT3_COPDX:
        case SAL_FFT3_ROPX:
        case SAL_FFT3_ROPDX:
        case SAL_FFT3_ZOPX:
        case SAL_FFT3_ZOPDX:
        case SAL_FFT3_ZROPX:
        case SAL_FFT3_ZROPDX:
        case SAL_FFT3M_COPX:
        case SAL_FFT3M_ROPX:
        case SAL_FFT3M_ZOPX:
        case SAL_FFT3M_ZROPX:
            fft_type_flag |= FFT_RADIX3;
            break;

        case SAL_FFT5_COPX:
        case SAL_FFT5_COPDX:
        case SAL_FFT5_ROPX:
        case SAL_FFT5_ROPDX:
        case SAL_FFT5_ZOPX:
        case SAL_FFT5_ZOPDX:
        case SAL_FFT5_ZROPX:
        case SAL_FFT5_ZROPDX:
        case SAL_FFT5M_COPX:
        case SAL_FFT5M_ROPX:
        case SAL_FFT5M_ZOPX:
        case SAL_FFT5M_ZROPX:
            fft_type_flag |= FFT_RADIX5;
            break;

        case SAL_FFT9_COPX:
        case SAL_FFT9_ZOPX:
            fft_type_flag |= FFT_RADIX9;
            break;

        default:
            fft_type_flag |= 0;
            break;
    }

    switch ( fft_type )
    {
        case SAL_FFT2D_RIPX:
        case SAL_FFT2D_RIPDX:
        case SAL_FFT2D_ROPX:
        case SAL_FFT2D_ROPDX:
        case SAL_FFT2D_ZRIPX:
        case SAL_FFT2D_ZRIPDX:
        case SAL_FFT2D_ZROPX:
        case SAL_FFT2D_ZROPDX:
        case SAL_FFT3_ROPX:
        case SAL_FFT3_ROPDX:
        case SAL_FFT3_ZROPX:
        case SAL_FFT3_ZROPDX:
        case SAL_FFT3M_ROPX:
        case SAL_FFT3M_ZROPX:
        case SAL_FFT5_ROPX:
        case SAL_FFT5_ROPDX:
        case SAL_FFT5_ZROPX:
        case SAL_FFT5_ZROPDX:
        case SAL_FFT5M_ROPX:
        case SAL_FFT5M_ZROPX:
        case SAL_FFT_RIPX:
        case SAL_FFT_RIPDX:
        case SAL_FFT_ROPX:
        case SAL_FFT_ROPDX:
        case SAL_FFT_ZRIPX:
        case SAL_FFT_ZRIPDX:
        case SAL_FFT_ZROPX:
        case SAL_FFT_ZROPDX:
        case SAL_FFTM_RIPX:
        case SAL_FFTM_RIPDX:
        case SAL_FFTM_ROPX:
        case SAL_FFTM_ROPDX:
        case SAL_FFTM_ZRIPX:
        case SAL_FFTM_ZRIPDX:
        case SAL_FFTM_ZROPX:
        case SAL_FFTM_ZROPDX:
            fft_type_flag |= FFT_REAL_ONLY;
            break;

        default:
            fft_type_flag |= 0;
            break;
    }

    switch ( fft_type )
    {
        case SAL_FFT2D_ZIPDX:
        case SAL_FFT2D_ZIPX:
        case SAL_FFT2D_ZOPDX:
        case SAL_FFT2D_ZOPX:
        case SAL_FFT3_ZOPX:
        case SAL_FFT3_ZOPDX:
        case SAL_FFT3M_ZOPX:
        case SAL_FFT5_ZOPX:
        case SAL_FFT5_ZOPDX:
        case SAL_FFT5M_ZOPX:
        case SAL_FFT9_ZOPX:
        case SAL_FFT_ZIPDX:
        case SAL_FFT_ZIPX:
        case SAL_FFT_ZOPDX:
        case SAL_FFT_ZOPX:
        case SAL_FFTM_ZIPDX:
        case SAL_FFTM_ZIPX:
        case SAL_FFTM_ZOPDX:
        case SAL_FFTM_ZOPX:
            fft_type_flag |= FFT_COMPLEX_SPLIT_ONLY;
            break;

        default:
            fft_type_flag |= 0;
            break;
    }

    switch ( fft_type )
    {
        case SAL_FFT2D_CIPDX:
        case SAL_FFT2D_CIPX:
        case SAL_FFT2D_COPDX:
        case SAL_FFT2D_COPX:
        case SAL_FFT3_COPX:
        case SAL_FFT3_COPDX:
        case SAL_FFT3M_COPX:
        case SAL_FFT5_COPX:
        case SAL_FFT5_COPDX:
        case SAL_FFT5M_COPX:
        case SAL_FFT9_COPX:
        case SAL_FFT_CIPDX:
        case SAL_FFT_CIPX:
        case SAL_FFT_COPDX:
        case SAL_FFT_COPX:
        case SAL_FFTM_CIPDX:
        case SAL_FFTM_CIPX:
        case SAL_FFTM_COPDX:
        case SAL_FFTM_COPX:
            fft_type_flag |= FFT_COMPLEX_INTERLEAVED_ONLY;
            break;

        default:
            fft_type_flag |= 0;
            break;
    }

    switch ( fft_type )
    {
        case SAL_FFT2D_CIPX:
        case SAL_FFT2D_COPX:
        case SAL_FFT2D_RIPX:
        case SAL_FFT2D_ROPX:
        case SAL_FFT2D_ZIPX:
        case SAL_FFT2D_ZOPX:
        case SAL_FFT2D_ZRIPX:
        case SAL_FFT2D_ZROPX:
        case SAL_FFT2D_CIPDX:
        case SAL_FFT2D_COPDX:
        case SAL_FFT2D_RIPDX:
        case SAL_FFT2D_ROPDX:
        case SAL_FFT2D_ZIPDX:
        case SAL_FFT2D_ZOPDX:
        case SAL_FFT2D_ZRIPDX:
        case SAL_FFT2D_ZROPDX:
            fft_type_flag |= 0;
            break;

        default:
            fft_type_flag |= FFT_IS_1D;
            break;
    }

    switch ( fft_type )
    {
        case SAL_FFT2D_CIPDX:
        case SAL_FFT2D_COPDX:
        case SAL_FFT2D_RIPDX:
        case SAL_FFT2D_ROPDX:
        case SAL_FFT2D_ZIPDX:
        case SAL_FFT2D_ZOPDX:
        case SAL_FFT2D_ZRIPDX:
        case SAL_FFT2D_ZROPDX:
        case SAL_FFT3_COPDX:
        case SAL_FFT3_ROPDX:
        case SAL_FFT3_ZOPDX:
        case SAL_FFT3_ZROPDX:
        case SAL_FFT5_COPDX:
        case SAL_FFT5_ROPDX:
        case SAL_FFT5_ZOPDX:
        case SAL_FFT5_ZROPDX:
        case SAL_FFT_CIPDX:
        case SAL_FFT_COPDX:
        case SAL_FFTM_CIPDX:
        case SAL_FFTM_COPDX:
        case SAL_FFTM_RIPDX:
        case SAL_FFTM_ROPDX:
        case SAL_FFTM_ZIPDX:
        case SAL_FFTM_ZOPDX:
        case SAL_FFTM_ZRIPDX:
        case SAL_FFTM_ZROPDX:
        case SAL_FFT_RIPDX:
        case SAL_FFT_ROPDX:
        case SAL_FFT_ZIPDX:
        case SAL_FFT_ZOPDX:
        case SAL_FFT_ZRIPDX:
        case SAL_FFT_ZROPDX:
            fft_type_flag |= FFT_IS_DOUBLE;
            break;

        default:
            fft_type_flag |= 0;
            break;
    }

    switch ( fft_type )
    {
        case SAL_FFT2D_CIPDX:
        case SAL_FFT2D_CIPX:
        case SAL_FFT2D_RIPDX:
        case SAL_FFT2D_RIPX:
        case SAL_FFT2D_ZIPDX:
        case SAL_FFT2D_ZIPX:
        case SAL_FFT2D_ZRIPDX:
        case SAL_FFT2D_ZRIPX:
        case SAL_FFT_CIPDX:
        case SAL_FFT_CIPX:
        case SAL_FFTM_CIPDX:
        case SAL_FFTM_CIPX:
        case SAL_FFTM_RIPDX:
        case SAL_FFTM_RIPX:
        case SAL_FFTM_ZIPDX:
        case SAL_FFTM_ZIPX:
        case SAL_FFTM_ZRIPDX:
        case SAL_FFTM_ZRIPX:
        case SAL_FFT_RIPDX:
        case SAL_FFT_RIPX:
        case SAL_FFT_ZIPDX:
        case SAL_FFT_ZIPX:
        case SAL_FFT_ZRIPDX:
        case SAL_FFT_ZRIPX:
            fft_type_flag |= FFT_IS_INPLACE;
            break;

        default:
            fft_type_flag |= 0;
            break;
    }

    return( fft_type_flag );
}

