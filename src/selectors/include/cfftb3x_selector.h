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
        cfftb3x_selector.h

----------------------------------------------------------------------------
*/

#ifndef CFFTB3X_SELECTOR_H
#define CFFTB3X_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef void ( *cfftb3x_func )( SAL_cf32 *, SAL_cf32 *, SAL_cf32 *, SAL_i32, SAL_i32, SAL_i32, SAL__return_info * );

    static inline void PREFIX( cfftb3x_selector )(
        SAL_cf32 *A,
        SAL_cf32 *W3,
        SAL_cf32 *C,
        SAL_i32 M,
        SAL_i32 F,
        SAL_i32 XFLAG,
        cfftb3x_func *func
    )
    {
        *func = CSAL_SUFFIX( cfftb3x );

        return;
    }

#ifdef __cplusplus
}
#endif

#endif
