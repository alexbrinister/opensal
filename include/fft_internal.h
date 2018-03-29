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
        fft_internal.h

----------------------------------------------------------------------------
*/

#ifndef FFT_INTERNAL_H
#define FFT_INTERNAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "csal_fft_internal.h"

    typedef struct sal__fft_setup
    {
        SAL__fft_setup_config_base * fft_setup_config_base;
        struct sal__fft_setup     ** fft_setup_table;
        SAL__fft_setup_csal        * csal_fft_setup;
        SAL__fft_setup_mcsal       * mcsal_fft_setup;
    } SAL__fft_setup;

    typedef struct sal__fft_setupd
    {
        SAL__fft_setup_config_base * fft_setup_config_base;
        struct sal__fft_setupd    ** fft_setup_table;
        SAL__fft_setupd_csal       * csal_fft_setup;
        SAL__fft_setup_mcsal       * mcsal_fft_setup;
    } SAL__fft_setupd;

#ifdef __cplusplus
}
#endif

#endif

