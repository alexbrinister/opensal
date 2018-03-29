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
        fft1d_setupd_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "fft_internal.h"
#include "adapters.h"

SAL_i32 PREFIX( fft1d_setupd_csal ) (
    const SAL_fft1d_funcd  fft_type,
    const SAL_i32          log2m,
    const SAL_i32          opt_flag,
    FFT_setupd            *p_setup,
    SAL__return_info      *r_info
)
{
    SAL_i32 log2n = 0;
    SAL_i32 nbytes;
    void * buffer;

    if ( log2m < 2 )
    {
      SAL_RINFO_SET_CODE( r_info, SAL_INVALID_SIZE );
      SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
      SAL_RINFO_PTR_RETURN_INT( r_info );
    }

    fft_setupd_set_config_base( fft_type, 0, log2m, log2n, opt_flag, p_setup, r_info );
    SAL_RINFO_CHECK_CODE_INT(r_info);

    fft_setupd_create_csal( p_setup, opt_flag, r_info );
    SAL_RINFO_CHECK_CODE_INT(r_info);

    fft_setupd_get_n_bytes_csal( p_setup, &nbytes, SAL_RESERVED_FLAG, r_info );
    SAL_RINFO_CHECK_CODE_INT(r_info);

    buffer = ( void * )calloc( nbytes, sizeof( SAL_char ) );

    if ( !buffer )
    {
      SAL_RINFO_SET_CODE( r_info, SAL_NOT_ENOUGH_MEMORY );
      SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
      SAL_RINFO_PTR_RETURN_INT( r_info );
    }

    fft_setupd_set_buffer_csal( p_setup, buffer, nbytes, SAL_RESERVED_FLAG, r_info );
    SAL_RINFO_CHECK_CODE_INT(r_info);

    fft_setupd_init_csal( p_setup, SAL_RESERVED_FLAG, r_info );

    SAL_RINFO_PTR_RETURN_INT( r_info );
}
