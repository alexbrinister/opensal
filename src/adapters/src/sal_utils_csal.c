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
        sal_utils_csal.c

----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sal.h"
#include "csal_struct.h"

SAL_i32  sal_libs_available = 0;

SAL_i32 sal_print_info(
    SAL_struct *p_sal_struct,
    const SAL_char *user_msg,
    FILE  *user_file_ptr,
    const  SAL_i32  flag )
{
    FILE  *file_ptr = user_file_ptr;

    if ( file_ptr == NULL )
        file_ptr = stdout;

    const SAL_char *msg = user_msg;

    if ( msg == NULL )
        msg = "";

    fprintf( file_ptr, "SAL_handle id %d\n", p_sal_struct->lib_id );
    return 0;
}

SAL_i32 sal_get_n_workers_used( SAL_struct *p_sal_struct, SAL_i32 *p_n_workers_used )
{
    ( void )p_sal_struct;
    *p_n_workers_used = SAL_SINGLE_USED;
    return 0;
}

SAL_i32 sal_set_worker_wait_behavior( SAL_struct *p_sal_struct, SAL_i32 flag )
{
    ( void )p_sal_struct;
    return 0;
}

SAL_i32 sal_get_worker_wait_behavior( SAL_struct *p_sal_struct, SAL_i32 *p_flag )
{
    ( void )p_sal_struct;
    if ( p_flag ) *p_flag = -1;
    return 0;
}

SAL_i32 sal_set_workers_poll( SAL_struct *p_sal_struct, SAL_i32 in_workers_poll )
{
    ( void )p_sal_struct;
    return 0;
}

SAL_i32 set_sal_libs_available( SAL_i32 libs_setting )
{
    sal_libs_available = libs_setting;
    return 0;
}

SAL_i32 get_sal_libs_available( SAL_i32 *p_libs_setting )
{
    *p_libs_setting = sal_libs_available;
    return 0;
}

void print_sal_libs_available( void )
{
    printf( "Available libraries: CSAL.\n" );
    return;
}

