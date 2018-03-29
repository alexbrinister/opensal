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
        zmat_auto_muldx.c

    Description:
        Matrix Auto-Multiply; Matrix Covariance

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "zmat_auto_muldx_selector.h"

SAL_STATUS_INT PREFIX( zmat_auto_muld )(
    SAL_zf64 *pA,
    SAL_i32 Atcols,
    SAL_zf64 *pC,
    SAL_i32 Ctcols,
    SAL_i32 n_c,
    SAL_i32 N,
    SAL_i32 flag
)
{
    SAL_i32 rc;

    rc = PREFIX( zmat_auto_muldx )( pA,
                                    Atcols,
                                    pC,
                                    Ctcols,
                                    n_c,
                                    N,
                                    flag,
                                    SAL_NN );
    return ( rc );
}

SAL_STATUS_INT PREFIX( zmat_auto_muld_ )(
    SAL_zf64 *pA,
    SAL_i32 *Atcols,
    SAL_zf64 *pC,
    SAL_i32 *Ctcols,
    SAL_i32 *n_c,
    SAL_i32 *N,
    SAL_i32 *flag
)
{
    SAL_i32 rc;

    rc = PREFIX( zmat_auto_muldx )( pA,
                                    *Atcols,
                                    pC,
                                    *Ctcols,
                                    *n_c,
                                    *N,
                                    *flag,
                                    SAL_NN );
    return ( rc );
}

SAL_STATUS_INT PREFIX( zmat_auto_muldx_ )(
    SAL_zf64 *pA,
    SAL_i32 *Atcols,
    SAL_zf64 *pC,
    SAL_i32 *Ctcols,
    SAL_i32 *n_c,
    SAL_i32 *N,
    SAL_i32 *flag,
    SAL_i32 *xflag
)
{
    SAL_i32 rc;

    rc = PREFIX( zmat_auto_muldx )( pA,
                                    *Atcols,
                                    pC,
                                    *Ctcols,
                                    *n_c,
                                    *N,
                                    *flag,
                                    *xflag );
    return ( rc );
}

SAL_STATUS_INT PREFIX( zmat_auto_muldx )(
    SAL_zf64 *pA,
    SAL_i32 Atcols,
    SAL_zf64 *pC,
    SAL_i32 Ctcols,
    SAL_i32 n_c,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 xflag
)
{
    zmat_auto_muldx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( zmat_auto_muldx_selector )( pA, Atcols, pC, Ctcols, n_c, N, flag, xflag, &func );

    ( * func )( pA, Atcols, pC, Ctcols, n_c, N, flag, xflag, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN_INT( r_info );
}

