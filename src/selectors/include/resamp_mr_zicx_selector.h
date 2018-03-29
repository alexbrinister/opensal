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
        resamp_mr_zicx_selector.h

----------------------------------------------------------------------------
*/

#ifndef RESAMP_MR_ZICX_SELECTOR_H
#define RESAMP_MR_ZICX_SELECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "adapters.h"

    typedef void ( *resamp_mr_zicx_func )( SAL_resamp_map, SAL_i32, SAL_i32, SAL_zf32 *, SAL_i32, SAL_zf32 *, SAL_i32, SAL_i32, SAL_i32, SAL_i32, SAL_i32, SAL__return_info * );

    static inline void PREFIX( resamp_mr_zicx_selector )(
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_zf32 *input,
        SAL_i32 input_tcols,
        SAL_zf32 *output,
        SAL_i32 output_tcols,
        SAL_i32 input_len,
        SAL_i32 num_rows,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        resamp_mr_zicx_func *func
    )
    {
        *func = CSAL_SUFFIX( resamp_mr_zicx );

        return;
    }

#ifdef __cplusplus
}
#endif

#endif
