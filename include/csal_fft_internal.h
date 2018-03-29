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
        csal_fft_internal.h

----------------------------------------------------------------------------
*/

#ifndef CSAL_FFT_INTERNAL_H
#define CSAL_FFT_INTERNAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "csal_internal.h"

#define FFT_SETUP_STRUCT_ALIGN    16

#define  FFT3_B1 ( -1.5                    )
#define  FFT3_B2 (  0.86602540378443864676 )

#define  FFT6_C1 (  0.5                    )
#define  FFT6_S1 (  0.86602540378443864676 )
#define  FFT6_T1 (  1.73205080756887729353 )
#define  FFT6_C2 ( -0.5                    )
#define  FFT6_S2 (  0.86602540378443864676 )
#define  FFT6_T2 ( -1.73205080756887729353 )

#define  FFT5_B1    ( -1.25                   )
#define  FFT5_B2    (  0.55901699437494742410 )
#define  FFT5_B3    (  0.95105651629515357212 )
#define  FFT5_B4    ( -1.53884176858762670129 )
#define  FFT5_B5    ( -0.36327126400268044295 )
#define  FFT5_B4vB3 ( -1.61803398874989484820 )
#define  FFT5_B5vB3 ( -0.38196601125010515180 )

#define  FFT8_SQRT2v2 ( 0.70710678118654752440 )

#define  FFT10_C1 (  0.80901699437494742410 )
#define  FFT10_S1 (  0.58778525229247312917 )
#define  FFT10_T1 (  0.72654252800536088590 )
#define  FFT10_C2 (  0.30901699437494742410 )
#define  FFT10_S2 (  0.95105651629515357212 )
#define  FFT10_T2 (  3.07768353717525340257 ) 
#define  FFT10_C3 ( -0.30901699437494742410 ) 
#define  FFT10_S3 (  0.95105651629515357212 )
#define  FFT10_T3 ( -3.07768353717525340257 )
#define  FFT10_C4 ( -0.80901699437494742410 )
#define  FFT10_S4 (  0.58778525229247312917 )
#define  FFT10_T4 ( -0.72654252800536088590 )

#define ROUNDUP_16( value ) \
    (((SAL_ui32 )(value) + 15U) & ~15U)

#define ROUNDUP_16L( value ) \
    (((unsigned long)(value) + 15UL) & ~15UL)

#define ROUND_UP_POW2L( x, mult_pow2 ) \
    ( ((unsigned long)(x) + (mult_pow2) - 1) & (unsigned long)(~((mult_pow2) - 1)) )

#define  TWOPI_CONSTANT ( ( SAL_f64 ) 6.2831853071795864769252868 )

    typedef struct
    {
        SAL_i32 *iA;
        SAL_i32 *iG;
        SAL_i32 *iBr;
        SAL_i32 *iW;
        SAL_i32 *iC;
    } FFT_C_TABLES;

    typedef struct
    {
        SAL_f32 *Ws;
        SAL_f32 *Wsc;
        SAL_i32  LN;
        SAL_i32  _pad;
    } FFT_C_WEIGHTS;

    typedef struct
    {
        FFT_C_WEIGHTS W;
        FFT_C_TABLES IT;
        SAL_i32      nbytes;
        SAL_i32     _pad;
    } FFT_C_1D;

    typedef struct
    {
        SAL_cf32     *Wxy;
        SAL_cf32     *Wxy_fcs;
        SAL_cf32     *Cachep;
        FFT_C_WEIGHTS Wx;
        FFT_C_TABLES  ITx;
        SAL_i32      *iSx;
        SAL_i32       Lnx;
        SAL_i32       Lnqx;
        FFT_C_WEIGHTS Wy;
        FFT_C_TABLES  ITy;
        SAL_i32      *iSy;
        SAL_i32       Lny;
        SAL_i32       Lnqy;
        SAL_i32       nbytes;
        SAL_i32      _pad;
    } FFT_C_XY;

    typedef struct
    {
        SAL_cf32     *CacheP;
        SAL_i32      *iSx;
        SAL_i32      *iSy;
        FFT_C_WEIGHTS Wx;
        FFT_C_TABLES  ITx;
        FFT_C_WEIGHTS Wy;
        FFT_C_TABLES  ITy;
        SAL_i32       LNqx;
        SAL_i32       LNqy;
        SAL_i32       nbytes;
        SAL_i32      _pad;
    } FFT_C_2D;

#define LN_FFT_C_MIN         (                  4 )
#define LN_FFT_C_THRESHOLD   (                 12 )
#define LN_FFT2D_C_MAX       ( LN_FFT_C_THRESHOLD )
#define LN_FFT2D_C_THRESHOLD (                  8 )


#define FFT_C_CACHEBLK    ( 1024 )
#define LN_FFT_C_CACHEBLK (   10 )

#define FFT_SETUP_NUM_TABLES ( 24 )

    typedef struct
    {
        SAL_cf32 *c;
        SAL_ui32  m;
        SAL_ui32  n;
        SAL_ui32  LOG2_m;
        SAL_f32   TWOPI_V_m;
        SAL_f32   ONE_V_m;
        SAL_f32   TWOPI;
        SAL_f32   SQRT_2_V_2;
        SAL_i32  _pad64;
    } FFT_TABLE;

    typedef struct
    {
        SAL_cf64 *c;
        SAL_i32  _pad32a;
        SAL_f64   TWOPI_V_m;
        SAL_f64   ONE_V_m;
        SAL_f64   TWOPI;
        SAL_f64   SQRT_2_V_2;
        SAL_ui32  m;
        SAL_ui32  n;
        SAL_ui32  LOG2_m;
        SAL_i32  _pad32b;
    } FFTD_TABLE;

    typedef struct sal__fft_setup_csal
    {
        void     *handle;
        SAL_zf32  twids;
        SAL_zf32  radix3_twids;
        SAL_zf32  radix5_twids;
        SAL_zf32  radix9_twids;
        SAL_ui32  log2m;
        SAL_i32  _pad64;

        struct
        {
            SAL_cf32 *twidp;
            SAL_cf32 *xy_twidp;
            SAL_ui32  log2x;
            SAL_ui32  log2y;
            SAL_ui32  log2mxy;
            SAL_ui32  stripx;
            SAL_ui32  stripy;
            SAL_i32  _pad;
        } big_radix2;
        struct
        {
            SAL_f32 *bitr_twidp;
            struct
            {
                SAL_f32  *bitr_twidp;
                SAL_f32  *rpass_twidp;
                SAL_ui8  *bitr_tabp;
                SAL_char *spare;
            } tables[ FFT_SETUP_NUM_TABLES ];
            struct
            {
                SAL_cf32 *xy_twidp;
                SAL_ui32  log2x;
                SAL_ui32  log2y;
                SAL_ui32  log2mxy;
                SAL_ui32  stripx;
                SAL_ui32  stripy;
                SAL_ui32  strip_size;
            } big_radix2;
            SAL_cf32 *fc_rpass_twidp;
            struct
            {
                SAL_cf32 *xy_twidp;
                SAL_ui32  log2x;
                SAL_ui32  log2y;
                SAL_ui32  log2mxy;
                SAL_ui32  stripx;
                SAL_ui32  stripy;
                SAL_ui32  strip_size;
            } big_radix3;
            SAL_cf32 *radix3_rpass_twidp;
            struct
            {
                SAL_cf32 *xy_twidp;
                SAL_ui32  log2x;
                SAL_ui32  log2y;
                SAL_ui32  log2mxy;
                SAL_ui32  stripx;
                SAL_ui32  stripy;
                SAL_ui32  strip_size;
            } big_radix5;
            SAL_cf32 *radix5_rpass_twidp;

            FFT_C_1D *setup_c_1d;
            FFT_C_XY *setup_c_1dxy;
            FFT_C_XY *setup_ct_1dxy;
            FFT_C_2D *setup_c_2d;

        } vmx;
        void *hmem_cf32;

        struct
        {
            SAL_zf32 complex_twidp;
            SAL_ui32 complex_log2x;
            SAL_ui32 complex_log2y;

            SAL_zf32 real_twidp;
            SAL_ui32 real_log2x;
            SAL_ui32 real_log2y;

            void *tempp;

            SAL_i32 foo;
        } aux;
        SAL_i32 bar;

        SAL_i32  fft_type_flags;
        SAL_ui32 NBYTESP;
    } SAL__fft_setup_csal;

    typedef struct sal__fft_setupd_csal
    {
        void     *handle;
        SAL_f64  *real_twidp;
        SAL_f64  *imag_twidp;
        SAL_cf64 *radix3_twidp_0;
        SAL_cf64 *radix3_twidp_1;
        SAL_cf64 *radix5_twidp_0;
        SAL_cf64 *radix5_twidp_1;
        SAL_ui32  m;
        SAL_ui32  log2m;
        SAL_i32   fft_type_flags;
        SAL_ui32  NBYTESP;
    } SAL__fft_setupd_csal;

    typedef struct sal__fft_setup_mcsal
    {
    } SAL__fft_setup_mcsal;

    typedef struct sal__fft_setup_config_base
    {
        SAL_ui32 fft_type;
        SAL_ui32 fft_type_flags;
        SAL_i32  log2m;
        SAL_i32  log2n;

        void *alloc_addr;
        void *buffer;

        SAL_i32 nbytes;
        SAL_i32 is_user_managed;
    } SAL__fft_setup_config_base;

#define COSINE_TWIDDLED( angle_delta, angle ) \
    ( ( cos ( (angle_delta) * (SAL_f64) (angle) ) ) )

#define COSINE_TWIDDLE( angle_delta, angle ) \
    ( (SAL_f32) COSINE_TWIDDLED( angle_delta, angle ) )

#define SINE_TWIDDLED( angle_delta, angle ) \
    ( ( sin ( (angle_delta) * (SAL_f64) (angle) ) ) )

#define SINE_TWIDDLE( angle_delta, angle ) \
    ( (SAL_f32) SINE_TWIDDLED( angle_delta, angle ) )

    extern FFT_TABLE  PREFIX ( fftwts_tab );
    extern FFTD_TABLE PREFIX ( fftwtsd_tab );

    extern void PREFIX ( _csal_bitr ) ( SAL_f32 *A, SAL_i32 LOG2N );
    extern void PREFIX ( _csal_bitrd ) ( SAL_f64 *A, SAL_i32 LOG2N );

    extern void PREFIX ( _csal_cfftsm ) ( SAL_f32 *A, SAL_i32 stride, SAL_i32 N, SAL_i32 F, SAL_i32 BRFLAG );
    extern void PREFIX ( _csal_cfftsmd ) ( SAL_f64 *C, SAL_i32 stride, SAL_i32 N, SAL_i32 F, SAL_i32 BRFLAG );

    extern void  PREFIX ( _csal_fft_rad3 ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 N, SAL_i32 FLAG );
    extern void  PREFIX ( _csal_fft_rad3d ) ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 N, SAL_i32 FLAG );

    extern void  PREFIX ( _csal_fft_rad5 ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 N, SAL_i32 FLAG );
    extern void  PREFIX ( _csal_fft_rad5d ) ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 N, SAL_i32 FLAG );

    extern void  PREFIX ( _csal_fft3_rpd ) ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 LOG2M, SAL_f64 *WR, SAL_f64 *WI, SAL_i32 FLAG );
    extern void  PREFIX ( _csal_fft5_rpd ) ( SAL_f64 *A, SAL_i32 I, SAL_f64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 LOG2M, SAL_f64 *WR, SAL_f64 *WI, SAL_i32 FLAG );

    extern void  PREFIX ( _csal_fft3_zb ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setup *setupp );
    extern void  PREFIX ( _csal_fft5_zb ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setup *setupp );

    extern void  PREFIX ( _csal_fft3_zrp ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setup *setupp );
    extern void  PREFIX ( _csal_fft5_zrp ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setup *setupp );

    extern void  PREFIX ( _csal_fft3_zrpd ) ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 LOG2M, SAL_f64 *WR, SAL_f64 *WI, SAL_i32 FLAG );
    extern void  PREFIX ( _csal_fft5_zrpd ) ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_ui32 LOG2M, SAL_f64 *WR, SAL_f64 *WI, SAL_i32 FLAG );

    extern void PREFIX ( _csal_fft3_small ) ( SAL_f32 *Ar, SAL_f32 *Ai, SAL_i32 I, SAL_f32 *Cr, SAL_f32 *Ci, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FI_FLAG );
    extern void PREFIX ( _csal_fft5_small ) ( SAL_f32 *Ar, SAL_f32 *Ai, SAL_i32 I, SAL_f32 *Cr, SAL_f32 *Ci, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FI_FLAG );

    extern void  PREFIX ( _csal_fft9_zb ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setup *setupp );

    extern void PREFIX ( _csal_fft_twiddles ) ( SAL_f32 *WR, SAL_f32 *WI, SAL_ui32 LOG2M );
    extern void PREFIX ( _csal_fft_twiddles3 ) ( SAL_f32 *WR, SAL_f32 *WI, SAL_ui32 LOG2M );
    extern void PREFIX ( _csal_fft_twiddles5 ) ( SAL_f32 *WR, SAL_f32 *WI, SAL_ui32 LOG2M );
    extern void PREFIX ( _csal_fft_twiddles9 ) ( SAL_f32 *WR, SAL_f32 *WI, SAL_ui32 LOG2M );

    extern void PREFIX ( _csal_fft_twiddlesd ) ( SAL_f64 *WR, SAL_f64 *WI, SAL_ui32 LOG2M );
    extern void PREFIX ( _csal_fft_twiddles3d ) ( SAL_cf64 *W0, SAL_cf64 *W1, SAL_ui32 LOG2M );
    extern void PREFIX ( _csal_fft_twiddles5d ) ( SAL_cf64 *W0, SAL_cf64 *W1, SAL_ui32 LOG2M );

    extern void  PREFIX ( _csal_fft_bitr ) ( SAL_f32 *C, SAL_i32 K, SAL_i32 KR, SAL_ui32 LOG2N );
    extern void  PREFIX ( _csal_fft_bitrd ) ( SAL_f64 *C, SAL_i32 K, SAL_i32 KR, SAL_ui32 LOG2N );

    extern void  PREFIX ( _csal_fft_zbitr ) ( SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N );
    extern void  PREFIX ( _csal_fft_zbitrd ) ( SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N );

    extern void  PREFIX ( _csal_fft_zd ) ( SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLA, FFT_setupd *setup );
    extern void  PREFIX ( _csal_fft_zb ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setup *setupp );
    extern void  PREFIX ( _csal_fft_zbd ) ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *B, SAL_i32 J, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setupd *setup );

    extern void  PREFIX ( _csal_fft_cd ) ( SAL_cf64 *A, SAL_i32 I, SAL_cf64 *B, SAL_i32 J, SAL_cf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setupd *setup );

    extern void  PREFIX ( _csal_fft_z ) ( SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setup *setupp );

    extern void  PREFIX ( _csal_fft_c ) ( SAL_cf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setup *setupp );

    extern void  PREFIX ( _csal_fft_zrp ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setup *setupp );
    extern void  PREFIX ( _csal_fft_zrpd ) ( SAL_zf64 *A, SAL_i32 I, SAL_zf64 *C, SAL_i32 K, SAL_ui32 LOG2N, SAL_i32 FLAG, FFT_setupd *setup );

    extern void  PREFIX ( _csal_zvmul ) ( SAL_zf32 *A, SAL_i32 I, SAL_zf32 *B, SAL_i32 J, SAL_zf32 *C, SAL_i32 K, SAL_ui32 N, SAL_i32 F );

    extern SAL_i32  sal__fft_setup_cf32 ( SAL__fft_setup_csal * setupp, SAL_ui32  log2m, SAL_ui32  *pnbytes, void *pbuffer );

    extern SAL_ui32 PREFIX( fft_type_flag_lookup )( const SAL_ui32 fft_type );

    extern void sal__fft_setup_aux_zf32 ( SAL_i32 Ln, SAL_i32 Lnx, SAL_ui32 *nbytesp, SAL_zf32 *twidsp );

#ifdef __cplusplus
}
#endif

#endif

