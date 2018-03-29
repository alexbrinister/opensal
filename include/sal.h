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
        sal.h

----------------------------------------------------------------------------
*/

#ifndef SAL_H
#define SAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

#define SAL_SUCCESS            (  0 )
#define SAL_FAILURE            ( -1 )
#define SAL_INVALID_ARGUMENT   ( -2 )
#define SAL_NOT_ENOUGH_MEMORY  ( -3 )
#define SAL_INVALID_SIZE       ( -4 )
#define SAL_INVALID_FLAG       ( -5 )
#define SAL_INVALID_FUNCTION   ( -6 )
#define SAL_FFT_NOT_SUPPORTED  ( -7 )
#define SAL_INVALID_HANDLE     ( -8 )
#define SAL_NOT_SUPPORTED      ( -9 )

#define SAL_SORT_EIG           ( 1 )

    typedef void                SAL_void;
    typedef char                SAL_char;
    typedef signed char         SAL_i8;
    typedef short               SAL_i16;
    typedef int                 SAL_i32;
    typedef long long           SAL_i64;
    typedef unsigned char       SAL_ui8;
    typedef unsigned short      SAL_ui16;
    typedef unsigned int        SAL_ui32;
    typedef unsigned long long  SAL_ui64;
    typedef float               SAL_f32;
    typedef double              SAL_f64;

    typedef struct
    {
        SAL_i8       real;
        SAL_i8       imag;
    } COMPLEX_S8;

    typedef struct
    {
        SAL_ui8      real;
        SAL_ui8      imag;
    } COMPLEX_U8;

    typedef struct
    {
        SAL_i16      real;
        SAL_i16      imag;
    } COMPLEX_S16;

    typedef struct
    {
        SAL_ui16     real;
        SAL_ui16     imag;
    } COMPLEX_U16;

    typedef struct
    {
        SAL_i32      real;
        SAL_i32      imag;
    } COMPLEX_S32;

    typedef struct
    {
        SAL_ui32     real;
        SAL_ui32     imag;
    } COMPLEX_U32;

    typedef struct
    {
        SAL_f32      real;
        SAL_f32      imag;
    } COMPLEX;

    typedef struct
    {
        SAL_f64      real;
        SAL_f64      imag;
    } DOUBLE_COMPLEX;

    typedef struct
    {
        SAL_f32     *realp;
        SAL_f32     *imagp;
    } COMPLEX_SPLIT;

    typedef struct
    {
        SAL_f64     *realp;
        SAL_f64     *imagp;
    } DOUBLE_COMPLEX_SPLIT;

    typedef COMPLEX                 COMPLEX_F32;
    typedef DOUBLE_COMPLEX          COMPLEX_F64;
    typedef COMPLEX_SPLIT           COMPLEX_SPLIT_F32;
    typedef DOUBLE_COMPLEX_SPLIT    COMPLEX_SPLIT_F64;

    typedef COMPLEX_F32         SAL_cf32;
    typedef COMPLEX_F64         SAL_cf64;
    typedef COMPLEX_SPLIT_F32   SAL_zf32;
    typedef COMPLEX_SPLIT_F64   SAL_zf64;
    typedef COMPLEX_S8          SAL_ci8;
    typedef COMPLEX_S16         SAL_ci16;
    typedef COMPLEX_S32         SAL_ci32;
    typedef COMPLEX_U8          SAL_cui8;
    typedef COMPLEX_U16         SAL_cui16;
    typedef COMPLEX_U32         SAL_cui32;

#define SAL_RESERVED_FLAG ( 0 )

#define SAL_CACHE_SYNCHRONOUS   ( 0 )
#define SAL_CACHE_ASYNCHRONOUS  ( 1 )

#define  SAL_CONJUGATE   ( 2 )

#define  SAL_ACCUMULATE       ( 1 )

#define  SAL_CONJUGATE_LEFT   ( 2 )
#define  SAL_CONJUGATE_RIGHT  ( 4 )

#define  SAL_TRANSPOSE_LEFT   (  8 )
#define  SAL_TRANSPOSE_RIGHT  ( 16 )

#define  SAL_ROUND_ZERO       ( 0 )
#define  SAL_ROUND_NEAREST    ( 1 )

#define  SAL_ROUND_UP         ( 2 )
#define  SAL_ROUND_DOWN       ( 3 )

#define  SAL_FIELD_SATURATE   ( 4 )

#define  SAL_FIELD_NOSATURATE ( 0 )

    typedef SAL_i32 SAL_status;
    
#define SAL_STATUS  SAL_void
#define SAL_STATUS_INT  SAL_i32

#define SAL_CONJUGATE_SIGNAL      ( 1 << 29 )
#define SAL_CONJUGATE_OSCILLATOR  ( 1 << 30 )

    typedef struct sal_unwrap_phase_state
    {
        double reserved[4];
    } SAL_unwrap_phase_state;

    typedef SAL_unwrap_phase_state* SAL_unwrap_phase_state_h;

#define SAL_UNWRAP_PHASE_START      ( 0 )
#define SAL_UNWRAP_PHASE_CONTINUE   ( 1 << 30 )

#define  FFT_FORWARD                  (  1 )
#define  FFT_INVERSE                  ( -1 )

#define  FFT_RADIX3                   (    1 )
#define  FFT_RADIX5                   (    2 )
#define  FFT_COMPLEX_ONLY             (    4 )
#define  FFT_REAL_ONLY                (    8 )
#define  FFT_DRAM_TWIDDLES            (   16 )
#define  FFT_OPTIMAL_INPUTS           (   32 )
#define  FFT_FAST_CONVOLUTION         (   64 )
#define  FFT_RADIX9                   (  128 )
#define  FFT_COMPLEX_SPLIT_ONLY       (  256 )
#define  FFT_COMPLEX_INTERLEAVED_ONLY (  512 )
#define  FFT_IS_1D                    ( 1024 )
#define  FFT_IS_DOUBLE                ( 2048 )
#define  FFT_IS_INPLACE               ( 4096 )
    
#define  SAL_HALF_WINDOW              ( 1 )
#define  SAL_HANN_DENORM              ( 0 )
#define  SAL_HANN_NORM                ( 2 )

#define  SAL_FFT_OPTIMIZE_FOR_TIME     ( 0L )
#define  SAL_FFT_OPTIMIZE_FOR_SPACE    ( 1L )
#define  SAL_FFT_OPTIMIZE_FOR_ACCURACY ( 2L )
#define  SAL_FFT_OPTIMIZE_RESERVED     ( 9L )

#define  SAL_FFT_DESTROY_INPUT        ( 0L )
#define  SAL_FFT_PRESERVE_INPUT       ( 2L )

#define  SAL_FFT_WILL_SUPPLY_TEMP_BUFFER  ( 32768L )

#define  SAL_POLL  ( 0 )
#define  SAL_SLEEP ( 1 )

    typedef struct sal__fft_setup  *FFT_setup;
    typedef struct sal__fft_setupd *FFT_setupd;

    typedef FFT_setup SAL_fft32;
    typedef FFT_setupd SAL_fft64;

    typedef FFT_setup* SAL_fft32_h;
    typedef FFT_setupd* SAL_fft64_h;

    typedef enum SAL_fft1d_func_t {
        SAL_FFT1D_FUNC_LB = 0,
        SAL_FFT3_CIPX,
        SAL_FFT3_COPX,
        SAL_FFT3_RIPX,
        SAL_FFT3_ROPX,
        SAL_FFT3_ZIPX,
        SAL_FFT3_ZOPX,
        SAL_FFT3_ZRIPX,
        SAL_FFT3_ZROPX,
        SAL_FFT3M_COPX,
        SAL_FFT3M_ROPX,
        SAL_FFT3M_ZOPX,
        SAL_FFT3M_ZROPX,
        SAL_FFT3M_ROWS_CIPX,
        SAL_FFT3M_COLS_CIPX,
        SAL_FFT3M_ROWS_COPX,
        SAL_FFT3M_COLS_COPX,
        SAL_FFT3M_ROWS_RIPX,
        SAL_FFT3M_COLS_RIPX,
        SAL_FFT3M_ROWS_ROPX,
        SAL_FFT3M_COLS_ROPX,
        SAL_FFT3M_ROWS_ZIPX,
        SAL_FFT3M_COLS_ZIPX,
        SAL_FFT3M_ROWS_ZOPX,
        SAL_FFT3M_COLS_ZOPX,
        SAL_FFT3M_ROWS_ZRIPX,
        SAL_FFT3M_COLS_ZRIPX,
        SAL_FFT3M_ROWS_ZROPX,
        SAL_FFT3M_COLS_ZROPX,
        SAL_FFT5_CIPX,
        SAL_FFT5_COPX,
        SAL_FFT5_RIPX,
        SAL_FFT5_ROPX,
        SAL_FFT5_ZIPX,
        SAL_FFT5_ZOPX,
        SAL_FFT5_ZRIPX,
        SAL_FFT5_ZROPX,
        SAL_FFT5M_COPX,
        SAL_FFT5M_ROPX,
        SAL_FFT5M_ZOPX,
        SAL_FFT5M_ZROPX,
        SAL_FFT5M_ROWS_CIPX,
        SAL_FFT5M_COLS_CIPX,
        SAL_FFT5M_ROWS_COPX,
        SAL_FFT5M_COLS_COPX,
        SAL_FFT5M_ROWS_RIPX,
        SAL_FFT5M_COLS_RIPX,
        SAL_FFT5M_ROWS_ROPX,
        SAL_FFT5M_COLS_ROPX,
        SAL_FFT5M_ROWS_ZIPX,
        SAL_FFT5M_COLS_ZIPX,
        SAL_FFT5M_ROWS_ZOPX,
        SAL_FFT5M_COLS_ZOPX,
        SAL_FFT5M_ROWS_ZRIPX,
        SAL_FFT5M_COLS_ZRIPX,
        SAL_FFT5M_ROWS_ZROPX,
        SAL_FFT5M_COLS_ZROPX,
        SAL_FFT9_COPX,
        SAL_FFT9_ZOPX,
        SAL_FFT_CIPX,
        SAL_FFT_COPX,
        SAL_FFT_RIPX,
        SAL_FFT_ROPX,
        SAL_FFT_ZIPX,
        SAL_FFT_ZOPX,
        SAL_FFT_ZRIPX,
        SAL_FFT_ZROPX,
        SAL_FFTM_CIPX,
        SAL_FFTM_COPX,
        SAL_FFTM_RIPX,
        SAL_FFTM_ROPX,
        SAL_FFTM_ZIPX,
        SAL_FFTM_ZOPX,
        SAL_FFTM_ZRIPX,
        SAL_FFTM_ZROPX,
        SAL_FFTM_ROWS_CIPX,
        SAL_FFTM_COLS_CIPX,
        SAL_FFTM_ROWS_COPX,
        SAL_FFTM_COLS_COPX,
        SAL_FFTM_ROWS_RIPX,
        SAL_FFTM_COLS_RIPX,
        SAL_FFTM_ROWS_ROPX,
        SAL_FFTM_COLS_ROPX,
        SAL_FFTM_ROWS_ZIPX,
        SAL_FFTM_COLS_ZIPX,
        SAL_FFTM_ROWS_ZOPX,
        SAL_FFTM_COLS_ZOPX,
        SAL_FFTM_ROWS_ZRIPX,
        SAL_FFTM_COLS_ZRIPX,
        SAL_FFTM_ROWS_ZROPX,
        SAL_FFTM_COLS_ZROPX,
        SAL_FFT1D_FUNC_UB
    } SAL_fft1d_func;

    typedef enum SAL_fft1d_funcd_t {
        SAL_FFT1D_FUNCD_LB = 100,
        SAL_FFT3_COPDX,
        SAL_FFT3_ROPDX,
        SAL_FFT3_ZOPDX,
        SAL_FFT3_ZROPDX,
        SAL_FFT5_COPDX,
        SAL_FFT5_ROPDX,
        SAL_FFT5_ZOPDX,
        SAL_FFT5_ZROPDX,
        SAL_FFT_CIPDX,
        SAL_FFT_COPDX,
        SAL_FFT_RIPDX,
        SAL_FFT_ROPDX,
        SAL_FFT_ZIPDX,
        SAL_FFT_ZOPDX,
        SAL_FFT_ZRIPDX,
        SAL_FFT_ZROPDX,
        SAL_FFTM_CIPDX,
        SAL_FFTM_COPDX,
        SAL_FFTM_RIPDX,
        SAL_FFTM_ROPDX,
        SAL_FFTM_ZIPDX,
        SAL_FFTM_ZOPDX,
        SAL_FFTM_ZRIPDX,
        SAL_FFTM_ZROPDX,
        SAL_FFTM_ROWS_CIPDX,
        SAL_FFTM_COLS_CIPDX,
        SAL_FFTM_ROWS_COPDX,
        SAL_FFTM_COLS_COPDX,
        SAL_FFTM_ROWS_RIPDX,
        SAL_FFTM_COLS_RIPDX,
        SAL_FFTM_ROWS_ROPDX,
        SAL_FFTM_COLS_ROPDX,
        SAL_FFTM_ROWS_ZIPDX,
        SAL_FFTM_COLS_ZIPDX,
        SAL_FFTM_ROWS_ZOPDX,
        SAL_FFTM_COLS_ZOPDX,
        SAL_FFTM_ROWS_ZRIPDX,
        SAL_FFTM_COLS_ZRIPDX,
        SAL_FFTM_ROWS_ZROPDX,
        SAL_FFTM_COLS_ZROPDX,
        SAL_FFT1D_FUNCD_UB
    } SAL_fft1d_funcd;

    typedef enum SAL_fft2d_func_t {
        SAL_FFT2D_FUNC_LB = 200,
        SAL_FFT2D_CIPX,
        SAL_FFT2D_COPX,
        SAL_FFT2D_RIPX,
        SAL_FFT2D_ROPX,
        SAL_FFT2D_ZIPX,
        SAL_FFT2D_ZOPX,
        SAL_FFT2D_ZRIPX,
        SAL_FFT2D_ZROPX,
        SAL_FFT2D_FUNC_UB
    } SAL_fft2d_func;

    typedef enum SAL_fft2d_funcd_t {
        SAL_FFT2D_FUNCD_LB = 300,
        SAL_FFT2D_CIPDX,
        SAL_FFT2D_COPDX,
        SAL_FFT2D_RIPDX,
        SAL_FFT2D_ROPDX,
        SAL_FFT2D_ZIPDX,
        SAL_FFT2D_ZOPDX,
        SAL_FFT2D_ZRIPDX,
        SAL_FFT2D_ZROPDX,
        SAL_FFT2D_FUNCD_UB,
        SAL_FFT_FUNC_UB
    } SAL_fft2d_funcd;

    typedef struct
    {
        int max_iterations;
        float epsilon;
    } SAL_eig_tune;

    typedef SAL_eig_tune* SAL_eig_tune_h;

    typedef struct sal_svd_tune
    {
        int max_iterations;
        float epsilon;
    } SAL_svd_tune;

    typedef SAL_svd_tune* SAL_svd_tune_h;

#define  SAL_SVD_FULL           ( 0 )
#define  SAL_SVD_THIN           ( 1 )
#define  SAL_SVD_TRUNC_TO_RANK  ( 2 )

#define  SAL_SVD_NO_V           ( 0 )

#define  SAL_SVD_V              ( 4 )

#define SAL_COND_EST_NONE      ( 0 )
#define SAL_COND_EST_1_NORM    ( 1 )
#define SAL_COND_EST_INF_NORM  ( 2 )
#define SAL_COND_EST_COMPONENT ( 3 )

#define SAL_NORMAL_SOLVER         ( 0 )
#define SAL_TRANSPOSE_SOLVER      ( 1 )

    typedef struct sal__resamp_filter  *SAL_resamp_filter;
    typedef struct sal__resamp_map     *SAL_resamp_map;

    typedef enum {
        SAL_RESAMP_ROCX, SAL_RESAMP_COCX, SAL_RESAMP_ZOCX,
        SAL_RESAMP_MR_ROCX, SAL_RESAMP_MR_COCX, SAL_RESAMP_MR_ZOCX,
        SAL_RESAMP_MC_ROCX, SAL_RESAMP_MC_COCX, SAL_RESAMP_MC_ZOCX,
        SAL_RESAMP_RICX, SAL_RESAMP_CICX, SAL_RESAMP_ZICX,
        SAL_RESAMP_MR_RICX, SAL_RESAMP_MR_CICX, SAL_RESAMP_MR_ZICX,
        SAL_RESAMP_MC_RICX, SAL_RESAMP_MC_CICX, SAL_RESAMP_MC_ZICX
    } SAL_resamp_name;

#define SAL_RESAMP_ZERO_OUT_OF_BOUNDS   ( 1 )
#define SAL_RESAMP_TAPER_OUT_OF_BOUNDS  ( 2 )

#define SAL_RESAMP_ACCUMULATE  ( 1 )

#define SAL_SINGLE_USED ( 1 )

    typedef struct SAL_handle_  *SAL_handle;

#define  SAL_N  ( 0 )
#define  SAL_C  ( 1 )

#define  SAL_NN  ( 0 )
#define  SAL_NC  ( 1 )
#define  SAL_CN  ( 2 )
#define  SAL_CC  ( 3 )

#define  SAL_NNN  ( 0 )
#define  SAL_NNC  ( 1 )
#define  SAL_NCN  ( 2 )
#define  SAL_NCC  ( 3 )
#define  SAL_CNN  ( 4 )
#define  SAL_CNC  ( 5 )
#define  SAL_CCN  ( 6 )
#define  SAL_CCC  ( 7 )

#define  SAL_NNNN  (  0 )
#define  SAL_NNNC  (  1 )
#define  SAL_NNCN  (  2 )
#define  SAL_NNCC  (  3 )
#define  SAL_NCNN  (  4 )
#define  SAL_NCNC  (  5 )
#define  SAL_NCCN  (  6 )
#define  SAL_NCCC  (  7 )
#define  SAL_CNNN  (  8 )
#define  SAL_CNNC  (  9 )
#define  SAL_CNCN  ( 10 )
#define  SAL_CNCC  ( 11 )
#define  SAL_CCNN  ( 12 )
#define  SAL_CCNC  ( 13 )
#define  SAL_CCCN  ( 14 )
#define  SAL_CCCC  ( 15 )

#define  SAL_NNNNN  (  0 )
#define  SAL_NNNNC  (  1 )
#define  SAL_NNNCN  (  2 )
#define  SAL_NNNCC  (  3 )
#define  SAL_NNCNN  (  4 )
#define  SAL_NNCNC  (  5 )
#define  SAL_NNCCN  (  6 )
#define  SAL_NNCCC  (  7 )
#define  SAL_NCNNN  (  8 )
#define  SAL_NCNNC  (  9 )
#define  SAL_NCNCN  ( 10 )
#define  SAL_NCNCC  ( 11 )
#define  SAL_NCCNN  ( 12 )
#define  SAL_NCCNC  ( 13 )
#define  SAL_NCCCN  ( 14 )
#define  SAL_NCCCC  ( 15 )
#define  SAL_CNNNN  ( 16 )
#define  SAL_CNNNC  ( 17 )
#define  SAL_CNNCN  ( 18 )
#define  SAL_CNNCC  ( 19 )
#define  SAL_CNCNN  ( 20 )
#define  SAL_CNCNC  ( 21 )
#define  SAL_CNCCN  ( 22 )
#define  SAL_CNCCC  ( 23 )
#define  SAL_CCNNN  ( 24 )
#define  SAL_CCNNC  ( 25 )
#define  SAL_CCNCN  ( 26 )
#define  SAL_CCNCC  ( 27 )
#define  SAL_CCCNN  ( 28 )
#define  SAL_CCCNC  ( 29 )
#define  SAL_CCCCN  ( 30 )
#define  SAL_CCCCC  ( 31 )

#define xint32 int

#define PASS_COMPLEX_SPLIT( splitp, rp, ip )            \
    ( ( ( unsigned long ) ( ( splitp ) ->realp = ( rp ) ) && \
        ( unsigned long ) ( ( splitp ) ->imagp = ( ip ) ) )  \
      ? ( splitp ) : ( splitp ) )

#define PASS_DOUBLE_COMPLEX_SPLIT( splitp, rp, ip ) \
    ( ( ( unsigned long ) ( ( splitp ) ->realp = ( rp ) ) && \
        ( unsigned long ) ( ( splitp ) ->imagp = ( ip ) ) )  \
      ? ( splitp ) : ( splitp ) )

#define  SAL_PATH_NOTHING              (   0 )
#define  SAL_PATH_CSAL                 (   1 )
#define  SAL_PATH_C                    (   2 )
#define  SAL_PATH_PPC                  (   3 )
#define  SAL_PATH_PPC603               (   4 )
#define  SAL_PATH_PPC750               (   5 )
#define  SAL_PATH_PPC7400              (   6 )
#define  SAL_PATH_PPC7400_VECTOR       SAL_PATH_PPC7400
#define  SAL_PATH_PPC7400_SCALAR       (   7 )
#define  SAL_PATH_PPC7400_NON_ALIGNED  (   8 )
#define  SAL_PATH_PPC7447              (   9 )
#define  SAL_PATH_PPC7447_VECTOR       SAL_PATH_PPC7447
#define  SAL_PATH_PPC7447_SCALAR       (  10 )
#define  SAL_PATH_PPC7447_NON_ALIGNED  (  11 )
#define  SAL_PATH_IBM970               (  12 )
#define  SAL_PATH_IBM970_VECTOR       SAL_PATH_IBM970
#define  SAL_PATH_IBM970_SCALAR        (  13 )
#define  SAL_PATH_IBM970_NON_ALIGNED   (  14 )
#define  SAL_PATH_IPPS                 (  15 )
#define  SAL_PATH_IPPI                 (  16 )
#define  SAL_PATH_MKL                  (  17 )
#define  SAL_PATH_IPP                  (  18 )
#define  SAL_PATH_IPP_MKL              (  19 )
#define  SAL_PATH_ASM_IPP              (  20 )
#define  SAL_PATH_ASM_MKL              (  21 )
#define  SAL_PATH_ASM_IPP_MKL          (  22 )
#define  SAL_PATH_INTEL_ASM            (  23 )
#define  SAL_PATH_INTEL_SAL            (  98 )
#define  SAL_PATH_UNKNOWN              ( 100 )

#if defined ( __STDC__ ) || defined ( __cplusplus )

    extern SAL_STATUS aspec ( SAL_cf32 *A, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS aspecx ( SAL_cf32 *A, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS blkman_window ( SAL_f32 *C, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS blkman_windowd ( SAL_f64 *C, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS blkman_windowdx ( SAL_f64 *C, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS blkman_windowx ( SAL_f32 *C, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS bprojimg ( SAL_f32 *A, SAL_f32 *C, SAL_i32 M, SAL_i32 N, SAL_i32 *P, SAL_i32 *Q, SAL_f32 *F, SAL_f32 *G );
    extern SAL_STATUS bprojimgd ( SAL_f64 *A, SAL_f64 *C, SAL_i32 M, SAL_i32 N, SAL_i32 *P, SAL_i32 *Q, SAL_f64 *F, SAL_f64 *G );
    extern SAL_STATUS bprojimgdx ( SAL_f64 *A, SAL_f64 *C, SAL_i32 M, SAL_i32 N, SAL_i32 *P, SAL_i32 *Q, SAL_f64 *F, SAL_f64 *G, SAL_i32 X );
    extern SAL_STATUS bprojimgx ( SAL_f32 *A, SAL_f32 *C, SAL_i32 M, SAL_i32 N, SAL_i32 *P, SAL_i32 *Q, SAL_f32 *F, SAL_f32 *G, SAL_i32 X );
    extern SAL_STATUS bprojrow ( SAL_f32 *C, SAL_f32 *A, SAL_i32 M, SAL_i32 N, SAL_i32 Q, SAL_f32 *F, SAL_f32 *G );
    extern SAL_STATUS bprojrowd ( SAL_f64 *C, SAL_f64 *A, SAL_i32 M, SAL_i32 N, SAL_i32 Q, SAL_f64 *F, SAL_f64 *G );
    extern SAL_STATUS bprojrowdx ( SAL_f64 *C, SAL_f64 *A, SAL_i32 M, SAL_i32 N, SAL_i32 Q, SAL_f64 *F, SAL_f64 *G, SAL_i32 X );
    extern SAL_STATUS bprojrowx ( SAL_f32 *C, SAL_f32 *A, SAL_i32 M, SAL_i32 N, SAL_i32 Q, SAL_f32 *F, SAL_f32 *G, SAL_i32 X );
    extern SAL_STATUS cache_flush_1d ( SAL_char *Ap, SAL_i32 Nbytes, SAL_i32 chan, SAL_i32 flag );
    extern SAL_STATUS cache_flush_2d ( SAL_char *Ap, SAL_i32 Atcols, SAL_i32 Nrows, SAL_i32 Ncols, SAL_i32 chan, SAL_i32 flag );
    extern SAL_STATUS cache_load_1d ( SAL_char *Ap, SAL_i32 Nbytes, SAL_i32 chan, SAL_i32 flag );
    extern SAL_STATUS cache_load_2d ( SAL_char *Ap, SAL_i32 Atcols, SAL_i32 Nrows, SAL_i32 Ncols, SAL_i32 chan, SAL_i32 flag );
    extern SAL_STATUS cache_zero_1d ( SAL_char *Ap, SAL_i32 Nbytes, SAL_i32 chan, SAL_i32 flag );
    extern SAL_STATUS cache_zero_2d ( SAL_char *Ap, SAL_i32 Atcols, SAL_i32 Nrows, SAL_i32 Ncols, SAL_i32 chan, SAL_i32 flag );
    extern SAL_STATUS cconv ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M );
    extern SAL_STATUS cconv2d ( SAL_cf32 *A, SAL_i32 tcols_A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 tcols_C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG );
    extern SAL_STATUS cconv2d_ia ( SAL_cf32 **A, SAL_cf32 **B, SAL_cf32 **C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG );
    extern SAL_STATUS cconv2dx ( SAL_cf32 *A, SAL_i32 tcols_A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 tcols_C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS cconv2d_iax ( SAL_cf32 **A, SAL_cf32 **B, SAL_cf32 **C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS cconvx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS cdotpr ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 N );
    extern SAL_STATUS cdotprd ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 N );
    extern SAL_STATUS cdotprdx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cdotprx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cexpmul ( SAL_f32 *A, SAL_i32 I, SAL_f32 *F, SAL_f32 *P, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *CEXPTAB, SAL_i32 LOG2M, SAL_i32 N );
    extern SAL_STATUS cexpmulx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *F, SAL_f32 *P, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *CEXPTAB, SAL_i32 LOG2M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cexptab ( SAL_cf32 *C, SAL_i32 LOG2M, SAL_i32 FLAG );
    extern SAL_STATUS cexptabx ( SAL_cf32 *C, SAL_i32 LOG2M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS cfft ( SAL_cf32 *C, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cfft2d ( SAL_cf32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 F );
    extern SAL_STATUS cfft2dd ( SAL_cf64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 F );
    extern SAL_STATUS cfft2ddx ( SAL_cf64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cfft2dx ( SAL_cf32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cfftb ( SAL_cf32 *A, SAL_cf32 *C, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cfftb3 ( SAL_cf32 *A, SAL_cf32 *C, SAL_cf32 *W3, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cfftb3x ( SAL_cf32 *A, SAL_cf32 *C, SAL_cf32 *W3, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cfftb5 ( SAL_cf32 *A, SAL_cf32 *C, SAL_cf32 *W5, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cfftb5x ( SAL_cf32 *A, SAL_cf32 *C, SAL_cf32 *W5, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cfftbd ( SAL_cf64 *A, SAL_cf64 *C, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cfftbdx ( SAL_cf64 *A, SAL_cf64 *C, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cfftbx ( SAL_cf32 *A, SAL_cf32 *C, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cfftd ( SAL_cf64 *C, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cfftdx ( SAL_cf64 *C, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cffto ( SAL_cf32 *C, SAL_cf32 *T, SAL_cf32 *D, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cfftod ( SAL_cf64 *C, SAL_cf64 *T, SAL_cf64 *D, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cfftodx ( SAL_cf64 *C, SAL_cf64 *T, SAL_cf64 *D, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cfftox ( SAL_cf32 *C, SAL_cf32 *T, SAL_cf32 *D, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cfftsc ( SAL_cf32 *C, SAL_i32 N );
    extern SAL_STATUS cfftscd ( SAL_cf64 *C, SAL_i32 N );
    extern SAL_STATUS cfftscdx ( SAL_cf64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cfftscx ( SAL_cf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cfftx ( SAL_cf32 *C, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cidotpr ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 N );
    extern SAL_STATUS cidotprd ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 N );
    extern SAL_STATUS cidotprdx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cidotprx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cimul ( SAL_cf32 *A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 NR, SAL_i32 NC, SAL_i32 F );
    extern SAL_STATUS cimuld ( SAL_cf64 *A, SAL_cf64 *B, SAL_cf64 *C, SAL_i32 NR, SAL_i32 NC, SAL_i32 F );
    extern SAL_STATUS cimuldx ( SAL_cf64 *A, SAL_cf64 *B, SAL_cf64 *C, SAL_i32 NR, SAL_i32 NC, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cimulx ( SAL_cf32 *A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 NR, SAL_i32 NC, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS_INT cmat_auto_mul ( SAL_cf32 *pA, SAL_i32 Atcols, SAL_cf32 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_auto_muld ( SAL_cf64 *pA, SAL_i32 Atcols, SAL_cf64 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_auto_muldx ( SAL_cf64 *pA, SAL_i32 Atcols, SAL_cf64 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT cmat_auto_mulx ( SAL_cf32 *pA, SAL_i32 Atcols, SAL_cf32 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT cmat_chol_dec ( SAL_cf32 *A, SAL_i32 Atcols, SAL_cf32 *LDU, SAL_i32 LDUtcols, SAL_i32 n, SAL_f32 *rcond_est, SAL_cf32 *v, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_chol_decx ( SAL_cf32 *A, SAL_i32 Atcols, SAL_cf32 *LDU, SAL_i32 LDUtcols, SAL_i32 n, SAL_f32 *rcond_est, SAL_cf32 *v, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT cmat_chol_sol ( SAL_cf32 *LDU, SAL_i32 LDUtcols, SAL_cf32 *b, SAL_cf32 *w, SAL_i32 n, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_chol_solx ( SAL_cf32 *LDU, SAL_i32 LDUtcols, SAL_cf32 *b, SAL_cf32 *w, SAL_i32 n, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS cmatinv_lu ( SAL_cf32 *C, SAL_cf32 *D, SAL_i32 *IP, SAL_i32 N );
    extern SAL_STATUS cmatinv_lux ( SAL_cf32 *C, SAL_cf32 *D, SAL_i32 *IP, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS_INT cmat_lud_dec ( SAL_cf32 *C, SAL_i32 Ctcols, SAL_i32 *D, SAL_i32 n, SAL_f32 *rcond_est, SAL_cf32 *v, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_lud_decx ( SAL_cf32 *C, SAL_i32 Ctcols, SAL_i32 *D, SAL_i32 n, SAL_f32 *rcond_est, SAL_cf32 *v, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT cmat_lud_sol ( SAL_cf32 *A, SAL_i32 Atcols, SAL_i32 *D, SAL_cf32 *b, SAL_cf32 *w, SAL_i32 n, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_lud_solx ( SAL_cf32 *A, SAL_i32 Atcols, SAL_i32 *D, SAL_cf32 *b, SAL_cf32 *w, SAL_i32 n, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT cmat_mgs_dec ( SAL_cf32 *AT, SAL_i32 ATtcols, SAL_cf32 *R, SAL_i32 Rtcols, SAL_i32 M, SAL_i32 N, SAL_f32 *rcond_est, SAL_cf32 *v, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_mgs_decx ( SAL_cf32 *AT, SAL_i32 ATtcols, SAL_cf32 *R, SAL_i32 Rtcols, SAL_i32 M, SAL_i32 N, SAL_f32 *rcond_est, SAL_cf32 *v, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT cmat_mgs_solr ( SAL_cf32 *R, SAL_i32 Rtcols, SAL_cf32 *b, SAL_cf32 *x, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_mgs_solrhr ( SAL_cf32 *R, SAL_i32 Rtcols, SAL_cf32 *b, SAL_cf32 *x, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_mgs_solrhrx ( SAL_cf32 *R, SAL_i32 Rtcols, SAL_cf32 *b, SAL_cf32 *x, SAL_i32 N, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT cmat_mgs_solrx ( SAL_cf32 *R, SAL_i32 Rtcols, SAL_cf32 *b, SAL_cf32 *x, SAL_i32 N, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT cmat_mul ( SAL_cf32 *pA, SAL_i32 Atcols, SAL_cf32 *pB, SAL_i32 Btcols, SAL_cf32 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_muld ( SAL_cf64 *pA, SAL_i32 Atcols, SAL_cf64 *pB, SAL_i32 Btcols, SAL_cf64 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT cmat_muldx ( SAL_cf64 *pA, SAL_i32 Atcols, SAL_cf64 *pB, SAL_i32 Btcols, SAL_cf64 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT cmat_mulx ( SAL_cf32 *pA, SAL_i32 Atcols, SAL_cf32 *pB, SAL_i32 Btcols, SAL_cf32 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS cmixer ( SAL_cf32 *A, SAL_i32 sA, SAL_f64 *F, SAL_f64 *P, SAL_cf32 *C, SAL_i32 sC, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS cmixerx ( SAL_cf32 *A, SAL_i32 sA, SAL_f64 *F, SAL_f64 *P, SAL_cf32 *C, SAL_i32 sC, SAL_i32 N, SAL_i32 flag, SAL_i32 eflag );
    extern SAL_STATUS cmma ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA );
    extern SAL_STATUS cmmax ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA, SAL_i32 X );
    extern SAL_STATUS cmmov ( SAL_cf32 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_cf32 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len );
    extern SAL_STATUS cmmovd ( SAL_cf64 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_cf64 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len );
    extern SAL_STATUS cmmovdx ( SAL_cf64 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_cf64 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len, SAL_i32 xflag );
    extern SAL_STATUS cmmovx ( SAL_cf32 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_cf32 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len, SAL_i32 xflag );
    extern SAL_STATUS cmms ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA );
    extern SAL_STATUS cmmsx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA, SAL_i32 X );
    extern SAL_STATUS cmmuld ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA );
    extern SAL_STATUS cmmuldx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA, SAL_i32 X );
    extern SAL_STATUS cmsm ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA );
    extern SAL_STATUS cmsmx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA, SAL_i32 X );
    extern SAL_STATUS cmtrans2 ( SAL_cf32 *A, SAL_cf32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C );
    extern SAL_STATUS cmtrans2d ( SAL_cf64 *A, SAL_cf64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C );
    extern SAL_STATUS cmtrans2dx ( SAL_cf64 *A, SAL_cf64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C, SAL_i32 X );
    extern SAL_STATUS cmtrans2x ( SAL_cf32 *A, SAL_cf32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C, SAL_i32 X );
    extern SAL_STATUS coher ( SAL_f32 *A, SAL_f32 *B, SAL_cf32 *C, SAL_f32 *D, SAL_i32 N );
    extern SAL_STATUS coherx ( SAL_f32 *A, SAL_f32 *B, SAL_cf32 *C, SAL_f32 *D, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS conv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M );
    extern SAL_STATUS conv2d ( SAL_f32 *A, SAL_i32 tcols_A, SAL_f32 *B, SAL_f32 *C, SAL_i32 tcols_C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG );
    extern SAL_STATUS conv2d_ia ( SAL_f32 **A, SAL_f32 **B, SAL_f32 **C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG );
    extern SAL_STATUS conv2d_iax ( SAL_f32 **A, SAL_f32 **B, SAL_f32 **C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS conv2dx ( SAL_f32 *A, SAL_i32 tcols_A, SAL_f32 *B, SAL_f32 *C, SAL_i32 tcols_C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS convm_cols ( SAL_f32 **A, SAL_f32 *B, SAL_f32 **C, SAL_i32 Nc, SAL_i32 Nr, SAL_i32 Nb, SAL_i32 F );
    extern SAL_STATUS convm_colsx ( SAL_f32 **A, SAL_f32 *B, SAL_f32 **C, SAL_i32 Nc, SAL_i32 Nr, SAL_i32 Nb, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS convm_rows ( SAL_f32 **A, SAL_f32 *B, SAL_f32 **C, SAL_i32 Nc, SAL_i32 Nr, SAL_i32 Nb, SAL_i32 F );
    extern SAL_STATUS convm_rowsx ( SAL_f32 **A, SAL_f32 *B, SAL_f32 **C, SAL_i32 Nc, SAL_i32 Nr, SAL_i32 Nb, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS convx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS crdesamp ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_cf32 *C, SAL_i32 N, SAL_i32 M );
    extern SAL_STATUS crdesampx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_cf32 *C, SAL_i32 N, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS crdotpr ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 N );
    extern SAL_STATUS crdotprd ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 N );
    extern SAL_STATUS crdotprdx ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS crdotprx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS crmixer ( SAL_f32 *A, SAL_i32 sA, SAL_f64 *F, SAL_f64 *P, SAL_cf32 *C, SAL_i32 sC, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS crmixerx ( SAL_f32 *A, SAL_i32 sA, SAL_f64 *F, SAL_f64 *P, SAL_cf32 *C, SAL_i32 sC, SAL_i32 N, SAL_i32 flag, SAL_i32 eflag );
    extern SAL_STATUS crvadd ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS crvaddx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS crvdiv ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS crvdivx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS crvmul ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS crvmulx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS crvsub ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS crvsubx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cspec ( SAL_cf32 *A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 N );
    extern SAL_STATUS cspecx ( SAL_cf32 *A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS ctoz ( SAL_cf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS ctozd ( SAL_cf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS ctozdx ( SAL_cf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS ctozx ( SAL_cf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvabs ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvabsx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvadd ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvaddd ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvadddx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvaddx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvcma ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS cvcmax ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvcmul ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvcmulx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvcomb ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvcombd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvcombdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvcombx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvconj ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvconjd ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvconjdx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvconjx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvcsml ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvcsmld ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvcsmldx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvcsmlx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvdbcon ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *S, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cvdbconx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *S, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cvdiv ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvdivd ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvdivdx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvdivx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvexp ( SAL_f32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvexpd ( SAL_f64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvexpdx ( SAL_f64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvexpm ( SAL_f32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvexpmx ( SAL_f32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvexpx ( SAL_f32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvfill ( SAL_cf32 *A, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvfillx ( SAL_cf32 *A, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvmags ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvmagsd ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvmagsdx ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvmagsx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvmgsa ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvmgsax ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvmov ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvmovd ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvmovdx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvmovx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvmul ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cvmuld ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS cvmuldx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cvmulx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS cvneg ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvnegd ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvnegdx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvnegx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvphas ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvphasx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvrcip ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvrcipd ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvrcipdx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvrcipx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvsma ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS cvsmad ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_cf64 *C, SAL_i32 K, SAL_cf64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS cvsmadx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_cf64 *C, SAL_i32 K, SAL_cf64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvsmax ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvsplit ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvsplitd ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvsplitdx ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvsplitx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvsqrt ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvsqrtx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvsub ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvsubd ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS cvsubdx ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS cvsubx ( SAL_cf32 *A, SAL_i32 I, SAL_cf32 *B, SAL_i32 J, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS deq22 ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS deq22x ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS desamp ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 N, SAL_i32 M );
    extern SAL_STATUS desampx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 N, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS dotpr ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS dotprd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS dotprdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS dotprx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS f3x3 ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *B, SAL_f32 *C );
    extern SAL_STATUS f3x3d ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *B, SAL_f64 *C );
    extern SAL_STATUS f3x3dx ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *B, SAL_f64 *C, SAL_i32 X );
    extern SAL_STATUS f3x3x ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *B, SAL_f32 *C, SAL_i32 X );
    extern SAL_STATUS f5x5 ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *B, SAL_f32 *C );
    extern SAL_STATUS f5x5d ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *B, SAL_f64 *C );
    extern SAL_STATUS f5x5dx ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *B, SAL_f64 *C, SAL_i32 X );
    extern SAL_STATUS f5x5x ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *B, SAL_f32 *C, SAL_i32 X );
    extern SAL_STATUS fcf_cipt ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_cf32 *T, SAL_f32 *S, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fcf_ciptx ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_cf32 *T, SAL_f32 *S, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcf_ript ( FFT_setup *SETUPP, SAL_f32 *C, SAL_f32 *T, SAL_f32 *S, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fcf_riptx ( FFT_setup *SETUPP, SAL_f32 *C, SAL_f32 *T, SAL_f32 *S, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcf_zipt ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_zf32 *T, SAL_f32 *S, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fcf_ziptx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_zf32 *T, SAL_f32 *S, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcf_zript ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_zf32 *T, SAL_f32 *S, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fcf_zriptx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_zf32 *T, SAL_f32 *S, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcs_cipt ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fcs_ciptx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcsm_cipt ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fcsm_ciptx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcsm_ript ( FFT_setup *SETUPP, SAL_f32 *A, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fcsm_riptx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcsm_zipt ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fcsm_ziptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcsm_zript ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fcsm_zriptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcs_ript ( FFT_setup *SETUPP, SAL_f32 *A, SAL_f32 *C, SAL_i32 K, SAL_f32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fcs_riptx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_f32 *C, SAL_i32 K, SAL_f32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcs_zipt ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fcs_ziptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fcs_zript ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fcs_zriptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );

    extern SAL_STATUS_INT fft1d_setup ( const SAL_fft1d_func FFT, const SAL_i32 LOG2N, const SAL_i32 FLAG, FFT_setup *SETUP );
    extern SAL_STATUS_INT fft1d_setupd ( const SAL_fft1d_funcd FFT, const SAL_i32 LOG2N, const SAL_i32 FLAG, FFT_setupd *SETUP );
    extern SAL_STATUS_INT fft2d_setup ( const SAL_fft2d_func FFT, const SAL_i32 LOG2NC, const SAL_i32 LOG2NR, const SAL_i32 FLAG, FFT_setup *SETUP );
    extern SAL_STATUS_INT fft2d_setupd ( const SAL_fft2d_funcd FFT, const SAL_i32 LOG2NC, const SAL_i32 LOG2NR, const SAL_i32 FLAG, FFT_setupd *SETUP );

    extern SAL_STATUS_INT fft1d_setup_user_alloc ( SAL_fft1d_func FFT, SAL_i32 LOG2N, SAL_i32 FLAG, FFT_setup *SETUP, void *BUFFER );
    extern SAL_STATUS_INT fft1d_setup_user_allocd ( SAL_fft1d_funcd FFT, SAL_i32 LOG2N, SAL_i32 FLAG, FFT_setupd *SETUP, void *BUFFER );
    extern SAL_STATUS_INT fft2d_setup_user_alloc ( SAL_fft2d_func FFT, SAL_i32 LOG2NC, SAL_i32 LOG2NR, SAL_i32 FLAG, FFT_setup *SETUP, void *BUFFER );
    extern SAL_STATUS_INT fft2d_setup_user_allocd ( SAL_fft2d_funcd FFT, SAL_i32 LOG2NC, SAL_i32 LOG2NR, SAL_i32 FLAG, FFT_setupd *SETUP, void *BUFFER );
    extern SAL_STATUS fft2d_cip ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_cipd ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_cipdx ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_cipt ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_ciptd ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_ciptdx ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_ciptx ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_cipx ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_cop ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_copd ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_copdx ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_copt ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_coptd ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_coptdx ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_coptx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_copx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_rip ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_ripd ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_ripdx ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_ript ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_riptd ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_f64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_riptdx ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_f64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_riptx ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_ripx ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_rop ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_ropd ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 IR, SAL_i32 IC, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_ropdx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 IR, SAL_i32 IC, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_ropt ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_roptd ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 IR, SAL_i32 IC, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_f64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_roptdx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 IR, SAL_i32 IC, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_f64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_roptx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_ropx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zipd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zipdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zipt ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_ziptd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_ziptdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_ziptx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zipx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zopd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zopdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zopt ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zoptd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zoptdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zoptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zopx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zrip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zripd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zripdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zript ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zriptd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zriptdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zriptx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zripx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zrop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zropd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zropdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zropt ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zroptd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG );
    extern SAL_STATUS fft2d_zroptdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zroptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft2d_zropx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2NC, SAL_ui32 LOG2NR, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3m_cols_cop ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_cols_copx ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_cols_rop ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_cols_ropx ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_cols_zip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_cols_zipx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_cols_zop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_cols_zopx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_cols_zrip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_cols_zripx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_cols_zrop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_cols_zropx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_cop ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_copx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3m_rop ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_ropx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3m_rows_cop ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_rows_copx ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_rows_rop ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_rows_ropx ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_rows_zip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_rows_zipx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_rows_zop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_rows_zopx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_rows_zrip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_rows_zripx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_rows_zrop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft3m_rows_zropx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_zop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_zopx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3m_zrop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fft3m_zropx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_cop ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_copd ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_copdx ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_copx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_rop ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_ropd ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_ropdx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_ropx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_zip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_zipd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_zipdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_zipx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_zop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_zopd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_zopdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_zopx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_zrip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_zripd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_zripdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_zripx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_zrop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_zropd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft3_zropdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft3_zropx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5m_cols_cop ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_cols_copx ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_cols_rop ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_cols_ropx ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_cols_zip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_cols_zipx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_cols_zop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_cols_zopx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_cols_zrip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_cols_zripx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_cols_zrop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_cols_zropx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_cop ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_copx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5m_rop ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_ropx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5m_rows_cop ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_rows_copx ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_rows_rop ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_rows_ropx ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_rows_zip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_rows_zipx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_rows_zop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_rows_zopx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_rows_zrip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_rows_zripx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_rows_zrop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fft5m_rows_zropx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_zop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_zopx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5m_zrop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fft5m_zropx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_cop ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_copd ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_copdx ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_copx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_rop ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_ropd ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_ropdx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_ropx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_zip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_zipd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_zipdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_zipx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_zop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_zopd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_zopdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_zopx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_zrip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_zripd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_zripdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_zripx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_zrop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_zropd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft5_zropdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft5_zropx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft9_cop ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft9_copx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft9_zop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft9_zopx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_acor ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 M );
    extern SAL_STATUS fft_acord ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 M );
    extern SAL_STATUS fft_acordx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 X );
    extern SAL_STATUS fft_acorx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 X );
    extern SAL_STATUS fft_ccor ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 M );
    extern SAL_STATUS fft_ccord ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 M );
    extern SAL_STATUS fft_ccordx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 X );
    extern SAL_STATUS fft_ccorx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 X );
    extern SAL_STATUS fft_cip ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_cipd ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_cipdx ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_cipt ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_ciptd ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 K, SAL_cf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_ciptdx ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 K, SAL_cf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_ciptx ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_cipx ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_cop ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_copd ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_copdx ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_copt ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_coptd ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_cf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_coptdx ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_cf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_coptx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_copx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_cvmags ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_cvmagsx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_free ( FFT_setup *SETUPP );
    extern SAL_STATUS fft_freed ( FFT_setupd *SETUPP );
    extern SAL_STATUS fftm_cip ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cipd ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cipdx ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_cipt ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_ciptd ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_ciptdx ( FFT_setupd *SETUPP, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_ciptx ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_cipx ( FFT_setup *SETUPP, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_cols_cip ( FFT_setup *SETUP, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_cipd ( FFT_setupd *SETUP, SAL_cf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_cipdx ( FFT_setupd *SETUP, SAL_cf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_cipx ( FFT_setup *SETUP, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_cop ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_copd ( FFT_setupd *SETUP, SAL_cf64 *A, SAL_i32 ATCOLS, SAL_cf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_copdx ( FFT_setupd *SETUP, SAL_cf64 *A, SAL_i32 ATCOLS, SAL_cf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_copx ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_rip ( FFT_setup *SETUP, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_ripd ( FFT_setupd *SETUP, SAL_f64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_ripdx ( FFT_setupd *SETUP, SAL_f64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_ripx ( FFT_setup *SETUP, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_rop ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_ropd ( FFT_setupd *SETUP, SAL_f64 *A, SAL_i32 ATCOLS, SAL_f64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_ropdx ( FFT_setupd *SETUP, SAL_f64 *A, SAL_i32 ATCOLS, SAL_f64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_ropx ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_zip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_zipd ( FFT_setupd *SETUP, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_zipdx ( FFT_setupd *SETUP, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_zipx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_zop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_zopd ( FFT_setupd *SETUP, SAL_zf64 *A, SAL_i32 ATCOLS, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_zopdx ( FFT_setupd *SETUP, SAL_zf64 *A, SAL_i32 ATCOLS, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_zopx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_zrip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_zripd ( FFT_setupd *SETUP, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_zripdx ( FFT_setupd *SETUP, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_zripx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_zrop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_zropd ( FFT_setupd *SETUP, SAL_zf64 *A, SAL_i32 ATCOLS, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_cols_zropdx ( FFT_setupd *SETUP, SAL_zf64 *A, SAL_i32 ATCOLS, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cols_zropx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_cop ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_copd ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_copdx ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_copt ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_coptd ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_coptdx ( FFT_setupd *SETUPP, SAL_cf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_coptx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_cf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_copx ( FFT_setup *SETUPP, SAL_cf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_cf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_rip ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_ripd ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_ripdx ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_ript ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_riptd ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_f64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_riptdx ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_f64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_riptx ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_ripx ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_rop ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_ropd ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 IR, SAL_i32 IC, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_ropdx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 IR, SAL_i32 IC, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_ropt ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_roptd ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 IR, SAL_i32 IC, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_f64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_roptdx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 IR, SAL_i32 IC, SAL_f64 *C, SAL_i32 KR, SAL_i32 KC, SAL_f64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_roptx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_f32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_ropx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 IR, SAL_i32 IC, SAL_f32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_rows_cip ( FFT_setup *SETUP, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_cipd ( FFT_setupd *SETUP, SAL_cf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_cipdx ( FFT_setupd *SETUP, SAL_cf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_cipx ( FFT_setup *SETUP, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_cop ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_copd ( FFT_setupd *SETUP, SAL_cf64 *A, SAL_i32 ATCOLS, SAL_cf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_copdx ( FFT_setupd *SETUP, SAL_cf64 *A, SAL_i32 ATCOLS, SAL_cf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_copx ( FFT_setup *SETUP, SAL_cf32 *A, SAL_i32 ATCOLS, SAL_cf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_rip ( FFT_setup *SETUP, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_ripd ( FFT_setupd *SETUP, SAL_f64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_ripdx ( FFT_setupd *SETUP, SAL_f64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_ripx ( FFT_setup *SETUP, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_rop ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_ropd ( FFT_setupd *SETUP, SAL_f64 *A, SAL_i32 ATCOLS, SAL_f64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_ropdx ( FFT_setupd *SETUP, SAL_f64 *A, SAL_i32 ATCOLS, SAL_f64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_ropx ( FFT_setup *SETUP, SAL_f32 *A, SAL_i32 ATCOLS, SAL_f32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_zip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_zipd ( FFT_setupd *SETUP, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_zipdx ( FFT_setupd *SETUP, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_zipx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_zop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_zopd ( FFT_setupd *SETUP, SAL_zf64 *A, SAL_i32 ATCOLS, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_zopdx ( FFT_setupd *SETUP, SAL_zf64 *A, SAL_i32 ATCOLS, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_zopx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_zrip ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_zripd ( FFT_setupd *SETUP, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_zripdx ( FFT_setupd *SETUP, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_zripx ( FFT_setup *SETUP, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_zrop ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_zropd ( FFT_setupd *SETUP, SAL_zf64 *A, SAL_i32 ATCOLS, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG );
    extern SAL_STATUS fftm_rows_zropdx ( FFT_setupd *SETUP, SAL_zf64 *A, SAL_i32 ATCOLS, SAL_zf64 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_rows_zropx ( FFT_setup *SETUP, SAL_zf32 *A, SAL_i32 ATCOLS, SAL_zf32 *C, SAL_i32 CTCOLS, SAL_i32 LOG2N, SAL_i32 NFFTS, SAL_i32 FI_FLAG, SAL_i32 FLAG );
    extern SAL_STATUS fftm_small ( SAL_zf32 *in_matrix, SAL_i32 in_stride, SAL_zf32 *out_matrix, SAL_i32 out_stride, SAL_ui32 fft_size, SAL_ui32 nffts, SAL_i32 fi_flag, SAL_i32 X );
    extern SAL_STATUS fftm_zip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zipd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zipdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zipt ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_ziptd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_ziptdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_ziptx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zipx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zopd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zopdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zopt ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zoptd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zoptdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zoptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zopx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zrip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zripd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zripdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zript ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zriptd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zriptdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zriptx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zripx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zrop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zropd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zropdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zropt ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zroptd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG );
    extern SAL_STATUS fftm_zroptdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf64 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zroptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fftm_zropx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 IR, SAL_i32 IC, SAL_zf32 *C, SAL_i32 KR, SAL_i32 KC, SAL_ui32 LOG2N, SAL_ui32 M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_rip ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_ripd ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_ripdx ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_ript ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 K, SAL_f32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_riptd ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 K, SAL_f64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_riptdx ( FFT_setupd *SETUPP, SAL_f64 *C, SAL_i32 K, SAL_f64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_riptx ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 K, SAL_f32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_ripx ( FFT_setup *SETUPP, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_rop ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_ropd ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_ropdx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_ropt ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_roptd ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_f64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_roptdx ( FFT_setupd *SETUPP, SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_f64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_roptx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_ropx ( FFT_setup *SETUPP, SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_setup ( SAL_ui32 LOG2M, SAL_i32 FLAG, FFT_setup *SETUPP, SAL_ui32 *NBYTESP );
    extern SAL_STATUS fft_setupd ( SAL_ui32 LOG2M, SAL_i32 FLAG, FFT_setupd *SETUPP, SAL_ui32 *NBYTESP );

    extern SAL_STATUS_INT fft1d_setup_create ( const SAL_fft1d_func fft_type, const SAL_i32 log2m, const SAL_i32 opt_flag, FFT_setup *p_setup );
    extern SAL_STATUS_INT fft1d_setup_init ( FFT_setup *p_setup, const SAL_i32 opt_flag );
    extern SAL_STATUS_INT fft2d_setup_create ( const SAL_fft2d_func fft_type, const SAL_i32 log2m, const SAL_i32 log2n, const SAL_i32 opt_flag, FFT_setup *p_setup );
    extern SAL_STATUS_INT fft2d_setup_init ( FFT_setup *p_setup, const SAL_i32 opt_flag );
    extern SAL_STATUS_INT fft_setup_set_buffer ( FFT_setup *p_setup, void *buffer, const SAL_i32 nbytes, const SAL_i32 flag );
    extern SAL_STATUS_INT fft_setup_get_n_bytes ( FFT_setup *p_setup, SAL_i32 *p_nbytes, SAL_i32 flag );
    extern SAL_STATUS_INT fft_setup_get_temp_n_bytes ( FFT_setup *p_setup, SAL_i32 *p_nbytes, SAL_i32 flag );

    extern SAL_STATUS_INT fft1d_setupd_create ( const SAL_fft1d_funcd fft_type, const SAL_i32 log2m, const SAL_i32 opt_flag, FFT_setupd *p_setup );
    extern SAL_STATUS_INT fft1d_setupd_init ( FFT_setupd *p_setup, const SAL_i32 opt_flag );
    extern SAL_STATUS_INT fft2d_setupd_create ( const SAL_fft2d_funcd fft_type, const SAL_i32 log2m, const SAL_i32 log2n, const SAL_i32 opt_flag, FFT_setupd *p_setup );
    extern SAL_STATUS_INT fft2d_setupd_init ( FFT_setupd *p_setup, const SAL_i32 opt_flag );
    extern SAL_STATUS_INT fft_setupd_set_buffer ( FFT_setupd *p_setup, void *buffer, const SAL_i32 nbytes, const SAL_i32 flag );
    extern SAL_STATUS_INT fft_setupd_get_n_bytes ( FFT_setupd *p_setup, SAL_i32 *p_nbytes, SAL_i32 flag );
    extern SAL_STATUS_INT fft_setupd_get_temp_n_bytes ( FFT_setupd *p_setup, SAL_i32 *p_nbytes, SAL_i32 flag );

    extern SAL_STATUS_INT fft_setup_fixup ( FFT_setup *SETUPP );
    extern SAL_STATUS_INT fft_setup_fixupd ( FFT_setupd *SETUPP );
    extern SAL_STATUS_INT fft_setup_get_temp_buffer_size ( FFT_setup *SETUPP, SAL_i32 *nbytes );
    extern SAL_STATUS_INT fft_setup_get_temp_buffer_sized ( FFT_setupd *SETUPP, SAL_i32 *nbytes );
    extern SAL_STATUS_INT fft_setup_set_temp_buffer ( FFT_setup *SETUPP, void *buffer );
    extern SAL_STATUS_INT fft_setup_set_temp_bufferd ( FFT_setupd *SETUPP, void *buffer );
    extern SAL_STATUS fft_setup_user_alloc ( SAL_ui32 LOG2M, SAL_i32 FLAG, FFT_setup *SETUPP, void *BUFFER );
    extern SAL_STATUS fft_setup_user_allocd ( SAL_ui32 LOG2M, SAL_i32 FLAG, FFT_setupd *SETUPP, void *BUFFER );
    extern SAL_STATUS fftwts3 ( SAL_cf32 *C, SAL_i32 M );
    extern SAL_STATUS fftwts3x ( SAL_cf32 *C, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS fftwts5 ( SAL_cf32 *C, SAL_i32 M );
    extern SAL_STATUS fftwts5x ( SAL_cf32 *C, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS fft_zip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zipd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zipdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zipt ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_ziptd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_ziptdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_ziptx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zipx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zopd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zopdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zopt ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zoptd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zoptdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zoptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zopx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zrip ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zripd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zripdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zript ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zriptd ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zriptdx ( FFT_setupd *SETUPP, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zriptx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zripx ( FFT_setup *SETUPP, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zrop ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zropd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zropdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zropt ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zroptd ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zroptdx ( FFT_setupd *SETUPP, SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zroptx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *T, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zropx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fft_zvmags ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG );
    extern SAL_STATUS fft_zvmagsx ( FFT_setup *SETUPP, SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS fir2 ( SAL_f32 *A, SAL_f32 *W, SAL_f32 *PSUM, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 SFLAG );
    extern SAL_STATUS fir2x ( SAL_f32 *A, SAL_f32 *W, SAL_f32 *PSUM, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 SFLAG, SAL_i32 X );
    extern SAL_STATUS fir3 ( SAL_f32 *A, SAL_f32 *W, SAL_f32 *PSUM, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 SFLAG );
    extern SAL_STATUS fir3x ( SAL_f32 *A, SAL_f32 *W, SAL_f32 *PSUM, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 SFLAG, SAL_i32 X );
    extern SAL_STATUS fixpixad ( SAL_f64 *A, SAL_i32 I, SAL_ui8 *C, SAL_i32 N );
    extern SAL_STATUS fixpixadx ( SAL_f64 *A, SAL_i32 I, SAL_ui8 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS fixpixb ( SAL_f32 *A, SAL_i32 I, SAL_ui8 *C, SAL_i32 N );
    extern SAL_STATUS fixpixbd ( SAL_f64 *A, SAL_i32 I, SAL_ui8 *C, SAL_i32 N );
    extern SAL_STATUS fixpixbdx ( SAL_f64 *A, SAL_i32 I, SAL_ui8 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS fixpixbx ( SAL_f32 *A, SAL_i32 I, SAL_ui8 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS flnz ( SAL_f32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 *C, SAL_i32 N );
    extern SAL_STATUS flnzx ( SAL_f32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS fltpixad ( SAL_ui8 *A, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS fltpixadx ( SAL_ui8 *A, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS fltpixb ( SAL_ui8 *A, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS fltpixbd ( SAL_ui8 *A, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS fltpixbdx ( SAL_ui8 *A, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS fltpixbx ( SAL_ui8 *A, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS *get_salcache ( void );
    extern SAL_STATUS hamm_window ( SAL_f32 *C, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS hamm_windowd ( SAL_f64 *C, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS hamm_windowdx ( SAL_f64 *C, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS hamm_windowx ( SAL_f32 *C, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS hann_window ( SAL_f32 *C, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS hann_windowd ( SAL_f64 *C, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS hann_windowdx ( SAL_f64 *C, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS hann_windowx ( SAL_f32 *C, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS hist ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 NB, SAL_f32 *MAX, SAL_f32 *MIN );
    extern SAL_STATUS histd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 NB, SAL_f64 *MAX, SAL_f64 *MIN );
    extern SAL_STATUS histdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 NB, SAL_f64 *MAX, SAL_f64 *MIN, SAL_i32 X );
    extern SAL_STATUS histx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 NB, SAL_f32 *MAX, SAL_f32 *MIN, SAL_i32 X );
    extern SAL_STATUS ihist ( SAL_ui16 *A, SAL_i32 I, SAL_i8 *C, SAL_i32 N );
    extern SAL_STATUS ihist32 ( SAL_ui16 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 N );
    extern SAL_STATUS ihist32x ( SAL_ui16 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS ihistx ( SAL_ui16 *A, SAL_i32 I, SAL_i8 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS imgfir ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *B, SAL_f32 *C, SAL_i32 M, SAL_i32 N );
    extern SAL_STATUS imgfird ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *B, SAL_f64 *C, SAL_i32 M, SAL_i32 N );
    extern SAL_STATUS imgfirdx ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *B, SAL_f64 *C, SAL_i32 M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS imgfirx ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *B, SAL_f32 *C, SAL_i32 M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lveq ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lveqd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lveqdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lveqi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lveqix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lveqx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvge ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvged ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvgedx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvgei ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvgeix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvgex ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvgt ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvgtd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvgtdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvgti ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvgtix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvgtx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvle ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvled ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvledx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvlei ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvleix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvlex ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvlt ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvltd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvltdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvlti ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvltix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvltx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvne ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvned ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvnedx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvnei ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvneix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvnex ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvnot ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvnotd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvnotdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvnoti ( SAL_i32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS lvnotix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS lvnotx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS_INT mat_auto_mul ( SAL_f32 *pA, SAL_i32 Atcols, SAL_f32 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT mat_auto_muld ( SAL_f64 *pA, SAL_i32 Atcols, SAL_f64 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT mat_auto_muldx ( SAL_f64 *pA, SAL_i32 Atcols, SAL_f64 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT mat_auto_mulx ( SAL_f32 *pA, SAL_i32 Atcols, SAL_f32 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT mat_chol_dec ( SAL_f32 *A, SAL_i32 Atcols, SAL_f32 *LDU, SAL_i32 LDUtcols, SAL_i32 n, SAL_f32 *rcond_est, SAL_f32 *v, SAL_i32 flag );
    extern SAL_STATUS_INT mat_chol_decx ( SAL_f32 *A, SAL_i32 Atcols, SAL_f32 *LDU, SAL_i32 LDUtcols, SAL_i32 n, SAL_f32 *rcond_est, SAL_f32 *v, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT mat_chol_sol ( SAL_f32 *LDU, SAL_i32 LDUtcols, SAL_f32 *b, SAL_f32 *w, SAL_i32 n, SAL_i32 flag );
    extern SAL_STATUS_INT mat_chol_solx ( SAL_f32 *LDU, SAL_i32 LDUtcols, SAL_f32 *b, SAL_f32 *w, SAL_i32 n, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS matinv_lu ( SAL_f32 *C, SAL_f32 *D, SAL_i32 *IP, SAL_i32 N );
    extern SAL_STATUS matinv_lux ( SAL_f32 *C, SAL_f32 *D, SAL_i32 *IP, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS_INT mat_lud_dec ( SAL_f32 *C, SAL_i32 Ctcols, SAL_i32 *D, SAL_i32 n, SAL_f32 *rcond_est, SAL_f32 *v, SAL_i32 flag );
    extern SAL_STATUS_INT mat_lud_decx ( SAL_f32 *C, SAL_i32 Ctcols, SAL_i32 *D, SAL_i32 n, SAL_f32 *rcond_est, SAL_f32 *v, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT mat_lud_sol ( SAL_f32 *A, SAL_i32 Atcols, SAL_i32 *D, SAL_f32 *b, SAL_f32 *w, SAL_i32 n, SAL_i32 flag );
    extern SAL_STATUS_INT mat_lud_solx ( SAL_f32 *A, SAL_i32 Atcols, SAL_i32 *D, SAL_f32 *b, SAL_f32 *w, SAL_i32 n, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT mat_mgs_dec ( SAL_f32 *AT, SAL_i32 ATtcols, SAL_f32 *R, SAL_i32 Rtcols, SAL_i32 M, SAL_i32 N, SAL_f32 *rcond_est, SAL_f32 *v, SAL_i32 flag );
    extern SAL_STATUS_INT mat_mgs_decx ( SAL_f32 *AT, SAL_i32 ATtcols, SAL_f32 *R, SAL_i32 Rtcols, SAL_i32 M, SAL_i32 N, SAL_f32 *rcond_est, SAL_f32 *v, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT mat_mgs_solr ( SAL_f32 *R, SAL_i32 Rtcols, SAL_f32 *b, SAL_f32 *x, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT mat_mgs_solrhr ( SAL_f32 *R, SAL_i32 Rtcols, SAL_f32 *b, SAL_f32 *x, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT mat_mgs_solrhrx ( SAL_f32 *R, SAL_i32 Rtcols, SAL_f32 *b, SAL_f32 *x, SAL_i32 N, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT mat_mgs_solrx ( SAL_f32 *R, SAL_i32 Rtcols, SAL_f32 *b, SAL_f32 *x, SAL_i32 N, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT mat_mul ( SAL_f32 *pA, SAL_i32 Atcols, SAL_f32 *pB, SAL_i32 Btcols, SAL_f32 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT mat_muld ( SAL_f64 *pA, SAL_i32 Atcols, SAL_f64 *pB, SAL_i32 Btcols, SAL_f64 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT mat_muldx ( SAL_f64 *pA, SAL_i32 Atcols, SAL_f64 *pB, SAL_i32 Btcols, SAL_f64 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT mat_mulx ( SAL_f32 *pA, SAL_i32 Atcols, SAL_f32 *pB, SAL_i32 Btcols, SAL_f32 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS maxmgv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS maxmgvd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS maxmgvdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS maxmgvi ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 *IC, SAL_i32 N );
    extern SAL_STATUS maxmgvix ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 *IC, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS maxmgvx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS maxv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS maxvd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS maxvdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS maxvi ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 *IC, SAL_i32 N );
    extern SAL_STATUS maxvid ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 *IC, SAL_i32 N );
    extern SAL_STATUS maxvidx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 *IC, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS maxvix ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 *IC, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS maxvx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS meamgv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS meamgvd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS meamgvdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS meamgvx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS meanv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS meanvd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS meanvdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS meanvx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS measqv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS measqvd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS measqvdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS measqvx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS medf ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 P );
    extern SAL_STATUS medf3x3 ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *C );
    extern SAL_STATUS medf3x3d ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *C );
    extern SAL_STATUS medf3x3dx ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *C, SAL_i32 X );
    extern SAL_STATUS medf3x3x ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *C, SAL_i32 X );
    extern SAL_STATUS medf5x5 ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *C );
    extern SAL_STATUS medf5x5d ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *C );
    extern SAL_STATUS medf5x5dx ( SAL_f64 *A, SAL_i32 NR, SAL_i32 NC, SAL_f64 *C, SAL_i32 X );
    extern SAL_STATUS medf5x5x ( SAL_f32 *A, SAL_i32 NR, SAL_i32 NC, SAL_f32 *C, SAL_i32 X );
    extern SAL_STATUS medfd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 P );
    extern SAL_STATUS medfdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 P, SAL_i32 X );
    extern SAL_STATUS medfx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 P, SAL_i32 X );
    extern SAL_STATUS minmgv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS minmgvd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS minmgvdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS minmgvi ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 *IC, SAL_i32 N );
    extern SAL_STATUS minmgvix ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 *IC, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS minmgvx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS minv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS minvd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS minvdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS minvi ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 *IC, SAL_i32 N );
    extern SAL_STATUS minvid ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 *IC, SAL_i32 N );
    extern SAL_STATUS minvidx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 *IC, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS minvix ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 *IC, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS minvx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS mmov ( SAL_f32 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_f32 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len );
    extern SAL_STATUS mmovd ( SAL_f64 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_f64 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len );
    extern SAL_STATUS mmovdx ( SAL_f64 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_f64 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len, SAL_i32 xflag );
    extern SAL_STATUS mmovx ( SAL_f32 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_f32 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len, SAL_i32 xflag );
    extern SAL_STATUS mmuld ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA );
    extern SAL_STATUS mmuldx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA, SAL_i32 X );
    extern SAL_STATUS mtrans2 ( SAL_f32 *A, SAL_f32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C );
    extern SAL_STATUS mtrans2d ( SAL_f64 *A, SAL_f64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C );
    extern SAL_STATUS mtrans2dx ( SAL_f64 *A, SAL_f64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C, SAL_i32 X );
    extern SAL_STATUS mtrans2x ( SAL_f32 *A, SAL_f32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C, SAL_i32 X );
    extern SAL_STATUS mvessq ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS mvessqx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS nzcros ( SAL_f32 *A, SAL_i32 I, SAL_i32 B, SAL_i32 *C, SAL_i32 *D, SAL_i32 N );
    extern SAL_STATUS nzcrosx ( SAL_f32 *A, SAL_i32 I, SAL_i32 B, SAL_i32 *C, SAL_i32 *D, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS polar ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS polard ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS polardx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS polarx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern void print_csal_version ( SAL_i32 x );
    extern void print_sal_version ( SAL_i32 x );
    extern SAL_STATUS rect ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS rectd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS rectdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS rectx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS_INT resamp_cicx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_cf32 *input, SAL_cf32 *output, SAL_i32 input_len, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_cocx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_cf32 *input, SAL_cf32 *output, SAL_i32 output_len, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_filter_close ( SAL_resamp_filter filter_handle, SAL_i32 flag_word );
    extern SAL_STATUS_INT resamp_filter_create ( SAL_f32 *filter_setp, SAL_i32 filter_len, SAL_i32 num_filters, SAL_resamp_name resamp_name, SAL_i32 flag_word, SAL_resamp_filter *filter_handlep, SAL_i32 *num_bytesp );
    extern SAL_STATUS_INT resamp_filter_create_user_alloc ( SAL_f32 *filter_setp, SAL_i32 filter_len, SAL_i32 num_filters, SAL_resamp_name resamp_name, SAL_i32 flag_word, SAL_resamp_filter *filter_handlep, void *bufferp );
    extern SAL_STATUS_INT resamp_make_filter_set ( SAL_f64 ( *filter_func ) ( SAL_f64 ) , SAL_f32 *filter_setp, SAL_i32 filter_len, SAL_i32 num_filters );
    extern SAL_STATUS_INT resamp_map_close ( SAL_resamp_map map_handle, SAL_i32 flag_word );
    extern SAL_STATUS_INT resamp_map_create ( SAL_resamp_filter filter_handle, SAL_f32 *map_setp, SAL_i32 map_len, SAL_i32 num_maps, SAL_i32 signal_len, SAL_i32 flag_word, SAL_resamp_map *map_handlep, SAL_i32 *num_bytesp );
    extern SAL_STATUS_INT resamp_map_create_user_alloc ( SAL_resamp_filter filter_handle, SAL_f32 *map_setp, SAL_i32 map_len, SAL_i32 num_maps, SAL_i32 signal_len, SAL_i32 flag_word, SAL_resamp_map *map_handlep, void *bufferp );
    extern SAL_STATUS_INT resamp_mc_cicx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_cf32 *input, SAL_i32 input_tcols, SAL_cf32 *output, SAL_i32 output_tcols, SAL_i32 input_len, SAL_i32 num_columns, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mc_cocx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_cf32 *input, SAL_i32 input_tcols, SAL_cf32 *output, SAL_i32 output_tcols, SAL_i32 output_len, SAL_i32 num_columns, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mc_ricx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_f32 *input, SAL_i32 input_tcols, SAL_f32 *output, SAL_i32 output_tcols, SAL_i32 input_len, SAL_i32 num_columns, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mc_rocx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_f32 *input, SAL_i32 input_tcols, SAL_f32 *output, SAL_i32 output_tcols, SAL_i32 output_len, SAL_i32 num_columns, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mc_zicx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_zf32 *input, SAL_i32 input_tcols, SAL_zf32 *output, SAL_i32 output_tcols, SAL_i32 input_len, SAL_i32 num_columns, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mc_zocx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_zf32 *input, SAL_i32 input_tcols, SAL_zf32 *output, SAL_i32 output_tcols, SAL_i32 output_len, SAL_i32 num_columns, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mr_cicx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_cf32 *input, SAL_i32 input_tcols, SAL_cf32 *output, SAL_i32 output_tcols, SAL_i32 input_len, SAL_i32 num_rows, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mr_cocx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_cf32 *input, SAL_i32 input_tcols, SAL_cf32 *output, SAL_i32 output_tcols, SAL_i32 output_len, SAL_i32 num_rows, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mr_ricx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_f32 *input, SAL_i32 input_tcols, SAL_f32 *output, SAL_i32 output_tcols, SAL_i32 input_len, SAL_i32 num_rows, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mr_rocx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_f32 *input, SAL_i32 input_tcols, SAL_f32 *output, SAL_i32 output_tcols, SAL_i32 output_len, SAL_i32 num_rows, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mr_zicx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_zf32 *input, SAL_i32 input_tcols, SAL_zf32 *output, SAL_i32 output_tcols, SAL_i32 input_len, SAL_i32 num_rows, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_mr_zocx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_zf32 *input, SAL_i32 input_tcols, SAL_zf32 *output, SAL_i32 output_tcols, SAL_i32 output_len, SAL_i32 num_rows, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_ricx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_f32 *input, SAL_f32 *output, SAL_i32 input_len, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_rocx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_f32 *input, SAL_f32 *output, SAL_i32 output_len, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_zicx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_zf32 *input, SAL_zf32 *output, SAL_i32 input_len, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS_INT resamp_zocx ( SAL_resamp_map map_handle, SAL_i32 map, SAL_i32 map_start_pos, SAL_zf32 *input, SAL_zf32 *output, SAL_i32 output_len, SAL_i32 flag_word, SAL_i32 xflag );
    extern SAL_STATUS rfft ( SAL_f32 *C, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS rfft2d ( SAL_f32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 F );
    extern SAL_STATUS rfft2dd ( SAL_f64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 F );
    extern SAL_STATUS rfft2ddx ( SAL_f64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS rfft2dx ( SAL_f32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS rfftb ( SAL_f32 *C, SAL_f32 *D, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS rfftbd ( SAL_f64 *C, SAL_f64 *D, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS rfftbdx ( SAL_f64 *C, SAL_f64 *D, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS rfftbx ( SAL_f32 *C, SAL_f32 *D, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS rfftd ( SAL_f64 *C, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS rfftdx ( SAL_f64 *C, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS rffto ( SAL_f32 *C, SAL_f32 *T, SAL_f32 *D, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS rfftod ( SAL_f64 *C, SAL_f64 *T, SAL_f64 *D, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS rfftodx ( SAL_f64 *C, SAL_f64 *T, SAL_f64 *D, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS rfftox ( SAL_f32 *C, SAL_f32 *T, SAL_f32 *D, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS rfftsc ( SAL_f32 *C, SAL_i32 N, SAL_i32 F, SAL_i32 G );
    extern SAL_STATUS rfftscd ( SAL_f64 *C, SAL_i32 N, SAL_i32 F, SAL_i32 G );
    extern SAL_STATUS rfftscdx ( SAL_f64 *C, SAL_i32 N, SAL_i32 F, SAL_i32 G, SAL_i32 X );
    extern SAL_STATUS rfftscx ( SAL_f32 *C, SAL_i32 N, SAL_i32 F, SAL_i32 G, SAL_i32 X );
    extern SAL_STATUS rfftx ( SAL_f32 *C, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS rmsqv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS rmsqvd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS rmsqvdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS rmsqvx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS_INT sal_create ( SAL_handle *sal_handle );
    extern SAL_STATUS_INT sal_init ( SAL_handle sal_handle );
    extern SAL_STATUS_INT sal_destroy ( SAL_handle sal_handle );
    extern SAL_STATUS_INT sal_print_info ( SAL_handle sal_handle, const SAL_char *msg, FILE *file_ptr, const SAL_i32 flag );
    extern SAL_STATUS_INT sal_set_worker_wait_behavior ( SAL_handle sal_handle, SAL_i32 flag );
    extern SAL_STATUS_INT sal_get_worker_wait_behavior ( SAL_handle sal_handle, SAL_i32 *p_flag );
    extern SAL_STATUS_INT sal_set_n_threads ( SAL_handle sal_handle, const SAL_i32 n_threads );
    extern SAL_STATUS_INT sal_get_n_threads ( SAL_handle sal_handle, SAL_i32 *p_n_threads );
    extern SAL_STATUS_INT sal_get_n_threads_used ( SAL_handle sal_handle, SAL_i32 *p_n_threads_used );
    extern SAL_STATUS_INT sal_get_n_workers_used ( SAL_handle sal_handle, SAL_i32 *p_n_workers_used );
    extern SAL_STATUS sal_74xx_set_nonjava ( void );
    extern SAL_i32 sal_get_path ( SAL_i32 flag );
    extern void sal_java_mode_disable ( void );
    extern void sal_java_mode_enable ( void );
    extern SAL_STATUS set_salcache ( void *A );
    extern SAL_STATUS spin ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 INC, SAL_i32 INR, SAL_i32 ONC, SAL_i32 ONR, SAL_i32 FLG, SAL_f32 *BKG );
    extern SAL_STATUS spind ( SAL_f64 *A, SAL_f64 *B, SAL_f64 *C, SAL_i32 INC, SAL_i32 INR, SAL_i32 ONC, SAL_i32 ONR, SAL_i32 FLG, SAL_f64 *BKG );
    extern SAL_STATUS spindx ( SAL_f64 *A, SAL_f64 *B, SAL_f64 *C, SAL_i32 INC, SAL_i32 INR, SAL_i32 ONC, SAL_i32 ONR, SAL_i32 FLG, SAL_f64 *BKG, SAL_i32 X );
    extern SAL_STATUS spinx ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 INC, SAL_i32 INR, SAL_i32 ONC, SAL_i32 ONR, SAL_i32 FLG, SAL_f32 *BKG, SAL_i32 X );
    extern SAL_STATUS svdiv ( SAL_f32 *A, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS svdivx ( SAL_f32 *A, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS svdivx_fast ( SAL_f32 *A, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS sve ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS sved ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS svedx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS svemg ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS svemgd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS svemgdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS svemgx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS svesq ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS svesqd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS svesqdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS svesqx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS svex ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS svs ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS svsd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS svsdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS svsx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS tconvl ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 M, SAL_i32 N, SAL_i32 P, SAL_i32 Q );
    extern SAL_STATUS tconvlx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 M, SAL_i32 N, SAL_i32 P, SAL_i32 Q, SAL_i32 X );
    extern SAL_STATUS trans ( SAL_f32 *A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 N );
    extern SAL_STATUS transx ( SAL_f32 *A, SAL_cf32 *B, SAL_cf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS unwrap_phase ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_unwrap_phase_state *P, SAL_i32 F );
    extern SAL_STATUS unwrap_phasex ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_unwrap_phase_state *P, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS vaam ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N );
    extern SAL_STATUS vaamx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vabmrg ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 F, SAL_i32 N, SAL_i32 P, SAL_i32 Q );
    extern SAL_STATUS vabmrgx ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 F, SAL_i32 N, SAL_i32 P, SAL_i32 Q, SAL_i32 X );
    extern SAL_STATUS vabs ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vabsd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vabsdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vabsi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vabsix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vabsx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vadd ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vaddd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vadddx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vaddi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vaddix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vaddx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vaint ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vaintx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS valog ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS valogd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS valogdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS valogx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vam ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vamd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vamdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vamerg ( SAL_f32 *A, SAL_i32 I, SAL_i32 M, SAL_f32 *B, SAL_i32 J, SAL_i32 N, SAL_f32 *C, SAL_i32 K );
    extern SAL_STATUS vamergx ( SAL_f32 *A, SAL_i32 I, SAL_i32 M, SAL_f32 *B, SAL_i32 J, SAL_i32 N, SAL_f32 *C, SAL_i32 K, SAL_i32 X );
    extern SAL_STATUS vamx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vandi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vandix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vasbm ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N );
    extern SAL_STATUS vasbmx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vasm ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vasmx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vatan ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vatan2 ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vatan2d ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vatan2dx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vatan2x ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vatand ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vatandx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vatanx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vavexp ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vavexpx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vavlin ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vavlinx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vcache ( void );
    extern SAL_STATUS vclip ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vclipc ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 *NLOW, SAL_i32 *NHI );
    extern SAL_STATUS vclipcx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 *NLOW, SAL_i32 *NHI, SAL_i32 X );
    extern SAL_STATUS vclipd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vclipdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vclipx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vclr ( SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vclrd ( SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vclrdx ( SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vclrx ( SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vcmerg ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vcmergx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vcmprs ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vcmprsx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vconvert_cs16_zf32 ( SAL_ci16 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_cs16_zf32x ( SAL_ci16 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_cs32_zf32 ( SAL_ci32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_cs32_zf32x ( SAL_ci32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_cs8_zf32 ( SAL_ci8 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_cs8_zf32x ( SAL_ci8 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_cu16_zf32 ( SAL_cui16 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_cu16_zf32x ( SAL_cui16 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_cu32_zf32 ( SAL_cui32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_cu32_zf32x ( SAL_cui32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_cu8_zf32 ( SAL_cui8 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_cu8_zf32x ( SAL_cui8 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_endian2 ( SAL_ui8 *p_src, SAL_i32 stride_src, SAL_ui8 *p_dst, SAL_i32 stride_dst, SAL_i32 n_elems );
    extern SAL_STATUS vconvert_endian2x ( SAL_ui8 *p_src, SAL_i32 stride_src, SAL_ui8 *p_dst, SAL_i32 stride_dst, SAL_i32 n_elems, SAL_i32 xflag );
    extern SAL_STATUS vconvert_endian4 ( SAL_ui8 *p_src, SAL_i32 stride_src, SAL_ui8 *p_dst, SAL_i32 stride_dst, SAL_i32 n_elems );
    extern SAL_STATUS vconvert_endian4x ( SAL_ui8 *p_src, SAL_i32 stride_src, SAL_ui8 *p_dst, SAL_i32 stride_dst, SAL_i32 n_elems, SAL_i32 xflag );
    extern SAL_STATUS vconvert_endian8 ( SAL_ui8 *p_src, SAL_i32 stride_src, SAL_ui8 *p_dst, SAL_i32 stride_dst, SAL_i32 n_elems );
    extern SAL_STATUS vconvert_endian8x ( SAL_ui8 *p_src, SAL_i32 stride_src, SAL_ui8 *p_dst, SAL_i32 stride_dst, SAL_i32 n_elems, SAL_i32 xflag );
    extern SAL_STATUS vconvert_f32_s16 ( SAL_f32 *A, SAL_i32 I, SAL_i16 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_f32_s16x ( SAL_f32 *A, SAL_i32 I, SAL_i16 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_f32_s32 ( SAL_f32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_f32_s32x ( SAL_f32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_f32_s8 ( SAL_f32 *A, SAL_i32 I, SAL_i8 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_f32_s8x ( SAL_f32 *A, SAL_i32 I, SAL_i8 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_f32_u16 ( SAL_f32 *A, SAL_i32 I, SAL_ui16 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_f32_u16x ( SAL_f32 *A, SAL_i32 I, SAL_ui16 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_f32_u32 ( SAL_f32 *A, SAL_i32 I, SAL_ui32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_f32_u32x ( SAL_f32 *A, SAL_i32 I, SAL_ui32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_f32_u8 ( SAL_f32 *A, SAL_i32 I, SAL_ui8 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_f32_u8x ( SAL_f32 *A, SAL_i32 I, SAL_ui8 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_s16_f32 ( SAL_i16 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_s16_f32x ( SAL_i16 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_s32_f32 ( SAL_i32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_s32_f32x ( SAL_i32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_s8_f32 ( SAL_i8 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_s8_f32x ( SAL_i8 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_u16_f32 ( SAL_ui16 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_u16_f32x ( SAL_ui16 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_u32_f32 ( SAL_ui32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_u32_f32x ( SAL_ui32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_u8_f32 ( SAL_ui8 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_u8_f32x ( SAL_ui8 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_zf32_cs16 ( SAL_zf32 *A, SAL_i32 I, SAL_ci16 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_zf32_cs16x ( SAL_zf32 *A, SAL_i32 I, SAL_ci16 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_zf32_cs32 ( SAL_zf32 *A, SAL_i32 I, SAL_ci32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_zf32_cs32x ( SAL_zf32 *A, SAL_i32 I, SAL_ci32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_zf32_cs8 ( SAL_zf32 *A, SAL_i32 I, SAL_ci8 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_zf32_cs8x ( SAL_zf32 *A, SAL_i32 I, SAL_ci8 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_zf32_cu16 ( SAL_zf32 *A, SAL_i32 I, SAL_cui16 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_zf32_cu16x ( SAL_zf32 *A, SAL_i32 I, SAL_cui16 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_zf32_cu32 ( SAL_zf32 *A, SAL_i32 I, SAL_cui32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_zf32_cu32x ( SAL_zf32 *A, SAL_i32 I, SAL_cui32 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vconvert_zf32_cu8 ( SAL_zf32 *A, SAL_i32 I, SAL_cui8 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG );
    extern SAL_STATUS vconvert_zf32_cu8x ( SAL_zf32 *A, SAL_i32 I, SAL_cui8 *C, SAL_i32 K, SAL_f32 *SCALE, SAL_f32 *BIAS, SAL_i32 N, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS vcos ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vcosd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vcosdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vcosx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vdbcon ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS vdbconx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS vdist ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vdistd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vdistdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vdistx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vdiv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vdivd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vdivdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vdivi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vdivix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vdivx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vdivz ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vdivzx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vdpsp ( SAL_f64 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vdpspx ( SAL_f64 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS venvlp ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS venvlpd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS venvlpdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS venvlpx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS veqvi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS veqvix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vexp ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vexpd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vexpdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vexpx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfill ( SAL_f32 *A, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfilld ( SAL_f64 *A, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfilldx ( SAL_f64 *A, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfilli ( SAL_i32 *A, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfillix ( SAL_i32 *A, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfillx ( SAL_f32 *A, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfixd ( SAL_f64 *A, SAL_i32 I, SAL_i16 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfixdx ( SAL_f64 *A, SAL_i32 I, SAL_i16 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfixr32 ( SAL_f32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfixr32d ( SAL_f64 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfixr32dx ( SAL_f64 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfixr32x ( SAL_f32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfixrd ( SAL_f64 *A, SAL_i32 I, SAL_i16 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfixrdx ( SAL_f64 *A, SAL_i32 I, SAL_i16 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vflt16 ( SAL_i16 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vflt16x ( SAL_i16 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vflt32d ( SAL_i32 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vflt32dx ( SAL_i32 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vflt8 ( SAL_i8 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vflt8x ( SAL_i8 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfltd ( SAL_i16 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfltdx ( SAL_i16 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfltu16 ( SAL_ui16 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfltu16x ( SAL_ui16 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfltu32d ( SAL_ui32 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfltu32dx ( SAL_ui32 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfltud ( SAL_ui16 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfltudx ( SAL_ui16 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfrac ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfracd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vfracdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vfracx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vgathr ( SAL_f32 *A, SAL_i32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vgathra ( SAL_f32 **A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vgathrad ( SAL_f64 **A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vgathradx ( SAL_f64 **A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vgathrax ( SAL_f32 **A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vgathrd ( SAL_f64 *A, SAL_i32 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vgathrdx ( SAL_f64 *A, SAL_i32 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vgathrx ( SAL_f32 *A, SAL_i32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vgen ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vgenp ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M );
    extern SAL_STATUS vgenpx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS vgenx ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS viclip ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS viclipx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vimag ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vimagd ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vimagdx ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vimagx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vindex ( SAL_f32 *A, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vindexx ( SAL_f32 *A, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vintb ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vintbx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlim ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vlimd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vlimdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlimx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlint ( SAL_f32 *A, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M );
    extern SAL_STATUS vlintx ( SAL_f32 *A, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS vlmerg ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vlmergx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vln ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlnd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlndx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlnm ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlnmx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlnmz ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlnmzx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlnx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlnz ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlnzx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlog ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlogd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlogdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlogm ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlogmx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlogmz ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlogmzx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlogx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vlogz ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vlogzx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vma ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vmad ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vmadx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmax ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vma_x ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmaxd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmaxdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmaxmg ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmaxmgd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmaxmgdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmaxmgx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmaxx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmin ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmind ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmindx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vminmg ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vminmgd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vminmgdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vminmgx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vminx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmma ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N );
    extern SAL_STATUS vmmax ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmmsb ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N );
    extern SAL_STATUS vmmsbx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmov ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmovd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmovdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmovi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmovix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmovx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmsa ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vmsad ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vmsadx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmsax ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmsb ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vmsbd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vmsbdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmsbx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmul ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmuld ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmuldx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmuli ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vmulix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vmulx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vnabs ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vnabsx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vneg ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vnegd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vnegdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vnegi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vnegix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vnegx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vori ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vorix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vpmerg ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vpmergx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vpoly ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 P );
    extern SAL_STATUS vpolyd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 P );
    extern SAL_STATUS vpolydx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 P, SAL_i32 X );
    extern SAL_STATUS vpolyx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 P, SAL_i32 X );
    extern SAL_STATUS vpythg ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N );
    extern SAL_STATUS vpythgx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vqint ( SAL_f32 *A, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M );
    extern SAL_STATUS vqintx ( SAL_f32 *A, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS vramp ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vrampd ( SAL_f64 *A, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vrampdx ( SAL_f64 *A, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vrampi ( SAL_i32 *A, SAL_i32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vrampix ( SAL_i32 *A, SAL_i32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vrampx ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vreal ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vreald ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vrealdx ( SAL_cf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vrealx ( SAL_cf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vrecip ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vrecipx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vrecipx_fast ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vrsqrt ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 J, SAL_i32 N );
    extern SAL_STATUS vrsqrtd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 J, SAL_i32 N );
    extern SAL_STATUS vrsqrtdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 J, SAL_i32 N, SAL_i32 xflag );
    extern SAL_STATUS vrsqrtx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 J, SAL_i32 N, SAL_i32 xflag );
    extern SAL_STATUS vrsum ( SAL_f32 *A, SAL_i32 I, SAL_f32 *S, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vrsumx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *S, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vrvrs ( SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vrvrsx ( SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsadd ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsaddd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsadddx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsaddi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsaddix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsaddx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsbm ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vsbmd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vsbmdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsbmx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsbsbm ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N );
    extern SAL_STATUS vsbsbmx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_f32 *E, SAL_i32 M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsbsm ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vsbsmx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vscal ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 NB );
    extern SAL_STATUS vscald ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 NB );
    extern SAL_STATUS vscaldx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 NB, SAL_i32 X );
    extern SAL_STATUS vscalx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 NB, SAL_i32 X );
    extern SAL_STATUS vscatr ( SAL_f32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS vscatra ( SAL_f32 *A, SAL_i32 I, SAL_f32 **B, SAL_i32 J, SAL_i32 N );
    extern SAL_STATUS vscatrad ( SAL_f64 *A, SAL_i32 I, SAL_f64 **B, SAL_i32 J, SAL_i32 N );
    extern SAL_STATUS vscatradx ( SAL_f64 *A, SAL_i32 I, SAL_f64 **B, SAL_i32 J, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vscatrax ( SAL_f32 *A, SAL_i32 I, SAL_f32 **B, SAL_i32 J, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vscatrd ( SAL_f64 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 N );
    extern SAL_STATUS vscatrdx ( SAL_f64 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vscatrx ( SAL_f32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsdiv ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsdivd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsdivdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsdivi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsdivix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsdivx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsimps ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsimpsx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsin ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsind ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsindx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsinx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsma ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vsmad ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vsmadx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsmax ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsmsa ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vsmsad ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vsmsadx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsmsax ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsmsb ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vsmsbd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vsmsbdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsmsbx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsmul ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsmuld ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsmuldx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsmuli ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsmulix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsmulx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsort ( SAL_f32 *C, SAL_i32 N , SAL_i32 OFLAG );
    extern SAL_STATUS vsorti ( SAL_f32 *C, SAL_i32 *IC, SAL_i32 *List_addr, SAL_i32 N , SAL_i32 OFLAG );
    extern SAL_STATUS vsortix ( SAL_f32 *C, SAL_i32 *IC, SAL_i32 *List_addr, SAL_i32 N , SAL_i32 OFLAG, SAL_i32 X );
    extern SAL_STATUS vsortx ( SAL_f32 *C, SAL_i32 N , SAL_i32 OFLAG, SAL_i32 X );
    extern SAL_STATUS vspdp ( SAL_f32 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vspdpx ( SAL_f32 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsq ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsqd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsqdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsqrt ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsqrtd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsqrtdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsqrtx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsqrtz ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsqrtzx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsqx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vssq ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vssqd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vssqdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vssqx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsub ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsubd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsubdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsubi ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vsubix ( SAL_i32 *A, SAL_i32 I, SAL_i32 *B, SAL_i32 J, SAL_i32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vsubx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vswap ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_i32 N );
    extern SAL_STATUS vswapd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_i32 N );
    extern SAL_STATUS vswapdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vswapx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vswsum ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 P );
    extern SAL_STATUS vswsumx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 P, SAL_i32 X );
    extern SAL_STATUS vtabi ( SAL_f32 *A, SAL_i32 I, SAL_f32 *S1, SAL_f32 *S2, SAL_f32 *C, SAL_i32 M, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vtabid ( SAL_f64 *A, SAL_i32 I, SAL_f64 *S1, SAL_f64 *S2, SAL_f64 *C, SAL_i32 M, SAL_f64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vtabidx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *S1, SAL_f64 *S2, SAL_f64 *C, SAL_i32 M, SAL_f64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vtabix ( SAL_f32 *A, SAL_i32 I, SAL_f32 *S1, SAL_f32 *S2, SAL_f32 *C, SAL_i32 M, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vtan ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vtanx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vthr ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vthres ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vthresd ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vthresdx ( SAL_f64 *A, SAL_i32 I, SAL_f64 *B, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vthresx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vthrsc ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS vthrscx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_f32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vthrx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vtmerg ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vtmergx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS vtrapz ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS vtrapzx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *B, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS warp ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 INC, SAL_i32 INR, SAL_i32 ONC, SAL_i32 ONR, SAL_i32 FLG, SAL_f32 *BKG );
    extern SAL_STATUS warpd ( SAL_f64 *A, SAL_f64 *B, SAL_f64 *C, SAL_i32 INC, SAL_i32 INR, SAL_i32 ONC, SAL_i32 ONR, SAL_i32 FLG, SAL_f64 *BKG );
    extern SAL_STATUS warpdx ( SAL_f64 *A, SAL_f64 *B, SAL_f64 *C, SAL_i32 INC, SAL_i32 INR, SAL_i32 ONC, SAL_i32 ONR, SAL_i32 FLG, SAL_f64 *BKG, SAL_i32 X );
    extern SAL_STATUS warpx ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 INC, SAL_i32 INR, SAL_i32 ONC, SAL_i32 ONR, SAL_i32 FLG, SAL_f32 *BKG, SAL_i32 X );
    extern SAL_STATUS wiener ( SAL_i32 L, SAL_f32 *A, SAL_f32 *C, SAL_f32 *F, SAL_f32 *P, SAL_i32 IFLG, SAL_i32 *IERR );
    extern SAL_STATUS wienerx ( SAL_i32 L, SAL_f32 *A, SAL_f32 *C, SAL_f32 *F, SAL_f32 *P, SAL_i32 IFLG, SAL_i32 *IERR, SAL_i32 X );
    extern SAL_STATUS zaspec ( SAL_zf32 *A, SAL_f32 *C, SAL_i32 N );
    extern SAL_STATUS zaspecx ( SAL_zf32 *A, SAL_f32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zcoher ( SAL_f32 *A, SAL_f32 *B, SAL_zf32 *C, SAL_f32 *D, SAL_i32 N );
    extern SAL_STATUS zcoherx ( SAL_f32 *A, SAL_f32 *B, SAL_zf32 *C, SAL_f32 *D, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zconv ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M );
    extern SAL_STATUS zconv2d ( SAL_zf32 *A, SAL_i32 tcols_A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 tcols_C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG );
    extern SAL_STATUS zconv2d_ia ( SAL_zf32 *A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG );
    extern SAL_STATUS zconv2d_iax ( SAL_zf32 *A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS zconv2dx ( SAL_zf32 *A, SAL_i32 tcols_A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 tcols_C, SAL_i32 DSX, SAL_i32 DSY, SAL_i32 NCB, SAL_i32 NRB, SAL_i32 NCC, SAL_i32 NRC, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS zconvx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS zcspec ( SAL_zf32 *A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 N );
    extern SAL_STATUS zcspecx ( SAL_zf32 *A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zdotpr ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 N );
    extern SAL_STATUS zdotprd ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 N );
    extern SAL_STATUS zdotprdx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zdotprx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zexpmul ( SAL_f32 *A, SAL_i32 I, SAL_f32 *F, SAL_f32 *P, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *ZEXPTAB, SAL_i32 LOG2M, SAL_i32 N );
    extern SAL_STATUS zexpmulx ( SAL_f32 *A, SAL_i32 I, SAL_f32 *F, SAL_f32 *P, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *ZEXPTAB, SAL_i32 LOG2M, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zexptab ( SAL_zf32 *C, SAL_i32 LOG2M, SAL_i32 FLAG );
    extern SAL_STATUS zexptabx ( SAL_zf32 *C, SAL_i32 LOG2M, SAL_i32 FLAG, SAL_i32 X );
    extern SAL_STATUS zidotpr ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 N );
    extern SAL_STATUS zidotprd ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 N );
    extern SAL_STATUS zidotprdx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zidotprx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zimul ( SAL_zf32 *A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 NR, SAL_i32 NC, SAL_i32 F );
    extern SAL_STATUS zimuld ( SAL_zf64 *A, SAL_zf64 *B, SAL_zf64 *C, SAL_i32 NR, SAL_i32 NC, SAL_i32 F );
    extern SAL_STATUS zimuldx ( SAL_zf64 *A, SAL_zf64 *B, SAL_zf64 *C, SAL_i32 NR, SAL_i32 NC, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS zimulx ( SAL_zf32 *A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 NR, SAL_i32 NC, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS_INT zmat_auto_mul ( SAL_zf32 *pA, SAL_i32 Atcols, SAL_zf32 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_auto_muld ( SAL_zf64 *pA, SAL_i32 Atcols, SAL_zf64 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_auto_muldx ( SAL_zf64 *pA, SAL_i32 Atcols, SAL_zf64 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT zmat_auto_mulx ( SAL_zf32 *pA, SAL_i32 Atcols, SAL_zf32 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT zmat_chol_dec ( SAL_zf32 *A, SAL_i32 Atcols, SAL_zf32 *LDU, SAL_i32 LDUtcols, SAL_i32 n, SAL_f32 *rcond_est, SAL_zf32 *v, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_chol_decx ( SAL_zf32 *A, SAL_i32 Atcols, SAL_zf32 *LDU, SAL_i32 LDUtcols, SAL_i32 n, SAL_f32 *rcond_est, SAL_zf32 *v, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT zmat_chol_sol ( SAL_zf32 *LDU, SAL_i32 LDUtcols, SAL_zf32 *b, SAL_zf32 *w, SAL_i32 n, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_chol_solx ( SAL_zf32 *LDU, SAL_i32 LDUtcols, SAL_zf32 *b, SAL_zf32 *w, SAL_i32 n, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT zmatherm_eig ( SAL_zf32 *A, SAL_i32 Atcols, SAL_f32 *Eval, SAL_zf32 *Evec, SAL_i32 Etcols, SAL_i32 N, SAL_eig_tune *Tune, SAL_f32 *Condn, SAL_i32 *Ind_v, SAL_i32 Flag );
    extern SAL_STATUS_INT zmatherm_eigx ( SAL_zf32 *A, SAL_i32 Atcols, SAL_f32 *Eval, SAL_zf32 *Evec, SAL_i32 Etcols, SAL_i32 N, SAL_eig_tune *Tune, SAL_f32 *Condn, SAL_i32 *Ind_v, SAL_i32 Flag, SAL_i32 X );
    extern SAL_STATUS zmatinv_lu ( SAL_zf32 *C, SAL_zf32 *D, SAL_i32 *IP, SAL_i32 N );
    extern SAL_STATUS zmatinv_lux ( SAL_zf32 *C, SAL_zf32 *D, SAL_i32 *IP, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS_INT zmat_lud_dec ( SAL_zf32 *C, SAL_i32 Ctcols, SAL_i32 *D, SAL_i32 n, SAL_f32 *rcond_est, SAL_zf32 *v, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_lud_decx ( SAL_zf32 *C, SAL_i32 Ctcols, SAL_i32 *D, SAL_i32 n, SAL_f32 *rcond_est, SAL_zf32 *v, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT zmat_lud_sol ( SAL_zf32 *A, SAL_i32 Atcols, SAL_i32 *D, SAL_zf32 *b, SAL_zf32 *w, SAL_i32 n, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_lud_solx ( SAL_zf32 *A, SAL_i32 Atcols, SAL_i32 *D, SAL_zf32 *b, SAL_zf32 *w, SAL_i32 n, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT zmat_mgs_dec ( SAL_zf32 *AT, SAL_i32 ATtcols, SAL_zf32 *R, SAL_i32 Rtcols, SAL_i32 M, SAL_i32 N, SAL_f32 *rcond_est, SAL_zf32 *v, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_mgs_decx ( SAL_zf32 *AT, SAL_i32 ATtcols, SAL_zf32 *R, SAL_i32 Rtcols, SAL_i32 M, SAL_i32 N, SAL_f32 *rcond_est, SAL_zf32 *v, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT zmat_mgs_solr ( SAL_zf32 *R, SAL_i32 Rtcols, SAL_zf32 *b, SAL_zf32 *x, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_mgs_solrhr ( SAL_zf32 *R, SAL_i32 Rtcols, SAL_zf32 *b, SAL_zf32 *x, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_mgs_solrhrx ( SAL_zf32 *R, SAL_i32 Rtcols, SAL_zf32 *b, SAL_zf32 *x, SAL_i32 N, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT zmat_mgs_solrx ( SAL_zf32 *R, SAL_i32 Rtcols, SAL_zf32 *b, SAL_zf32 *x, SAL_i32 N, SAL_i32 flag, SAL_i32 X );
    extern SAL_STATUS_INT zmat_mul ( SAL_zf32 *pA, SAL_i32 Atcols, SAL_zf32 *pB, SAL_i32 Btcols, SAL_zf32 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_muld ( SAL_zf64 *pA, SAL_i32 Atcols, SAL_zf64 *pB, SAL_i32 Btcols, SAL_zf64 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS_INT zmat_muldx ( SAL_zf64 *pA, SAL_i32 Atcols, SAL_zf64 *pB, SAL_i32 Btcols, SAL_zf64 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS_INT zmat_mulx ( SAL_zf32 *pA, SAL_i32 Atcols, SAL_zf32 *pB, SAL_i32 Btcols, SAL_zf32 *pC, SAL_i32 Ctcols, SAL_i32 nr_c, SAL_i32 nc_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );
    extern SAL_STATUS zmixer ( SAL_zf32 *A, SAL_i32 sA, SAL_f64 *F, SAL_f64 *P, SAL_zf32 *C, SAL_i32 sC, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS zmixerx ( SAL_zf32 *A, SAL_i32 sA, SAL_f64 *F, SAL_f64 *P, SAL_zf32 *C, SAL_i32 sC, SAL_i32 N, SAL_i32 flag, SAL_i32 eflag );
    extern SAL_STATUS zmma ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA );
    extern SAL_STATUS zmmax ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA, SAL_i32 X );
    extern SAL_STATUS zmmov ( SAL_zf32 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_zf32 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len );
    extern SAL_STATUS zmmovd ( SAL_zf64 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_zf64 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len );
    extern SAL_STATUS zmmovdx ( SAL_zf64 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_zf64 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len, SAL_i32 xflag );
    extern SAL_STATUS zmmovx ( SAL_zf32 *pSrc, SAL_i32 stride_x_src, SAL_i32 stride_y_src, SAL_zf32 *pDst, SAL_i32 stride_x_dst, SAL_i32 stride_y_dst, SAL_i32 x_len, SAL_i32 y_len, SAL_i32 xflag );
    extern SAL_STATUS zmms ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA );
    extern SAL_STATUS zmmsx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA, SAL_i32 X );
    extern SAL_STATUS zmmuld ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA );
    extern SAL_STATUS zmmuldx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA, SAL_i32 X );
    extern SAL_STATUS zmsm ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA );
    extern SAL_STATUS zmsmx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 MC, SAL_i32 NC, SAL_i32 NA, SAL_i32 X );
    extern SAL_STATUS zmtrans2 ( SAL_zf32 *A, SAL_zf32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C );
    extern SAL_STATUS zmtrans2d ( SAL_zf64 *A, SAL_zf64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C );
    extern SAL_STATUS zmtrans2dx ( SAL_zf64 *A, SAL_zf64 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C, SAL_i32 X );
    extern SAL_STATUS zmtrans2x ( SAL_zf32 *A, SAL_zf32 *C, SAL_i32 NC, SAL_i32 NR, SAL_i32 tcols_A, SAL_i32 tcols_C, SAL_i32 X );
    extern SAL_STATUS zrdesamp ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_zf32 *C, SAL_i32 N, SAL_i32 M );
    extern SAL_STATUS zrdesampx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_zf32 *C, SAL_i32 N, SAL_i32 M, SAL_i32 X );
    extern SAL_STATUS zrdotpr ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 N );
    extern SAL_STATUS zrdotprd ( SAL_zf64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 N );
    extern SAL_STATUS zrdotprdx ( SAL_zf64 *A, SAL_i32 I, SAL_f64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zrdotprx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zrmixer ( SAL_f32 *A, SAL_i32 sA, SAL_f64 *F, SAL_f64 *P, SAL_zf32 *C, SAL_i32 sC, SAL_i32 N, SAL_i32 flag );
    extern SAL_STATUS zrmixerx ( SAL_f32 *A, SAL_i32 sA, SAL_f64 *F, SAL_f64 *P, SAL_zf32 *C, SAL_i32 sC, SAL_i32 N, SAL_i32 flag, SAL_i32 eflag );
    extern SAL_STATUS zrvadd ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zrvaddx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zrvdiv ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zrvdivx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zrvmul ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zrvmulx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zrvsub ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zrvsubx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS ztoc ( SAL_zf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS ztocd ( SAL_zf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS ztocdx ( SAL_zf64 *A, SAL_i32 I, SAL_cf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS ztocx ( SAL_zf32 *A, SAL_i32 I, SAL_cf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS ztrans ( SAL_f32 *A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 N );
    extern SAL_STATUS ztransx ( SAL_f32 *A, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvabs ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvabsx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvadd ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvaddd ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvadddx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvaddx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvcma ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS zvcmax ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvcmul ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvcmuld ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvcmuldx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvcmulx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvconj ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvconjd ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvconjdx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvconjx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvdbcon ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *S, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS zvdbconx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *S, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS zvdiv ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvdivd ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvdivdx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvdivx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvdivx_fast ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvexp ( SAL_f32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvexpd ( SAL_f64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvexpdx ( SAL_f64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvexpm ( SAL_f32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvexpmx ( SAL_f32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvexpx ( SAL_f32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvfill ( SAL_zf32 *A, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvfillx ( SAL_zf32 *A, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvimag ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvimagd ( SAL_zf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvimagdx ( SAL_zf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvimagx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvmags ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvmagsd ( SAL_zf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvmagsdx ( SAL_zf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvmagsx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvmgsa ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvmgsax ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *B, SAL_i32 J, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvmov ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvmovd ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvmovdx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvmovx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvmul ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS zvmuld ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F );
    extern SAL_STATUS zvmuldx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS zvmulx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 F, SAL_i32 X );
    extern SAL_STATUS zvneg ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvnegd ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvnegdx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvnegx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvphas ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvphasx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvrcip ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvrcipd ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvrcipdx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvrcipx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvrcipx_fast ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvreal ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvreald ( SAL_zf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvrealdx ( SAL_zf64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvrealx ( SAL_zf32 *A, SAL_i32 I, SAL_f32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvsma ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS zvsmad ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *D, SAL_i32 L, SAL_i32 N );
    extern SAL_STATUS zvsmadx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_zf64 *C, SAL_i32 K, SAL_zf64 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvsmax ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 K, SAL_zf32 *D, SAL_i32 L, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvsqrt ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvsqrtx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvsub ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvsubd ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvsubdx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvsubx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvzsml ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvzsmld ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_zf64 *C, SAL_i32 K, SAL_i32 N );
    extern SAL_STATUS zvzsmldx ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_zf64 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );
    extern SAL_STATUS zvzsmlx ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_zf32 *C, SAL_i32 K, SAL_i32 N, SAL_i32 X );

#else

    extern void aspec ( );
    extern void aspecx ( );
    extern void blkman_window ( );
    extern void blkman_windowd ( );
    extern void blkman_windowdx ( );
    extern void blkman_windowx ( );
    extern void bprojimg ( );
    extern void bprojimgd ( );
    extern void bprojimgdx ( );
    extern void bprojimgx ( );
    extern void bprojrow ( );
    extern void bprojrowd ( );
    extern void bprojrowdx ( );
    extern void bprojrowx ( );
    extern void cache_flush_1d ( );
    extern void cache_flush_2d ( );
    extern void cache_load_1d ( );
    extern void cache_load_2d ( );
    extern void cache_zero_1d ( );
    extern void cache_zero_2d ( );
    extern void cconv ( );
    extern void cconv2d ( );
    extern void cconv2dx ( );
    extern void cconvx ( );
    extern void cdotpr ( );
    extern void cdotprd ( );
    extern void cdotprdx ( );
    extern void cdotprx ( );
    extern void cexpmul ( );
    extern void cexpmulx ( );
    extern void cexptab ( );
    extern void cexptabx ( );
    extern void cfft ( );
    extern void cfft2d ( );
    extern void cfft2dd ( );
    extern void cfft2ddx ( );
    extern void cfft2dx ( );
    extern void cfftb ( );
    extern void cfftb3 ( );
    extern void cfftb3x ( );
    extern void cfftb5 ( );
    extern void cfftb5x ( );
    extern void cfftbd ( );
    extern void cfftbdx ( );
    extern void cfftbx ( );
    extern void cfftd ( );
    extern void cfftdx ( );
    extern void cffto ( );
    extern void cfftod ( );
    extern void cfftodx ( );
    extern void cfftox ( );
    extern void cfftsc ( );
    extern void cfftscd ( );
    extern void cfftscdx ( );
    extern void cfftscx ( );
    extern void cfftx ( );
    extern void cidotpr ( );
    extern void cidotprd ( );
    extern void cidotprdx ( );
    extern void cidotprx ( );
    extern void cimul ( );
    extern void cimuld ( );
    extern void cimuldx ( );
    extern void cimulx ( );
    extern void cmat_auto_mul ( );
    extern void cmat_auto_muld ( );
    extern void cmat_auto_muldx ( );
    extern void cmat_auto_mulx ( );
    extern int cmat_chol_dec( );
    extern int cmat_chol_decx( );
    extern int cmat_chol_sol( );
    extern int cmat_chol_solx( );
    extern void cmatinv_lu ( );
    extern void cmatinv_lux ( );
    extern int cmat_lud_dec( );
    extern int cmat_lud_decx( );
    extern int cmat_lud_sol( );
    extern int cmat_lud_solx( );
    extern int cmat_mgs_dec( );
    extern int cmat_mgs_decx( );
    extern int cmat_mgs_solr( );
    extern int cmat_mgs_solrhr( );
    extern int cmat_mgs_solrhrx( );
    extern int cmat_mgs_solrx( );
    extern void cmat_mul ( );
    extern void cmat_muld ( );
    extern void cmat_muldx ( );
    extern void cmat_mulx ( );
    extern void cmixer ( );
    extern void cmixerx ( );
    extern void cmma ( );
    extern void cmmax ( );
    extern void cmmov ( );
    extern void cmmovd ( );
    extern void cmmovdx ( );
    extern void cmmovx ( );
    extern void cmms ( );
    extern void cmmsx ( );
    extern void cmmuld ( );
    extern void cmmuldx ( );
    extern void cmsm ( );
    extern void cmsmx ( );
    extern void cmtrans2 ( );
    extern void cmtrans2d ( );
    extern void cmtrans2dx ( );
    extern void cmtrans2x ( );
    extern void coher ( );
    extern void coherx ( );
    extern void conv ( );
    extern void conv2d ( );
    extern void conv2dx ( );
    extern void convm_cols ( );
    extern void convm_colsx ( );
    extern void convm_rows ( );
    extern void convm_rowsx ( );
    extern void convx ( );
    extern void crdesamp ( );
    extern void crdesampx ( );
    extern void crdotpr ( );
    extern void crdotprd ( );
    extern void crdotprdx ( );
    extern void crdotprx ( );
    extern void crmixer ( );
    extern void crmixerx ( );
    extern void crvadd ( );
    extern void crvaddx ( );
    extern void crvdiv ( );
    extern void crvdivx ( );
    extern void crvmul ( );
    extern void crvmulx ( );
    extern void crvsub ( );
    extern void crvsubx ( );
    extern void cspec ( );
    extern void cspecx ( );
    extern void ctoz ( );
    extern void ctozd ( );
    extern void ctozdx ( );
    extern void ctozx ( );
    extern void cvabs ( );
    extern void cvabsx ( );
    extern void cvadd ( );
    extern void cvaddd ( );
    extern void cvadddx ( );
    extern void cvaddx ( );
    extern void cvcma ( );
    extern void cvcmax ( );
    extern void cvcmul ( );
    extern void cvcmulx ( );
    extern void cvcomb ( );
    extern void cvcombd ( );
    extern void cvcombdx ( );
    extern void cvcombx ( );
    extern void cvconj ( );
    extern void cvconjd ( );
    extern void cvconjdx ( );
    extern void cvconjx ( );
    extern void cvcsml ( );
    extern void cvcsmld ( );
    extern void cvcsmldx ( );
    extern void cvcsmlx ( );
    extern void cvdbcon ( );
    extern void cvdbconx ( );
    extern void cvdiv ( );
    extern void cvdivd ( );
    extern void cvdivdx ( );
    extern void cvdivx ( );
    extern void cvexp ( );
    extern void cvexpd ( );
    extern void cvexpdx ( );
    extern void cvexpm ( );
    extern void cvexpmx ( );
    extern void cvexpx ( );
    extern void cvfill ( );
    extern void cvfillx ( );
    extern void cvmags ( );
    extern void cvmagsd ( );
    extern void cvmagsdx ( );
    extern void cvmagsx ( );
    extern void cvmgsa ( );
    extern void cvmgsax ( );
    extern void cvmov ( );
    extern void cvmovd ( );
    extern void cvmovdx ( );
    extern void cvmovx ( );
    extern void cvmul ( );
    extern void cvmuld ( );
    extern void cvmuldx ( );
    extern void cvmulx ( );
    extern void cvneg ( );
    extern void cvnegd ( );
    extern void cvnegdx ( );
    extern void cvnegx ( );
    extern void cvphas ( );
    extern void cvphasx ( );
    extern void cvrcip ( );
    extern void cvrcipd ( );
    extern void cvrcipdx ( );
    extern void cvrcipx ( );
    extern void cvsma ( );
    extern void cvsmad ( );
    extern void cvsmadx ( );
    extern void cvsmax ( );
    extern void cvsplit ( );
    extern void cvsplitd ( );
    extern void cvsplitdx ( );
    extern void cvsplitx ( );
    extern void cvsqrt ( );
    extern void cvsqrtx ( );
    extern void cvsub ( );
    extern void cvsubd ( );
    extern void cvsubdx ( );
    extern void cvsubx ( );
    extern void deq22 ( );
    extern void deq22x ( );
    extern void desamp ( );
    extern void desampx ( );
    extern void dotpr ( );
    extern void dotprd ( );
    extern void dotprdx ( );
    extern void dotprx ( );
    extern void f3x3 ( );
    extern void f3x3d ( );
    extern void f3x3dx ( );
    extern void f3x3x ( );
    extern void f5x5 ( );
    extern void f5x5d ( );
    extern void f5x5dx ( );
    extern void f5x5x ( );
    extern void fcf_cipt ( );
    extern void fcf_ciptx ( );
    extern void fcf_ript ( );
    extern void fcf_riptx ( );
    extern void fcf_zipt ( );
    extern void fcf_ziptx ( );
    extern void fcf_zript ( );
    extern void fcf_zriptx ( );
    extern void fcs_cipt ( );
    extern void fcs_ciptx ( );
    extern void fcsm_cipt ( );
    extern void fcsm_ciptx ( );
    extern void fcsm_ript ( );
    extern void fcsm_riptx ( );
    extern void fcsm_zipt ( );
    extern void fcsm_ziptx ( );
    extern void fcsm_zript ( );
    extern void fcsm_zriptx ( );
    extern void fcs_ript ( );
    extern void fcs_riptx ( );
    extern void fcs_zipt ( );
    extern void fcs_ziptx ( );
    extern void fcs_zript ( );
    extern void fcs_zriptx ( );
    extern int fft1d_setup ( );
    extern int fft1d_setup_user_alloc ( );
    extern int fft1d_setupd ( );
    extern int fft1d_setup_user_allocd ( );
    extern void fft2d_cip ( );
    extern void fft2d_cipd ( );
    extern void fft2d_cipdx ( );
    extern void fft2d_cipt ( );
    extern void fft2d_ciptd ( );
    extern void fft2d_ciptdx ( );
    extern void fft2d_ciptx ( );
    extern void fft2d_cipx ( );
    extern void fft2d_cop ( );
    extern void fft2d_copd ( );
    extern void fft2d_copdx ( );
    extern void fft2d_copt ( );
    extern void fft2d_coptd ( );
    extern void fft2d_coptdx ( );
    extern void fft2d_coptx ( );
    extern void fft2d_copx ( );
    extern void fft2d_rip ( );
    extern void fft2d_ripd ( );
    extern void fft2d_ripdx ( );
    extern void fft2d_ript ( );
    extern void fft2d_riptd ( );
    extern void fft2d_riptdx ( );
    extern void fft2d_riptx ( );
    extern void fft2d_ripx ( );
    extern void fft2d_rop ( );
    extern void fft2d_ropd ( );
    extern void fft2d_ropdx ( );
    extern void fft2d_ropt ( );
    extern void fft2d_roptd ( );
    extern void fft2d_roptdx ( );
    extern void fft2d_roptx ( );
    extern void fft2d_ropx ( );
    extern int fft2d_setup ( );
    extern int fft2d_setup_user_alloc ( );
    extern int fft2d_setupd ( );
    extern int fft2d_setup_user_allocd ( );
    extern void fft2d_zip ( );
    extern void fft2d_zipd ( );
    extern void fft2d_zipdx ( );
    extern void fft2d_zipt ( );
    extern void fft2d_ziptd ( );
    extern void fft2d_ziptdx ( );
    extern void fft2d_ziptx ( );
    extern void fft2d_zipx ( );
    extern void fft2d_zop ( );
    extern void fft2d_zopd ( );
    extern void fft2d_zopdx ( );
    extern void fft2d_zopt ( );
    extern void fft2d_zoptd ( );
    extern void fft2d_zoptdx ( );
    extern void fft2d_zoptx ( );
    extern void fft2d_zopx ( );
    extern void fft2d_zrip ( );
    extern void fft2d_zripd ( );
    extern void fft2d_zripdx ( );
    extern void fft2d_zript ( );
    extern void fft2d_zriptd ( );
    extern void fft2d_zriptdx ( );
    extern void fft2d_zriptx ( );
    extern void fft2d_zripx ( );
    extern void fft2d_zrop ( );
    extern void fft2d_zropd ( );
    extern void fft2d_zropdx ( );
    extern void fft2d_zropt ( );
    extern void fft2d_zroptd ( );
    extern void fft2d_zroptdx ( );
    extern void fft2d_zroptx ( );
    extern void fft2d_zropx ( );
    extern void fft3m_cols_cop ( );
    extern void fft3m_cols_copx ( );
    extern void fft3m_cols_rop ( );
    extern void fft3m_cols_ropx ( );
    extern void fft3m_cols_zip ( );
    extern void fft3m_cols_zipx ( );
    extern void fft3m_cols_zop ( );
    extern void fft3m_cols_zopx ( );
    extern void fft3m_cols_zrip ( );
    extern void fft3m_cols_zripx ( );
    extern void fft3m_cols_zrop ( );
    extern void fft3m_cols_zropx ( );
    extern void fft3m_cop ( );
    extern void fft3m_copx ( );
    extern void fft3m_rop ( );
    extern void fft3m_ropx ( );
    extern void fft3m_rows_cop ( );
    extern void fft3m_rows_copx ( );
    extern void fft3m_rows_rop ( );
    extern void fft3m_rows_ropx ( );
    extern void fft3m_rows_zip ( );
    extern void fft3m_rows_zipx ( );
    extern void fft3m_rows_zop ( );
    extern void fft3m_rows_zopx ( );
    extern void fft3m_rows_zrip ( );
    extern void fft3m_rows_zripx ( );
    extern void fft3m_rows_zrop ( );
    extern void fft3m_rows_zropx ( );
    extern void fft3m_zop ( );
    extern void fft3m_zopx ( );
    extern void fft3m_zrop ( );
    extern void fft3m_zropx ( );
    extern void fft3_cop ( );
    extern void fft3_copd ( );
    extern void fft3_copdx ( );
    extern void fft3_copx ( );
    extern void fft3_rop ( );
    extern void fft3_ropd ( );
    extern void fft3_ropdx ( );
    extern void fft3_ropx ( );
    extern void fft3_zip ( );
    extern void fft3_zipd ( );
    extern void fft3_zipdx ( );
    extern void fft3_zipx ( );
    extern void fft3_zop ( );
    extern void fft3_zopd ( );
    extern void fft3_zopdx ( );
    extern void fft3_zopx ( );
    extern void fft3_zrip ( );
    extern void fft3_zripd ( );
    extern void fft3_zripdx ( );
    extern void fft3_zripx ( );
    extern void fft3_zrop ( );
    extern void fft3_zropd ( );
    extern void fft3_zropdx ( );
    extern void fft3_zropx ( );
    extern void fft5m_cols_cop ( );
    extern void fft5m_cols_copx ( );
    extern void fft5m_cols_rop ( );
    extern void fft5m_cols_ropx ( );
    extern void fft5m_cols_zip ( );
    extern void fft5m_cols_zipx ( );
    extern void fft5m_cols_zop ( );
    extern void fft5m_cols_zopx ( );
    extern void fft5m_cols_zrip ( );
    extern void fft5m_cols_zripx ( );
    extern void fft5m_cols_zrop ( );
    extern void fft5m_cols_zropx ( );
    extern void fft5m_cop ( );
    extern void fft5m_copx ( );
    extern void fft5m_rop ( );
    extern void fft5m_ropx ( );
    extern void fft5m_rows_cop ( );
    extern void fft5m_rows_copx ( );
    extern void fft5m_rows_rop ( );
    extern void fft5m_rows_ropx ( );
    extern void fft5m_rows_zip ( );
    extern void fft5m_rows_zipx ( );
    extern void fft5m_rows_zop ( );
    extern void fft5m_rows_zopx ( );
    extern void fft5m_rows_zrip ( );
    extern void fft5m_rows_zripx ( );
    extern void fft5m_rows_zrop ( );
    extern void fft5m_rows_zropx ( );
    extern void fft5m_zop ( );
    extern void fft5m_zopx ( );
    extern void fft5m_zrop ( );
    extern void fft5m_zropx ( );
    extern void fft5_cop ( );
    extern void fft5_copd ( );
    extern void fft5_copdx ( );
    extern void fft5_copx ( );
    extern void fft5_rop ( );
    extern void fft5_ropd ( );
    extern void fft5_ropdx ( );
    extern void fft5_ropx ( );
    extern void fft5_zip ( );
    extern void fft5_zipd ( );
    extern void fft5_zipdx ( );
    extern void fft5_zipx ( );
    extern void fft5_zop ( );
    extern void fft5_zopd ( );
    extern void fft5_zopdx ( );
    extern void fft5_zopx ( );
    extern void fft5_zrip ( );
    extern void fft5_zripd ( );
    extern void fft5_zripdx ( );
    extern void fft5_zripx ( );
    extern void fft5_zrop ( );
    extern void fft5_zropd ( );
    extern void fft5_zropdx ( );
    extern void fft5_zropx ( );
    extern void fft9_cop ( );
    extern void fft9_copx ( );
    extern void fft9_zop ( );
    extern void fft9_zopx ( );
    extern void fft_acor ( );
    extern void fft_acordx ( );
    extern void fft_acorx ( );
    extern void fft_ccor ( );
    extern void fft_ccordx ( );
    extern void fft_ccorx ( );
    extern void fft_cip ( );
    extern void fft_cipd ( );
    extern void fft_cipdx ( );
    extern void fft_cipt ( );
    extern void fft_ciptd ( );
    extern void fft_ciptdx ( );
    extern void fft_ciptx ( );
    extern void fft_cipx ( );
    extern void fft_cop ( );
    extern void fft_copd ( );
    extern void fft_copdx ( );
    extern void fft_copt ( );
    extern void fft_coptd ( );
    extern void fft_coptdx ( );
    extern void fft_coptx ( );
    extern void fft_copx ( );
    extern void fft_cvmags ( );
    extern void fft_cvmagsx ( );
    extern void fft_free ( );
    extern void fft_freed ( );
    extern void fftm_cip ( );
    extern void fftm_cipd ( );
    extern void fftm_cipdx ( );
    extern void fftm_cipt ( );
    extern void fftm_ciptd ( );
    extern void fftm_ciptdx ( );
    extern void fftm_ciptx ( );
    extern void fftm_cipx ( );
    extern void fftm_cols_cip ( );
    extern void fftm_cols_cipd ( );
    extern void fftm_cols_cipdx ( );
    extern void fftm_cols_cipx ( );
    extern void fftm_cols_cop ( );
    extern void fftm_cols_copd ( );
    extern void fftm_cols_copdx ( );
    extern void fftm_cols_copx ( );
    extern void fftm_cols_rip ( );
    extern void fftm_cols_ripd ( );
    extern void fftm_cols_ripdx ( );
    extern void fftm_cols_ripx ( );
    extern void fftm_cols_rop ( );
    extern void fftm_cols_ropd ( );
    extern void fftm_cols_ropdx ( );
    extern void fftm_cols_ropx ( );
    extern void fftm_cols_zip ( );
    extern void fftm_cols_zipd ( );
    extern void fftm_cols_zipdx ( );
    extern void fftm_cols_zipx ( );
    extern void fftm_cols_zop ( );
    extern void fftm_cols_zopd ( );
    extern void fftm_cols_zopdx ( );
    extern void fftm_cols_zopx ( );
    extern void fftm_cols_zrip ( );
    extern void fftm_cols_zripd ( );
    extern void fftm_cols_zripdx ( );
    extern void fftm_cols_zripx ( );
    extern void fftm_cols_zrop ( );
    extern void fftm_cols_zropd ( );
    extern void fftm_cols_zropdx ( );
    extern void fftm_cols_zropx ( );
    extern void fftm_cop ( );
    extern void fftm_copd ( );
    extern void fftm_copdx ( );
    extern void fftm_copt ( );
    extern void fftm_coptd ( );
    extern void fftm_coptdx ( );
    extern void fftm_coptx ( );
    extern void fftm_copx ( );
    extern void fftm_rip ( );
    extern void fftm_ripd ( );
    extern void fftm_ripdx ( );
    extern void fftm_ript ( );
    extern void fftm_riptd ( );
    extern void fftm_riptdx ( );
    extern void fftm_riptx ( );
    extern void fftm_ripx ( );
    extern void fftm_rop ( );
    extern void fftm_ropd ( );
    extern void fftm_ropdx ( );
    extern void fftm_ropt ( );
    extern void fftm_roptd ( );
    extern void fftm_roptdx ( );
    extern void fftm_roptx ( );
    extern void fftm_ropx ( );
    extern void fftm_rows_cip ( );
    extern void fftm_rows_cipd ( );
    extern void fftm_rows_cipdx ( );
    extern void fftm_rows_cipx ( );
    extern void fftm_rows_cop ( );
    extern void fftm_rows_copd ( );
    extern void fftm_rows_copdx ( );
    extern void fftm_rows_copx ( );
    extern void fftm_rows_rip ( );
    extern void fftm_rows_ripd ( );
    extern void fftm_rows_ripdx ( );
    extern void fftm_rows_ripx ( );
    extern void fftm_rows_rop ( );
    extern void fftm_rows_ropd ( );
    extern void fftm_rows_ropdx ( );
    extern void fftm_rows_ropx ( );
    extern void fftm_rows_zip ( );
    extern void fftm_rows_zipd ( );
    extern void fftm_rows_zipdx ( );
    extern void fftm_rows_zipx ( );
    extern void fftm_rows_zop ( );
    extern void fftm_rows_zopd ( );
    extern void fftm_rows_zopdx ( );
    extern void fftm_rows_zopx ( );
    extern void fftm_rows_zrip ( );
    extern void fftm_rows_zripd ( );
    extern void fftm_rows_zripdx ( );
    extern void fftm_rows_zripx ( );
    extern void fftm_rows_zrop ( );
    extern void fftm_rows_zropd ( );
    extern void fftm_rows_zropdx ( );
    extern void fftm_rows_zropx ( );
    extern void fftm_small ( );
    extern void fftm_zip ( );
    extern void fftm_zipd ( );
    extern void fftm_zipdx ( );
    extern void fftm_zipt ( );
    extern void fftm_ziptd ( );
    extern void fftm_ziptdx ( );
    extern void fftm_ziptx ( );
    extern void fftm_zipx ( );
    extern void fftm_zop ( );
    extern void fftm_zopd ( );
    extern void fftm_zopdx ( );
    extern void fftm_zopt ( );
    extern void fftm_zoptd ( );
    extern void fftm_zoptdx ( );
    extern void fftm_zoptx ( );
    extern void fftm_zopx ( );
    extern void fftm_zrip ( );
    extern void fftm_zripd ( );
    extern void fftm_zripdx ( );
    extern void fftm_zript ( );
    extern void fftm_zriptd ( );
    extern void fftm_zriptdx ( );
    extern void fftm_zriptx ( );
    extern void fftm_zripx ( );
    extern void fftm_zrop ( );
    extern void fftm_zropd ( );
    extern void fftm_zropdx ( );
    extern void fftm_zropt ( );
    extern void fftm_zroptd ( );
    extern void fftm_zroptdx ( );
    extern void fftm_zroptx ( );
    extern void fftm_zropx ( );
    extern void fft_rip ( );
    extern void fft_ripd ( );
    extern void fft_ripdx ( );
    extern void fft_ript ( );
    extern void fft_riptd ( );
    extern void fft_riptdx ( );
    extern void fft_riptx ( );
    extern void fft_ripx ( );
    extern void fft_rop ( );
    extern void fft_ropd ( );
    extern void fft_ropdx ( );
    extern void fft_ropt ( );
    extern void fft_roptd ( );
    extern void fft_roptdx ( );
    extern void fft_roptx ( );
    extern void fft_ropx ( );
    extern void fft_setup ( );
    extern void fft_setupd ( );

    extern int fft1d_setup_create ( );
    extern int fft1d_setup_init ( );
    extern int fft2d_setup_create ( );
    extern int fft2d_setup_init ( );
    extern int fft_setup_set_buffer ( );
    extern int fft_setup_get_n_bytes ( );
    extern int fft_setup_get_tmep_n_bytes ( );

    extern int fft1d_setupd_create ( );
    extern int fft1d_setupd_init ( );
    extern int fft2d_setupd_create ( );
    extern int fft2d_setupd_init ( );
    extern int fft_setupd_set_buffer ( );
    extern int fft_setupd_get_n_bytes ( );
    extern int fft_setupd_get_tmep_n_bytes ( );

    extern int fft_setup_fixup ( );
    extern int fft_setup_fixupd ( );
    extern int fft_setup_get_temp_buffer_size ( );
    extern int fft_setup_get_temp_buffer_sized ( );
    extern int fft_setup_set_temp_buffer ( );
    extern int fft_setup_set_temp_bufferd ( );
    extern void fft_setup_user_alloc ( );
    extern void fft_setup_user_allocd ( );
    extern void fftwts3 ( );
    extern void fftwts3x ( );
    extern void fftwts5 ( );
    extern void fftwts5x ( );
    extern void fft_zip ( );
    extern void fft_zipd ( );
    extern void fft_zipdx ( );
    extern void fft_zipt ( );
    extern void fft_ziptd ( );
    extern void fft_ziptdx ( );
    extern void fft_ziptx ( );
    extern void fft_zipx ( );
    extern void fft_zop ( );
    extern void fft_zopd ( );
    extern void fft_zopdx ( );
    extern void fft_zopt ( );
    extern void fft_zoptd ( );
    extern void fft_zoptdx ( );
    extern void fft_zoptx ( );
    extern void fft_zopx ( );
    extern void fft_zrip ( );
    extern void fft_zripd ( );
    extern void fft_zripdx ( );
    extern void fft_zript ( );
    extern void fft_zriptd ( );
    extern void fft_zriptdx ( );
    extern void fft_zriptx ( );
    extern void fft_zripx ( );
    extern void fft_zrop ( );
    extern void fft_zropd ( );
    extern void fft_zropdx ( );
    extern void fft_zropt ( );
    extern void fft_zroptd ( );
    extern void fft_zroptdx ( );
    extern void fft_zroptx ( );
    extern void fft_zropx ( );
    extern void fft_zvmags ( );
    extern void fft_zvmagsx ( );
    extern void fir2 ( );
    extern void fir2x ( );
    extern void fir3 ( );
    extern void fir3x ( );
    extern void fixpixad ( );
    extern void fixpixadx ( );
    extern void fixpixb ( );
    extern void fixpixbd ( );
    extern void fixpixbdx ( );
    extern void fixpixbx ( );
    extern void flnz ( );
    extern void flnzx ( );
    extern void fltpixad ( );
    extern void fltpixadx ( );
    extern void fltpixb ( );
    extern void fltpixbd ( );
    extern void fltpixbdx ( );
    extern void fltpixbx ( );
    extern void *get_salcache ( );
    extern void hamm_window ( );
    extern void hamm_windowd ( );
    extern void hamm_windowdx ( );
    extern void hamm_windowx ( );
    extern void hann_window ( );
    extern void hann_windowd ( );
    extern void hann_windowdx ( );
    extern void hann_windowx ( );
    extern void hist ( );
    extern void histd ( );
    extern void histdx ( );
    extern void histx ( );
    extern void ihist ( );
    extern void ihist32 ( );
    extern void ihist32x ( );
    extern void ihistx ( );
    extern void imgfir ( );
    extern void imgfird ( );
    extern void imgfirdx ( );
    extern void imgfirx ( );
    extern void lveq ( );
    extern void lveqd ( );
    extern void lveqdx ( );
    extern void lveqi ( );
    extern void lveqix ( );
    extern void lveqx ( );
    extern void lvge ( );
    extern void lvged ( );
    extern void lvgedx ( );
    extern void lvgei ( );
    extern void lvgeix ( );
    extern void lvgex ( );
    extern void lvgt ( );
    extern void lvgtd ( );
    extern void lvgtdx ( );
    extern void lvgti ( );
    extern void lvgtix ( );
    extern void lvgtx ( );
    extern void lvle ( );
    extern void lvled ( );
    extern void lvledx ( );
    extern void lvlei ( );
    extern void lvleix ( );
    extern void lvlex ( );
    extern void lvlt ( );
    extern void lvltd ( );
    extern void lvltdx ( );
    extern void lvlti ( );
    extern void lvltix ( );
    extern void lvltx ( );
    extern void lvne ( );
    extern void lvned ( );
    extern void lvnedx ( );
    extern void lvnei ( );
    extern void lvneix ( );
    extern void lvnex ( );
    extern void lvnot ( );
    extern void lvnotd ( );
    extern void lvnotdx ( );
    extern void lvnoti ( );
    extern void lvnotix ( );
    extern void lvnotx ( );
    extern void mat_auto_mul ( );
    extern void mat_auto_muld ( );
    extern void mat_auto_muldx ( );
    extern void mat_auto_mulx ( );
    extern int mat_chol_dec( );
    extern int mat_chol_decx( );
    extern int mat_chol_sol( );
    extern int mat_chol_solx( );
    extern void matinv_lu ( );
    extern void matinv_lux ( );
    extern int mat_lud_dec( );
    extern int mat_lud_decx( );
    extern int mat_lud_sol( );
    extern int mat_lud_solx( );
    extern int mat_mgs_dec( );
    extern int mat_mgs_decx( );
    extern int mat_mgs_solr( );
    extern int mat_mgs_solrhr( );
    extern int mat_mgs_solrhrx( );
    extern int mat_mgs_solrx( );
    extern void mat_mul ( );
    extern void mat_muld ( );
    extern void mat_muldx ( );
    extern void mat_mulx ( );
    extern void maxmgv ( );
    extern void maxmgvd ( );
    extern void maxmgvdx ( );
    extern void maxmgvi ( );
    extern void maxmgvix ( );
    extern void maxmgvx ( );
    extern void maxv ( );
    extern void maxvd ( );
    extern void maxvdx ( );
    extern void maxvi ( );
    extern void maxvid ( );
    extern void maxvidx ( );
    extern void maxvix ( );
    extern void maxvx ( );
    extern void meamgv ( );
    extern void meamgvd ( );
    extern void meamgvdx ( );
    extern void meamgvx ( );
    extern void meanv ( );
    extern void meanvd ( );
    extern void meanvdx ( );
    extern void meanvx ( );
    extern void measqv ( );
    extern void measqvd ( );
    extern void measqvdx ( );
    extern void measqvx ( );
    extern void medf ( );
    extern void medf3x3 ( );
    extern void medf3x3d ( );
    extern void medf3x3dx ( );
    extern void medf3x3x ( );
    extern void medf5x5 ( );
    extern void medf5x5d ( );
    extern void medf5x5dx ( );
    extern void medf5x5x ( );
    extern void medfd ( );
    extern void medfdx ( );
    extern void medfx ( );
    extern void minmgv ( );
    extern void minmgvd ( );
    extern void minmgvdx ( );
    extern void minmgvi ( );
    extern void minmgvix ( );
    extern void minmgvx ( );
    extern void minv ( );
    extern void minvd ( );
    extern void minvdx ( );
    extern void minvi ( );
    extern void minvid ( );
    extern void minvidx ( );
    extern void minvix ( );
    extern void minvx ( );
    extern void mmov ( );
    extern void mmovd ( );
    extern void mmovdx ( );
    extern void mmovx ( );
    extern void mmuld ( );
    extern void mmuldx ( );
    extern void mtrans2 ( );
    extern void mtrans2d ( );
    extern void mtrans2dx ( );
    extern void mtrans2x ( );
    extern void mvessq ( );
    extern void mvessqx ( );
    extern void nzcros ( );
    extern void nzcrosx ( );
    extern void polar ( );
    extern void polard ( );
    extern void polardx ( );
    extern void polarx ( );
    extern void print_csal_version ( );
    extern void print_sal_version ( );
    extern void rect ( );
    extern void rectd ( );
    extern void rectdx ( );
    extern void rectx ( );
    extern int resamp_cicx ( );
    extern int resamp_cocx ( );
    extern int resamp_filter_close ( );
    extern int resamp_filter_create ( );
    extern int resamp_filter_create_user_alloc ( );
    extern int resamp_make_filter_set ( );
    extern int resamp_map_close ( );
    extern int resamp_map_create ( );
    extern int resamp_map_create_user_alloc ( );
    extern int resamp_mc_cicx ( );
    extern int resamp_mc_cocx ( );
    extern int resamp_mc_ricx ( );
    extern int resamp_mc_rocx ( );
    extern int resamp_mc_zicx ( );
    extern int resamp_mc_zocx ( );
    extern int resamp_mr_cicx ( );
    extern int resamp_mr_cocx ( );
    extern int resamp_mr_ricx ( );
    extern int resamp_mr_rocx ( );
    extern int resamp_mr_zicx ( );
    extern int resamp_mr_zocx ( );
    extern int resamp_ricx ( );
    extern int resamp_rocx ( );
    extern int resamp_zicx ( );
    extern int resamp_zocx ( );
    extern void rfft ( );
    extern void rfft2d ( );
    extern void rfft2dd ( );
    extern void rfft2ddx ( );
    extern void rfft2dx ( );
    extern void rfftb ( );
    extern void rfftbd ( );
    extern void rfftbdx ( );
    extern void rfftbx ( );
    extern void rfftd ( );
    extern void rfftdx ( );
    extern void rffto ( );
    extern void rfftod ( );
    extern void rfftodx ( );
    extern void rfftox ( );
    extern void rfftsc ( );
    extern void rfftscd ( );
    extern void rfftscdx ( );
    extern void rfftscx ( );
    extern void rfftx ( );
    extern void rmsqv ( );
    extern void rmsqvd ( );
    extern void rmsqvdx ( );
    extern void rmsqvx ( );
    extern void sal_74xx_set_nonjava ( );
    extern int sal_get_path ( );
    extern int sal_create( );
    extern int sal_init( );
    extern int sal_destroy( );
    extern int sal_print_info( );
    extern void set_salcache ( );
    extern void spin ( );
    extern void spind ( );
    extern void spindx ( );
    extern void spinx ( );
    extern void svdiv ( );
    extern void svdivx ( );
    extern void svdivx_fast ( );
    extern void sve ( );
    extern void sved ( );
    extern void svedx ( );
    extern void svemg ( );
    extern void svemgd ( );
    extern void svemgdx ( );
    extern void svemgx ( );
    extern void svesq ( );
    extern void svesqd ( );
    extern void svesqdx ( );
    extern void svesqx ( );
    extern void svex ( );
    extern void svs ( );
    extern void svsd ( );
    extern void svsdx ( );
    extern void svsx ( );
    extern void tconvl ( );
    extern void tconvlx ( );
    extern void trans ( );
    extern void transx ( );
    extern void unwrap_phase ( );
    extern void unwrap_phasex ( );
    extern void vaam ( );
    extern void vaamx ( );
    extern void vabmrg ( );
    extern void vabmrgx ( );
    extern void vabs ( );
    extern void vabsd ( );
    extern void vabsdx ( );
    extern void vabsi ( );
    extern void vabsix ( );
    extern void vabsx ( );
    extern void vadd ( );
    extern void vaddd ( );
    extern void vadddx ( );
    extern void vaddi ( );
    extern void vaddix ( );
    extern void vaddx ( );
    extern void vaint ( );
    extern void vaintx ( );
    extern void valog ( );
    extern void valogd ( );
    extern void valogdx ( );
    extern void valogx ( );
    extern void vam ( );
    extern void vamd ( );
    extern void vamdx ( );
    extern void vamerg ( );
    extern void vamergx ( );
    extern void vamx ( );
    extern void vandi ( );
    extern void vandix ( );
    extern void vasbm ( );
    extern void vasbmx ( );
    extern void vasm ( );
    extern void vasmx ( );
    extern void vatan ( );
    extern void vatan2 ( );
    extern void vatan2d ( );
    extern void vatan2dx ( );
    extern void vatan2x ( );
    extern void vatand ( );
    extern void vatandx ( );
    extern void vatanx ( );
    extern void vavexp ( );
    extern void vavexpx ( );
    extern void vavlin ( );
    extern void vavlinx ( );
    extern void vcache ( );
    extern void vclip ( );
    extern void vclipc ( );
    extern void vclipcx ( );
    extern void vclipd ( );
    extern void vclipdx ( );
    extern void vclipx ( );
    extern void vclr ( );
    extern void vclrd ( );
    extern void vclrdx ( );
    extern void vclrx ( );
    extern void vcmerg ( );
    extern void vcmergx ( );
    extern void vcmprs ( );
    extern void vcmprsx ( );
    extern void vconvert_cs16_zf32 ( );
    extern void vconvert_cs16_zf32x ( );
    extern void vconvert_cs32_zf32 ( );
    extern void vconvert_cs32_zf32x ( );
    extern void vconvert_cs8_zf32 ( );
    extern void vconvert_cs8_zf32x ( );
    extern void vconvert_cu16_zf32 ( );
    extern void vconvert_cu16_zf32x ( );
    extern void vconvert_cu32_zf32 ( );
    extern void vconvert_cu32_zf32x ( );
    extern void vconvert_cu8_zf32 ( );
    extern void vconvert_cu8_zf32x ( );
    extern void vconvert_endian2 ( );
    extern void vconvert_endian2x ( );
    extern void vconvert_endian4 ( );
    extern void vconvert_endian4x ( );
    extern void vconvert_endian8 ( );
    extern void vconvert_endian8x ( );
    extern void vconvert_f32_s16 ( );
    extern void vconvert_f32_s16x ( );
    extern void vconvert_f32_s32 ( );
    extern void vconvert_f32_s32x ( );
    extern void vconvert_f32_s8 ( );
    extern void vconvert_f32_s8x ( );
    extern void vconvert_f32_u16 ( );
    extern void vconvert_f32_u16x ( );
    extern void vconvert_f32_u32 ( );
    extern void vconvert_f32_u32x ( );
    extern void vconvert_f32_u8 ( );
    extern void vconvert_f32_u8x ( );
    extern void vconvert_s16_f32 ( );
    extern void vconvert_s16_f32x ( );
    extern void vconvert_s32_f32 ( );
    extern void vconvert_s32_f32x ( );
    extern void vconvert_s8_f32 ( );
    extern void vconvert_s8_f32x ( );
    extern void vconvert_u16_f32 ( );
    extern void vconvert_u16_f32x ( );
    extern void vconvert_u32_f32 ( );
    extern void vconvert_u32_f32x ( );
    extern void vconvert_u8_f32 ( );
    extern void vconvert_u8_f32x ( );
    extern void vconvert_zf32_cs16 ( );
    extern void vconvert_zf32_cs16x ( );
    extern void vconvert_zf32_cs32 ( );
    extern void vconvert_zf32_cs32x ( );
    extern void vconvert_zf32_cs8 ( );
    extern void vconvert_zf32_cs8x ( );
    extern void vconvert_zf32_cu16 ( );
    extern void vconvert_zf32_cu16x ( );
    extern void vconvert_zf32_cu32 ( );
    extern void vconvert_zf32_cu32x ( );
    extern void vconvert_zf32_cu8 ( );
    extern void vconvert_zf32_cu8x ( );
    extern void vcos ( );
    extern void vcosd ( );
    extern void vcosdx ( );
    extern void vcosx ( );
    extern void vdbcon ( );
    extern void vdbconx ( );
    extern void vdist ( );
    extern void vdistd ( );
    extern void vdistdx ( );
    extern void vdistx ( );
    extern void vdiv ( );
    extern void vdivd ( );
    extern void vdivdx ( );
    extern void vdivi ( );
    extern void vdivix ( );
    extern void vdivx ( );
    extern void vdivz ( );
    extern void vdivzx ( );
    extern void vdpsp ( );
    extern void vdpspx ( );
    extern void venvlp ( );
    extern void venvlpd ( );
    extern void venvlpdx ( );
    extern void venvlpx ( );
    extern void veqvi ( );
    extern void veqvix ( );
    extern void vexp ( );
    extern void vexpd ( );
    extern void vexpdx ( );
    extern void vexpx ( );
    extern void vfill ( );
    extern void vfilld ( );
    extern void vfilldx ( );
    extern void vfilli ( );
    extern void vfillix ( );
    extern void vfillx ( );
    extern void vfixd ( );
    extern void vfixdx ( );
    extern void vfixr32 ( );
    extern void vfixr32d ( );
    extern void vfixr32dx ( );
    extern void vfixr32x ( );
    extern void vfixrd ( );
    extern void vfixrdx ( );
    extern void vflt16 ( );
    extern void vflt16x ( );
    extern void vflt32d ( );
    extern void vflt32dx ( );
    extern void vflt8 ( );
    extern void vflt8x ( );
    extern void vfltd ( );
    extern void vfltdx ( );
    extern void vfltu16 ( );
    extern void vfltu16x ( );
    extern void vfltu32d ( );
    extern void vfltu32dx ( );
    extern void vfltud ( );
    extern void vfltudx ( );
    extern void vfrac ( );
    extern void vfracd ( );
    extern void vfracdx ( );
    extern void vfracx ( );
    extern void vgathr ( );
    extern void vgathra ( );
    extern void vgathrad ( );
    extern void vgathradx ( );
    extern void vgathrax ( );
    extern void vgathrd ( );
    extern void vgathrdx ( );
    extern void vgathrx ( );
    extern void vgen ( );
    extern void vgenp ( );
    extern void vgenpx ( );
    extern void vgenx ( );
    extern void viclip ( );
    extern void viclipx ( );
    extern void vimag ( );
    extern void vimagd ( );
    extern void vimagdx ( );
    extern void vimagx ( );
    extern void vindex ( );
    extern void vindexx ( );
    extern void vintb ( );
    extern void vintbx ( );
    extern void vlim ( );
    extern void vlimd ( );
    extern void vlimdx ( );
    extern void vlimx ( );
    extern void vlint ( );
    extern void vlintx ( );
    extern void vlmerg ( );
    extern void vlmergx ( );
    extern void vln ( );
    extern void vlnd ( );
    extern void vlndx ( );
    extern void vlnm ( );
    extern void vlnmx ( );
    extern void vlnmz ( );
    extern void vlnmzx ( );
    extern void vlnx ( );
    extern void vlnz ( );
    extern void vlnzx ( );
    extern void vlog ( );
    extern void vlogd ( );
    extern void vlogdx ( );
    extern void vlogm ( );
    extern void vlogmx ( );
    extern void vlogmz ( );
    extern void vlogmzx ( );
    extern void vlogx ( );
    extern void vlogz ( );
    extern void vlogzx ( );
    extern void vma ( );
    extern void vmad ( );
    extern void vmadx ( );
    extern void vmax ( );
    extern void vma_x ( );
    extern void vmaxd ( );
    extern void vmaxdx ( );
    extern void vmaxmg ( );
    extern void vmaxmgd ( );
    extern void vmaxmgdx ( );
    extern void vmaxmgx ( );
    extern void vmaxx ( );
    extern void vmin ( );
    extern void vmind ( );
    extern void vmindx ( );
    extern void vminmg ( );
    extern void vminmgd ( );
    extern void vminmgdx ( );
    extern void vminmgx ( );
    extern void vminx ( );
    extern void vmma ( );
    extern void vmmax ( );
    extern void vmmsb ( );
    extern void vmmsbx ( );
    extern void vmov ( );
    extern void vmovd ( );
    extern void vmovdx ( );
    extern void vmovi ( );
    extern void vmovix ( );
    extern void vmovx ( );
    extern void vmsa ( );
    extern void vmsad ( );
    extern void vmsadx ( );
    extern void vmsax ( );
    extern void vmsb ( );
    extern void vmsbd ( );
    extern void vmsbdx ( );
    extern void vmsbx ( );
    extern void vmul ( );
    extern void vmuld ( );
    extern void vmuldx ( );
    extern void vmuli ( );
    extern void vmulix ( );
    extern void vmulx ( );
    extern void vnabs ( );
    extern void vnabsx ( );
    extern void vneg ( );
    extern void vnegd ( );
    extern void vnegdx ( );
    extern void vnegi ( );
    extern void vnegix ( );
    extern void vnegx ( );
    extern void vori ( );
    extern void vorix ( );
    extern void vpmerg ( );
    extern void vpmergx ( );
    extern void vpoly ( );
    extern void vpolyd ( );
    extern void vpolydx ( );
    extern void vpolyx ( );
    extern void vpythg ( );
    extern void vpythgx ( );
    extern void vqint ( );
    extern void vqintx ( );
    extern void vramp ( );
    extern void vrampd ( );
    extern void vrampdx ( );
    extern void vrampi ( );
    extern void vrampix ( );
    extern void vrampx ( );
    extern void vreal ( );
    extern void vreald ( );
    extern void vrealdx ( );
    extern void vrealx ( );
    extern void vrecip ( );
    extern void vrecipx ( );
    extern void vrecipx_fast ( );
    extern void vrsqrt ( );
    extern void vrsqrtd ( );
    extern void vrsqrtdx ( );
    extern void vrsqrtx ( );
    extern void vrsum ( );
    extern void vrsumx ( );
    extern void vrvrs ( );
    extern void vrvrsx ( );
    extern void vsadd ( );
    extern void vsaddd ( );
    extern void vsadddx ( );
    extern void vsaddi ( );
    extern void vsaddix ( );
    extern void vsaddx ( );
    extern void vsbm ( );
    extern void vsbmd ( );
    extern void vsbmdx ( );
    extern void vsbmx ( );
    extern void vsbsbm ( );
    extern void vsbsbmx ( );
    extern void vsbsm ( );
    extern void vsbsmx ( );
    extern void vscal ( );
    extern void vscald ( );
    extern void vscaldx ( );
    extern void vscalx ( );
    extern void vscatr ( );
    extern void vscatra ( );
    extern void vscatrad ( );
    extern void vscatradx ( );
    extern void vscatrax ( );
    extern void vscatrd ( );
    extern void vscatrdx ( );
    extern void vscatrx ( );
    extern void vsdiv ( );
    extern void vsdivd ( );
    extern void vsdivdx ( );
    extern void vsdivi ( );
    extern void vsdivix ( );
    extern void vsdivx ( );
    extern void vsimps ( );
    extern void vsimpsx ( );
    extern void vsin ( );
    extern void vsind ( );
    extern void vsindx ( );
    extern void vsinx ( );
    extern void vsma ( );
    extern void vsmad ( );
    extern void vsmadx ( );
    extern void vsmax ( );
    extern void vsmsa ( );
    extern void vsmsad ( );
    extern void vsmsadx ( );
    extern void vsmsax ( );
    extern void vsmsb ( );
    extern void vsmsbd ( );
    extern void vsmsbdx ( );
    extern void vsmsbx ( );
    extern void vsmul ( );
    extern void vsmuld ( );
    extern void vsmuldx ( );
    extern void vsmuli ( );
    extern void vsmulix ( );
    extern void vsmulx ( );
    extern void vsort ( );
    extern void vsorti ( );
    extern void vsortix ( );
    extern void vsortx ( );
    extern void vspdp ( );
    extern void vspdpx ( );
    extern void vsq ( );
    extern void vsqd ( );
    extern void vsqdx ( );
    extern void vsqrt ( );
    extern void vsqrtd ( );
    extern void vsqrtdx ( );
    extern void vsqrtx ( );
    extern void vsqrtz ( );
    extern void vsqrtzx ( );
    extern void vsqx ( );
    extern void vssq ( );
    extern void vssqd ( );
    extern void vssqdx ( );
    extern void vssqx ( );
    extern void vsub ( );
    extern void vsubd ( );
    extern void vsubdx ( );
    extern void vsubi ( );
    extern void vsubix ( );
    extern void vsubx ( );
    extern void vswap ( );
    extern void vswapd ( );
    extern void vswapdx ( );
    extern void vswapx ( );
    extern void vswsum ( );
    extern void vswsumx ( );
    extern void vtabi ( );
    extern void vtabid ( );
    extern void vtabidx ( );
    extern void vtabix ( );
    extern void vtan ( );
    extern void vtanx ( );
    extern void vthr ( );
    extern void vthres ( );
    extern void vthresd ( );
    extern void vthresdx ( );
    extern void vthresx ( );
    extern void vthrsc ( );
    extern void vthrscx ( );
    extern void vthrx ( );
    extern void vtmerg ( );
    extern void vtmergx ( );
    extern void vtrapz ( );
    extern void vtrapzx ( );
    extern void warp ( );
    extern void warpd ( );
    extern void warpdx ( );
    extern void warpx ( );
    extern void wiener ( );
    extern void wienerx ( );
    extern void zaspec ( );
    extern void zaspecd ( );
    extern void zaspecdx ( );
    extern void zaspecx ( );
    extern void zcoher ( );
    extern void zcoherd ( );
    extern void zcoherdx ( );
    extern void zcoherx ( );
    extern void zconv ( );
    extern void zconv2d ( );
    extern void zconv2dx ( );
    extern void zconvx ( );
    extern void zcspec ( );
    extern void zcspecx ( );
    extern void zdotpr ( );
    extern void zdotprd ( );
    extern void zdotprdx ( );
    extern void zdotprx ( );
    extern void zexpmul ( );
    extern void zexpmuld ( );
    extern void zexpmuldx ( );
    extern void zexpmulx ( );
    extern void zexptab ( );
    extern void zexptabd ( );
    extern void zexptabdx ( );
    extern void zexptabx ( );
    extern void zidotpr ( );
    extern void zidotprd ( );
    extern void zidotprdx ( );
    extern void zidotprx ( );
    extern void zimul ( );
    extern void zimuld ( );
    extern void zimuldx ( );
    extern void zimulx ( );
    extern void zmat_auto_mul ( );
    extern void zmat_auto_muld ( );
    extern void zmat_auto_muldx ( );
    extern void zmat_auto_mulx ( );
    extern int zmat_chol_dec( );
    extern int zmat_chol_decx( );
    extern int zmat_chol_sol( );
    extern int zmat_chol_solx( );
    extern int zmatherm_eig ( );
    extern int zmatherm_eigx ( );
    extern void zmatinv_lu ( );
    extern void zmatinv_lux ( );
    extern int zmat_lud_dec( );
    extern int zmat_lud_decx( );
    extern int zmat_lud_sol( );
    extern int zmat_lud_solx( );
    extern int zmat_mgs_dec( );
    extern int zmat_mgs_decx( );
    extern int zmat_mgs_solr( );
    extern int zmat_mgs_solrhr( );
    extern int zmat_mgs_solrhrx( );
    extern int zmat_mgs_solrx( );
    extern void zmat_mul ( );
    extern void zmat_muld ( );
    extern void zmat_muldx ( );
    extern void zmat_mulx ( );
    extern void zmixer ( );
    extern void zmixerx ( );
    extern void zmma ( );
    extern void zmmax ( );
    extern void zmmov ( );
    extern void zmmovd ( );
    extern void zmmovdx ( );
    extern void zmmovx ( );
    extern void zmms ( );
    extern void zmmsx ( );
    extern void zmmuld ( );
    extern void zmmuldx ( );
    extern void zmsm ( );
    extern void zmsmx ( );
    extern void zmtrans2 ( );
    extern void zmtrans2d ( );
    extern void zmtrans2dx ( );
    extern void zmtrans2x ( );
    extern void zoher ( );
    extern void zoherd ( );
    extern void zoherdx ( );
    extern void zoherx ( );
    extern void zrdesamp ( );
    extern void zrdesampx ( );
    extern void zrdotpr ( );
    extern void zrdotprd ( );
    extern void zrdotprdx ( );
    extern void zrdotprx ( );
    extern void zrmixer ( );
    extern void zrmixerx ( );
    extern void zrvadd ( );
    extern void zrvaddd ( );
    extern void zrvadddx ( );
    extern void zrvaddx ( );
    extern void zrvdiv ( );
    extern void zrvdivd ( );
    extern void zrvdivdx ( );
    extern void zrvdivx ( );
    extern void zrvmul ( );
    extern void zrvmuld ( );
    extern void zrvmuldx ( );
    extern void zrvmulx ( );
    extern void zrvsub ( );
    extern void zrvsubd ( );
    extern void zrvsubdx ( );
    extern void zrvsubx ( );
    extern void zspec ( );
    extern void zspecd ( );
    extern void zspecdx ( );
    extern void zspecx ( );
    extern void ztoc ( );
    extern void ztocd ( );
    extern void ztocdx ( );
    extern void ztocx ( );
    extern void ztrans ( );
    extern void ztransd ( );
    extern void ztransdx ( );
    extern void ztransx ( );
    extern void zvabs ( );
    extern void zvabsd ( );
    extern void zvabsdx ( );
    extern void zvabsx ( );
    extern void zvadd ( );
    extern void zvaddd ( );
    extern void zvadddx ( );
    extern void zvaddx ( );
    extern void zvcma ( );
    extern void zvcmad ( );
    extern void zvcmax ( );
    extern void zvcmul ( );
    extern void zvcmuld ( );
    extern void zvcmuldx ( );
    extern void zvcmulx ( );
    extern void zvcomb ( );
    extern void zvcombd ( );
    extern void zvcombdx ( );
    extern void zvcombx ( );
    extern void zvconj ( );
    extern void zvconjd ( );
    extern void zvconjdx ( );
    extern void zvconjx ( );
    extern void zvdbcon ( );
    extern void zvdbconx ( );
    extern void zvdiv ( );
    extern void zvdivd ( );
    extern void zvdivdx ( );
    extern void zvdivx ( );
    extern void zvdivx_fast ( );
    extern void zvexp ( );
    extern void zvexpd ( );
    extern void zvexpdx ( );
    extern void zvexpm ( );
    extern void zvexpmd ( );
    extern void zvexpmdx ( );
    extern void zvexpmx ( );
    extern void zvexpx ( );
    extern void zvfill ( );
    extern void zvfilld ( );
    extern void zvfilldx ( );
    extern void zvfillx ( );
    extern void zvimag ( );
    extern void zvimagd ( );
    extern void zvimagdx ( );
    extern void zvimagx ( );
    extern void zvmags ( );
    extern void zvmagsd ( );
    extern void zvmagsdx ( );
    extern void zvmagsx ( );
    extern void zvmgsa ( );
    extern void zvmgsad ( );
    extern void zvmgsadx ( );
    extern void zvmgsax ( );
    extern void zvmov ( );
    extern void zvmovd ( );
    extern void zvmovdx ( );
    extern void zvmovx ( );
    extern void zvmul ( );
    extern void zvmuld ( );
    extern void zvmuldx ( );
    extern void zvmulx ( );
    extern void zvneg ( );
    extern void zvnegd ( );
    extern void zvnegdx ( );
    extern void zvnegx ( );
    extern void zvphas ( );
    extern void zvphasd ( );
    extern void zvphasdx ( );
    extern void zvphasx ( );
    extern void zvrcip ( );
    extern void zvrcipd ( );
    extern void zvrcipdx ( );
    extern void zvrcipx ( );
    extern void zvrcipx_fast ( );
    extern void zvreal ( );
    extern void zvreald ( );
    extern void zvrealdx ( );
    extern void zvrealx ( );
    extern void zvsma ( );
    extern void zvsmad ( );
    extern void zvsmadx ( );
    extern void zvsmax ( );
    extern void zvsqrt ( );
    extern void zvsqrtd ( );
    extern void zvsqrtdx ( );
    extern void zvsqrtx ( );
    extern void zvsub ( );
    extern void zvsubd ( );
    extern void zvsubdx ( );
    extern void zvsubx ( );
    extern void zvzsml ( );
    extern void zvzsmld ( );
    extern void zvzsmldx ( );

#endif

#define SAL__EMPTY()
#define SAL_SINGLE( _fn ) _fn SAL__EMPTY()

#ifdef __cplusplus
}
#endif

#endif

