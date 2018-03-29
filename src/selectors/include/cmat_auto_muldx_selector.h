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
        cmat_auto_muldx_selector.h

----------------------------------------------------------------------------
*/

#ifndef CMAT_AUTO_MULDX_SELECTOR_H
#define CMAT_AUTO_MULDX_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef void ( *cmat_auto_muldx_func )( SAL_cf64 *, SAL_i32, SAL_cf64 *, SAL_i32, SAL_i32, SAL_i32, SAL_i32, SAL_i32, SAL__return_info * );

    static inline void PREFIX( cmat_auto_muldx_selector )(
        SAL_cf64 *pA,
        SAL_i32 Atcols,
        SAL_cf64 *pC,
        SAL_i32 Ctcols,
        SAL_i32 n_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        cmat_auto_muldx_func *func
    )
    {
        *func = CSAL_SUFFIX( cmat_auto_muldx );

        return;
    }

#ifdef __cplusplus
}
#endif

#endif
