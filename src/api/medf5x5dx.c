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
        medf5x5dx.c

    Description:
        Filter, 5 x 5 Median

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "medf5x5dx_selector.h"

SAL_STATUS PREFIX( medf5x5d )(
    SAL_f64 *A,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_f64 *C
)
{
    SAL_CALL_RETURN( PREFIX( medf5x5dx )( A, NR, NC, C, SAL_NX ) );
}

SAL_STATUS PREFIX( medf5x5dx )(
    SAL_f64 *A,
    SAL_i32 NR,
    SAL_i32 NC,
    SAL_f64 *C,
    SAL_i32 XFLAG
)
{
    medf5x5dx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( medf5x5dx_selector )( A, NR, NC, C, XFLAG, &func );

    ( * func )( A, NR, NC, C, XFLAG, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN( r_info );
}

