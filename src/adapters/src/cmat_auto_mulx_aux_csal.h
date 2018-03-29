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
        cmat_auto_mulx_aux_csal.h

----------------------------------------------------------------------------
*/

#ifndef CMAT_AUTO_MULX_AUX_CSAL_H
#define CMAT_AUTO_MULX_AUX_CSAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <csal_internal.h>

    static SAL_i32 PREFIX( cmat_auto_mulx_aa ) ( SAL_cf32 *pA,
    SAL_i32 Atcols,
    SAL_cf32 *pC,
    SAL_i32 Ctcols,
    SAL_i32 n_c,
    SAL_i32 N,
    SAL_i32 flag,
    SAL_i32 xflag );

    static SAL_i32 PREFIX( cmat_auto_mulx_ata ) ( SAL_cf32 *pA,
            SAL_i32 Atcols,
            SAL_cf32 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag );

    static SAL_i32 PREFIX( cmat_auto_mulx_aat ) ( SAL_cf32 *pA,
            SAL_i32 Atcols,
            SAL_cf32 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag );

    static SAL_i32 PREFIX( cmat_auto_mulx_atat ) ( SAL_cf32 *pA,
            SAL_i32 Atcols,
            SAL_cf32 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag );

    static SAL_i32 PREFIX( cmat_auto_mulx_aa ) ( SAL_cf32 *pA,
            SAL_i32 Atcols,
            SAL_cf32 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_cf32 result;

        SAL_cf32 src_r;
        SAL_cf32 src_l;

        const SAL_cf32 zero_cf32 = { 0.0, 0.0 };

        SAL_f32 conj_r;
        SAL_f32 conj_l;

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
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ]
                         : zero_cf32;

                for ( k = 0; k < n_c; k++ )
                {
                    src_l = pA [ ( i * Atcols ) + k ];
                    src_r = pA [ ( k * Atcols ) + j ];

                    src_l.imag *= conj_l;
                    src_r.imag *= conj_r;

                    result.real += ( src_l.real * src_r.real ) -
                                   ( src_l.imag * src_r.imag );

                    result.imag += ( src_l.real * src_r.imag ) +
                                   ( src_l.imag * src_r.real );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( cmat_auto_mulx_ata ) ( SAL_cf32 *pA,
            SAL_i32 Atcols,
            SAL_cf32 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_cf32 result;

        SAL_cf32 src_r;
        SAL_cf32 src_l;

        const SAL_cf32 zero_cf32 = { 0.0, 0.0 };

        SAL_f32 conj_r;
        SAL_f32 conj_l;

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
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ]
                         : zero_cf32;

                for ( k = 0; k < N; k++ )
                {
                    src_l = pA [ ( k * Atcols ) + i ];
                    src_r = pA [ ( k * Atcols ) + j ];

                    src_l.imag *= conj_l;
                    src_r.imag *= conj_r;

                    result.real += ( src_l.real * src_r.real ) -
                                   ( src_l.imag * src_r.imag );

                    result.imag += ( src_l.real * src_r.imag ) +
                                   ( src_l.imag * src_r.real );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( cmat_auto_mulx_aat ) ( SAL_cf32 *pA,
            SAL_i32 Atcols,
            SAL_cf32 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_cf32 result;

        SAL_cf32 src_r;
        SAL_cf32 src_l;

        const SAL_cf32 zero_cf32 = { 0.0, 0.0 };

        SAL_f32 conj_r;
        SAL_f32 conj_l;

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
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ]
                         : zero_cf32;

                for ( k = 0; k < N; k++ )
                {
                    src_l = pA [ ( i * Atcols ) + k ];
                    src_r = pA [ ( j * Atcols ) + k ];

                    src_l.imag *= conj_l;
                    src_r.imag *= conj_r;

                    result.real += ( src_l.real * src_r.real ) -
                                   ( src_l.imag * src_r.imag );

                    result.imag += ( src_l.real * src_r.imag ) +
                                   ( src_l.imag * src_r.real );
                }

                pC [ ( i * Ctcols ) + j ] = result;
            }
        }

        return ( SAL_SUCCESS );
    }

    static SAL_i32 PREFIX( cmat_auto_mulx_atat ) ( SAL_cf32 *pA,
            SAL_i32 Atcols,
            SAL_cf32 *pC,
            SAL_i32 Ctcols,
            SAL_i32 n_c,
            SAL_i32 N,
            SAL_i32 flag,
            SAL_i32 xflag )
    {
        SAL_i32 i, j, k;

        SAL_cf32 result;

        SAL_cf32 src_r;
        SAL_cf32 src_l;

        const SAL_cf32 zero_cf32 = { 0.0, 0.0 };

        SAL_f32 conj_r;
        SAL_f32 conj_l;

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
                result = ( flag & SAL_ACCUMULATE ) ? pC [ ( i * Ctcols ) + j ]
                         : zero_cf32;

                for ( k = 0; k < N; k++ )
                {
                    src_l = pA [ ( k * Atcols ) + i ];
                    src_r = pA [ ( j * Atcols ) + k ];

                    src_l.imag *= conj_l;
                    src_r.imag *= conj_r;

                    result.real += ( src_l.real * src_r.real ) -
                                   ( src_l.imag * src_r.imag );

                    result.imag += ( src_l.real * src_r.imag ) +
                                   ( src_l.imag * src_r.real );
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

