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
        zmat_chol_decx.c

    Description:
        Matrix Cholesky Decomposition and Condition

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "zmat_chol_decx_selector.h"

SAL_STATUS_INT PREFIX( zmat_chol_decx_ )(
    SAL_zf32 *A,
    SAL_i32 *Atcols,
    SAL_zf32 *LDU,
    SAL_i32 *LDUtcols,
    SAL_i32 *n,
    SAL_f32 *rcond_est,
    SAL_zf32 *v,
    SAL_i32 *flag,
    SAL_i32 *xflag
)
{
    SAL_i32 retval;

    retval = PREFIX( zmat_chol_decx )( A, *Atcols, LDU, *LDUtcols, *n, rcond_est,
                                       v, *flag, *xflag );
    return( retval );
}

SAL_STATUS_INT PREFIX( zmat_chol_dec_ )(
    SAL_zf32 *A,
    SAL_i32 *Atcols,
    SAL_zf32 *LDU,
    SAL_i32 *LDUtcols,
    SAL_i32 *n,
    SAL_f32 *rcond_est,
    SAL_zf32 *v,
    SAL_i32 *flag
)
{
    SAL_i32 retval;

    retval = PREFIX( zmat_chol_decx )( A, *Atcols, LDU, *LDUtcols, *n, rcond_est,
                                       v, *flag, SAL_NNN );
    return( retval );
}

SAL_STATUS_INT PREFIX( zmat_chol_dec )(
    SAL_zf32 *A,
    SAL_i32 Atcols,
    SAL_zf32 *LDU,
    SAL_i32 LDUtcols,
    SAL_i32 n,
    SAL_f32 *rcond_est,
    SAL_zf32 *v,
    SAL_i32 flag
)
{
    SAL_i32 retval;

    retval = PREFIX( zmat_chol_decx )( A, Atcols, LDU, LDUtcols, n, rcond_est,
                                       v, flag, SAL_NNN );
    return( retval );
}

SAL_STATUS_INT PREFIX( zmat_chol_decx )(
    SAL_zf32 *A,
    SAL_i32 Atcols,
    SAL_zf32 *LDU,
    SAL_i32 LDUtcols,
    SAL_i32 n,
    SAL_f32 *rcond_est,
    SAL_zf32 *v,
    SAL_i32 flag,
    SAL_i32 xflag
)
{
    zmat_chol_decx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( zmat_chol_decx_selector )( A, Atcols, LDU, LDUtcols, n, rcond_est, v, flag, xflag, &func );

    ( * func )( A, Atcols, LDU, LDUtcols, n, rcond_est, v, flag, xflag, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN_INT( r_info );
}

