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
        sal_create.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include "sal.h"
#include "sal_csal_common_internal.h"
#include "sal_struct.h"

SAL_i32 sal_create_default( SAL_struct *sal_struct );

SAL_i32 sal_create( SAL_struct **pp_sal_struct )
{
    SAL_struct *sal_struct = ( SAL_struct * )calloc( 1, sizeof( SAL_struct ) );

    if ( sal_struct == NULL )
    {
        fprintf( stderr, "ERROR Cannot allocate SAL_struct\n" );
        exit( 1 );
    }

    sal_struct->lib_id = SAL_LIB_ID;

    sal_struct->state = 0;

    sal_create_default( sal_struct );

    *pp_sal_struct = sal_struct;

    return 0;
}

