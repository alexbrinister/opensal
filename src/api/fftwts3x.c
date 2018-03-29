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
        fftwts3x.c

    Description:

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "fftwts3x_selector.h"

SAL_STATUS PREFIX( fftwts3 )(
    SAL_cf32 *W3,
    SAL_i32 M
)
{
    SAL_CALL_RETURN( PREFIX( fftwts3x )( W3, M, SAL_NX ) );
}

SAL_STATUS PREFIX( fftwts3x )(
    SAL_cf32 *W3,
    SAL_i32 M,
    SAL_i32 XFLAG
)
{
    fftwts3x_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( fftwts3x_selector )( W3, M, XFLAG, &func );

    ( * func )( W3, M, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

