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
        fft_freed_selector.h

----------------------------------------------------------------------------
*/

#ifndef FFT_SETUP_SELECTOR_H
#define FFT_SETUP_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef void ( *fft_freed_func )( FFT_setupd *, SAL__return_info  * );

    static inline void PREFIX( fft_freed_selector )(
        FFT_setupd     *p_setupd,
        fft_freed_func *func
    )
    {
        *func = fft_freed_base;

        return;
    }

#ifdef __cplusplus
}
#endif

#endif
