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
        sal_csal_common_internal.h

----------------------------------------------------------------------------
*/

#ifndef SAL_CSAL_COMMON_INTERNAL_H
#define SAL_CSAL_COMMON_INTERNAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "sal.h"
#include "sal_macros.h"

#define SAL_EST_NORM_1   ( 0 )
#define SAL_EST_NORM_INF ( 1 )

#define SAL_MVMULT_NOTRANSPOSE ( 0 )
#define SAL_MVMULT_TRANSPOSE   ( 1 )

#define SAL__MASK_TRANSPOSE ( SAL_TRANSPOSE_LEFT | SAL_TRANSPOSE_RIGHT )

#define CSAL_LIB_ID ( 0 )
#define SAL_LIB_ID  ( 1 )

#define N_COLS_STRIP_MIN 16

#define MAX( a, b ) (( (a)>(b) ) ? (a) : (b))

    extern void PREFIX( _csal_malloc_mat_float ) ( SAL_f32 **Y, SAL_i32 nrows, SAL_i32 ncols );
    extern void PREFIX( _csal_malloc_mat_int ) ( SAL_i32 **Y, SAL_i32 nrows, SAL_i32 ncols );
    extern void PREFIX( _csal_matfbs_sum ) ( SAL_f32 *SUM_ADDR, SAL_f32 *VEC1_ADDR, SAL_i32 STRIDE1, SAL_f32 *VEC2_ADDR, SAL_i32 STRIDE2, SAL_i32 COUNT );

    extern void PREFIX( _csal_cmat_norm1_estx )( void *M, void ( *mvmult_func )( void *M, SAL_cf32 *x, SAL_cf32 *y, SAL_i32 flag, SAL_i32 n ), SAL_f32 *norm_est, SAL_cf32 *c_v, SAL_cf32 *c_u, SAL_i32 t, SAL_cf32 *X0, SAL_i32 n, SAL_i32 flag, SAL_i32 XFLAG );
    extern void PREFIX( _csal_mat_norm1_estx )( void *M, void ( *mvmult_func )( void *M, SAL_f32 *x, SAL_f32 *y, SAL_i32 flag, SAL_i32 n ), SAL_f32 *norm_est, SAL_f32 *v, SAL_f32 *u, SAL_i32 t, SAL_f32 *X0, SAL_i32 n, SAL_i32 flag, SAL_i32 XFLAG );
    extern void PREFIX( _csal_zmat_norm1_estx )( void *M, void ( *mvmult_func )( void *M, SAL_zf32 *x, SAL_zf32 *y, SAL_i32 flag, SAL_i32 n ), SAL_f32 *norm_est, SAL_zf32 *v, SAL_zf32 *u, SAL_i32 t, SAL_zf32 *X0, SAL_i32 n, SAL_i32 flag, SAL_i32 XFLAG );

    extern void PREFIX( _csal_matinvxvec_lu ) ( void *pM, SAL_f32 *b, SAL_f32 *w, SAL_i32 flag, SAL_i32 n );
    extern void PREFIX( _csal_cmatinvxvec_lu ) ( void *pM, SAL_cf32 *b, SAL_cf32 *w, SAL_i32 flag, SAL_i32 n );
    extern SAL_f32 PREFIX( _csal_cmodulus ) ( SAL_f32 *a, SAL_f32 *b );
    extern SAL_f64 PREFIX( _csal_cmodulusd ) ( SAL_f64 *a, SAL_f64 *b );
    extern void PREFIX( _csal_zmatinvxvec_lu ) ( void *pM, SAL_zf32 *b, SAL_zf32 *w, SAL_i32 flag, SAL_i32 n );
    extern void PREFIX( _csal_matinvxvec_mgs ) ( void *pM, SAL_f32 *b, SAL_f32 *w, SAL_i32 flag, SAL_i32 n );
    extern void PREFIX( _csal_cmatinvxvec_mgs ) ( void *pM, SAL_cf32 *b, SAL_cf32 *w, SAL_i32 flag, SAL_i32 n );
    extern void PREFIX( _csal_zmatinvxvec_mgs ) ( void *pM, SAL_zf32 *b, SAL_zf32 *w, SAL_i32 flag, SAL_i32 n );
    extern void PREFIX( _csal_matinvxvec_chol ) ( void *pM, SAL_f32 *b, SAL_f32 *w, SAL_i32 flag, SAL_i32 n );
    extern void PREFIX( _csal_cmatinvxvec_chol ) ( void *pM, SAL_cf32 *b, SAL_cf32 *w, SAL_i32 flag, SAL_i32 n );
    extern void PREFIX( _csal_zmatinvxvec_chol ) ( void *pM, SAL_zf32 *b, SAL_zf32 *w, SAL_i32 flag, SAL_i32 n );

    void PREFIX( mat_fsm_gemm ) ( SAL_i32 nc_task, SAL_i32 LUtcols,
                                  SAL_f32 *LU00, SAL_f32 * LU01, SAL_f32 * LU10, SAL_f32 *LU11,
                                  SAL_i32 mu, SAL_i32 rtrunc, SAL_i32 m, SAL_i32 flag );
    SAL_i32 PREFIX( mat_lud_dec_ns_tr ) (
        SAL_f32 *CTp,
        SAL_i32 Tcc,
        SAL_f32 *Bp,
        SAL_i32 *Vpivp,
        SAL_i32 *ICp,
        SAL_i32 Nc,
        SAL_i32 Nr );
    void PREFIX( matfsm ) ( SAL_f32 *Ap, SAL_i32 Atcols, SAL_f32 *Lp, SAL_i32 Ltcols,
                            SAL_f32 *Up, SAL_i32 Utcols, SAL_i32 n, SAL_i32 m );
    void PREFIX( rowswap ) ( SAL_f32 *A, SAL_i32 Atcols, SAL_i32 *Ppiv, SAL_f32 *tmprow, SAL_i32 m, SAL_i32 n );
    void PREFIX( perm2piv_vec ) ( SAL_i32 *vperm, SAL_i32 *vpiv, SAL_i32 *vtmp, SAL_i32 m, SAL_i32 n );
    extern void PREFIX( swap_cols ) ( SAL_f32 *col0, SAL_f32 *col1, SAL_i32 tcols, SAL_i32 nrows );
    void PREFIX( vnsmam4lud ) ( SAL_f32 *A, SAL_f32 *B, SAL_i32 bstride, SAL_f32 *C, SAL_i32 Ctcols, SAL_i32 n, SAL_i32 m );

    typedef struct
    {
        SAL_f32 *LU;
        SAL_i32 *Pvec;
        SAL_f32 *Svec;
        SAL_f32 *SBtmp;
        SAL_i32 LUtcols;
        SAL_i32 n;
    } mat_lu_decomp;

    typedef struct
    {
        SAL_cf32 *LU;
        SAL_i32 *Pvec;
        SAL_f32 *Svec;
        SAL_cf32 *SBtmp;
        SAL_i32 LUtcols;
        SAL_i32 n;
    } cmat_lu_decomp;

    typedef struct
    {
        SAL_zf32 *LU;
        SAL_i32 *Pvec;
        SAL_f32 *Svec;
        SAL_zf32 *SBtmp;
        SAL_i32 LUtcols;
        SAL_i32 n;
    } zmat_lu_decomp;

    typedef struct
    {
        SAL_f32 *Q;
        SAL_f32 *R;

        SAL_f32 *Svec;
        SAL_f32 *SBtmp;
        SAL_i32 Qtcols;
        SAL_i32 Rtcols;
        SAL_i32 m;
        SAL_i32 n;
    } mat_mgs_decomp;

    typedef struct
    {
        SAL_cf32 *Q;
        SAL_cf32 *R;

        SAL_f32 *Svec;
        SAL_cf32 *SBtmp;
        SAL_i32 Qtcols;
        SAL_i32 Rtcols;
        SAL_i32 m;
        SAL_i32 n;
    } cmat_mgs_decomp;

    typedef struct
    {
        SAL_zf32 *Q;
        SAL_zf32 *R;

        SAL_f32 *Svec;
        SAL_zf32 *SBtmp;
        SAL_i32 Qtcols;
        SAL_i32 Rtcols;
        SAL_i32 m;
        SAL_i32 n;
    } zmat_mgs_decomp;

    typedef struct
    {
        SAL_f32 *LDU;
        SAL_f32 *Svec;
        SAL_f32 *SBtmp;
        SAL_i32 LDUtcols;
        SAL_i32 n;
    } mat_chol_decomp;

    typedef struct
    {
        SAL_cf32 *LDU;
        SAL_f32 *Svec;
        SAL_cf32 *SBtmp;
        SAL_i32 LDUtcols;
        SAL_i32 n;
    } cmat_chol_decomp;

    typedef struct
    {
        SAL_zf32 *LDU;
        SAL_f32 *Svec;
        SAL_zf32 *SBtmp;
        SAL_i32 LDUtcols;
        SAL_i32 n;
    } zmat_chol_decomp;

#ifdef __cplusplus
}
#endif

#endif
