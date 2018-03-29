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
        csal_resamp_internal.h

----------------------------------------------------------------------------
*/

#ifndef CSAL_RESAMP_INTERNAL_H
#define CSAL_RESAMP_INTERNAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "csal_internal.h"

#define RESAMP_FILTER_STATE_CREATED  0x7eadbeef
#define RESAMP_FILTER_STATE_CLOSED   0x7eefdead
#define RESAMP_MAP_STATE_CREATED     0x7eadbeef
#define RESAMP_MAP_STATE_CLOSED      0x7eefdead

#define RESAMP_NAME_LAST  (SAL_ui32)SAL_RESAMP_MC_ZICX

#define RESAMP_FILTER_CREATE_FLAG_MASK  0
#define RESAMP_FILTER_CLOSE_FLAG_MASK  0
#define RESAMP_MAP_CREATE_FLAG_MASK  ( SAL_RESAMP_ZERO_OUT_OF_BOUNDS | \
    SAL_RESAMP_TAPER_OUT_OF_BOUNDS )
#define RESAMP_MAP_CLOSE_FLAG_MASK  0
#define RESAMP_IC_FLAG_MASK  ( SAL_RESAMP_ACCUMULATE )
#define RESAMP_OC_FLAG_MASK  ( SAL_RESAMP_ACCUMULATE )

    typedef struct sal__resamp_filter
    {
        void           *alloc_handle;
        SAL_f32        *filter_setp;
        SAL_i32         state;
        SAL_i32         ref_count;
        SAL_i32         num_bytes;
        SAL_i32         filter_len;
        SAL_i32         signal_start_offset;
        SAL_i32         num_filters;
        SAL_resamp_name resamp_name;
        SAL_i32         filter_create_flag;
    } SAL__resamp_filter;

    typedef struct
    {
        SAL_i32 filter_start_index;
        SAL_i32 signal_start_index;
        SAL_i32 num_pts;
    } resamp_map_desc;

    typedef struct sal__resamp_map
    {
        void               *alloc_handle;
        SAL__resamp_filter *filter_object;
        resamp_map_desc    *map_setp;
        SAL_i32             state;
        SAL_i32             num_bytes;
        SAL_i32             map_len;
        SAL_i32             num_maps;
        SAL_i32             signal_len;
        SAL_i32             map_create_flag;
    } SAL__resamp_map;

    extern void PREFIX( _csal_resamp_roc ) ( resamp_map_desc *mapp,
            SAL_f32 *filterp, SAL_f32 *inp, SAL_i32 inx,
            SAL_f32 *outp, SAL_i32 outx, SAL_i32 num_out_pts,
            SAL_i32 accum_flag );

    extern void PREFIX( _csal_resamp_coc ) ( resamp_map_desc *mapp,
            SAL_f32 *filterp, SAL_cf32 *inp, SAL_i32 inx,
            SAL_cf32 *outp, SAL_i32 outx, SAL_i32 num_out_pts,
            SAL_i32 accum_flag );

    extern void PREFIX( _csal_resamp_zoc ) ( resamp_map_desc *mapp,
            SAL_f32 *filterp, SAL_zf32 *inp, SAL_i32 inx,
            SAL_zf32 *outp, SAL_i32 outx, SAL_i32 num_out_pts,
            SAL_i32 accum_flag );

    extern void PREFIX( _csal_resamp_ric ) ( resamp_map_desc *mapp,
            SAL_f32 *filterp, SAL_f32 *inp, SAL_i32 inx,
            SAL_f32 *outp, SAL_i32 outx, SAL_i32 num_in_pts,
            SAL_i32 tot_out_pts );

    extern void PREFIX( _csal_resamp_cic ) ( resamp_map_desc *mapp,
            SAL_f32 *filterp, SAL_cf32 *inp, SAL_i32 inx,
            SAL_cf32 *outp, SAL_i32 outx, SAL_i32 num_in_pts,
            SAL_i32 tot_out_pts );

    extern void PREFIX( _csal_resamp_zic ) ( resamp_map_desc *mapp,
            SAL_f32 *filterp, SAL_zf32 *inp, SAL_i32 inx,
            SAL_zf32 *outp, SAL_i32 outx, SAL_i32 num_in_pts,
            SAL_i32 tot_out_pts );

#ifdef __cplusplus
}
#endif

#endif
