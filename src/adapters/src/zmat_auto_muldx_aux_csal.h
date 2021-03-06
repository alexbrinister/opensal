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
        zmat_auto_muldx_aux_csal.h

----------------------------------------------------------------------------
*/

#ifndef ZMAT_AUTO_MULDX_AUX_CSAL_H
#define ZMAT_AUTO_MULDX_AUX_CSAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <csal_internal.h>

    static SAL_i32 PREFIX( zmat_auto_muldx_aa ) ( SAL_zf64 *pA,
    SAL_i32 Atcols,
    SAL_zf64 *pC,
    SAL_i32 Ctcols,
    SAL_i32 n_c,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 xflag );

    static SAL_i32 PREFIX( zmat_auto_muldx_ata ) ( SAL_zf64 *pA,
            SAL_i32 Atcols,
            SAL_zf64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag );

    static SAL_i32 PREFIX( zmat_auto_muldx_aat ) ( SAL_zf64 *pA,
            SAL_i32 Atcols,
            SAL_zf64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag );

    static SAL_i32 PREFIX( zmat_auto_muldx_atat ) ( SAL_zf64 *pA,
            SAL_i32 Atcols,
            SAL_zf64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag );

    static SAL_i32 PREFIX( zmat_auto_muldx_aa ) ( SAL_zf64 *pA,
            SAL_i32 Atcols,
            SAL_zf64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_f64 result_r;
        SAL_f64 result_i;

        SAL_f64 src_r_r;
        SAL_f64 src_r_i;
        SAL_f64 src_l_r;
        SAL_f64 src_l_i;

        SAL_f64 conj_r;
        SAL_f64 conj_l;

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

        conj_l = ( flag & SAL_CONJUGATE_LEFT )  ? -1.0 : 1.0;
        conj_r = ( flag & SAL_CONJUGATE_RIGHT ) ? -1.0 : 1.0;

        for ( i = 0; i < n_c; i++ )
        {
            for ( j = 0; j < n_c; j++ )
            {
                result_r = ( flag & SAL_ACCUMULATE ) ? pC->realp [ ( i * Ctcols ) + j ]
                           : 0.0;

                result_i = ( flag & SAL_ACCUMULATE ) ? pC->imagp [ ( i * Ctcols ) + j ]
                           : 0.0;

                for ( k = 0; k < n_c; k++ )
                {
                    src_l_r = pA->realp [ ( i * Atcols ) + k ];
                    src_l_i = pA->imagp [ ( i * Atcols ) + k ];

                    src_r_r = pA->realp [ ( k * Atcols ) + j ];
                    src_r_i = pA->imagp [ ( k * Atcols ) + j ];

                    src_l_i *= conj_l;
                    src_r_i *= conj_r;

                    result_r += ( src_l_r * src_r_r ) - ( src_l_i * src_r_i );

                    result_i += ( src_l_r * src_r_i ) + ( src_l_i * src_r_r );
                }

                pC->realp [ ( i * Ctcols ) + j ] = result_r;
                pC->imagp [ ( i * Ctcols ) + j ] = result_i;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( zmat_auto_muldx_ata ) ( SAL_zf64 *pA,
            SAL_i32 Atcols,
            SAL_zf64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_f64 result_r;
        SAL_f64 result_i;

        SAL_f64 src_r_r;
        SAL_f64 src_r_i;
        SAL_f64 src_l_r;
        SAL_f64 src_l_i;

        SAL_f64 conj_r;
        SAL_f64 conj_l;

        ( void )xflag;

        if ( Atcols == 0 )
        {
            Atcols = n_c;
        }

        if ( Ctcols == 0 )
        {
            Ctcols = n_c;
        }

        conj_l = ( flag & SAL_CONJUGATE_LEFT )  ? -1.0 : 1.0;
        conj_r = ( flag & SAL_CONJUGATE_RIGHT ) ? -1.0 : 1.0;

        for ( i = 0; i < n_c; i++ )
        {
            for ( j = 0; j < n_c; j++ )
            {
                result_r = ( flag & SAL_ACCUMULATE ) ? pC->realp [ ( i * Ctcols ) + j ]
                           : 0.0;

                result_i = ( flag & SAL_ACCUMULATE ) ? pC->imagp [ ( i * Ctcols ) + j ]
                           : 0.0;

                for ( k = 0; k < N; k++ )
                {
                    src_l_r = pA->realp [ ( k * Atcols ) + i ];
                    src_l_i = pA->imagp [ ( k * Atcols ) + i ];

                    src_r_r = pA->realp [ ( k * Atcols ) + j ];
                    src_r_i = pA->imagp [ ( k * Atcols ) + j ];

                    src_l_i *= conj_l;
                    src_r_i *= conj_r;

                    result_r += ( src_l_r * src_r_r ) - ( src_l_i * src_r_i );

                    result_i += ( src_l_r * src_r_i ) + ( src_l_i * src_r_r );
                }

                pC->realp [ ( i * Ctcols ) + j ] = result_r;
                pC->imagp [ ( i * Ctcols ) + j ] = result_i;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( zmat_auto_muldx_aat ) ( SAL_zf64 *pA,
            SAL_i32 Atcols,
            SAL_zf64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_f64 result_r;
        SAL_f64 result_i;

        SAL_f64 src_r_r;
        SAL_f64 src_r_i;
        SAL_f64 src_l_r;
        SAL_f64 src_l_i;

        SAL_f64 conj_r;
        SAL_f64 conj_l;

        ( void )xflag;

        if ( Atcols == 0 )
        {
            Atcols = N;
        }

        if ( Ctcols == 0 )
        {
            Ctcols = n_c;
        }

        conj_l = ( flag & SAL_CONJUGATE_LEFT )  ? -1.0 : 1.0;
        conj_r = ( flag & SAL_CONJUGATE_RIGHT ) ? -1.0 : 1.0;

        for ( i = 0; i < n_c; i++ )
        {
            for ( j = 0; j < n_c; j++ )
            {
                result_r = ( flag & SAL_ACCUMULATE ) ? pC->realp [ ( i * Ctcols ) + j ]
                           : 0.0;

                result_i = ( flag & SAL_ACCUMULATE ) ? pC->imagp [ ( i * Ctcols ) + j ]
                           : 0.0;

                for ( k = 0; k < N; k++ )
                {
                    src_l_r = pA->realp [ ( i * Atcols ) + k ];
                    src_l_i = pA->imagp [ ( i * Atcols ) + k ];

                    src_r_r = pA->realp [ ( j * Atcols ) + k ];
                    src_r_i = pA->imagp [ ( j * Atcols ) + k ];

                    src_l_i *= conj_l;
                    src_r_i *= conj_r;

                    result_r += ( src_l_r * src_r_r ) - ( src_l_i * src_r_i );

                    result_i += ( src_l_r * src_r_i ) + ( src_l_i * src_r_r );
                }

                pC->realp [ ( i * Ctcols ) + j ] = result_r;
                pC->imagp [ ( i * Ctcols ) + j ] = result_i;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( zmat_auto_muldx_atat ) ( SAL_zf64 *pA,
            SAL_i32 Atcols,
            SAL_zf64 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_f64 result_r;
        SAL_f64 result_i;

        SAL_f64 src_r_r;
        SAL_f64 src_r_i;
        SAL_f64 src_l_r;
        SAL_f64 src_l_i;

        SAL_f64 conj_r;
        SAL_f64 conj_l;

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

        conj_l = ( flag & SAL_CONJUGATE_LEFT )  ? -1.0 : 1.0;
        conj_r = ( flag & SAL_CONJUGATE_RIGHT ) ? -1.0 : 1.0;

        for ( i = 0; i < n_c; i++ )
        {
            for ( j = 0; j < n_c; j++ )
            {
                result_r = ( flag & SAL_ACCUMULATE ) ? pC->realp [ ( i * Ctcols ) + j ]
                           : 0.0;

                result_i = ( flag & SAL_ACCUMULATE ) ? pC->imagp [ ( i * Ctcols ) + j ]
                           : 0.0;

                for ( k = 0; k < N; k++ )
                {
                    src_l_r = pA->realp [ ( k * Atcols ) + i ];
                    src_l_i = pA->imagp [ ( k * Atcols ) + i ];

                    src_r_r = pA->realp [ ( j * Atcols ) + k ];
                    src_r_i = pA->imagp [ ( j * Atcols ) + k ];

                    src_l_i *= conj_l;
                    src_r_i *= conj_r;

                    result_r += ( src_l_r * src_r_r ) - ( src_l_i * src_r_i );

                    result_i += ( src_l_r * src_r_i ) + ( src_l_i * src_r_r );
                }

                pC->realp [ ( i * Ctcols ) + j ] = result_r;
                pC->imagp [ ( i * Ctcols ) + j ] = result_i;
            }
        }

        return ( SAL_SUCCESS );
    }

#ifdef __cplusplus
}
#endif

#endif
