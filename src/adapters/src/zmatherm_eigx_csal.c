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
        zmatherm_eigx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <math.h>
#include <stdlib.h>
#include "csal_internal.h"

void PREFIX( zmatherm_eigx_csal )(
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
    SAL_i32 X,
    SAL__return_info *r_info
)
{
    SAL_f32 *Evecr;
    SAL_f32 *Tau, *subD;
    SAL_i32 ierr, i;
    SAL_f32 emin, emax;
    SAL_f32 *Buf;

    ( void )Tune;
    ( void )Flag;
    ( void )X;

    Buf = ( SAL_f32 * )malloc( 3 * N * sizeof( SAL_f32 ) );

    if ( Buf == NULL )
    {
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_SET_CODE( r_info, -1 );
        return;
    }

    Tau = Buf;

    subD = Buf + 2 * N;

    if ( Evec )
    {
        Evecr = Evec->realp;
    }
    else
    {
        Evecr = NULL;
    }

    PREFIX( _csal_zhtridi )( A, Atcols, Eval, subD, Tau, N );

    ierr = PREFIX( _csal_tql2 )( Eval, subD, Evecr, Etcols, N );

    if ( ierr )
    {
        if ( Buf ) free( Buf );

        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_SET_CODE( r_info, ierr );
        return;
    }

    if ( Ind_v )
    {
        PREFIX( _csal_sortabsi )( Eval, Ind_v, N );

        if ( Condn )
        {
            *Condn = fabs( Eval[Ind_v[0]] / Eval[Ind_v[N - 1]] );
        }
    }
    else
    {
        if ( Condn )
        {
            emax = fabs( Eval[0] );
            emin = emax;

            for ( i = 1; i < N; i++ )
            {
                if ( fabs( Eval[i] ) > emax )
                    emax = fabs( Eval[i] );
                else if ( fabs( Eval[i] ) < emin )
                    emin = fabs( Eval[i] );
            }

            *Condn = emax / emin;
        }
    }

    if ( Evec )
    {
        PREFIX( _csal_zhtribk )( A, Evec, Tau, Atcols, Etcols, N );
    }

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );

    free( Buf );

    SAL_RINFO_SET_CODE( r_info, ierr );
    return;
}

