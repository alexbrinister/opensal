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
        mat_chol_solx.c

    Description:
        Matrix Cholesky solver

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "mat_chol_solx_selector.h"

SAL_STATUS_INT PREFIX( mat_chol_sol_ )(
    SAL_f32 *LDU,
    SAL_i32 *LDUtcols,
    SAL_f32 *b,
    SAL_f32 *w,
    SAL_i32 *n,
    SAL_i32 *flag
)
{
    SAL_i32 retval;

    retval = PREFIX( mat_chol_solx )( LDU, *LDUtcols, b, w, *n, *flag, SAL_NNN );
    return( retval );
}

SAL_STATUS_INT PREFIX( mat_chol_solx_ )(
    SAL_f32 *LDU,
    SAL_i32 *LDUtcols,
    SAL_f32 *b,
    SAL_f32 *w,
    SAL_i32 *n,
    SAL_i32 *flag,
    SAL_i32 *xflag
)
{
    SAL_i32 retval;

    retval = PREFIX( mat_chol_solx )( LDU, *LDUtcols, b, w, *n, *flag, *xflag );
    return( retval );
}

SAL_STATUS_INT PREFIX( mat_chol_sol )(
    SAL_f32 *LDU,
    SAL_i32 LDUtcols,
    SAL_f32 *b,
    SAL_f32 *w,
    SAL_i32 n,
    SAL_i32 flag
)
{
    SAL_i32 retval;

    retval = PREFIX( mat_chol_solx )( LDU, LDUtcols, b, w, n, flag, SAL_NNN );
    return( retval );
}

SAL_STATUS_INT PREFIX( mat_chol_solx )(
    SAL_f32 *LDU,
    SAL_i32 LDUtcols,
    SAL_f32 *b,
    SAL_f32 *w,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag
)
{
    mat_chol_solx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( mat_chol_solx_selector )( LDU, LDUtcols, b, w, n, flag, xflag, &func );

    ( * func )( LDU, LDUtcols, b, w, n, flag, xflag, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN_INT( r_info );
}

