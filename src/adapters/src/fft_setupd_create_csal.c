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
        fft_setupd_create_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "fft_internal.h"
#include "adapters.h"

SAL_i32 PREFIX( fft_setupd_create_csal ) (
    FFT_setupd           *p_setup,
    const SAL_i32             opt_flag,
    SAL__return_info     *r_info
)
{
    SAL_i32 nbytes;

    if ( ( ( *p_setup )->fft_setup_config_base->log2m < 2 ) &&
         ( ( *p_setup )->fft_setup_config_base->log2n < 2 ) )
    {
        SAL_RINFO_SET_CODE( r_info, SAL_INVALID_SIZE );
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_PTR_RETURN_INT( r_info );
    }

    PREFIX( fft_setupd_get_n_bytes_csal )( p_setup, &nbytes, SAL_RESERVED_FLAG, r_info );

    SAL_RINFO_PTR_RETURN_INT( r_info );
}
