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
        sal_get_path_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "csal_internal.h"

SAL_i32 PREFIX( sal__path ) = SAL_PATH_NOTHING;

SAL_i32 PREFIX( sal_get_path_ )( SAL_i32 *flag )
{
    return( PREFIX( sal_get_path )( *flag ) );
}

SAL_i32 PREFIX( sal_get_path )( SAL_i32 flag )
{
    SAL_i32 path;

    ( void )flag;

    path = PREFIX( sal__path );

    if ( path > SAL_PATH_UNKNOWN )
    {
        path = SAL_PATH_UNKNOWN;
    }

    SAL_SET_PATH_NOTHING();

    return( path );
}

