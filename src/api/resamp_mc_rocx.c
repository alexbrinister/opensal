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
        resamp_mc_rocx.c

    Description:
        Output-Centered Resampling Functions

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "resamp_mc_rocx_selector.h"

SAL_STATUS_INT PREFIX( resamp_mc_rocx_ )(
    SAL_resamp_map *map_handle,
    SAL_i32 *map,
    SAL_i32 *map_start_pos,
    SAL_f32 *input,
    SAL_i32 *input_tcols,
    SAL_f32 *output,
    SAL_i32 *output_tcols,
    SAL_i32 *output_len,
    SAL_i32 *num_columns,
    SAL_i32 *flag_word,
    SAL_i32 *xflag
)
{
    return ( PREFIX( resamp_mc_rocx )( *map_handle, *map, *map_start_pos,
                                       input, *input_tcols, output, *output_tcols,
                                       *output_len, *num_columns, *flag_word, *xflag ) );
}

SAL_STATUS_INT PREFIX( resamp_mc_roc_ )(
    SAL_resamp_map *map_handle,
    SAL_i32 *map,
    SAL_i32 *map_start_pos,
    SAL_f32 *input,
    SAL_i32 *input_tcols,
    SAL_f32 *output,
    SAL_i32 *output_tcols,
    SAL_i32 *output_len,
    SAL_i32 *num_columns,
    SAL_i32 *flag_word
)
{
    return ( PREFIX( resamp_mc_rocx )( *map_handle, *map, *map_start_pos,
                                       input, *input_tcols, output, *output_tcols,
                                       *output_len, *num_columns, *flag_word, SAL_NX ) );
}

SAL_STATUS_INT PREFIX( resamp_mc_roc )(
    SAL_resamp_map map_handle,
    SAL_i32 map,
    SAL_i32 map_start_pos,
    SAL_f32 *input,
    SAL_i32 input_tcols,
    SAL_f32 *output,
    SAL_i32 output_tcols,
    SAL_i32 output_len,
    SAL_i32 num_columns,
    SAL_i32 flag_word
)
{
    return ( PREFIX( resamp_mc_rocx )( map_handle, map, map_start_pos,
                                       input, input_tcols, output, output_tcols,
                                       output_len, num_columns, flag_word, SAL_NX ) );
}

SAL_STATUS_INT PREFIX( resamp_mc_rocx )(
    SAL_resamp_map map_handle,
    SAL_i32 map,
    SAL_i32 map_start_pos,
    SAL_f32 *input,
    SAL_i32 input_tcols,
    SAL_f32 *output,
    SAL_i32 output_tcols,
    SAL_i32 output_len,
    SAL_i32 num_columns,
    SAL_i32 flag_word,
    SAL_i32 xflag
)
{
    resamp_mc_rocx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( resamp_mc_rocx_selector )( map_handle, map, map_start_pos, input, input_tcols, output, output_tcols, output_len, num_columns, flag_word, xflag, &func );

    ( * func )( map_handle, map, map_start_pos, input, input_tcols, output, output_tcols, output_len, num_columns, flag_word, xflag, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN_INT( r_info );
}

