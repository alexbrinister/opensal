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
        rfftodx_selector.h

----------------------------------------------------------------------------
*/

#ifndef RFFTODX_SELECTOR_H
#define RFFTODX_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef void ( *rfftodx_func )( SAL_f64 *, SAL_f64 *, SAL_f64 *, SAL_i32, SAL_i32, SAL_i32, SAL__return_info * );

    static inline void PREFIX( rfftodx_selector )(
        SAL_f64 *c,
        SAL_f64 *t,
        SAL_f64 *d,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        rfftodx_func *func
    )
    {
        *func = CSAL_SUFFIX( rfftodx );

        return;
    }

#ifdef __cplusplus
}
#endif

#endif