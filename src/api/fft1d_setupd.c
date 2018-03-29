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
        fft1d_setupd.c

    Description:

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fft1d_setupd_selector.h"

SAL_STATUS_INT PREFIX( fft1d_setupd_ )(
    const SAL_fft1d_funcd *FFT_TYPE_FLAG,
    const SAL_i32 *LOG2N,
    const SAL_i32 *OPT_FLAG,
    FFT_setupd *SETUPP
)
{
    SAL_CALL_RETURN( PREFIX( fft1d_setupd )( *FFT_TYPE_FLAG, *LOG2N, *OPT_FLAG, SETUPP ) );

    return SAL_SUCCESS;
}

SAL_STATUS_INT PREFIX( fft1d_setupd )(
    const SAL_fft1d_funcd FFT_TYPE_FLAG,
    const SAL_i32 LOG2N,
    const SAL_i32 OPT_FLAG,
    FFT_setupd *SETUPP
)
{
    fft1d_setupd_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fft1d_setupd_selector )( FFT_TYPE_FLAG, LOG2N, OPT_FLAG, SETUPP, &func );

    ( * func )( FFT_TYPE_FLAG, LOG2N, OPT_FLAG, SETUPP, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN_INT( r_info );
}

