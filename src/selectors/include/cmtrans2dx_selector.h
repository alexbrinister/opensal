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
        cmtrans2dx_selector.h

----------------------------------------------------------------------------
*/

#ifndef CMTRANS2DX_SELECTOR_H
#define CMTRANS2DX_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef void ( *cmtrans2dx_func )( SAL_cf64 *, SAL_cf64 *, SAL_i32, SAL_i32, SAL_i32, SAL_i32, SAL_i32, SAL__return_info * );

    static inline void PREFIX( cmtrans2dx_selector )(
        SAL_cf64 *c_A,
        SAL_cf64 *c_C,
        SAL_i32 NC,
        SAL_i32 NR,
        SAL_i32 TCA,
        SAL_i32 TCC,
        SAL_i32 XFLAG,
        cmtrans2dx_func *func
    )
    {
        *func = CSAL_SUFFIX( cmtrans2dx );

        return;
    }

#ifdef __cplusplus
}
#endif

#endif
