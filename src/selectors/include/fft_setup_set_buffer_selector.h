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
        fft_setup_set_buffer_selector.h

----------------------------------------------------------------------------
*/

#ifndef FFT_SETUP_SET_BUFFER_SELECTOR_H
#define FFT_SETUP_SET_BUFFER_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef SAL_i32 ( *fft_setup_set_buffer_func )( FFT_setup *p_setup, void *buffer,
            const SAL_i32 nbytes, const SAL_i32 flag, SAL__return_info * );

    static inline void PREFIX( fft_setup_set_buffer_selector )(
        FFT_setup           *p_setup,
        void                *buffer,
        const SAL_i32            nbytes,
        const SAL_i32            flag,
        fft_setup_set_buffer_func *func
    )
    {
        *func = BASE_SUFFIX( fft_setup_set_buffer );

        return;
    }

#ifdef __cplusplus
}
#endif

#endif
