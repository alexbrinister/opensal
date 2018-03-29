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
        mat_mgs_solrhrx_selector.h

----------------------------------------------------------------------------
*/

#ifndef MAT_MGS_SOLRHRX_SELECTOR_H
#define MAT_MGS_SOLRHRX_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef void ( *mat_mgs_solrhrx_func )( SAL_f32 *, SAL_i32, SAL_f32 *, SAL_f32 *, SAL_i32, SAL_i32, SAL_i32, SAL__return_info * );

    static inline void PREFIX( mat_mgs_solrhrx_selector )(
        SAL_f32 *R,
        SAL_i32 R_tcols,
        SAL_f32 *B,
        SAL_f32 *X,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        mat_mgs_solrhrx_func *func
    )
    {
        *func = CSAL_SUFFIX( mat_mgs_solrhrx );

        return;
    }

#ifdef __cplusplus
}
#endif

#endif
