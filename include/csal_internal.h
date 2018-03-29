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
        csal_internal.h

----------------------------------------------------------------------------
*/

#ifndef CSAL_INTERNAL_H
#define CSAL_INTERNAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <math.h>
#include "sal.h"
#include "sal_macros.h"
#include "sal_csal_common_internal.h"

#define  ONE_PI   ( 3.14159265358979323846 )
#define  TWO_PI   ( 6.28318530717958647693 )
#define  TWO_PIV3 ( 2.09439510239319549231 )
#define  TWO_PIV5 ( 1.25663706143591729539 )
#define  TWO_PIV9 ( 0.69813170079773183077 )

#define  TWO_PI_RECP       ( 0.15915494309189533577    )
#define  TWO_PI_V_POW2_32  ( 1.46291807926715968105e-9 )

#define  POW2_32           ( 4294967296.0 )

#define  SQRT2V2           ( 0.70710678118654752440 )
#define  LN10              ( 2.30258509299404568402 )

#define  FP_EXPONENT_SHIFT ( 23UL )
#define  DP_EXPONENT_SHIFT ( 46UL )

#define  MAX_S8  (  0x7fL )
#define  MIN_S8  ( ~0x7fL )
#define  MAX_S16 (  0x7fffL )
#define  MIN_S16 ( ~0x7fffL )
#define  MAX_S32 (  0x7fffffffL )
#define  MIN_S32 ( ~0x7fffffffL )

#define  MAX_U8  ( 0xffUL )
#define  MIN_U8  ( 0UL    )
#define  MAX_U16 ( 0xffffUL )
#define  MIN_U16 (      0UL )
#define  MAX_U32 ( 0xffffffffUL )
#define  MIN_U32 (          0UL )

#define BASE_SUFFIX(func) PREFIX(func##_base)
#define CSAL_SUFFIX(func) PREFIX(func##_csal)

#define SAL__MASK_TRANSPOSE ( SAL_TRANSPOSE_LEFT | SAL_TRANSPOSE_RIGHT )

#define SWAP( A, B ) { t = A; A = B; B = t; }

#define CSAL_MAX( a, b ) (( (a)>(b) ) ? (a) : (b))
#define CSAL_MIN( a, b ) (( (a)<(b) ) ? (a) : (b))

#define ROUND_DOWN_POW2( x, mult_pow2 ) \
    ( (u)(x) & (unsigned long)(~((mult_pow2) - 1)) )

#define ROUND_UP_POW2( x, mult_pow2 ) \
    ( ((unsigned long)(x) + (mult_pow2) - 1) & (unsigned long)(~((mult_pow2) - 1)) )

#define  SAL_ROUND_MASK  ( SAL_ROUND_ZERO | SAL_ROUND_NEAREST | \
                           SAL_ROUND_UP | SAL_ROUND_DOWN )
#define  SAL_FIELD_MASK  ( SAL_FIELD_NOSATURATE | SAL_FIELD_SATURATE )

#define  F32_FIX_ZERO( f32, fix_type, output ) \
    output = (fix_type)(f32);

#define  F32_FIX_NEAREST_SIGNED( f32, fix_type, output ) \
    { \
        if ( (f32) >= 0.0 ) { \
            output = (fix_type)((f32) + 0.5); \
            if ( ((SAL_f32)(output) - (f32)) == 0.5 ) output &= ~1UL; \
        } \
        else { \
            output = (fix_type)((f32) - 0.5); \
            if ( ((SAL_f32)(output) - (f32)) == -0.5 ) output = (output + 1UL) & ~1UL; \
        } \
    }

#define  F32_FIX_NEAREST_UNSIGNED( f32, fix_type, output ) \
    { \
        output = (fix_type)((f32) + 0.5); \
        if ( ((SAL_f32)(output) - (f32)) == 0.5 ) output &= ~1UL; \
    }

#define  F32_FIX_UP_SIGNED( f32, fix_type, output ) \
    { \
        output = (fix_type)(f32); \
        if ( ((f32) > 0.0) && ((SAL_f32)(output) != (f32)) ) ++output; \
    }

#define  F32_FIX_UP_UNSIGNED( f32, fix_type, output ) \
    { \
        output = (fix_type)(f32); \
        if ( (SAL_f32)(output) != (f32) ) ++output; \
    }

#define  F32_FIX_DOWN_SIGNED( f32, fix_type, output ) \
    { \
        output = (fix_type)(f32); \
        if ( ((f32) < 0.0) && ((SAL_f32)(output) != (f32)) ) --output; \
    }

#define  F32_FIX_DOWN_UNSIGNED( f32, fix_type, output ) \
    output = (fix_type)(f32);

#define  SATURATE_S8( s32 ) \
    { \
        if ( s32 > MAX_S8 ) s32 = MAX_S8; \
        else if ( s32 < MIN_S8 ) s32 = MIN_S8; \
    }

#define  SATURATE_U8( u32 ) \
    if ( u32 > MAX_U8 ) u32 = MAX_U8;

#define  SATURATE_S16( s32 ) \
    { \
        if ( s32 > MAX_S16 ) s32 = MAX_S16; \
        else if ( s32 < MIN_S16 ) s32 = MIN_S16; \
    }

#define  SATURATE_U16( u32 ) \
    if ( u32 > MAX_U16 ) u32 = MAX_U16;

#define  SATURATE_S32( s32 )

#define  SATURATE_U32( u32 )

    extern SAL_i32 PREFIX( sal__path );

#define SAL_SET_PATH( path ) \
    PREFIX(sal__path) = path;

#define SAL_SET_PATH_NOTHING() \
    SAL_SET_PATH( SAL_PATH_NOTHING )

#define SAL_SET_PATH_CSAL() \
    SAL_SET_PATH( SAL_PATH_CSAL )

#define SAL_SET_PATH_UNKNOWN() \
    SAL_SET_PATH( SAL_PATH_UNKNOWN )

    typedef union sal_un_32
    {
        SAL_f32  m_f32;
        SAL_i32  m_s32;
        SAL_ui32 m_u32;
    } SAL_un_32;

    typedef union sal_un_64
    {
        SAL_f64  m_f64;
        SAL_i32  m_s32[2];
        SAL_ui32 m_u32[2];
    } SAL_un_64;

    extern void PREFIX( _csal_create_heap ) ( SAL_f32 *C, SAL_i32 N );
    extern void PREFIX( _csal_create_heapd ) ( SAL_f64 *C, SAL_i32 N );
    extern void PREFIX( _csal_crmixerx ) ( SAL_f32 *A, SAL_i32 sA, SAL_f64 *F, SAL_f64 *P, SAL_cf32 *C, SAL_i32 sC, SAL_i32 N, SAL_i32 flag, SAL_i32 eflag );
    extern SAL_i32  PREFIX( _csal_fixr_ieee ) ( SAL_f32 *VAL );
    extern SAL_i32  PREFIX( _csal_fixrd_ieee ) ( SAL_f64 *VAL );
    extern void PREFIX( _csal_freal ) ( SAL_i32 N, SAL_f32 *TOP, SAL_f32 *BOT, SAL_f32 *W, SAL_i32 WINC );
    extern void PREFIX( _csal_freald ) ( SAL_i32 N, SAL_f64 *TOP, SAL_f64 *BOT, SAL_f64 *W, SAL_i32 WINC );
    extern void PREFIX( _csal_heap_sort ) ( SAL_f32 *C, SAL_i32 N );
    extern void PREFIX( _csal_heap_sortd ) ( SAL_f64 *C, SAL_i32 N );
    extern void PREFIX( _csal_ireal ) ( SAL_i32 N, SAL_f32 *TOP, SAL_f32 *BOT, SAL_f32 *W, SAL_i32 WINC );
    extern void PREFIX( _csal_ireald ) ( SAL_i32 N, SAL_f64 *TOP, SAL_f64 *BOT, SAL_f64 *W, SAL_i32 WINC );
    extern void PREFIX( _csal_matfbsd_sum ) ( SAL_f64 *SUM_ADDR, SAL_f64 *VEC1_ADDR, SAL_i32 STRIDE1, SAL_f64 *VEC2_ADDR, SAL_i32 STRIDE2, SAL_i32 COUNT );
    extern void PREFIX( _csal_rhvbp ) ( SAL_i32 N, SAL_f32 *PROJ_START, SAL_f32 *PROJ_DELTAX, SAL_f32 *PROJ_ADDR, SAL_f32 *IMAGE_ROW );
    extern void PREFIX( _csal_rhvbpd ) ( SAL_i32 N, SAL_f64 *PROJ_START, SAL_f64 *PROJ_DELTAX, SAL_f64 *PROJ_ADDR, SAL_f64 *IMAGE_ROW );
    extern void PREFIX( _csal_sortabsi ) ( SAL_f32 *Eval, SAL_i32 *Ind_v, SAL_i32 N );
    extern SAL_i32  PREFIX( _csal_tql2 )( SAL_f32 *D, SAL_f32 *E, SAL_f32 *Zre, SAL_i32 Ztcols, SAL_i32 N );
    extern void PREFIX ( _csal_warps ) ( SAL_f32 *A, SAL_f32 *B, SAL_f32 *C, SAL_i32 INC, SAL_i32 INR, SAL_i32 ONC, SAL_i32 ONR, SAL_i32 F, SAL_f32 *V );
    extern void PREFIX( _csal_vrot2nc ) ( SAL_f32 *v0, SAL_f32 *v1, SAL_f32 *cs, SAL_i32 n, SAL_i32 swap_rows );
    extern void PREFIX( _csal_vrot2ncd ) ( SAL_f64 *v0, SAL_f64 *v1, SAL_f64 *cs, SAL_i32 n, SAL_i32 swap_rows );
    extern void PREFIX( _csal_zhtribk )( SAL_zf32 *A, SAL_zf32 *Z, SAL_f32 *Tau, SAL_i32 Atcols, SAL_i32 Ztcols, SAL_i32 N );
    extern void PREFIX( _csal_zhtridi )( SAL_zf32 *A, SAL_i32 Atcols, SAL_f32 *D, SAL_f32 *E, SAL_f32 *Tau, SAL_i32 N );
    extern void PREFIX( _csal_zvrot2nc ) ( SAL_zf32 *v0, SAL_zf32 *v1, SAL_f32 *Pret, SAL_i32 n, SAL_i32 swap_rows );
    extern void PREFIX( _csal_zvrot2ncd ) ( SAL_zf64 *v0, SAL_zf64 *v1, SAL_f64 *Pret, SAL_i32 n, SAL_i32 swap_rows );
    extern SAL_i32  PREFIX( _csal_mat_svdker ) ( SAL_f32 *V, SAL_i32 Vtcols, SAL_f32 *D, SAL_f32 *U, SAL_i32 Utcols, SAL_i32 m, SAL_i32 n, SAL_i32 qr_flag, SAL_svd_tune *svd_tune, SAL_f32 *cond_num, SAL_i32 *numerical_rank, SAL_i32 sal_svd_flag, SAL_i32 xflag );
    extern SAL_i32  PREFIX( _csal_mat_svdkerd ) ( SAL_f64 *V, SAL_i32 Vtcols, SAL_f64 *D, SAL_f64 *U, SAL_i32 Utcols, SAL_i32 m, SAL_i32 n, SAL_i32 qr_flag, SAL_svd_tune *svd_tune, SAL_f32 *cond_num, SAL_i32 *numerical_rank, SAL_i32 sal_svd_flag, SAL_i32 xflag );
    extern SAL_i32  PREFIX( _csal_zmat_svdker ) ( SAL_zf32 *V, SAL_i32 Vtcols, SAL_f32 *D, SAL_zf32 *U, SAL_i32 Utcols, SAL_i32 m, SAL_i32 n, SAL_i32 qr_flag, SAL_svd_tune *svd_tune, SAL_f32 *cond_num, SAL_i32 *numerical_rank, SAL_i32 sal_svd_flag, SAL_i32 xflag );
    extern SAL_i32  PREFIX( _csal_zmat_svdkerd ) ( SAL_zf64 *V, SAL_i32 Vtcols, SAL_f64 *D, SAL_zf64 *U, SAL_i32 Utcols, SAL_i32 m, SAL_i32 n, SAL_i32 qr_flag, SAL_svd_tune *svd_tune, SAL_f32 *cond_num, SAL_i32 *numerical_rank, SAL_i32 sal_svd_flag, SAL_i32 xflag );
    extern SAL_i32  PREFIX( _csal_herm_schur_1s_row ) ( SAL_zf32 *U, SAL_i32 Utcols, SAL_i32 n, SAL_i32 p, SAL_i32 q, SAL_f32 *Pret );
    extern SAL_i32  PREFIX( _csal_cherm_schur_1s_row ) ( SAL_cf32 *U, SAL_i32 Utcols, SAL_i32 n, SAL_i32 p, SAL_i32 q, SAL_f32 *Pret );
    extern SAL_i32  PREFIX( _csal_sym_schur_1s_row ) ( SAL_f32 *U, SAL_i32 Utcols, SAL_i32 n, SAL_i32 p, SAL_i32 q, SAL_f32 *cs );
    extern SAL_i32  PREFIX( _csal_herm_schur_1s_rowd ) ( SAL_zf64 *U, SAL_i32 Utcols, SAL_i32 n, SAL_i32 p, SAL_i32 q, SAL_f64 *Pret );
    extern SAL_i32  PREFIX( _csal_cherm_schur_1s_rowd ) ( SAL_cf64 *U, SAL_i32 Utcols, SAL_i32 n, SAL_i32 p, SAL_i32 q, SAL_f64 *Pret );
    extern SAL_i32  PREFIX( _csal_sym_schur_1s_rowd ) ( SAL_f64 *U, SAL_i32 Utcols, SAL_i32 n, SAL_i32 p, SAL_i32 q, SAL_f64 *cs );
    extern SAL_i32  PREFIX( _csal_zmat_auto_mulx ) ( SAL_zf32 *pA, SAL_i32 Atcols, SAL_zf32 *pC, SAL_i32 Ctcols, SAL_i32 n_c, SAL_i32 N, SAL_i32 flag, SAL_i32 xflag );

#define MAX_INDEX ( 10 )

#define CC_SLOPE ( ( SAL_f32 ) ( 0.00102 ) ) 
    typedef struct
    {
        long    index;
        SAL_f32 time;
        SAL_i32 _pad64;
    } CC_DATA;

    extern CC_DATA PREFIX ( cc_data[] );

#ifdef __cplusplus
}
#endif

#endif

