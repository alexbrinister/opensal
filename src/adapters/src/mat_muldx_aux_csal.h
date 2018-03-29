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
        mat_muldx_aux_csal.h

----------------------------------------------------------------------------
*/

#ifndef MAT_MULDX_AUX_CSAL_H
#define MAT_MULDX_AUX_CSAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <csal_internal.h>

    static SAL_i32 PREFIX( mat_mul_nn ) ( SAL_f64 *pA,
    SAL_i32 Atcols,
    SAL_f64 *pB,
    SAL_i32 Btcols,
    SAL_f64 *pC,
    SAL_i32 Ctcols,
    SAL_i32 nr_c,
    SAL_i32 nc_c,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 xflag );

    static SAL_i32 PREFIX( mat_mul_tn ) ( SAL_f64 *pAt,
                                          SAL_i32 Atcols,
                                          SAL_f64 *pB,
                                          SAL_i32 Btcols,
                                          SAL_f64 *pC,
                                          SAL_i32 Ctcols,
                                          SAL_i32 nr_c,
                                          SAL_i32 nc_c,
                                          SAL_i32 N,
                                          SAL_i32 flag,
                                          SAL_i32 xflag );

    static SAL_i32 PREFIX( mat_mul_nt ) ( SAL_f64 *pA,
                                          SAL_i32 Atcols,
                                          SAL_f64 *pBt,
                                          SAL_i32 Btcols,
                                          SAL_f64 *pC,
                                          SAL_i32 Ctcols,
                                          SAL_i32 nr_c,
                                          SAL_i32 nc_c,
                                          SAL_i32 N,
                                          SAL_i32 flag,
                                          SAL_i32 xflag );

    static SAL_i32 PREFIX( mat_mul_tt ) ( SAL_f64 *pAt,
                                          SAL_i32 Atcols,
                                          SAL_f64 *pBt,
                                          SAL_i32 Btcols,
                                          SAL_f64 *pC,
                                          SAL_i32 Ctcols,
                                          SAL_i32 nr_c,
                                          SAL_i32 nc_c,
                                          SAL_i32 N,
                                          SAL_i32 flag,
                                          SAL_i32 xflag );

    static SAL_i32 PREFIX( mat_mul_nn ) ( SAL_f64 *pA,
                                          SAL_i32 Atcols,
                                          SAL_f64 *pB,
                                          SAL_i32 Btcols,
                                          SAL_f64 *pC,
                                          SAL_i32 Ctcols,
                                          SAL_i32 nr_c,
                                          SAL_i32 nc_c,
                                          SAL_i32 N,
                                          SAL_i32 flag,
                                          SAL_i32 xflag )
    {
        SAL_i32 i, j, n;

        SAL_f64 result;

        ( void )xflag;

        for ( i = 0; i < nr_c; i++ )
        {
            for ( j = 0; j < nc_c; j++ )
            {
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ] : 0.0;

                for ( n = 0; n < N; n++ )
                {
                    result += ( pA [ ( i * Atcols ) + n ] * pB [ ( n * Btcols ) + j ] );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( mat_mul_tn ) ( SAL_f64 *pAt,
                                          SAL_i32 Atcols,
                                          SAL_f64 *pB,
                                          SAL_i32 Btcols,
                                          SAL_f64 *pC,
                                          SAL_i32 Ctcols,
                                          SAL_i32 nr_c,
                                          SAL_i32 nc_c,
                                          SAL_i32 N,
                                          SAL_i32 flag,
                                          SAL_i32 xflag )
    {
        SAL_i32 i, j, n;

        SAL_f64 result;

        ( void )xflag;

        for ( i = 0; i < nr_c; i++ )
        {
            for ( j = 0; j < nc_c; j++ )
            {
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ] : 0.0;

                for ( n = 0; n < N; n++ )
                {
                    result += ( pAt [ ( n * Atcols ) + i ] * pB [ ( n * Btcols ) + j ] );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( mat_mul_nt ) ( SAL_f64 *pA,
                                          SAL_i32 Atcols,
                                          SAL_f64 *pBt,
                                          SAL_i32 Btcols,
                                          SAL_f64 *pC,
                                          SAL_i32 Ctcols,
                                          SAL_i32 nr_c,
                                          SAL_i32 nc_c,
                                          SAL_i32 N,
                                          SAL_i32 flag,
                                          SAL_i32 xflag )
    {
        SAL_i32 i, j, n;

        SAL_f64 result;

        ( void )xflag;

        for ( i = 0; i < nr_c; i++ )
        {
            for ( j = 0; j < nc_c; j++ )
            {
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ] : 0.0;

                for ( n = 0; n < N; n++ )
                {
                    result += ( pA [ ( i * Atcols ) + n ] * pBt [ ( j * Btcols ) + n ] );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( mat_mul_tt ) ( SAL_f64 *pAt,
                                          SAL_i32 Atcols,
                                          SAL_f64 *pBt,
                                          SAL_i32 Btcols,
                                          SAL_f64 *pC,
                                          SAL_i32 Ctcols,
                                          SAL_i32 nr_c,
                                          SAL_i32 nc_c,
                                          SAL_i32 N,
                                          SAL_i32 flag,
                                          SAL_i32 xflag )
    {
        SAL_i32 i, j, n;

        SAL_f64 result;

        ( void )xflag;

        for ( i = 0; i < nr_c; i++ )
        {
            for ( j = 0; j < nc_c; j++ )
            {
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ] : 0.0;

                for ( n = 0; n < N; n++ )
                {
                    result += ( pAt [ ( n * Atcols ) + i ] * pBt [ ( j * Btcols ) + n ] );
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
