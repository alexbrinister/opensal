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
        cmat_mgs_solrhrx.c

    Description:
        Matrix MGS QR Solutions

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "cmat_mgs_solrhrx_selector.h"

SAL_STATUS_INT PREFIX( cmat_mgs_solrhr_ )(
    SAL_cf32 *R,
    SAL_i32 *R_tcols,
    SAL_cf32 *B,
    SAL_cf32 *X,
    SAL_i32 *n,
    SAL_i32 *flag
)
{
    SAL_i32 retval;

    retval = PREFIX( cmat_mgs_solrhrx )( R, *R_tcols, B, X, *n, *flag, SAL_NN );

    return( retval );
}

SAL_STATUS_INT PREFIX( cmat_mgs_solrhrx_ )(
    SAL_cf32 *R,
    SAL_i32 *R_tcols,
    SAL_cf32 *B,
    SAL_cf32 *X,
    SAL_i32 *n,
    SAL_i32 *flag,
    SAL_i32 *xflag
)
{
    SAL_i32 retval;

    retval = PREFIX( cmat_mgs_solrhrx )( R, *R_tcols, B, X, *n, *flag, *xflag );

    return( retval );
}

SAL_STATUS_INT PREFIX( cmat_mgs_solrhr )(
    SAL_cf32 *R,
    SAL_i32 R_tcols,
    SAL_cf32 *B,
    SAL_cf32 *X,
    SAL_i32 n,
    SAL_i32 flag
)
{
    SAL_i32 retval;

    retval = PREFIX( cmat_mgs_solrhrx )( R, R_tcols, B, X, n, flag, SAL_NN );

    return( retval );
}

SAL_STATUS_INT PREFIX( cmat_mgs_solrhrx )(
    SAL_cf32 *c_R,
    SAL_i32 R_tcols,
    SAL_cf32 *c_B,
    SAL_cf32 *c_X,
    SAL_i32 n,
    SAL_i32 flag,
    SAL_i32 xflag
)
{
    cmat_mgs_solrhrx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( cmat_mgs_solrhrx_selector )( c_R, R_tcols, c_B, c_X, n, flag, xflag, &func );

    ( * func )( c_R, R_tcols, c_B, c_X, n, flag, xflag, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN_INT( r_info );
}

