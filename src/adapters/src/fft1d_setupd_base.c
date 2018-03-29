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
        fft1d_setupd_base.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "adapters.h"
#include "fft_internal.h"

SAL_i32 PREFIX( fft1d_setupd_base )(
    const SAL_fft1d_funcd fft_type,
    const SAL_i32 log2m,
    const SAL_i32 opt_flag,
    FFT_setupd *p_setup,
    SAL__return_info *r_info
)
{
    unsigned long alloc_size;
    SAL_i32 log2n = 0;

    if ( ( fft_type <= SAL_FFT1D_FUNCD_LB ) ||
         ( fft_type >= SAL_FFT1D_FUNCD_UB ) )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_FFT_NOT_SUPPORTED );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_PTR_RETURN_INT( r_info );
    }

    if ( !( p_setup && *p_setup ) )
    {
        alloc_size = sizeof( SAL__fft_setupd );
        *p_setup = ( FFT_setupd ) calloc( alloc_size, sizeof( SAL_char ) );

        if ( !( *p_setup ) )
        {
            SAL_RINFO_SET_CODE( r_info, SAL_NOT_ENOUGH_MEMORY );
            SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
            SAL_RINFO_PTR_RETURN_INT( r_info );
        }

    }

    fft_setupd_create_base( fft_type, log2m, log2n, opt_flag, p_setup, r_info );
    SAL_RINFO_CHECK_CODE_INT(r_info);

    fft_setupd_init_base( p_setup, SAL_RESERVED_FLAG, r_info );

    SAL_RINFO_PTR_RETURN_INT( r_info );
}

