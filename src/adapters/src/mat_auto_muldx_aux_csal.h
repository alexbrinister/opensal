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
        mat_auto_muldx_aux_csal.h

----------------------------------------------------------------------------
*/

#ifndef MAT_AUTO_MULDX_AUX_CSAL_H
#define MAT_AUTO_MULDX_AUX_CSAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <csal_internal.h>

    static SAL_i32 PREFIX( mat_auto_muldx_aa ) ( SAL_f64 *pA,
    SAL_i32 Atcols,
    SAL_f64 *pC,
    SAL_i32 Ctcols,
    SAL_i32 n_c,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 xflag );

    static SAL_i32 PREFIX( mat_auto_muldx_ata ) ( SAL_f64 *pA,
            SAL_i32 Atcols,
            SAL_f64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag );

    static SAL_i32 PREFIX( mat_auto_muldx_aat ) ( SAL_f64 *pA,
            SAL_i32 Atcols,
            SAL_f64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag );

    static SAL_i32 PREFIX( mat_auto_muldx_atat ) ( SAL_f64 *pA,
            SAL_i32 Atcols,
            SAL_f64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag );

    static SAL_i32 PREFIX( mat_auto_muldx_aa ) ( SAL_f64 *pA,
            SAL_i32 Atcols,
            SAL_f64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_f64 result;

        SAL_f64 src_r;
        SAL_f64 src_l;

        ( void )xflag;

        if ( N != n_c )
        {
            return ( SAL_INVALID_ARGUMENT );
        }

        if ( Atcols == 0 )
        {
            Atcols = n_c;
        }

        if ( Ctcols == 0 )
        {
            Ctcols = n_c;
        }

        for ( i = 0; i < n_c; i++ )
        {
            for ( j = 0; j < n_c; j++ )
            {
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ] : 0.0;

                for ( k = 0; k < n_c; k++ )
                {
                    src_l = pA [ ( i * Atcols ) + k ];
                    src_r = pA [ ( k * Atcols ) + j ];

                    result += ( src_r * src_l );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( mat_auto_muldx_ata ) ( SAL_f64 *pA,
            SAL_i32 Atcols,
            SAL_f64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_f64 result;

        SAL_f64 src_r;
        SAL_f64 src_l;

        ( void )xflag;

        if ( Atcols == 0 )
        {
            Atcols = n_c;
        }

        if ( Ctcols == 0 )
        {
            Ctcols = n_c;
        }

        for ( i = 0; i < n_c; i++ )
        {
            for ( j = 0; j < n_c; j++ )
            {
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ] : 0.0;

                for ( k = 0; k < N; k++ )
                {
                    src_l = pA [ ( k * Atcols ) + i ];
                    src_r = pA [ ( k * Atcols ) + j ];

                    result += ( src_r * src_l );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( mat_auto_muldx_aat ) ( SAL_f64 *pA,
            SAL_i32 Atcols,
            SAL_f64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_f64 result;

        SAL_f64 src_r;
        SAL_f64 src_l;

        ( void )xflag;

        if ( Atcols == 0 )
        {
            Atcols = N;
        }

        if ( Ctcols == 0 )
        {
            Ctcols = n_c;
        }

        for ( i = 0; i < n_c; i++ )
        {
            for ( j = 0; j < n_c; j++ )
            {
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ] : 0.0;

                for ( k = 0; k < N; k++ )
                {
                    src_l = pA [ ( i * Atcols ) + k ];
                    src_r = pA [ ( j * Atcols ) + k ];

                    result += ( src_r * src_l );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( mat_auto_muldx_atat ) ( SAL_f64 *pA,
            SAL_i32 Atcols,
            SAL_f64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_f64 result;

        SAL_f64 src_r;
        SAL_f64 src_l;

        ( void )xflag;

        if ( N != n_c )
        {
            return ( SAL_INVALID_ARGUMENT );
        }

        if ( Atcols == 0 )
        {
            Atcols = n_c;
        }

        if ( Ctcols == 0 )
        {
            Ctcols = n_c;
        }

        for ( i = 0; i < n_c; i++ )
        {
            for ( j = 0; j < n_c; j++ )
            {
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ] : 0.0;

                for ( k = 0; k < N; k++ )
                {
                    src_l = pA [ ( k * Atcols ) + i ];
                    src_r = pA [ ( j * Atcols ) + k ];

                    result += ( src_r * src_l );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

#ifdef __cplusplus
}
#endif

#endif
