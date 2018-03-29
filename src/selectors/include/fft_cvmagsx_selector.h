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
        fft_cvmagsx_selector.h

----------------------------------------------------------------------------
*/

#ifndef FFT_CVMAGSX_SELECTOR_H
#define FFT_CVMAGSX_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef void ( *fft_cvmagsx_func )( FFT_setup *, SAL_cf32 *, SAL_i32, SAL_f32 *, SAL_i32, SAL_ui32, SAL_i32, SAL_i32, SAL__return_info * );

    static inline void PREFIX( fft_cvmagsx_selector )(
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        fft_cvmagsx_func *func
    )
    {
        *func = CSAL_SUFFIX( fft_cvmagsx );

        return;
    }

#ifdef __cplusplus
}
#endif

#endif
