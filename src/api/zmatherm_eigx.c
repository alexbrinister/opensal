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
        zmatherm_eigx.c

    Description:
        Eigenvalues and Eigenvectors of Hermitian Matrix

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "zmatherm_eigx_selector.h"

SAL_STATUS_INT PREFIX( zmatherm_eigx_ )(
    SAL_zf32 *A,
    SAL_i32 *Atcols,
    SAL_f32 *Eval,
    SAL_zf32 *Evec,
    SAL_i32 *Etcols,
    SAL_i32 *N,
    SAL_eig_tune *Tune,
    SAL_f32 *Condn,
    SAL_i32 *Ind_v,
    SAL_i32 *Flag,
    SAL_i32 *X
)
{
    SAL_i32 ierr;

    ierr = PREFIX( zmatherm_eigx )( A,
                                    *Atcols,
                                    Eval,
                                    Evec,
                                    *Etcols,
                                    *N,
                                    Tune,
                                    Condn,
                                    Ind_v,
                                    *Flag,
                                    *X );
    return( ierr );
}

SAL_STATUS_INT PREFIX( zmatherm_eig_ )(
    SAL_zf32 *A,
    SAL_i32 *Atcols,
    SAL_f32 *Eval,
    SAL_zf32 *Evec,
    SAL_i32 *Etcols,
    SAL_i32 *N,
    SAL_eig_tune *Tune,
    SAL_f32 *Condn,
    SAL_i32 *Ind_v,
    SAL_i32 *Flag
)
{
    SAL_i32 ierr;

    ierr = PREFIX( zmatherm_eigx )( A,
                                    *Atcols,
                                    Eval,
                                    Evec,
                                    *Etcols,
                                    *N,
                                    Tune,
                                    Condn,
                                    Ind_v,
                                    *Flag,
                                    SAL_NNN );

    return( ierr );
}

SAL_STATUS_INT PREFIX( zmatherm_eig )(
    SAL_zf32 *A,
    SAL_i32 Atcols,
    SAL_f32 *Eval,
    SAL_zf32 *Evec,
    SAL_i32 Etcols,
    SAL_i32 N,
    SAL_eig_tune *Tune,
    SAL_f32 *Condn,
    SAL_i32 *Ind_v,
    SAL_i32 Flag
)
{
    SAL_i32 ierr;

    ierr = PREFIX( zmatherm_eigx )( A,
                                    Atcols,
                                    Eval,
                                    Evec,
                                    Etcols,
                                    N,
                                    Tune,
                                    Condn,
                                    Ind_v,
                                    Flag,
                                    SAL_NNN );

    return( ierr );
}

SAL_STATUS_INT PREFIX( zmatherm_eigx )(
    SAL_zf32 *A,
    SAL_i32 Atcols,
    SAL_f32 *Eval,
    SAL_zf32 *Evec,
    SAL_i32 Etcols,
    SAL_i32 N,
    SAL_eig_tune *Tune,
    SAL_f32 *Condn,
    SAL_i32 *Ind_v,
    SAL_i32 Flag,
    SAL_i32 X
)
{
    zmatherm_eigx_func func;
    SAL__return_info r_info;

    SAL_RINFO_INIT( r_info );

    PREFIX( zmatherm_eigx_selector )( A, Atcols, Eval, Evec, Etcols, N, Tune, Condn, Ind_v, Flag, X, &func );

    ( * func )( A, Atcols, Eval, Evec, Etcols, N, Tune, Condn, Ind_v, Flag, X, &r_info );

    SAL_SET_PATH( r_info.path );

    SAL_RINFO_RETURN_INT( r_info );
}

