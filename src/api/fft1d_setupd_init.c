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
        fft1d_setupd_init.c

    Description:

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fft1d_setupd_init_selector.h"

SAL_STATUS_INT PREFIX( fft1d_setupd_init_ )(
    FFT_setupd          *p_setup,
    const SAL_i32           *flag
)
{
    SAL_CALL_RETURN( PREFIX( fft1d_setupd_init )( p_setup, *flag ) );

    return SAL_SUCCESS;
}

SAL_STATUS_INT PREFIX( fft1d_setupd_init )(
    FFT_setupd          *p_setup,
    const SAL_i32            flag
)
{
    fft1d_setupd_init_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fft1d_setupd_init_selector )( p_setup, flag, &func );

    ( * func )( p_setup, flag, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN_INT( r_info );
}

