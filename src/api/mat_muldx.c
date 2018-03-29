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
        mat_muldx.c

    Description:
        Matrix Multiply, With Column Strides

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "mat_muldx_selector.h"

SAL_STATUS_INT PREFIX( mat_muld )(
    SAL_f64 *pA,
    SAL_i32 Atcols,
    SAL_f64 *pB,
    SAL_i32 Btcols,
    SAL_f64 *pC,
    SAL_i32 Ctcols,
    SAL_i32 nr_c,
    SAL_i32 nc_c,
    SAL_i32 N,
    SAL_i32 flag
)
{
    SAL_i32 rc;

    rc = PREFIX( mat_muldx )( pA,
                              Atcols,
                              pB,
                              Btcols,
                              pC,
                              Ctcols,
                              nr_c,
                              nc_c,
                              N,
                              flag,
                              SAL_NNN );
    return ( rc );
}

SAL_STATUS_INT PREFIX( mat_muld_ )(
    SAL_f64 *pA,
    SAL_i32 *Atcols,
    SAL_f64 *pB,
    SAL_i32 *Btcols,
    SAL_f64 *pC,
    SAL_i32 *Ctcols,
    SAL_i32 *nr_c,
    SAL_i32 *nc_c,
    SAL_i32 *N,
    SAL_i32 *flag
)
{
    SAL_i32 rc;

    rc = PREFIX( mat_muldx )( pA,
                              *Atcols,
                              pB,
                              *Btcols,
                              pC,
                              *Ctcols,
                              *nr_c,
                              *nc_c,
                              *N,
                              *flag,
                              SAL_NNN );
    return ( rc );
}

SAL_STATUS_INT PREFIX( mat_muldx_ )(
    SAL_f64 *pA,
    SAL_i32 *Atcols,
    SAL_f64 *pB,
    SAL_i32 *Btcols,
    SAL_f64 *pC,
    SAL_i32 *Ctcols,
    SAL_i32 *nr_c,
    SAL_i32 *nc_c,
    SAL_i32 *N,
    SAL_i32 *flag,
    SAL_i32 *xflag
)
{
    SAL_i32 rc;

    rc = PREFIX( mat_muldx )( pA,
                              *Atcols,
                              pB,
                              *Btcols,
                              pC,
                              *Ctcols,
                              *nr_c,
                              *nc_c,
                              *N,
                              *flag,
                              *xflag );
    return ( rc );
}

SAL_STATUS_INT PREFIX( mat_muldx )(
    SAL_f64 *pA,
    SAL_i32 Atcols,
    SAL_f64 *pB,
    SAL_i32 Btcols,
    SAL_f64 *pC,
    SAL_i32 Ctcols,
    SAL_i32 nr_c,
    SAL_i32 nc_c,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 xflag
)
{
    mat_muldx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( mat_muldx_selector )( pA, Atcols, pB, Btcols, pC, Ctcols, nr_c, nc_c, N, flag, xflag, &func );

    ( * func )( pA, Atcols, pB, Btcols, pC, Ctcols, nr_c, nc_c, N, flag, xflag, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN_INT( r_info );
}

