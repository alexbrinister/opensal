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
        fftm_ziptx_selector.h

----------------------------------------------------------------------------
*/

#ifndef FFTM_ZIPTX_SELECTOR_H
#define FFTM_ZIPTX_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef void ( *fftm_ziptx_func )( FFT_setup *, SAL_zf32 *, SAL_i32, SAL_i32, SAL_zf32 *, SAL_ui32, SAL_ui32, SAL_i32, SAL_i32, SAL__return_info * );

    static inline void PREFIX( fftm_ziptx_selector )(
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        fftm_ziptx_func *func
    )
    {
        *func = CSAL_SUFFIX( fftm_ziptx );

        return;
    }

#ifdef __cplusplus
}
#endif

#endif
