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
        adapters.h

----------------------------------------------------------------------------
*/

#ifndef ADAPTERS_CSAL_H
#define ADAPTERS_CSAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "csal_internal.h"
#include "sal_internal.h"


    void PREFIX( aspecx_csal ) (
        SAL_cf32 *c_A,
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( blkmandx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( blkman_windowdx_csal ) (
        SAL_f64 *C,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( blkman_windowx_csal ) (
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( blkmanx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( bprojimgdx_csal ) (
        SAL_f64 *PROJECTION,
        SAL_f64 *IMAGE,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_i32 *ROW_START,
        SAL_i32 *ROW_COUNT,
        SAL_f64 *PROJ_START,
        SAL_f64 *PROJ_DELTA,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( bprojimgx_csal ) (
        SAL_f32 *PROJECTION,
        SAL_f32 *IMAGE,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_i32 *ROW_START,
        SAL_i32 *ROW_COUNT,
        SAL_f32 *PROJ_START,
        SAL_f32 *PROJ_DELTA,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( bprojrowdx_csal ) (
        SAL_f64 *ROW_START,
        SAL_f64 *PROJECTION,
        SAL_i32 PROJ_NUM,
        SAL_i32 PROJ_SIZE,
        SAL_i32 ROW_COUNT,
        SAL_f64 *PROJ_START,
        SAL_f64 *PROJ_DELTA,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( bprojrowx_csal ) (
        SAL_f32 *ROW_START,
        SAL_f32 *PROJECTION,
        SAL_i32 PROJ_NUM,
        SAL_i32 PROJ_SIZE,
        SAL_i32 ROW_COUNT,
        SAL_f32 *PROJ_START,
        SAL_f32 *PROJ_DELTA,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cconv2d_iax_csal ) (
        SAL_cf32 **A,
        SAL_cf32 **B,
        SAL_cf32 **C,
        SAL_i32 DSX,
        SAL_i32 DSY,
        SAL_i32 NCB,
        SAL_i32 NRB,
        SAL_i32 NCC,
        SAL_i32 NRC,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( cconv2dx_csal ) (
        SAL_cf32 *A,
        SAL_i32 TCA,
        SAL_cf32 *B,
        SAL_cf32 *C,
        SAL_i32 TCC,
        SAL_i32 DSX,
        SAL_i32 DSY,
        SAL_i32 NCB,
        SAL_i32 NRB,
        SAL_i32 NCC,
        SAL_i32 NRC,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( cconvx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cdotprdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_B,
        SAL_i32 J,
        SAL_cf64 *c_S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( cdotprx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cexpmulx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *F,
        SAL_f32 *P,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_cf32 *CEXPTAB,
        SAL_i32 LOG2M,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( cexptabx_csal ) (
        SAL_cf32 *C,
        SAL_i32 LOG2M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfft2ddx_csal ) (
        SAL_cf64 *c_c,
        SAL_i32 nc,
        SAL_i32 nr,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfft2dx_csal ) (
        SAL_cf32 *c_c,
        SAL_i32 nc,
        SAL_i32 nr,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftb3x_csal ) (
        SAL_cf32 *A,
        SAL_cf32 *W3,
        SAL_cf32 *C,
        SAL_i32 M,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftb5x_csal ) (
        SAL_cf32 *A,
        SAL_cf32 *W5,
        SAL_cf32 *C,
        SAL_i32 M,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftbdx_csal ) (
        SAL_cf64 *c_c,
        SAL_cf64 *c_d,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftbx_csal ) (
        SAL_cf32 *c_c,
        SAL_cf32 *c_d,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftdx_csal ) (
        SAL_cf64 *c_c,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftodx_csal ) (
        SAL_cf64 *c,
        SAL_cf64 *t,
        SAL_cf64 *d,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftox_csal ) (
        SAL_cf32 *c,
        SAL_cf32 *t,
        SAL_cf32 *d,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftscdx_csal ) (
        SAL_cf64 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftscx_csal ) (
        SAL_cf32 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cfftx_csal ) (
        SAL_cf32 *c_c,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cidotprdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_B,
        SAL_i32 J,
        SAL_cf64 *c_S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cidotprx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cimuldx_csal ) (
        SAL_cf64 *c_A,
        SAL_cf64 *c_B,
        SAL_cf64 *c_C,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cimulx_csal ) (
        SAL_cf32 *c_A,
        SAL_cf32 *c_B,
        SAL_cf32 *c_C,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cmatinv_lux_csal ) (
        SAL_cf32 *c_C,
        SAL_cf32 *c_D,
        SAL_i32 *IP,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );
    

    void PREFIX( cmat_auto_muldx_csal ) (
        SAL_cf64 *pA,
        SAL_i32 Atcols,
        SAL_cf64 *pC,
        SAL_i32 Ctcols,
        SAL_i32 n_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_auto_mulx_csal ) (
        SAL_cf32 *pA,
        SAL_i32 Atcols,
        SAL_cf32 *pC,
        SAL_i32 Ctcols,
        SAL_i32 n_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_chol_decx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 Atcols,
        SAL_cf32 *c_LDU,
        SAL_i32 LDUtcols,
        SAL_i32 n,
        SAL_f32 *rcond_est,
        SAL_cf32 *c_v,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_chol_solx_csal ) (
        SAL_cf32 *c_LDU,
        SAL_i32 LDUtcols,
        SAL_cf32 *c_b,
        SAL_cf32 *c_w,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_lud_decx_csal ) (
        SAL_cf32 *c_C,
        SAL_i32 Ctcols,
        SAL_i32 *D,
        SAL_i32 n,
        SAL_f32 *rcond_est,
        SAL_cf32 *c_v,
        SAL_i32 flag,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_lud_solx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 Atcols,
        SAL_i32 *D,
        SAL_cf32 *c_b,
        SAL_cf32 *c_w,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_mgs_decx_csal ) (
        SAL_cf32 *c_AT,
        SAL_i32 ATtcols,
        SAL_cf32 *c_R,
        SAL_i32 Rtcols,
        SAL_i32 m,
        SAL_i32 n,
        SAL_f32 *rcond_est,
        SAL_cf32 *c_v,
        SAL_i32 flag,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_mgs_solrhrx_csal ) (
        SAL_cf32 *c_R,
        SAL_i32 R_tcols,
        SAL_cf32 *c_B,
        SAL_cf32 *c_X,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_mgs_solrx_csal ) (
        SAL_cf32 *c_R,
        SAL_i32 R_tcols,
        SAL_cf32 *c_B,
        SAL_cf32 *c_X,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_muldx_csal ) (
        SAL_cf64 *pA,
        SAL_i32 Atcols,
        SAL_cf64 *pB,
        SAL_i32 Btcols,
        SAL_cf64 *pC,
        SAL_i32 Ctcols,
        SAL_i32 nr_c,
        SAL_i32 nc_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmat_mulx_csal ) (
        SAL_cf32 *pA,
        SAL_i32 Atcols,
        SAL_cf32 *pB,
        SAL_i32 Btcols,
        SAL_cf32 *pC,
        SAL_i32 Ctcols,
        SAL_i32 nr_c,
        SAL_i32 nc_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( _csal_cmat_norm1_estx_csal ) (
        void *M,
        void ( *mvmult_func )( void *M, SAL_cf32 *x, SAL_cf32 *y, SAL_i32 flag, SAL_i32 n ),
        SAL_f32 *norm_est,
        SAL_cf32 *c_v,
        SAL_cf32 *c_u,
        SAL_i32 t,
        SAL_cf32 *X0,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cmixerx_csal ) (
        SAL_cf32 *A,
        SAL_i32 sA,
        SAL_f64 *F,
        SAL_f64 *P,
        SAL_cf32 *C,
        SAL_i32 sC,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 eflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmmax_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_cf32 *c_D,
        SAL_i32 L,
        SAL_i32 MC,
        SAL_i32 NC,
        SAL_i32 NA,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cmmovdx_csal ) (
        SAL_cf64 *pSrc,
        SAL_i32 stride_x_src,
        SAL_i32 stride_y_src,
        SAL_cf64 *pDst,
        SAL_i32 stride_x_dst,
        SAL_i32 stride_y_dst,
        SAL_i32 x_len,
        SAL_i32 y_len,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmmovx_csal ) (
        SAL_cf32 *pSrc,
        SAL_i32 stride_x_src,
        SAL_i32 stride_y_src,
        SAL_cf32 *pDst,
        SAL_i32 stride_x_dst,
        SAL_i32 stride_y_dst,
        SAL_i32 x_len,
        SAL_i32 y_len,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( cmmsx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_cf32 *c_D,
        SAL_i32 L,
        SAL_i32 MC,
        SAL_i32 NC,
        SAL_i32 NA,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cmmuldx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_B,
        SAL_i32 J,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 MC,
        SAL_i32 NC,
        SAL_i32 NA,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cmsmx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_cf32 *c_D,
        SAL_i32 L,
        SAL_i32 MC,
        SAL_i32 NC,
        SAL_i32 NA,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cmtrans2dx_csal ) (
        SAL_cf64 *c_A,
        SAL_cf64 *c_C,
        SAL_i32 NC,
        SAL_i32 NR,
        SAL_i32 TCA,
        SAL_i32 TCC,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cmtrans2x_csal ) (
        SAL_cf32 *c_A,
        SAL_cf32 *c_C,
        SAL_i32 NC,
        SAL_i32 NR,
        SAL_i32 TCA,
        SAL_i32 TCC,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( coherx_csal ) (
        SAL_f32 *A,
        SAL_f32 *B,
        SAL_cf32 *c_C,
        SAL_f32 *D,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( conv2d_iax_csal ) (
        SAL_f32 **A,
        SAL_f32 **B,
        SAL_f32 **C,
        SAL_i32 DSX,
        SAL_i32 DSY,
        SAL_i32 NCB,
        SAL_i32 NRB,
        SAL_i32 NCC,
        SAL_i32 NRC,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( conv2dx_csal ) (
        SAL_f32 *A,
        SAL_i32 TCA,
        SAL_f32 *B,
        SAL_f32 *C,
        SAL_i32 TCC,
        SAL_i32 DSX,
        SAL_i32 DSY,
        SAL_i32 NCB,
        SAL_i32 NRB,
        SAL_i32 NCC,
        SAL_i32 NRC,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( convm_colsx_csal ) (
        SAL_f32 **A,
        SAL_f32 *B,
        SAL_f32 **C,
        SAL_i32 Nc,
        SAL_i32 Nr,
        SAL_i32 Nb,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( convm_rowsx_csal ) (
        SAL_f32 **A,
        SAL_f32 *B,
        SAL_f32 **C,
        SAL_i32 Nc,
        SAL_i32 Nr,
        SAL_i32 Nb,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( convx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( crdesampx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_cf32 *c_C,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( crdotprdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_cf64 *c_S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( crdotprx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_cf32 *c_S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( crmixerx_csal ) (
        SAL_f32 *A,
        SAL_i32 sA,
        SAL_f64 *F,
        SAL_f64 *P,
        SAL_cf32 *C,
        SAL_i32 sC,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 eflag,
        SAL__return_info *r_info
    );

    void PREFIX( crvaddx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( crvdivx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( crvmulx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( crvsubx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cspecx_csal ) (
        SAL_cf32 *c_A,
        SAL_cf32 *c_B,
        SAL_cf32 *c_C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( ctozdx_csal ) (
        SAL_cf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( ctozx_csal ) (
        SAL_cf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( cvabsx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvadddx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_B,
        SAL_i32 J,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvaddx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvcmax_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_cf32 *c_D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvcmulx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvcombdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvcombx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvconjdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvconjx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvcsmldx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_S,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvcsmlx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_S,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvdbconx_csal ) (
        SAL_cf32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( cvdivdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_B,
        SAL_i32 J,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvdivx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvexpdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvexpmx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvexpx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvfillx_csal ) (
        SAL_cf32 *S,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvmagsdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvmagsx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvmgsax_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvmovdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvmovx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvmuldx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_B,
        SAL_i32 J,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvmulx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvnegdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvnegx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvphasx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvrcipdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvrcipx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvsmadx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_S,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_cf64 *c_D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvsmax_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_S,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_cf32 *c_D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvsplitdx_csal ) (
        SAL_cf64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( cvsplitx_csal ) (
        SAL_cf32 *A_c,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( cvsqrtx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvsubdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_cf64 *c_B,
        SAL_i32 J,
        SAL_cf64 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( cvsubx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_cf32 *c_B,
        SAL_i32 J,
        SAL_cf32 *c_C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( deq22x_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( desampx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( dotprdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( dotprx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( f3x3dx_csal ) (
        SAL_f64 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f64 *B,
        SAL_f64 *C,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( f3x3x_csal ) (
        SAL_f32 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f32 *B,
        SAL_f32 *C,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( f5x5dx_csal ) (
        SAL_f64 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f64 *B,
        SAL_f64 *C,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( f5x5x_csal ) (
        SAL_f32 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f32 *B,
        SAL_f32 *C,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fcf_ciptx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *C,
        SAL_cf32 *T,
        SAL_f32 *S,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcf_riptx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *C,
        SAL_f32 *T,
        SAL_f32 *S,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcf_ziptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_zf32 *T,
        SAL_f32 *S,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcf_zriptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_zf32 *T,
        SAL_f32 *S,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcsm_ciptx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_cf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcsm_riptx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_f32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcsm_ziptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcsm_zriptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcs_ciptx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_cf32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcs_riptx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcs_ziptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fcs_zriptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_cipdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_ciptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_cf64 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_ciptx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_cf32 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_cipx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_copdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_coptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_cf64 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_coptx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_cf32 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_copx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_ripdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_riptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_f64 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_riptx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_f32 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_ripx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_ropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_roptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_f64 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_roptx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_f32 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_ropx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zipdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_ziptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf64 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_ziptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zipx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zopdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zoptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf64 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zoptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zopx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zripdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zriptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf64 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zriptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zripx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zroptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf64 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zroptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft2d_zropx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2NC,
        SAL_ui32 LOG2NR,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_cols_copx_csal ) (
        FFT_setup *SETUP,
        SAL_cf32 *A,
        SAL_i32 ATCOLS,
        SAL_cf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_cols_ropx_csal ) (
        FFT_setup *SETUP,
        SAL_f32 *A,
        SAL_i32 ATCOLS,
        SAL_f32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_cols_zopx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_cols_zropx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_copx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_ropx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_rows_copx_csal ) (
        FFT_setup *SETUP,
        SAL_cf32 *A,
        SAL_i32 ATCOLS,
        SAL_cf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_rows_ropx_csal ) (
        FFT_setup *SETUP,
        SAL_f32 *A,
        SAL_i32 ATCOLS,
        SAL_f32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_rows_zopx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_rows_zropx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_zopx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft3m_zropx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft3_copdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *A,
        SAL_i32 I,
        SAL_cf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3_copx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 I,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3_ropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3_ropx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft3_zopdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft3_zopx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft3_zropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft3_zropx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_cols_copx_csal ) (
        FFT_setup *SETUP,
        SAL_cf32 *A,
        SAL_i32 ATCOLS,
        SAL_cf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_cols_ropx_csal ) (
        FFT_setup *SETUP,
        SAL_f32 *A,
        SAL_i32 ATCOLS,
        SAL_f32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_cols_zopx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_cols_zropx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_copx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_ropx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_rows_copx_csal ) (
        FFT_setup *SETUP,
        SAL_cf32 *A,
        SAL_i32 ATCOLS,
        SAL_cf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_rows_ropx_csal ) (
        FFT_setup *SETUP,
        SAL_f32 *A,
        SAL_i32 ATCOLS,
        SAL_f32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_rows_zopx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_rows_zropx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_zopx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft5m_zropx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft5_copdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *A,
        SAL_i32 I,
        SAL_cf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5_copx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 I,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5_ropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5_ropx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft5_zopdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft5_zopx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft5_zropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft5_zropx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft9_copx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 I,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft9_zopx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cipdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_ciptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_cf64 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_ciptx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_cf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cipx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_cipdx_csal ) (
        FFT_setupd *SETUP,
        SAL_cf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_cipx_csal ) (
        FFT_setup *SETUP,
        SAL_cf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_copdx_csal ) (
        FFT_setupd *SETUP,
        SAL_cf64 *A,
        SAL_i32 ATCOLS,
        SAL_cf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_copx_csal ) (
        FFT_setup *SETUP,
        SAL_cf32 *A,
        SAL_i32 ATCOLS,
        SAL_cf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_ripdx_csal ) (
        FFT_setupd *SETUP,
        SAL_f64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_ripx_csal ) (
        FFT_setup *SETUP,
        SAL_f32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_ropdx_csal ) (
        FFT_setupd *SETUP,
        SAL_f64 *A,
        SAL_i32 ATCOLS,
        SAL_f64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_ropx_csal ) (
        FFT_setup *SETUP,
        SAL_f32 *A,
        SAL_i32 ATCOLS,
        SAL_f32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_zipdx_csal ) (
        FFT_setupd *SETUP,
        SAL_zf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_zipx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_zopdx_csal ) (
        FFT_setupd *SETUP,
        SAL_zf64 *A,
        SAL_i32 ATCOLS,
        SAL_zf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_zopx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_zripdx_csal ) (
        FFT_setupd *SETUP,
        SAL_zf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_zripx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_zropdx_csal ) (
        FFT_setupd *SETUP,
        SAL_zf64 *A,
        SAL_i32 ATCOLS,
        SAL_zf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_cols_zropx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_copdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_coptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_cf64 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_coptx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_cf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_copx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_cf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_ripdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_riptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_f64 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_riptx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_f32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_ripx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_ropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_roptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_f64 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_roptx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_f32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_ropx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_f32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_cipdx_csal ) (
        FFT_setupd *SETUP,
        SAL_cf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_cipx_csal ) (
        FFT_setup *SETUP,
        SAL_cf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_copdx_csal ) (
        FFT_setupd *SETUP,
        SAL_cf64 *A,
        SAL_i32 ATCOLS,
        SAL_cf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_copx_csal ) (
        FFT_setup *SETUP,
        SAL_cf32 *A,
        SAL_i32 ATCOLS,
        SAL_cf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_ripdx_csal ) (
        FFT_setupd *SETUP,
        SAL_f64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_ripx_csal ) (
        FFT_setup *SETUP,
        SAL_f32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_ropdx_csal ) (
        FFT_setupd *SETUP,
        SAL_f64 *A,
        SAL_i32 ATCOLS,
        SAL_f64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_ropx_csal ) (
        FFT_setup *SETUP,
        SAL_f32 *A,
        SAL_i32 ATCOLS,
        SAL_f32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_zipdx_csal ) (
        FFT_setupd *SETUP,
        SAL_zf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_zipx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_zopdx_csal ) (
        FFT_setupd *SETUP,
        SAL_zf64 *A,
        SAL_i32 ATCOLS,
        SAL_zf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_zopx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_zripdx_csal ) (
        FFT_setupd *SETUP,
        SAL_zf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_zripx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_zropdx_csal ) (
        FFT_setupd *SETUP,
        SAL_zf64 *A,
        SAL_i32 ATCOLS,
        SAL_zf64 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_rows_zropx_csal ) (
        FFT_setup *SETUP,
        SAL_zf32 *A,
        SAL_i32 ATCOLS,
        SAL_zf32 *C,
        SAL_i32 CTCOLS,
        SAL_i32 LOG2N,
        SAL_i32 NFFTS,
        SAL_i32 FI_FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zipdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_ziptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf64 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_ziptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zipx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zopdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zoptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf64 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zoptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zopx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zripdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zriptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf64 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zriptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zripx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zroptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf64 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf64 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zroptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftm_zropx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 IR,
        SAL_i32 IC,
        SAL_zf32 *C,
        SAL_i32 KR,
        SAL_i32 KC,
        SAL_ui32 LOG2N,
        SAL_ui32 M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fftwts3x_csal ) (
        SAL_cf32 *W3,
        SAL_i32 M,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fftwts5x_csal ) (
        SAL_cf32 *W5,
        SAL_i32 M,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    SAL_i32 PREFIX( fft_setup_set_config_base )(
        const SAL_ui32 fft_type,
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          opt_flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_set_config_base )(
        const SAL_ui32 fft_type,
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          opt_flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_setup_mcsal )(
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_setupd_mcsal )(
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_setup_base )(
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_setupd_base )(
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_setup_csal )(
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_setupd_csal )(
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft1d_setup_base )(
        const SAL_fft1d_func fft_type,
        const SAL_i32          log2m,
        const SAL_i32          flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft1d_setupd_base )(
        const SAL_fft1d_funcd fft_type,
        const SAL_i32          log2m,
        const SAL_i32          flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_create_base )(
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_create_base )(
        const SAL_ui32 fft_type_flags,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_create_csal ) (
        FFT_setup         *p_setup,
        const SAL_i32          opt_flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_create_csal ) (
        FFT_setupd        *p_setup,
        const SAL_i32          opt_flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft1d_setup_create_base ) (
        const SAL_fft1d_func fft_type,
        const SAL_i32          log2m,
        const SAL_i32          opt_flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft1d_setupd_create_base ) (
        const SAL_fft1d_funcd fft_type,
        const SAL_i32          log2m,
        const SAL_i32          opt_flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft1d_setup_init_base )(
        FFT_setup         *p_setup,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft1d_setupd_init_base )(
        FFT_setupd        *p_setup,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft1d_setup_csal )(
        const SAL_fft1d_func fft_type,
        const SAL_i32          log2m,
        const SAL_i32          flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft1d_setupd_csal )(
        const SAL_fft1d_funcd fft_type,
        const SAL_i32          log2m,
        const SAL_i32          flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft2d_setup_base )(
        const SAL_fft2d_func fft_type,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft2d_setupd_base )(
        const SAL_fft2d_funcd fft_type,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft2d_setup_create_base ) (
        const SAL_fft2d_func fft_type,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          opt_flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft2d_setupd_create_base ) (
        const SAL_fft2d_funcd fft_type,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          opt_flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft2d_setup_init_base )(
        FFT_setup         *p_setup,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft2d_setupd_init_base )(
        FFT_setupd        *p_setup,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft2d_setup_csal )(
        const SAL_fft2d_func fft_type,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft2d_setupd_csal )(
        const SAL_fft2d_funcd fft_type,
        const SAL_i32          log2m,
        const SAL_i32          log2n,
        const SAL_i32          flag,
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_get_n_bytes_base )(
        FFT_setup         *p_setup,
        SAL_i32               *p_nbytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_get_n_bytes_base )(
        FFT_setupd        *p_setup,
        SAL_i32               *p_nbytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_get_temp_n_bytes_base )(
        FFT_setup         *p_setup,
        SAL_i32               *p_nbytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_get_temp_n_bytes_base )(
        FFT_setupd        *p_setup,
        SAL_i32               *p_nbytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_get_n_bytes_csal )(
        FFT_setup         *p_setup,
        SAL_i32               *p_nbytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_get_n_bytes_csal )(
        FFT_setupd        *p_setup,
        SAL_i32               *p_nbytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_get_temp_n_bytes_csal )(
        FFT_setup         *p_setup,
        SAL_i32               *p_nbytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_get_temp_n_bytes_csal )(
        FFT_setupd        *p_setup,
        SAL_i32               *p_nbytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_init_base )(
        FFT_setup         *p_setup,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_init_base )(
        FFT_setupd        *p_setup,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_init_csal )(
        FFT_setup         *p_setup,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_init_csal )(
        FFT_setupd        *p_setup,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_set_buffer_base )(
        FFT_setup         *p_setup,
        void              *buffer,
        const SAL_i32          n_bytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_set_buffer_base )(
        FFT_setupd        *p_setup,
        void              *buffer,
        const SAL_i32          n_bytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setup_set_buffer_csal )(
        FFT_setup         *p_setup,
        void              *buffer,
        const SAL_i32          n_bytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    SAL_i32 PREFIX( fft_setupd_set_buffer_csal )(
        FFT_setupd        *p_setup,
        void              *buffer,
        const SAL_i32          n_bytes,
        const SAL_i32          flag,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_free_base )(
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_freed_base )(
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_free_csal )(
        FFT_setup         *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_freed_csal )(
        FFT_setupd        *p_setup,
        SAL__return_info  *r_info
    );

    void PREFIX( fft_cipdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_ciptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *C,
        SAL_i32 K,
        SAL_cf64 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_ciptx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_cf32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_cipx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_copdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *A,
        SAL_i32 I,
        SAL_cf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_coptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_cf64 *A,
        SAL_i32 I,
        SAL_cf64 *C,
        SAL_i32 K,
        SAL_cf64 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_coptx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 I,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_cf32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_copx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 I,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_cvmagsx_csal ) (
        FFT_setup *SETUPP,
        SAL_cf32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_ripdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_riptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_f64 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_riptx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_ripx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_ropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_roptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_f64 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_roptx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_ropx_csal ) (
        FFT_setup *SETUPP,
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zipdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_ziptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_zf64 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_ziptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zipx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zopdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zoptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_zf64 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zoptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zopx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zripdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zriptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_zf64 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zriptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zripx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zropdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zroptdx_csal ) (
        FFT_setupd *SETUPP,
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_zf64 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zroptx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *T,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zropx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fft_zvmagsx_csal ) (
        FFT_setup *SETUPP,
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_ui32 LOG2N,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( fir2x_csal ) (
        SAL_f32 *A,
        SAL_f32 *W,
        SAL_f32 *Psum,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 Sflag,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fir3x_csal ) (
        SAL_f32 *A,
        SAL_f32 *W,
        SAL_f32 *Psum,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 Sflag,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fixpixadx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_ui8 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fixpixbdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_ui8 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fixpixbx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_ui8 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( flnzx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_i32 *S1,
        SAL_i32 *S2,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fltpixadx_csal ) (
        SAL_ui8 *A,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fltpixbdx_csal ) (
        SAL_ui8 *A,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( fltpixbx_csal ) (
        SAL_ui8 *A,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( hammdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( hamm_windowdx_csal ) (
        SAL_f64 *C,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( hamm_windowx_csal ) (
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( hammx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( hanndx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( hann_windowdx_csal ) (
        SAL_f64 *C,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( hann_windowx_csal ) (
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( hannx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( histdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 N,
        SAL_i32 NB,
        SAL_f64 *AMAX,
        SAL_f64 *AMIN,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( histx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 NB,
        SAL_f32 *AMAX,
        SAL_f32 *AMIN,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( ihist32x_csal ) (
        SAL_ui16 *A,
        SAL_i32 I,
        SAL_i32 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( ihistx_csal ) (
        SAL_ui16 *A,
        SAL_i32 I,
        SAL_i8 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( imgfirdx_csal ) (
        SAL_f64 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f64 *B,
        SAL_f64 *C,
        SAL_i32 M,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( imgfirx_csal ) (
        SAL_f32 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f32 *B,
        SAL_f32 *C,
        SAL_i32 M,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lveqdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lveqix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lveqx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvgedx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvgeix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvgex_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvgtdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvgtix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvgtx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvledx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvleix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvlex_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvltdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvltix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvltx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvnedx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvneix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvnex_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvnotdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvnotix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( lvnotx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( matinv_lux_csal ) (
        SAL_f32 *C,
        SAL_f32 *D,
        SAL_i32 *IP,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( mat_auto_muldx_csal ) (
        SAL_f64 *pA,
        SAL_i32 Atcols,
        SAL_f64 *pC,
        SAL_i32 Ctcols,
        SAL_i32 n_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mat_auto_mulx_csal ) (
        SAL_f32 *pA,
        SAL_i32 Atcols,
        SAL_f32 *pC,
        SAL_i32 Ctcols,
        SAL_i32 n_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mat_chol_decx_csal ) (
        SAL_f32 *A,
        SAL_i32 Atcols,
        SAL_f32 *LDU,
        SAL_i32 LDUtcols,
        SAL_i32 n,
        SAL_f32 *rcond_est,
        SAL_f32 *v,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mat_chol_solx_csal ) (
        SAL_f32 *LDU,
        SAL_i32 LDUtcols,
        SAL_f32 *b,
        SAL_f32 *w,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mat_lud_decx_csal ) (
        SAL_f32 *A,
        SAL_i32 Atcols,
        SAL_i32 *VPerm,
        SAL_i32 n,
        SAL_f32 *rcond_est,
        SAL_f32 *v,
        SAL_i32 flag ,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( mat_lud_solx_csal ) (
        SAL_f32 *LU,
        SAL_i32 LUtcols,
        SAL_i32 *D,
        SAL_f32 *b,
        SAL_f32 *w,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mat_mgs_decx_csal ) (
        SAL_f32 *AT,
        SAL_i32 ATtcols,
        SAL_f32 *R,
        SAL_i32 Rtcols,
        SAL_i32 m,
        SAL_i32 n,
        SAL_f32 *rcond_est,
        SAL_f32 *v,
        SAL_i32 flag,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( mat_mgs_solrhrx_csal ) (
        SAL_f32 *R,
        SAL_i32 R_tcols,
        SAL_f32 *B,
        SAL_f32 *X,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mat_mgs_solrx_csal ) (
        SAL_f32 *R,
        SAL_i32 R_tcols,
        SAL_f32 *B,
        SAL_f32 *X,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mat_muldx_csal ) (
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
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mat_mulx_csal ) (
        SAL_f32 *pA,
        SAL_i32 Atcols,
        SAL_f32 *pB,
        SAL_i32 Btcols,
        SAL_f32 *pC,
        SAL_i32 Ctcols,
        SAL_i32 nr_c,
        SAL_i32 nc_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( _csal_mat_norm1_estx_csal ) (
        void *M,
        void ( *mvmult_func )( void *M, SAL_f32 *x, SAL_f32 *y, SAL_i32 flag, SAL_i32 n ),
        SAL_f32 *norm_est,
        SAL_f32 *v,
        SAL_f32 *u,
        SAL_i32 t,
        SAL_f32 *X0,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( maxmgvdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( maxmgvix_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_i32 *S2,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( maxmgvx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( maxvdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( maxvidx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S1,
        SAL_i32 *S2,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( maxvix_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_i32 *S2,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( maxvx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( meamgvdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( meamgvx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( meanvdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( meanvx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( measqvdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( measqvx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( medf3x3dx_csal ) (
        SAL_f64 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f64 *C,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( medf3x3x_csal ) (
        SAL_f32 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f32 *C,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( medf5x5dx_csal ) (
        SAL_f64 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f64 *C,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( medf5x5x_csal ) (
        SAL_f32 *A,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_f32 *C,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( medfdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( medfx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( minmgvdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( minmgvix_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_i32 *S2,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( minmgvx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( minvdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( minvidx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S1,
        SAL_i32 *S2,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( minvix_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_i32 *S2,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( minvx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( mmovdx_csal ) (
        SAL_f64 *pSrc,
        SAL_i32 stride_x_src,
        SAL_i32 stride_y_src,
        SAL_f64 *pDst,
        SAL_i32 stride_x_dst,
        SAL_i32 stride_y_dst,
        SAL_i32 x_len,
        SAL_i32 y_len,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mmovx_csal ) (
        SAL_f32 *pSrc,
        SAL_i32 stride_x_src,
        SAL_i32 stride_y_src,
        SAL_f32 *pDst,
        SAL_i32 stride_x_dst,
        SAL_i32 stride_y_dst,
        SAL_i32 x_len,
        SAL_i32 y_len,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( mmuldx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 MC,
        SAL_i32 NC,
        SAL_i32 NA,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );
    
    void PREFIX( mtrans2dx_csal ) (
        SAL_f64 *A,
        SAL_f64 *C,
        SAL_i32 NC,
        SAL_i32 NR,
        SAL_i32 TCA,
        SAL_i32 TCC,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( mtrans2x_csal ) (
        SAL_f32 *A,
        SAL_f32 *C,
        SAL_i32 NC,
        SAL_i32 NR,
        SAL_i32 TCA,
        SAL_i32 TCC,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( mvessqx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( nzcrosx_csal ) (
        SAL_f32 *r_A,
        SAL_i32 I,
        SAL_i32 IN,
        SAL_i32 *IL,
        SAL_i32 *NF,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( polardx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( polarx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rectdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rectx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_cicx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_cf32 *input,
        SAL_cf32 *output,
        SAL_i32 input_len,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_cocx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_cf32 *input,
        SAL_cf32 *output,
        SAL_i32 output_len,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mc_cicx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_cf32 *input,
        SAL_i32 input_tcols,
        SAL_cf32 *output,
        SAL_i32 output_tcols,
        SAL_i32 input_len,
        SAL_i32 num_columns,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mc_cocx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_cf32 *input,
        SAL_i32 input_tcols,
        SAL_cf32 *output,
        SAL_i32 output_tcols,
        SAL_i32 output_len,
        SAL_i32 num_columns,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mc_ricx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_f32 *input,
        SAL_i32 input_tcols,
        SAL_f32 *output,
        SAL_i32 output_tcols,
        SAL_i32 input_len,
        SAL_i32 num_columns,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mc_rocx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_f32 *input,
        SAL_i32 input_tcols,
        SAL_f32 *output,
        SAL_i32 output_tcols,
        SAL_i32 output_len,
        SAL_i32 num_columns,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mc_zicx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_zf32 *input,
        SAL_i32 input_tcols,
        SAL_zf32 *output,
        SAL_i32 output_tcols,
        SAL_i32 input_len,
        SAL_i32 num_columns,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mc_zocx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_zf32 *input,
        SAL_i32 input_tcols,
        SAL_zf32 *output,
        SAL_i32 output_tcols,
        SAL_i32 output_len,
        SAL_i32 num_columns,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mr_cicx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_cf32 *input,
        SAL_i32 input_tcols,
        SAL_cf32 *output,
        SAL_i32 output_tcols,
        SAL_i32 input_len,
        SAL_i32 num_rows,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mr_cocx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_cf32 *input,
        SAL_i32 input_tcols,
        SAL_cf32 *output,
        SAL_i32 output_tcols,
        SAL_i32 output_len,
        SAL_i32 num_rows,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mr_ricx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_f32 *input,
        SAL_i32 input_tcols,
        SAL_f32 *output,
        SAL_i32 output_tcols,
        SAL_i32 input_len,
        SAL_i32 num_rows,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mr_rocx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_f32 *input,
        SAL_i32 input_tcols,
        SAL_f32 *output,
        SAL_i32 output_tcols,
        SAL_i32 output_len,
        SAL_i32 num_rows,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mr_zicx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_zf32 *input,
        SAL_i32 input_tcols,
        SAL_zf32 *output,
        SAL_i32 output_tcols,
        SAL_i32 input_len,
        SAL_i32 num_rows,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_mr_zocx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_zf32 *input,
        SAL_i32 input_tcols,
        SAL_zf32 *output,
        SAL_i32 output_tcols,
        SAL_i32 output_len,
        SAL_i32 num_rows,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_ricx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_f32 *input,
        SAL_f32 *output,
        SAL_i32 input_len,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_rocx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_f32 *input,
        SAL_f32 *output,
        SAL_i32 output_len,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_zicx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_zf32 *input,
        SAL_zf32 *output,
        SAL_i32 input_len,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( resamp_zocx_csal ) (
        SAL_resamp_map map_handle,
        SAL_i32 map,
        SAL_i32 map_start_pos,
        SAL_zf32 *input,
        SAL_zf32 *output,
        SAL_i32 output_len,
        SAL_i32 flag_word,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( rfft2ddx_csal ) (
        SAL_f64 *c,
        SAL_i32 nc,
        SAL_i32 nr,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rfft2dx_csal ) (
        SAL_f32 *c,
        SAL_i32 nc,
        SAL_i32 nr,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rfftbdx_csal ) (
        SAL_f64 *c,
        SAL_f64 *d,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rfftbx_csal ) (
        SAL_f32 *c,
        SAL_f32 *d,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rfftdx_csal ) (
        SAL_f64 *c,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rfftodx_csal ) (
        SAL_f64 *c,
        SAL_f64 *t,
        SAL_f64 *d,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rfftox_csal ) (
        SAL_f32 *c,
        SAL_f32 *t,
        SAL_f32 *d,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rfftscdx_csal ) (
        SAL_f64 *C,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 FS,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rfftscx_csal ) (
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 FS,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rfftx_csal ) (
        SAL_f32 *c,
        SAL_i32 n,
        SAL_i32 f,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rmsqvdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( rmsqvx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( spindx_csal ) (
        SAL_f64 *A,
        SAL_f64 *B,
        SAL_f64 *C,
        SAL_i32 INC,
        SAL_i32 INR,
        SAL_i32 ONC,
        SAL_i32 ONR,
        SAL_i32 F,
        SAL_f64 *V,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( spinx_csal ) (
        SAL_f32 *A,
        SAL_f32 *B,
        SAL_f32 *C,
        SAL_i32 INC,
        SAL_i32 INR,
        SAL_i32 ONC,
        SAL_i32 ONR,
        SAL_i32 F,
        SAL_f32 *V,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( svdivx_csal ) (
        SAL_f32 *S,
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( svedx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( svemgdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( svemgx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( svesqdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( svesqx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( svex_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( svsdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( svsx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( tconvlx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 LA,
        SAL_i32 LL,
        SAL_i32 LU,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( transx_csal ) (
        SAL_f32 *A,
        SAL_cf32 *c_B,
        SAL_cf32 *c_C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( unwrap_phasex_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_unwrap_phase_state *P,
        SAL_i32 F,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( vaamx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_f32 *E,
        SAL_i32 M,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vabmrgx_csal ) (
        SAL_f32 *A,
        SAL_f32 *B,
        SAL_f32 *C,
        SAL_i32 F,
        SAL_i32 M,
        SAL_i32 NA,
        SAL_i32 NB,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vabsdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vabsix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vabsx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vadddx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vaddix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vaddx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vaintx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( valogdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( valogx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vamdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vamergx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_i32 NA,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_i32 NB,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vamx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vandix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vasbmx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_f32 *E,
        SAL_i32 M,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vasmx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *S,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vatan2dx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vatan2x_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vatandx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vatanx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vavexpx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vavlinx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vclipcx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_f32 *S2,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 *NLOW,
        SAL_i32 *NHI,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vclipdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S1,
        SAL_f64 *S2,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vclipx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_f32 *S2,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vclrdx_csal ) (
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vclrx_csal ) (
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vcmergx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vcmprsx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_endian2x_csal ) (
        SAL_ui8* p_src,
        SAL_i32 stride_src,
        SAL_ui8* p_dst,
        SAL_i32 stride_dst,
        SAL_i32 n_elems,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_endian4x_csal ) (
        SAL_ui8* p_src,
        SAL_i32 stride_src,
        SAL_ui8* p_dst,
        SAL_i32 stride_dst,
        SAL_i32 n_elems,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_endian8x_csal ) (
        SAL_ui8* p_src,
        SAL_i32 stride_src,
        SAL_ui8* p_dst,
        SAL_i32 stride_dst,
        SAL_i32 n_elems,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );
    void PREFIX( vconvert_cs16_zf32x_csal ) (
        SAL_ci16 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_cs32_zf32x_csal ) (
        SAL_ci32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_cs8_zf32x_csal ) (
        SAL_ci8 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_cu16_zf32x_csal ) (
        SAL_cui16 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_cu32_zf32x_csal ) (
        SAL_cui32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_cu8_zf32x_csal ) (
        SAL_cui8 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_f32_s16x_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_i16 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_f32_s32x_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_f32_s8x_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_i8 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_f32_u16x_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_ui16 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_f32_u32x_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_ui32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_f32_u8x_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_ui8 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_s16_f32x_csal ) (
        SAL_i16 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_s32_f32x_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_s8_f32x_csal ) (
        SAL_i8 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_u16_f32x_csal ) (
        SAL_ui16 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_u32_f32x_csal ) (
        SAL_ui32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_u8_f32x_csal ) (
        SAL_ui8 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_zf32_cs16x_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_ci16 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_zf32_cs32x_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_ci32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_zf32_cs8x_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_ci8 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_zf32_cu16x_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_cui16 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_zf32_cu32x_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_cui32 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vconvert_zf32_cu8x_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_cui8 *C,
        SAL_i32 K,
        SAL_f32 *SCALE,
        SAL_f32 *BIAS,
        SAL_i32 N,
        SAL_i32 FLAG,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vcosdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vcosx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vdbconx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vdistdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vdistx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vdivdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vdivix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vdivzx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vdivx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vdpspx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( venvlpdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( venvlpx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( veqvix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vexpdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vexpx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfilldx_csal ) (
        SAL_f64 *S,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfillix_csal ) (
        SAL_i32 *S,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfillx_csal ) (
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( vfixdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_i16 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfixr32dx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfixr32x_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfixrdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_i16 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vflt16x_csal ) (
        SAL_i16 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vflt32dx_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( vflt8x_csal ) (
        SAL_i8 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfltdx_csal ) (
        SAL_i16 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfltu16x_csal ) (
        SAL_ui16 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfltu32dx_csal ) (
        SAL_ui32 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( vfltudx_csal ) (
        SAL_ui16 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfracdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vfracx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vgathradx_csal ) (
        SAL_f64 **A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vgathrax_csal ) (
        SAL_f32 **A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vgathrdx_csal ) (
        SAL_f64 *A,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vgathrx_csal ) (
        SAL_f32 *A,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vgenpx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 M,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vgenx_csal ) (
        SAL_f32 *S1,
        SAL_f32 *S2,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( viclipx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_f32 *S2,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vimagdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vimagx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vindexx_csal ) (
        SAL_f32 *A,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( vintbx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *S,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( vlimdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S1,
        SAL_f64 *S2,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlimx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_f32 *S2,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlintx_csal ) (
        SAL_f32 *A,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 M,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlmergx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlndx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlnmzx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlnmx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlnzx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlnx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlogdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlogmzx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlogmx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlogzx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vlogx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vma_x_csal )(
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmadx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmaxdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmaxmgdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmaxmgx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmaxx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmindx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vminmgdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vminmgx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vminx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmmax_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_f32 *E,
        SAL_i32 M,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmmsbx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_f32 *E,
        SAL_i32 M,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmovdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmovix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmovx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmsadx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *S,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmsax_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *S,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmsbdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmsbx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmuldx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmulix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vmulx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vnabsx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vnegdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vnegix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vnegx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );


    void PREFIX( vorix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vpmergx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vpolydx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vpolyx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vpythgx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_f32 *E,
        SAL_i32 M,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vqintx_csal ) (
        SAL_f32 *A,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 M,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vrampdx_csal ) (
        SAL_f64 *S1,
        SAL_f64 *S2,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vrampix_csal ) (
        SAL_i32 *S1,
        SAL_i32 *S2,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vrampx_csal ) (
        SAL_f32 *S1,
        SAL_f32 *S2,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vrealdx_csal ) (
        SAL_cf64 *c_A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vrealx_csal ) (
        SAL_cf32 *c_A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vrecipx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vrsqrtdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 J,
        SAL_i32 N,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( vrsqrtx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 J,
        SAL_i32 N,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( vrsumx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vrvrsx_csal ) (
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsadddx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsaddix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *S,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsaddx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsbmdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsbmx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsbsbmx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_f32 *E,
        SAL_i32 M,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsbsmx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *S,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vscaldx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *d_B,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 NB,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vscalx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *r_B,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 NB,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vscatradx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 **C,
        SAL_i32 J,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vscatrax_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 **r_B,
        SAL_i32 J,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vscatrdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vscatrx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsdivdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsdivix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *S,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsdivx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsimpsx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsindx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsinx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsmadx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsmax_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsmsadx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S2,
        SAL_f64 *S1,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsmsax_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S2,
        SAL_f32 *S1,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsmsbdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsmsbx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsmuldx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsmulix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *S,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsmulx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsortix_csal ) (
        SAL_f32 *C,
        SAL_i32 *IC,
        SAL_i32 *List_addr,
        SAL_i32 N,
        SAL_i32 Oflag,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsortx_csal ) (
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 Oflag,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vspdpx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsqdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsqrtdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsqrtzx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsqrtx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsqx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vssqdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vssqx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsubdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsubix_csal ) (
        SAL_i32 *A,
        SAL_i32 I,
        SAL_i32 *B,
        SAL_i32 J,
        SAL_i32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vsubx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vswapdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vswapx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vswsumx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vtabidx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S1,
        SAL_f64 *S2,
        SAL_f64 *C,
        SAL_i32 M,
        SAL_f64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vtabix_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_f32 *S2,
        SAL_f32 *C,
        SAL_i32 M,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vtanx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vthresdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_f64 *S,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vthresx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vthrscx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S1,
        SAL_f32 *S2,
        SAL_f32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vthrx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vtmergx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( vtrapzx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( warpdx_csal ) (
        SAL_f64 *A,
        SAL_f64 *B,
        SAL_f64 *C,
        SAL_i32 INC,
        SAL_i32 INR,
        SAL_i32 ONC,
        SAL_i32 ONR,
        SAL_i32 F,
        SAL_f64 *V,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( warpx_csal ) (
        SAL_f32 *A,
        SAL_f32 *B,
        SAL_f32 *C,
        SAL_i32 INC,
        SAL_i32 INR,
        SAL_i32 ONC,
        SAL_i32 ONR,
        SAL_i32 F,
        SAL_f32 *V,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( wienerx_csal ) (
        SAL_i32 L,
        SAL_f32 *A,
        SAL_f32 *C,
        SAL_f32 *F,
        SAL_f32 *P,
        SAL_i32 IFLG,
        SAL_i32 *IERR,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( zaspecx_csal ) (
        SAL_zf32 *A,
        SAL_f32 *C,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zcoherx_csal ) (
        SAL_f32 *A,
        SAL_f32 *B,
        SAL_zf32 *C,
        SAL_f32 *D,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zconv2d_iax_csal ) (
        SAL_zf32 *A,
        SAL_zf32 *B,
        SAL_zf32 *C,
        SAL_i32 DSX,
        SAL_i32 DSY,
        SAL_i32 NCB,
        SAL_i32 NRB,
        SAL_i32 NCC,
        SAL_i32 NRC,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zconv2dx_csal ) (
        SAL_zf32 *A,
        SAL_i32 TCA,
        SAL_zf32 *B,
        SAL_zf32 *C,
        SAL_i32 TCC,
        SAL_i32 DSX,
        SAL_i32 DSY,
        SAL_i32 NCB,
        SAL_i32 NRB,
        SAL_i32 NCC,
        SAL_i32 NRC,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zconvx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zcspecx_csal ) (
        SAL_zf32 *A,
        SAL_zf32 *B,
        SAL_zf32 *C,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zdotprdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *B,
        SAL_i32 J,
        SAL_zf64 *S,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zdotprx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *S,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zexpmulx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_f32 *F,
        SAL_f32 *P,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *ZEXPTAB,
        SAL_i32 LOG2M,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zexptabx_csal ) (
        SAL_zf32 *C,
        SAL_i32 LOG2M,
        SAL_i32 FLAG,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zidotprdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *B,
        SAL_i32 J,
        SAL_zf64 *S,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zidotprx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *S,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zimuldx_csal ) (
        SAL_zf64 *A,
        SAL_zf64 *B,
        SAL_zf64 *C,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_i32 F,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zimulx_csal ) (
        SAL_zf32 *A,
        SAL_zf32 *B,
        SAL_zf32 *C,
        SAL_i32 NR,
        SAL_i32 NC,
        SAL_i32 F,
        SAL_i32 X,
        SAL__return_info *r_info
    );


    void PREFIX( zmatherm_eigx_csal ) (
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
    );

    void PREFIX( zmatinv_lux_csal ) (
        SAL_zf32 *C,
        SAL_zf32 *D,
        SAL_i32 *IP,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_auto_muldx_csal ) (
        SAL_zf64 *pA,
        SAL_i32 Atcols,
        SAL_zf64 *pC,
        SAL_i32 Ctcols,
        SAL_i32 n_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_auto_mulx_csal ) (
        SAL_zf32 *pA,
        SAL_i32 Atcols,
        SAL_zf32 *pC,
        SAL_i32 Ctcols,
        SAL_i32 n_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_chol_decx_csal ) (
        SAL_zf32 *A,
        SAL_i32 Atcols,
        SAL_zf32 *LDU,
        SAL_i32 LDUtcols,
        SAL_i32 n,
        SAL_f32 *rcond_est,
        SAL_zf32 *v,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_chol_solx_csal ) (
        SAL_zf32 *LDU,
        SAL_i32 LDUtcols,
        SAL_zf32 *b,
        SAL_zf32 *w,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_lud_decx_csal ) (
        SAL_zf32 *C,
        SAL_i32 Ctcols,
        SAL_i32 *D,
        SAL_i32 n,
        SAL_f32 *rcond_est,
        SAL_zf32 *v,
        SAL_i32 flag,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_lud_solx_csal ) (
        SAL_zf32 *A,
        SAL_i32 Atcols,
        SAL_i32 *D,
        SAL_zf32 *b,
        SAL_zf32 *w,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_mgs_decx_csal ) (
        SAL_zf32 *AT,
        SAL_i32 ATtcols,
        SAL_zf32 *R,
        SAL_i32 Rtcols,
        SAL_i32 m,
        SAL_i32 n,
        SAL_f32 *rcond_est,
        SAL_zf32 *v,
        SAL_i32 flag,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_mgs_solrhrx_csal ) (
        SAL_zf32 *R,
        SAL_i32 R_tcols,
        SAL_zf32 *B,
        SAL_zf32 *X,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_mgs_solrx_csal ) (
        SAL_zf32 *R,
        SAL_i32 R_tcols,
        SAL_zf32 *B,
        SAL_zf32 *X,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_muldx_csal ) (
        SAL_zf64 *pA,
        SAL_i32 Atcols,
        SAL_zf64 *pB,
        SAL_i32 Btcols,
        SAL_zf64 *pC,
        SAL_i32 Ctcols,
        SAL_i32 nr_c,
        SAL_i32 nc_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_mulx_csal ) (
        SAL_zf32 *pA,
        SAL_i32 Atcols,
        SAL_zf32 *pB,
        SAL_i32 Btcols,
        SAL_zf32 *pC,
        SAL_i32 Ctcols,
        SAL_i32 nr_c,
        SAL_i32 nc_c,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( _csal_zmat_norm1_estx_csal ) (
        void *M,
        void ( *mvmult_func )( void *M, SAL_zf32 *x, SAL_zf32 *y, SAL_i32 flag, SAL_i32 n ),
        SAL_f32 *norm_est,
        SAL_zf32 *v,
        SAL_zf32 *u,
        SAL_i32 t,
        SAL_zf32 *X0,
        SAL_i32 n,
        SAL_i32 flag,
        SAL_i32 XFLAG,
        SAL__return_info *r_info
    );

    void PREFIX( zmat_svdx_csal ) (
        SAL_zf32 *A,
        SAL_i32 Atcols,
        SAL_f32 *D,
        SAL_zf32 *U,
        SAL_i32 Utcols,
        SAL_zf32 *V,
        SAL_i32 Vtcols,
        SAL_i32 m,
        SAL_i32 n,
        SAL_svd_tune *svd_tune,
        SAL_f32 *cond_num,
        SAL_i32 *numerical_rank,
        SAL_i32 sal_svd_flag,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zmixerx_csal ) (
        SAL_zf32 *A,
        SAL_i32 sA,
        SAL_f64 *F,
        SAL_f64 *P,
        SAL_zf32 *C,
        SAL_i32 sC,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 eflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmmax_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *D,
        SAL_i32 L,
        SAL_i32 MC,
        SAL_i32 NC,
        SAL_i32 NA,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zmmovdx_csal ) (
        SAL_zf64 *pSrc,
        SAL_i32 stride_x_src,
        SAL_i32 stride_y_src,
        SAL_zf64 *pDst,
        SAL_i32 stride_x_dst,
        SAL_i32 stride_y_dst,
        SAL_i32 x_len,
        SAL_i32 y_len,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmmovx_csal ) (
        SAL_zf32 *pSrc,
        SAL_i32 stride_x_src,
        SAL_i32 stride_y_src,
        SAL_zf32 *pDst,
        SAL_i32 stride_x_dst,
        SAL_i32 stride_y_dst,
        SAL_i32 x_len,
        SAL_i32 y_len,
        SAL_i32 xflag,
        SAL__return_info *r_info
    );

    void PREFIX( zmmsx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *D,
        SAL_i32 L,
        SAL_i32 MC,
        SAL_i32 NC,
        SAL_i32 NA,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zmmuldx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *B,
        SAL_i32 J,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 MC,
        SAL_i32 NC,
        SAL_i32 NA,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zmsmx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *D,
        SAL_i32 L,
        SAL_i32 MC,
        SAL_i32 NC,
        SAL_i32 NA,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zmtrans2dx_csal ) (
        SAL_zf64 *A,
        SAL_zf64 *C,
        SAL_i32 NC,
        SAL_i32 NR,
        SAL_i32 TCA,
        SAL_i32 TCC,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zmtrans2x_csal ) (
        SAL_zf32 *A,
        SAL_zf32 *C,
        SAL_i32 NC,
        SAL_i32 NR,
        SAL_i32 TCA,
        SAL_i32 TCC,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zrdesampx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_zf32 *C,
        SAL_i32 N,
        SAL_i32 P,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zrdotprdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_f64 *B,
        SAL_i32 J,
        SAL_zf64 *S,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zrdotprx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_zf32 *S,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zrmixerx_csal ) (
        SAL_f32 *A,
        SAL_i32 sA,
        SAL_f64 *F,
        SAL_f64 *P,
        SAL_zf32 *C,
        SAL_i32 sC,
        SAL_i32 N,
        SAL_i32 flag,
        SAL_i32 eflag,
        SAL__return_info *r_info
    );

    void PREFIX( zrvaddx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zrvdivx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zrvmulx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zrvsubx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( ztocdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_cf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( ztocx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_cf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( ztransx_csal ) (
        SAL_f32 *A,
        SAL_zf32 *B,
        SAL_zf32 *C,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvabsx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvadddx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *B,
        SAL_i32 J,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvaddx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvcmax_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvcmuldx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *B,
        SAL_i32 J,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvcmulx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvconjdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvconjx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvdbconx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *S,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvdivdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *B,
        SAL_i32 J,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvdivx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvexpdx_csal ) (
        SAL_f64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvexpmx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvexpx_csal ) (
        SAL_f32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvfillx_csal ) (
        SAL_zf32 *S,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvimagdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N ,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvimagx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvmagsdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvmagsx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvmgsax_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *B,
        SAL_i32 J,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvmovdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvmovx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvmuldx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *B,
        SAL_i32 J,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvmulx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 F,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvnegdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvnegx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvphasx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvrcipdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvrcipx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvrealdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_f64 *C,
        SAL_i32 K,
        SAL_i32 N ,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvrealx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_f32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvsmadx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *S,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_zf64 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvsmax_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *S,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_zf32 *D,
        SAL_i32 L,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvsqrtx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvsubdx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *B,
        SAL_i32 J,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvsubx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *B,
        SAL_i32 J,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvzsmldx_csal ) (
        SAL_zf64 *A,
        SAL_i32 I,
        SAL_zf64 *S,
        SAL_zf64 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

    void PREFIX( zvzsmlx_csal ) (
        SAL_zf32 *A,
        SAL_i32 I,
        SAL_zf32 *S,
        SAL_zf32 *C,
        SAL_i32 K,
        SAL_i32 N,
        SAL_i32 X,
        SAL__return_info *r_info
    );

#ifdef __cplusplus
}
#endif

#endif

