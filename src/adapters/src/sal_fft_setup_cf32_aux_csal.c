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
        sal_fft_setup_cf32_aux_csal.c

----------------------------------------------------------------------------
*/

#include <math.h>
#include <stdlib.h>
#include "csal_fft_internal.h"
#include "sal.h"

#define SC1_SC2_SC3 0
#define CS1_CS2_SC3 1
#define SC1_CS2_CS3 2
#define CS1_SC2_SC3 3
#define WINC (2*96)
#define MEMORY_ALLOC_INFO 0

typedef struct
{
    SAL_i32  iA_size;
    SAL_i32  iG_size;
    SAL_i32  iBr_size;
    SAL_i32  iW_size;
    SAL_i32  iC_size;
} FFT_C_TABLE_SIZE;

typedef struct
{
    SAL_i32  Ws_size;
    SAL_i32  Wsc_size;
} FFT_C_WEIGHT_SIZE;

typedef struct
{
    FFT_C_WEIGHT_SIZE W;
    FFT_C_TABLE_SIZE IT;
    SAL_i32   nbytes;
} FFT_C_1D_SIZE;

typedef struct
{
    SAL_i32  Wxy_size;
    SAL_i32  Cachep_size;
    FFT_C_WEIGHT_SIZE Wx;
    FFT_C_TABLE_SIZE ITx;
    SAL_i32  iSx_size;
    FFT_C_WEIGHT_SIZE Wy;
    FFT_C_TABLE_SIZE ITy;
    SAL_i32  iSy_size;
    SAL_i32  nbytes;
} FFT_C_XY_SIZE;

typedef struct
{
    SAL_i32  Cachep_size;
    FFT_C_WEIGHT_SIZE Wx;
    FFT_C_TABLE_SIZE ITx;
    SAL_i32  iSx_size;
    FFT_C_WEIGHT_SIZE Wy;
    FFT_C_TABLE_SIZE ITy;
    SAL_i32  iSy_size;
    SAL_i32  nbytes;
} FFT_C_2D_SIZE;

#define CIP_SETUP  0
#define CIPT_SETUP 1

static SAL_i32  sal__fft_c_get_mem_size( FFT_C_1D_SIZE *S, SAL_i32  setup_ln );
static SAL_i32  sal__fft2d_c_get_mem_size( FFT_C_2D_SIZE *S, SAL_i32  Lnx, SAL_i32  Lny );
static SAL_i32  sal__fftxy_c_get_mem_size( FFT_C_XY_SIZE *S, SAL_i32  setup_ln );
static void sal__fft_br_table_cf32( SAL_i32  *T, SAL_i32  LN );
static SAL_i32  sal__fft_br_index_cf32( SAL_i32  *A, SAL_i32  *C, SAL_i32  *T, SAL_i32   LOG2N );

static SAL_i32  sal__fft_c_weights( SAL_f32 *W, SAL_f32 *Wsc, SAL_i32  *BrT,
                                    SAL_i32  *S, SAL_i32  *G, SAL_i32  *IW, SAL_i32  LOG2N );

static SAL_i32  sal__fftm_c_weights( SAL_f32 *W, SAL_f32 *Wsc, SAL_i32  *BrT,
                                     SAL_i32  *S, SAL_i32  LN );

static SAL_i32  sal__fftxy_setup( SAL_cf32 *Wxyp, SAL_cf32 *Wxyp_fcs,
                                  FFT_C_WEIGHTS *Wx, FFT_C_TABLES *ITx,
                                  FFT_C_WEIGHTS *Wy, FFT_C_TABLES *ITy,
                                  SAL_i32  *iSx, SAL_i32  *iSy,
                                  SAL_i32  LNx, SAL_i32  LNqx, SAL_i32  LNy, SAL_i32  LNqy, SAL_i32  F );

static SAL_i32  sal__fft2d_setup( FFT_C_TABLES *ITx, FFT_C_WEIGHTS *Wy, FFT_C_TABLES *ITy,
                                  SAL_i32  *iA, SAL_i32  *iC, SAL_i32  *iSx, SAL_i32  *iSy,
                                  SAL_i32  LNx, SAL_i32  LNqx, SAL_i32  LNy, SAL_i32  LNqy );

SAL_i32  sal__fft_setup_cf32( SAL__fft_setup_csal *setupp,
                              SAL_ui32  log2m,
                              SAL_ui32  *pnbytes,
                              void *pbuffer )
{
    SAL_i32  rc, ln_max2d, ln_max1d, log2n_xy;
    SAL_i32  setup_n, setup_log2n;
    SAL_i32  Lnx, Lnqx, Lny, Lnqy;
    SAL_i32  alloc_size, asize;
    SAL_char *fft_c_mem_ptr = NULL;
    SAL_i32  fft_c_mem_size, size;
    SAL_i32  fft1d_size, fftxy_size, fft2d_size;
    FFT_C_1D_SIZE *setup_c_1d_size, *s1d_sizep;
    FFT_C_XY_SIZE *setup_c_xy_size, *sxy_sizep;
    FFT_C_2D_SIZE *setup_c_2d_size, *s2d_sizep;
    FFT_C_2D *s2d_setupp;
    FFT_C_1D *s1d_setupp;
    FFT_C_XY *sxy_setupp, *sxyt_setupp;
    SAL_ui32  s1d_size, sxy_size, s2d_size;
    SAL_ui32  s1d_mem, sxy_mem, s2d_mem;
    void *hmemsize = NULL;
    SAL_char *setup_ptr = NULL;

    ( *pnbytes ) = 0;

    if ( setupp != NULL )
        setupp->hmem_cf32 = NULL;

    if ( log2m < LN_FFT_C_MIN )
    {
        return ( 0 );
    }

    ln_max1d = log2m;

    if ( ln_max1d < LN_FFT_C_THRESHOLD )
        ln_max1d = LN_FFT_C_THRESHOLD;

    s1d_mem = LN_FFT_C_THRESHOLD * sizeof( FFT_C_1D );
    s1d_size = LN_FFT_C_THRESHOLD * sizeof( FFT_C_1D_SIZE );

    sxy_mem = 0;
    sxy_size = 0;

    if ( ln_max1d > LN_FFT_C_THRESHOLD )
    {
        sxy_mem = ( ln_max1d - LN_FFT_C_THRESHOLD ) * sizeof( FFT_C_XY );
        sxy_size = ( ln_max1d - LN_FFT_C_THRESHOLD ) * sizeof( FFT_C_XY_SIZE );
    }

    sxy_mem *= 2;

    ln_max2d = log2m;

    if ( ln_max2d > LN_FFT2D_C_THRESHOLD )
        ln_max2d = LN_FFT2D_C_THRESHOLD;

    s2d_mem = ( ln_max2d + 1 - LN_FFT_C_MIN );
    s2d_mem *= ( LN_FFT2D_C_MAX + 1 - LN_FFT_C_MIN );

    s2d_size = s2d_mem * sizeof( FFT_C_2D_SIZE );
    s2d_mem *= sizeof( FFT_C_2D );

    ( void )rc;
    hmemsize = ( void * )calloc( ( unsigned long )( s1d_size + sxy_size + s2d_size + ( 3 * 16 ) ), 1UL );

    if ( !hmemsize )
    {
        goto label_error_return;
    }

    setup_ptr = ( SAL_char * )ROUNDUP_16L( hmemsize );

    setup_c_1d_size = ( FFT_C_1D_SIZE * )setup_ptr;
    setup_ptr += s1d_size;
    setup_c_xy_size = ( FFT_C_XY_SIZE * )setup_ptr;
    setup_ptr += sxy_size;
    setup_c_2d_size = ( FFT_C_2D_SIZE * )setup_ptr;

    fft_c_mem_size = 0;
    fft1d_size = 0;
    fftxy_size = 0;
    s1d_sizep = setup_c_1d_size;
    sxy_sizep = setup_c_xy_size;
    s2d_sizep = setup_c_2d_size;

    for ( setup_log2n = LN_FFT_C_MIN; setup_log2n <= ln_max1d; setup_log2n++ )
    {
        if ( setup_log2n <= LN_FFT_C_THRESHOLD )
        {
            fft1d_size += sal__fft_c_get_mem_size( s1d_sizep, setup_log2n );
            s1d_sizep++;
        }
        else
        {
            size = sal__fftxy_c_get_mem_size( sxy_sizep, setup_log2n );
            sxy_sizep++;
            fftxy_size += ( size * 2 );
        }
    }

    fft_c_mem_size = fft1d_size + fftxy_size;

    fft2d_size = 0;

    for ( Lny = LN_FFT_C_MIN; Lny <= ( SAL_i32 )ln_max2d; Lny++ )
        for ( Lnx = LN_FFT_C_MIN; Lnx <= ( SAL_i32 )LN_FFT2D_C_MAX; Lnx++ )
        {
            fft2d_size += sal__fft2d_c_get_mem_size( s2d_sizep, Lnx, Lny );
            s2d_sizep++;
        }

    fft_c_mem_size += fft2d_size;

    fft_c_mem_size += ( s1d_mem + sxy_mem + s2d_mem );
    ( *pnbytes ) += fft_c_mem_size + ( 3 * 16 );

    if ( setupp == NULL )
    {
        goto label_nbyte_only_return;
    }

    fft_c_mem_ptr = ( SAL_char * ) ROUNDUP_16L( pbuffer );

    setupp->vmx.setup_c_1d = ( FFT_C_1D * )fft_c_mem_ptr;
    fft_c_mem_ptr += s1d_mem;
    setupp->vmx.setup_c_1dxy = ( FFT_C_XY * )fft_c_mem_ptr;
    fft_c_mem_ptr += ( sxy_mem / 2 );
    setupp->vmx.setup_ct_1dxy = ( FFT_C_XY * )fft_c_mem_ptr;

    fft_c_mem_ptr += ( sxy_mem / 2 );
    setupp->vmx.setup_c_2d = ( FFT_C_2D * )fft_c_mem_ptr;
    fft_c_mem_ptr += s2d_mem;

    alloc_size = 0;
    s1d_sizep = setup_c_1d_size;
    s1d_setupp = setupp->vmx.setup_c_1d;

    for ( setup_log2n = LN_FFT_C_MIN; setup_log2n <= LN_FFT_C_THRESHOLD; setup_log2n++ )
    {
        setup_n = ( 1 << setup_log2n );

        fft_c_mem_ptr = ( SAL_char * )ROUNDUP_16L( fft_c_mem_ptr );
        s1d_setupp->nbytes = s1d_sizep->nbytes;

        s1d_setupp->W.Ws = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += s1d_sizep->W.Ws_size;

        s1d_setupp->W.Wsc = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += s1d_sizep->W.Wsc_size;

        s1d_setupp->IT.iBr = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += s1d_sizep->IT.iBr_size;

        s1d_setupp->IT.iW = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += s1d_sizep->IT.iW_size;

        s1d_setupp->IT.iG = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += s1d_sizep->IT.iG_size;

        s1d_setupp->IT.iA = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += s1d_sizep->IT.iA_size;

        s1d_setupp->IT.iC = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += s1d_sizep->IT.iC_size;

        sal__fft_br_table_cf32( s1d_setupp->IT.iBr, setup_log2n );
        asize = ( ( setup_n / 4 ) * sizeof( SAL_i32 ) );
        asize = ROUNDUP_16( asize );
        alloc_size += asize;

        asize = sal__fft_br_index_cf32( s1d_setupp->IT.iA, s1d_setupp->IT.iC,
                                        s1d_setupp->IT.iBr, setup_log2n );
        alloc_size += asize;

        asize = sal__fft_c_weights( s1d_setupp->W.Ws, s1d_setupp->W.Wsc,
                                    s1d_setupp->IT.iBr, s1d_setupp->IT.iW,
                                    s1d_setupp->IT.iG, s1d_setupp->IT.iA, setup_log2n );
        alloc_size += asize;
        s1d_setupp++;
        s1d_sizep++;
    }

    log2n_xy = LN_FFT_C_THRESHOLD + 1;
    sxy_sizep = setup_c_xy_size;
    sxy_setupp = setupp->vmx.setup_c_1dxy;
    sxyt_setupp = setupp->vmx.setup_ct_1dxy;

    for ( setup_log2n = log2n_xy; setup_log2n <= ln_max1d; setup_log2n++ )
    {
        setup_n = ( 1 << setup_log2n );

        Lny = setup_log2n / 2;
        Lnx = setup_log2n - Lny;

        if ( ( setup_n / FFT_C_CACHEBLK ) == 0 )
        {
            Lnqx = Lnx;
            Lnqy = Lny;
        }
        else
        {
            Lnqx = LN_FFT_C_CACHEBLK - Lny;

            if ( Lnqx < 2 )
                Lnqx = 2;

            Lnqy = LN_FFT_C_CACHEBLK - Lnx;

            if ( Lnqy < 2 )
                Lnqy = 2;
        }

        fft_c_mem_ptr = ( SAL_char * )ROUNDUP_16L( fft_c_mem_ptr );
        sxy_setupp->nbytes = sxy_sizep->nbytes;

        sxy_setupp->Wxy = ( SAL_cf32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wxy_size;

        sxy_setupp->Wxy_fcs = ( SAL_cf32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wxy_size;

        sxy_setupp->Cachep = ( SAL_cf32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Cachep_size;

        sxy_setupp->Wx.Ws = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wx.Ws_size;

        sxy_setupp->Wx.Wsc = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wx.Wsc_size;

        sxy_setupp->Lnx = Lnx;
        sxy_setupp->Lnqx = Lnqx;

        sxy_setupp->ITx.iA = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iA_size;

        sxy_setupp->ITx.iBr = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iBr_size;

        sxy_setupp->ITx.iW = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iW_size;

        sxy_setupp->ITx.iC = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iC_size;

        sxy_setupp->ITx.iG = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iG_size;

        sxy_setupp->iSx = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->iSx_size;

        sxy_setupp->Wy.Ws = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wy.Ws_size;

        sxy_setupp->Wy.Wsc = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wy.Wsc_size;

        sxy_setupp->Lny = Lny;
        sxy_setupp->Lnqy = Lnqy;

        sxy_setupp->ITy.iA = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iA_size;

        sxy_setupp->ITy.iBr = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iBr_size;

        sxy_setupp->ITy.iW = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iW_size;

        sxy_setupp->ITy.iC = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iC_size;

        sxy_setupp->ITy.iG = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iG_size;

        sxy_setupp->iSy = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->iSy_size;

        asize = 1 << ( Lnx + Lnqy );

        if ( asize < ( 1 << ( Lny + Lnqx ) ) )
            asize = ( 1 << ( Lny + Lnqx ) );

        asize *= sizeof( SAL_cf32 );
        asize = ROUNDUP_16( asize );
        alloc_size += asize;

        asize = ( sizeof( SAL_i32 ) << ( Lnx - 1 ) );
        asize += ( sizeof( SAL_i32 ) << ( Lny - 1 ) );
        alloc_size += asize;

        alloc_size += sal__fftxy_setup( sxy_setupp->Wxy, sxy_setupp->Wxy_fcs,
                                        &sxy_setupp->Wx, &sxy_setupp->ITx,
                                        &sxy_setupp->Wy, &sxy_setupp->ITy,
                                        sxy_setupp->iSx, sxy_setupp->iSy,
                                        Lnx, Lnqx, Lny, Lnqy, CIP_SETUP );

        sxyt_setupp->Wxy = ( SAL_cf32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wxy_size;

        sxyt_setupp->Wxy_fcs = ( SAL_cf32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wxy_size;

        sxyt_setupp->Cachep = ( SAL_cf32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Cachep_size;

        sxyt_setupp->Wx.Ws = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wx.Ws_size;

        sxyt_setupp->Wx.Wsc = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wx.Wsc_size;

        sxyt_setupp->Lnx = Lnx;
        sxyt_setupp->Lnqx = Lnqx;

        sxyt_setupp->ITx.iA = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iA_size;

        sxyt_setupp->ITx.iBr = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iBr_size;

        sxyt_setupp->ITx.iW = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iW_size;

        sxyt_setupp->ITx.iC = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iC_size;

        sxyt_setupp->ITx.iG = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITx.iG_size;

        sxyt_setupp->iSx = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->iSx_size;

        sxyt_setupp->Wy.Ws = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wy.Ws_size;

        sxyt_setupp->Wy.Wsc = ( SAL_f32 * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->Wy.Wsc_size;

        sxyt_setupp->Lny = Lny;
        sxyt_setupp->Lnqy = Lnqy;

        sxyt_setupp->ITy.iA = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iA_size;

        sxyt_setupp->ITy.iBr = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iBr_size;

        sxyt_setupp->ITy.iW = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iW_size;

        sxyt_setupp->ITy.iC = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iC_size;

        sxyt_setupp->ITy.iG = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->ITy.iG_size;

        sxyt_setupp->iSy = ( SAL_i32  * )fft_c_mem_ptr;
        fft_c_mem_ptr += sxy_sizep->iSy_size;

        asize = 1 << ( Lnx + Lnqy );

        if ( asize < ( 1 << ( Lny + Lnqx ) ) )
            asize = ( 1 << ( Lny + Lnqx ) );

        asize *= sizeof( SAL_cf32 );
        asize = ROUNDUP_16( asize );
        alloc_size += asize;

        asize = ( sizeof( SAL_i32 ) << ( Lnx - 1 ) );
        asize += ( sizeof( SAL_i32 ) << ( Lny - 1 ) );
        alloc_size += asize;

        alloc_size += sal__fftxy_setup( sxyt_setupp->Wxy, sxyt_setupp->Wxy_fcs,
                                        &sxyt_setupp->Wx, &sxyt_setupp->ITx,
                                        &sxyt_setupp->Wy, &sxyt_setupp->ITy,
                                        sxyt_setupp->iSx, sxyt_setupp->iSy,
                                        Lnx, Lnqx, Lny, Lnqy, CIPT_SETUP );

        sxy_setupp++;
        sxyt_setupp++;
        sxy_sizep++;

    }

    s2d_sizep = setup_c_2d_size;
    s2d_setupp = setupp->vmx.setup_c_2d;

    for ( Lny = LN_FFT_C_MIN; Lny <= ( SAL_i32 )ln_max2d; Lny++ )
    {
        s1d_setupp = setupp->vmx.setup_c_1d;

        for ( Lnx = LN_FFT_C_MIN; Lnx <= ( SAL_i32 )LN_FFT2D_C_MAX; Lnx++ )
        {
            setup_n = ( 1 << ( Lnx + Lny ) );

            if ( ( setup_n / FFT_C_CACHEBLK ) == 0 )
            {
                Lnqx = Lnx;
                Lnqy = Lny;
            }
            else
            {
                Lnqx = LN_FFT_C_CACHEBLK - Lny;

                if ( Lnqx < 2 )
                    Lnqx = 2;

                Lnqy = LN_FFT_C_CACHEBLK - Lnx;

                if ( Lnqy < 2 )
                    Lnqy = 2;
            }

            fft_c_mem_ptr = ( SAL_char * )ROUNDUP_16L( fft_c_mem_ptr );
            s2d_setupp->nbytes = s2d_sizep->nbytes;

            s2d_setupp->CacheP = ( SAL_cf32 * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->Cachep_size;

            s2d_setupp->Wx.Ws = s1d_setupp->W.Ws;
            s2d_setupp->Wx.Wsc = s1d_setupp->W.Wsc;
            s2d_setupp->LNqx = Lnqx;

            s2d_setupp->ITx.iA = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->ITx.iA_size;

            s2d_setupp->ITx.iBr = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->ITx.iBr_size;

            s2d_setupp->ITx.iW = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->ITx.iW_size;

            s2d_setupp->ITx.iC = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->ITx.iC_size;

            s2d_setupp->ITx.iG = s1d_setupp->IT.iG;

            s2d_setupp->iSx = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->iSx_size;

            s2d_setupp->Wy.Ws = ( SAL_f32 * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->Wy.Ws_size;

            s2d_setupp->Wy.Wsc = ( SAL_f32 * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->Wy.Wsc_size;

            s2d_setupp->LNqy = Lnqy;

            s2d_setupp->ITy.iA = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->ITy.iA_size;

            s2d_setupp->ITy.iBr = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->ITy.iBr_size;

            s2d_setupp->ITy.iW = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->ITy.iW_size;

            s2d_setupp->ITy.iC = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->ITy.iC_size;

            s2d_setupp->ITy.iG = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->ITy.iG_size;

            s2d_setupp->iSy = ( SAL_i32  * )fft_c_mem_ptr;
            fft_c_mem_ptr += s2d_sizep->iSy_size;

            asize = ( sizeof( SAL_i32 ) << ( Lnx - 1 ) );
            asize += ( sizeof( SAL_i32 ) << ( Lny - 1 ) );
            alloc_size += asize;
            alloc_size += sal__fft2d_setup( &s2d_setupp->ITx,
                                            &s2d_setupp->Wy, &s2d_setupp->ITy,
                                            s1d_setupp->IT.iA, s1d_setupp->IT.iC,
                                            s2d_setupp->iSx, s2d_setupp->iSy,
                                            Lnx, Lnqx, Lny, Lnqy );
            s1d_setupp++;
            s2d_setupp++;
            s2d_sizep++;
        }
    }

label_nbyte_only_return:

    free( hmemsize );

    return ( 0 );

label_error_return:

    if ( hmemsize != NULL )
    {
        free( hmemsize );
    }

    return ( -1 );
}

static void sal__fft_br_table_cf32( SAL_i32  *T, SAL_i32  LOG2N )
{
    SAL_i32  i, j, k, N;
    SAL_i32  temp;

    N = ( 1 << LOG2N ) / 4;

    for ( i = 0; i < N; i++ )
        T[i] = i;

    j = 0;

    for ( i = 1; i < ( N - 1 ); i += 1 )
    {
        k = ( N >> 1 );

        while ( k <= j )
        {
            j -= k;
            k >>= 1;
        }

        j += k;

        if ( i < j )
        {
            temp = T[i];
            T[i] = T[j];
            T[j] = temp;
        }
    }
}

static SAL_i32  sal__fft_c_get_mem_size( FFT_C_1D_SIZE *S, SAL_i32  setup_ln )
{
    SAL_i32  N, nbytes, iw_size, ig_size, ws_size;
    SAL_i32  wsc_size, ia_size, ic_size, br_size;

    N = ( 1 << setup_ln );

    ws_size = 6 * ( ( N / 32 ) - 1 ) * sizeof( SAL_f32 );

    if ( ws_size < 0 )
        ws_size = 0;

    ws_size = ROUNDUP_16( ws_size );
    S->W.Ws_size = ws_size;

    if ( setup_ln <= 10 )
        wsc_size = ( ( N / 4 ) * 12 ) * sizeof( SAL_f32 );
    else
        wsc_size = ( ( N / 4 ) * 6 ) * sizeof( SAL_f32 );

    wsc_size = ROUNDUP_16( wsc_size );
    S->W.Wsc_size = wsc_size;

    br_size = ( N / 4 ) * sizeof( SAL_i32 );
    br_size = ROUNDUP_16( br_size );
    S->IT.iBr_size = br_size;

    iw_size = ( ( N / 16 ) - 1 ) * sizeof( SAL_i32 );
    iw_size = ROUNDUP_16( iw_size );
    S->IT.iW_size  = iw_size;

    ig_size = ( ( N / 16 ) - 1 ) * 2 * sizeof( SAL_i32 );
    ig_size = ROUNDUP_16( ig_size );
    S->IT.iG_size = ig_size;

    ia_size = ( N / 16 ) * sizeof( SAL_i32 );
    ia_size = ROUNDUP_16( ia_size );
    S->IT.iA_size = ia_size;

    ic_size = ( N / 16 ) * sizeof( SAL_i32 );
    ic_size = ROUNDUP_16( ic_size );
    S->IT.iC_size = ic_size;

    nbytes = ws_size + wsc_size + br_size +
             iw_size + ig_size + ia_size + ic_size;

    S->nbytes = nbytes;
    return( nbytes );
}

static SAL_i32  sal__fft_br_index_cf32( SAL_i32  *A, SAL_i32  *C, SAL_i32  *T, SAL_i32   LOG2N )
{
    SAL_i32  j, i, s, t, N, No16;

    N = 1 << LOG2N;
    No16 = N >> 4;
    j = 0;
    i = 0;
    s = -1;

    while ( j < No16 )
    {
        s++;

        t = T[i] >> 2;

        if ( s == t )
        {
            A[j] = s << 5;
            C[j] = t << 5;
            j++;
            i++;
        }

        else if ( s < t )
        {
            C[j] = s << 5;
            A[j] = t << 5;
            j++;

            if ( j < No16 )
            {
                A[j] = s << 5;
                C[j] = t << 5;
            }

            j++;
            i++;
        }

        else
            i++;
    }

    j *= sizeof( SAL_i32 );
    j = ROUNDUP_16( j );
    return( j * 2 );
}

static SAL_i32  sal__fft_c_weights( SAL_f32 *W, SAL_f32 *Wsc, SAL_i32  *BrT,
                                    SAL_i32  *S, SAL_i32  *G, SAL_i32  *IW, SAL_i32  LOG2N )
{
    SAL_i32  ibytes, wbytes, No4, windx;
    SAL_i32  g, gc, is, l0, l, k, jnum, j, N;
    SAL_f64 PIoN, a, b, c;
    SAL_f64 cos1, cos2, cos3, acos3;
    SAL_f64 sin1, sin2, sin3, asin3;
    SAL_f32 wt2r, w2r, wt1r, wt3r;
    SAL_f32 w3re, wt13r;
    SAL_f32 wr1, wr2, wr3;
    SAL_f32 wi1, wi2, wi3;
    SAL_f64 dtmp;
    SAL_f32 *wrp1, *wrp2, *wrp3;
    SAL_f32 *wip1, *wip2, *wip3;

    N = 1 << LOG2N;
    PIoN = TWOPI_CONSTANT / ( SAL_f64 )N;
    No4 = N >> 2;
    wbytes = 0;
    is = 0;
    S[is] = 0;
    is++;

    wt2r = 0.0;
    w2r = 0.0;
    wt1r = 0.0;
    wt3r = 0.0;
    wt13r = 0.0;
    w3re = 0.0;

    for ( j = 1; j < N / 16; j++ )
    {
        k = BrT[j];
        a = ( SAL_f64 )k * PIoN;
        b = a + a;
        c = a + b;

        cos1 = cos( a );
        cos2 = cos( b );
        cos3 = cos( c );
        sin1 = sin( a );
        sin2 = sin( b );
        sin3 = sin( c );

        if ( cos3 < 0 )
            acos3 = -cos3;
        else
            acos3 = cos3;

        if ( sin3 < 0 )
            asin3 = -sin3;
        else
            asin3 = sin3;

        jnum = j & 0x3;
        wt1r = 0;
        wt2r = 0;
        w2r = 0;
        wt3r = 0;
        wt13r = 0;
        w3re = 0;

        switch ( ( SAL_i32 )jnum )
        {
            case SC1_SC2_SC3:

                if ( asin3 > acos3 )
                {
                    dtmp = sin1 / cos1;
                    wt1r = ( SAL_f32 )dtmp;

                    dtmp = sin2 / cos2;
                    wt2r = ( SAL_f32 )dtmp;

                    w2r = ( SAL_f32 )cos2;

                    dtmp = cos3 / sin3;
                    wt3r = ( SAL_f32 )dtmp;
                    S[is] = 0;
                    is++;

                    dtmp = sin3 / cos1;
                    wt13r = ( SAL_f32 )dtmp;

                    w3re = ( SAL_f32 )cos1;
                }

                else
                {
                    dtmp = sin1 / cos1;
                    wt1r = ( SAL_f32 )dtmp;

                    dtmp = sin2 / cos2;
                    wt2r = ( SAL_f32 )dtmp;

                    w2r = ( SAL_f32 )cos2;

                    dtmp = sin3 / cos3;
                    wt3r = ( SAL_f32 )dtmp;
                    S[is] = 1;
                    is++;

                    dtmp = cos3 / cos1;
                    wt13r = ( SAL_f32 )dtmp;

                    w3re = ( SAL_f32 )cos1;
                }

                break;

            case CS1_CS2_SC3:
                dtmp = cos1 / sin1;
                wt1r = ( SAL_f32 )dtmp;

                dtmp = cos2 / sin2;
                wt2r = ( SAL_f32 )dtmp;

                w2r = ( SAL_f32 )sin2;

                dtmp = sin3 / cos3;
                wt3r = ( SAL_f32 )dtmp;

                dtmp = sin1 / cos3;
                wt13r = ( SAL_f32 )dtmp;

                w3re = ( SAL_f32 )cos3;

                break;

            case SC1_CS2_CS3:
                dtmp = sin1 / cos1;
                wt1r = ( SAL_f32 )dtmp;

                dtmp = cos2 / sin2;
                wt2r = ( SAL_f32 )dtmp;

                w2r = ( SAL_f32 )sin2;

                dtmp = cos3 / sin3;
                wt3r = ( SAL_f32 )dtmp;

                dtmp = cos1 / sin3;
                wt13r = ( SAL_f32 )dtmp;

                w3re = ( SAL_f32 )sin3;

                break;

            case CS1_SC2_SC3:

                if ( asin3 > acos3 )
                {
                    dtmp = cos1 / sin1;
                    wt1r = ( SAL_f32 )dtmp;

                    dtmp = sin2 / cos2;
                    wt2r = ( SAL_f32 )dtmp;

                    w2r = ( SAL_f32 )cos2;

                    dtmp = cos3 / sin3;
                    wt3r = ( SAL_f32 )dtmp;
                    S[is] = 0;
                    is++;

                    dtmp = sin3 / sin1;
                    wt13r = ( SAL_f32 )dtmp;

                    w3re = ( SAL_f32 )sin1;

                }
                else
                {
                    dtmp = cos1 / sin1;
                    wt1r = ( SAL_f32 )dtmp;

                    dtmp = sin2 / cos2;
                    wt2r = ( SAL_f32 )dtmp;

                    w2r = ( SAL_f32 )cos2;

                    dtmp = sin3 / cos3;
                    wt3r = ( SAL_f32 )dtmp;
                    S[is] = 1;
                    is++;

                    dtmp = cos3 / sin1;
                    wt13r = ( SAL_f32 )dtmp;

                    w3re = ( SAL_f32 )sin1;

                }

                break;
        }

        if ( ( j & 0x1 ) == 0 )
        {
            *W = wt1r;
            W++;
            *W = wt2r;
            W++;
            *W = wt3r;
            W++;
            *W = w2r;
            W++;
            *W = w3re;
            W++;
            *W = wt13r;
            W++;
            wbytes += 24;
        }
    }

    ibytes = ( ( ( N / 16 ) - 1 ) * sizeof( SAL_i32 ) );
    ibytes = ROUNDUP_16( ibytes );
    wbytes = ROUNDUP_16( wbytes );

    if ( LOG2N <= 10 )
    {
        wrp1 = Wsc;
        wrp2 = Wsc + 8;
        wrp3 = Wsc + 16;

        wip1 = Wsc + 24;
        wip2 = Wsc + 32;
        wip3 = Wsc + 40;

        windx = 0;

        l0 = l = 0;

        for ( j = 0; j < No4; j++ )
        {
            k = BrT[l0] + l;
            a = ( SAL_f32 )k * PIoN;
            b = a + a;
            c = a + b;

            l++;

            if ( l == 4 )
            {
                IW++;
                l0 = *IW;
                l0 >>= 5;
                l = 0;
            }

            wr1 = ( SAL_f32 )cos( a );
            *wrp1 = -wr1;
            *( wrp1 + 1 ) = wr1;
            wrp1 += 2;
            wbytes += 8;

            wi1 = ( SAL_f32 )sin( a );
            *wip1 = -wi1;
            *( wip1 + 1 ) = -wi1;
            wip1 += 2;
            wbytes += 8;

            wr2 = ( SAL_f32 )cos( b );
            *wrp2 = wr2;
            *( wrp2 + 1 ) = wr2;
            wrp2 += 2;
            wbytes += 8;

            wi2 = ( SAL_f32 )sin( b );
            *wip2 = wi2;
            *( wip2 + 1 ) = -wi2;
            wip2 += 2;
            wbytes += 8;

            wr3 = ( SAL_f32 )cos( c );
            *wrp3 = wr3;
            *( wrp3 + 1 ) = wr3;
            wrp3 += 2;
            wbytes += 8;

            wi3 = ( SAL_f32 )sin( c );
            *wip3 = wi3;
            *( wip3 + 1 ) = -wi3;
            wip3 += 2;
            wbytes += 8;

            windx++;

            if ( windx == 4 )
            {
                wrp1 += 40;
                wrp2 += 40;
                wrp3 += 40;
                wip1 += 40;
                wip2 += 40;
                wip3 += 40;
                windx = 0;
            }
        }
    }

    else
    {
        wrp1 = Wsc;
        wip1 = Wsc + 4;
        wrp2 = Wsc + 8;
        wip2 = Wsc + 12;
        wrp3 = Wsc + 16;
        wip3 = Wsc + 20;

        windx = 0;

        l0 = l = 0;

        for ( j = 0; j < No4; j++ )
        {
            k = BrT[l0] + l;
            a = ( SAL_f32 )k * PIoN;
            b = a + a;
            c = a + b;

            l++;

            if ( l == 4 )
            {
                IW++;
                l0 = *IW;
                l0 >>= 5;
                l = 0;
            }

            wr1 = ( SAL_f32 )cos( a );
            *( wrp1 + windx ) = wr1;
            wbytes += 4;

            wi1 = ( SAL_f32 )sin( a );
            *( wip1 + windx ) = wi1;
            wbytes += 4;

            wr2 = ( SAL_f32 )cos( b );
            *( wrp2 + windx ) = wr2;
            wbytes += 4;

            wi2 = ( SAL_f32 )sin( b );
            *( wip2 + windx ) = wi2;
            wbytes += 4;

            wr3 = ( SAL_f32 )cos( c );
            *( wrp3 + windx ) = wr3;
            wbytes += 4;

            wi3 = ( SAL_f32 )sin( c );
            *( wip3 + windx ) = wi3;
            wbytes += 4;

            windx++;

            if ( windx == 4 )
            {
                wrp1 += 24;
                wrp2 += 24;
                wrp3 += 24;
                wip1 += 24;
                wip2 += 24;
                wip3 += 24;
                windx = 0;
            }
        }
    }

    wbytes = ROUNDUP_16( wbytes );

    j = 0;

    for ( k = 1; k < N / 16; k++ )
    {
        g = ( N / 4 ) - BrT[k<<1];
        gc = BrT[g];
        G[k+( N/16 )-1] = gc;

        if ( ( k & 0x1 ) == 0 )
        {
            G[j] = S[k];
            G[j+1] = S[gc>>1];
            j += 2;
        }
    }

    j = ( ( ( N / 16 ) - 1 ) * 2 * sizeof( SAL_i32 ) );
    j = ROUNDUP_16( j );
    ibytes += j;

    return( wbytes + ibytes );
}

static SAL_i32  sal__fftxy_c_get_mem_size( FFT_C_XY_SIZE *S, SAL_i32  setup_ln )
{
    SAL_i32  setup_n, nbytes;
    SAL_i32  lnx, lnqx, lny, lnqy;
    SAL_i32  Nx, nqx, Ny, nqy;
    SAL_i32  wxy_size, cachep_size;
    SAL_i32  wsx_size, wscx_size, iax_size, ibrx_size;
    SAL_i32  iwx_size, icx_size, igx_size;
    SAL_i32  wsy_size, wscy_size, iay_size, ibry_size;
    SAL_i32  iwy_size, icy_size, igy_size;
    SAL_i32  isx_size, isy_size;

    setup_n = ( 1 << setup_ln );
    lny = setup_ln / 2;
    lnx = setup_ln - lny;

    Nx = 1 << lnx;
    Ny = 1 << lny;

    if ( ( setup_n / FFT_C_CACHEBLK ) == 0 )
    {
        lnqx = lnx;
        lnqy = lny;
    }
    else
    {
        lnqx = LN_FFT_C_CACHEBLK - lny;

        if ( lnqx < 2 )
            lnqx = 2;

        lnqy = LN_FFT_C_CACHEBLK - lnx;

        if ( lnqy < 2 )
            lnqy = 2;
    }

    nqx = 1 << lnqx;
    nqy = 1 << lnqy;

    wxy_size = ( Nx * Ny ) * sizeof( SAL_cf32 );
    wxy_size = ROUNDUP_16( wxy_size );
    S->Wxy_size = wxy_size;

    cachep_size = 1 << ( lnx + lnqy );

    if ( cachep_size < ( 1 << ( lny + lnqx ) ) )
        cachep_size = ( 1 << ( lny + lnqx ) );

    cachep_size *= sizeof( SAL_cf32 );
    cachep_size = ROUNDUP_16( cachep_size );
    S->Cachep_size = cachep_size;

    wsx_size = 6 * ( ( Nx / 32 ) - 1 ) * sizeof( SAL_f32 );

    if ( wsx_size < 0 )
        wsx_size = 0;

    wsx_size = ROUNDUP_16( wsx_size );
    S->Wx.Ws_size = wsx_size;
    wscx_size = ( 12 * Nx / 4 ) * sizeof( SAL_f32 );
    wscx_size = ROUNDUP_16( wscx_size );
    S->Wx.Wsc_size = wscx_size;

    if ( lnx & 0x1 )
        iax_size = ( Nx * nqy / 32 ) * sizeof( SAL_i32 );
    else
        iax_size = ( Nx * nqy / 16 ) * sizeof( SAL_i32 );

    iax_size = ROUNDUP_16( iax_size );
    S->ITx.iA_size = iax_size;
    ibrx_size = ( Nx * nqy / 16 ) * sizeof( SAL_i32 );
    ibrx_size = ROUNDUP_16( ibrx_size );
    S->ITx.iBr_size = ibrx_size;
    iwx_size = ( Nx * nqy / 16 ) * sizeof( SAL_i32 );
    iwx_size = ROUNDUP_16( iwx_size );
    S->ITx.iW_size = iwx_size;
    icx_size = ( Nx * nqy / 16 ) * sizeof( SAL_i32 );
    icx_size = ROUNDUP_16( icx_size );
    S->ITx.iC_size = icx_size;
    igx_size = ( ( Nx / 16 ) - 1 ) * 2 * sizeof( SAL_i32 );
    igx_size = ROUNDUP_16( igx_size );
    S->ITx.iG_size = igx_size;

    isx_size = ( Nx / 2 ) * sizeof( SAL_i32 );
    isx_size = ROUNDUP_16( isx_size );
    S->iSx_size = isx_size;

    wsy_size = 6 * ( ( Ny / 32 ) - 1 ) * sizeof( SAL_f32 );

    if ( wsy_size < 0 )
        wsy_size = 0;

    wsy_size = ROUNDUP_16( wsy_size );
    S->Wy.Ws_size = wsy_size;
    wscy_size = ( 12 * Ny / 4 ) * sizeof( SAL_f32 );
    wscy_size = ROUNDUP_16( wscy_size );
    S->Wy.Wsc_size = wscy_size;

    if ( lny & 0x1 )
        iay_size = ( Ny * nqx / 32 ) * sizeof( SAL_i32 );
    else
        iay_size = ( Ny * nqx / 16 ) * sizeof( SAL_i32 );

    iay_size = ROUNDUP_16( iay_size );
    S->ITy.iA_size = iay_size;
    ibry_size = ( Ny * nqx / 16 ) * sizeof( SAL_i32 );
    ibry_size = ROUNDUP_16( ibry_size );
    S->ITy.iBr_size = ibry_size;
    iwy_size = ( Ny * nqx / 16 ) * sizeof( SAL_i32 );
    iwy_size = ROUNDUP_16( iwy_size );
    S->ITy.iW_size = iwy_size;
    icy_size = ( Ny * nqx / 16 ) * sizeof( SAL_i32 );
    icy_size = ROUNDUP_16( icy_size );
    S->ITy.iC_size = icy_size;
    igy_size = ( ( Ny / 16 ) - 1 ) * 2 * sizeof( SAL_i32 );
    igy_size = ROUNDUP_16( igy_size );
    S->ITy.iG_size = igy_size;

    isy_size = ( Ny / 2 ) * sizeof( SAL_i32 );
    isy_size = ROUNDUP_16( isy_size );
    S->iSy_size = isy_size;

    nbytes = ( wxy_size << 1 ) + cachep_size + wsx_size + wscx_size
             + iax_size + ibrx_size + iwx_size + icx_size
             + igx_size + wsy_size + wscy_size + iay_size
             + ibry_size + iwy_size + icy_size + igy_size
             + isx_size + isy_size;

    S->nbytes = nbytes;
    return( nbytes );
}

static SAL_i32  sal__fft2d_c_get_mem_size( FFT_C_2D_SIZE *S, SAL_i32  Lnx, SAL_i32  Lny )
{
    SAL_i32  N, nbytes;
    SAL_i32  lnqx, lnqy;
    SAL_i32  Nx, nqx, Ny, nqy;
    SAL_i32  cachep_size;
    SAL_i32  iax_size, ibrx_size;
    SAL_i32  iwx_size, icx_size;
    SAL_i32  wsy_size, wscy_size, iay_size, ibry_size;
    SAL_i32  iwy_size, icy_size, igy_size;
    SAL_i32  isx_size, isy_size;

    N = ( 1 << ( Lnx + Lny ) );
    Nx = 1 << Lnx;
    Ny = 1 << Lny;

    if ( ( N / FFT_C_CACHEBLK ) == 0 )
    {
        lnqx = Lnx;
        lnqy = Lny;
    }
    else
    {
        lnqx = LN_FFT_C_CACHEBLK - Lny;

        if ( lnqx < 2 )
            lnqx = 2;

        lnqy = LN_FFT_C_CACHEBLK - Lnx;

        if ( lnqy < 2 )
            lnqy = 2;
    }

    nqx = 1 << lnqx;
    nqy = 1 << lnqy;

    cachep_size = 1 << ( Lnx + lnqy );

    if ( cachep_size < ( 1 << ( Lny + lnqx ) ) )
        cachep_size = ( 1 << ( Lny + lnqx ) );

    cachep_size *= sizeof( SAL_cf32 );
    cachep_size = ROUNDUP_16( cachep_size );
    S->Cachep_size = cachep_size;

    S->Wx.Ws_size = 0;
    S->Wx.Wsc_size = 0;

    iax_size = ( Nx / 16 ) * nqy * sizeof( SAL_i32 );
    iax_size = ROUNDUP_16( iax_size );
    S->ITx.iA_size = iax_size;

    ibrx_size = ( Nx / 4 ) * nqy * sizeof( SAL_i32 );
    ibrx_size = ROUNDUP_16( ibrx_size );
    S->ITx.iBr_size = ibrx_size;

    iwx_size = ( Nx / 16 ) * nqy * sizeof( SAL_i32 );
    iwx_size = ROUNDUP_16( iwx_size );
    S->ITx.iW_size = iwx_size;

    icx_size = ( Nx / 16 ) * nqy * sizeof( SAL_i32 );
    icx_size = ROUNDUP_16( icx_size );
    S->ITx.iC_size = icx_size;
    S->ITx.iG_size = 0;

    isx_size = ( Nx / 2 ) * sizeof( SAL_i32 );
    isx_size = ROUNDUP_16( isx_size );
    S->iSx_size = isx_size;

    wsy_size = 6 * ( ( Ny / 32 ) - 1 ) * sizeof( SAL_f32 );

    if ( wsy_size < 0 )
        wsy_size = 0;

    wsy_size = ROUNDUP_16( wsy_size );
    S->Wy.Ws_size = wsy_size;
    wscy_size = ( 12 * Ny / 4 ) * sizeof( SAL_f32 );
    wscy_size = ROUNDUP_16( wscy_size );
    S->Wy.Wsc_size = wscy_size;

    if ( Lny & 0x1 )
        iay_size = ( Ny * nqx / 32 ) * sizeof( SAL_i32 );
    else
        iay_size = ( Ny * nqx / 16 ) * sizeof( SAL_i32 );

    iay_size = ROUNDUP_16( iay_size );
    S->ITy.iA_size = iay_size;
    ibry_size = ( Ny * nqx / 16 ) * sizeof( SAL_i32 );
    ibry_size = ROUNDUP_16( ibry_size );
    S->ITy.iBr_size = ibry_size;
    iwy_size = ( Ny * nqx / 16 ) * sizeof( SAL_i32 );
    iwy_size = ROUNDUP_16( iwy_size );
    S->ITy.iW_size = iwy_size;
    icy_size = ( Ny * nqx / 16 ) * sizeof( SAL_i32 );
    icy_size = ROUNDUP_16( icy_size );
    S->ITy.iC_size = icy_size;
    igy_size = ( ( Ny / 16 ) - 1 ) * 2 * sizeof( SAL_i32 );
    igy_size = ROUNDUP_16( igy_size );
    S->ITy.iG_size = igy_size;

    isy_size = ( Ny / 2 ) * sizeof( SAL_i32 );
    isy_size = ROUNDUP_16( isy_size );
    S->iSy_size = isy_size;

    nbytes = cachep_size + iax_size + ibrx_size + iwx_size + icx_size
             + wsy_size + wscy_size + iay_size
             + ibry_size + iwy_size + icy_size + igy_size
             + isx_size + isy_size;

    S->nbytes = nbytes;
    return( nbytes );
}

static SAL_i32  sal__fftxy_setup( SAL_cf32 *Wxyp, SAL_cf32 *Wxyp_fcs,
                                  FFT_C_WEIGHTS *Wx, FFT_C_TABLES *ITx,
                                  FFT_C_WEIGHTS *Wy, FFT_C_TABLES *ITy,
                                  SAL_i32  *iSx, SAL_i32  *iSy, SAL_i32  LNx, SAL_i32  LNqx,
                                  SAL_i32  LNy, SAL_i32  LNqy, SAL_i32  F )
{
    SAL_i32  g, gc, i, j, k, indx, rndx;
    SAL_i32  dx, dy, nc, NX, NY, Nqx, Nqy;
    SAL_i32  *tptr, *brptr, *icptr, *iaptr, *iwptr, *ibptr, *gptr;
    SAL_i32  abytes, alloc_bytes, wbytes;
    SAL_f64 freq, a;
    SAL_f64 cosa, sina;
    SAL_cf32 *wp;

    alloc_bytes = 0;

    NX = 1 << LNx;
    NY = 1 << LNy;
    Nqx = 1 << LNqx;
    Nqy = 1 << LNqy;

    freq = TWOPI_CONSTANT / ( SAL_f64 )( NX * NY );

    for ( i = 0; i < NY; i += Nqy )
    {
        for ( k = 0; k < Nqy; k++ )
        {
            wp = Wxyp + k;

            for ( j = 0; j < NX; j++ )
            {
                a = ( SAL_f64 )( ( i + k ) * j ) * freq;
                cosa = cos( a );
                sina = sin( a );

                wp->real = ( SAL_f32 )cosa;
                wp->imag = ( SAL_f32 )sina;
                wp += Nqy;
            }
        }

        Wxyp += ( Nqy * NX );
    }

    alloc_bytes = ( NY * NX * sizeof( SAL_cf32 ) );

    wp = Wxyp_fcs;

    for ( i = 0; i < NY; i++ )
        for ( j = 0; j < NX; j++ )
        {
            a = ( SAL_f64 )( i * j ) * freq;
            cosa = cos( a );
            sina = sin( a );

            wp->real = ( SAL_f32 )cosa;
            wp->imag = ( SAL_f32 )sina;
            wp++;
        }

    alloc_bytes = ( NY * NX * sizeof( SAL_cf32 ) ) << 1 ;

    brptr = iSx;
    tptr = iSx + ( NX / 4 );
    sal__fft_br_table_cf32( brptr, LNx );
    wbytes = sal__fftm_c_weights( Wx->Ws, Wx->Wsc, brptr, tptr, LNx );
    wbytes = ROUNDUP_16( wbytes );
    alloc_bytes += wbytes;

    j = 0;
    gptr = ITx->iG;

    for ( k = 1; k < NX / 16; k++ )
    {
        g = ( NX / 4 ) - brptr[k<<1];
        gc = brptr[g];
        gptr[k+( NX/16 )-1] = gc;

        if ( ( k & 0x1 ) == 0 )
        {
            gptr[j] = tptr[k];
            gptr[j+1] = tptr[gc>>1];
            j += 2;
        }
    }

    abytes = ( ( ( NX / 16 ) - 1 ) * 2 * sizeof( SAL_i32 ) );
    abytes = ROUNDUP_16( abytes );
    alloc_bytes += abytes;

    if ( LNx & 0x1 )
        nc = NX / 8;
    else
        nc = NX / 4;

    iaptr = ITx->iA;
    j = 0;

    for ( i = 0; i < ( nc*Nqy / 4 ); i++ )
    {
        *iaptr = j;
        j += ( 4 * ( sizeof( SAL_cf32 ) ) );
        iaptr++;
    }

    abytes = ( nc * ( Nqy / 4 ) * sizeof( SAL_i32 ) );
    abytes = ROUNDUP_16( abytes );
    alloc_bytes += abytes;

    ibptr = ITx->iBr;
    iwptr = ITx->iW;

    for ( i = 0; i < NX / 4; i++ )
        for ( j = 0; j < Nqy; j += 4 )
        {
            k = brptr[i] << 2;
            *ibptr = ( ( k * Nqy ) + j ) * ( sizeof( SAL_cf32 ) );
            *iwptr = i * 48;
            iwptr++;
            ibptr++;
        }

    abytes = ( ( NX / 4 ) * ( Nqy / 4 ) * 2 * sizeof( SAL_i32 ) );
    abytes = ROUNDUP_16( abytes );
    alloc_bytes += abytes;

    if ( F == CIP_SETUP )
    {
        dx = 4;
        dy = NX;
    }
    else
    {
        dx = ( 4 * NX );
        dy = 1;
    }

    indx = 0;
    rndx = 0;
    icptr = ITx->iC;

    if ( NX == NY )
        for ( i = 0; i < NX / 4; i++ )
        {
            if ( ( i & 0x3 ) == 0 )
            {
                indx = rndx;
                rndx += dx;
            }

            for ( j = 0; j < Nqy; j += 4 )
            {
                *icptr = ( indx + ( j * dy ) ) * ( sizeof( SAL_cf32 ) );
                icptr++;
            }

            indx += NX;
        }

    else
        for ( i = 0; i < NX / 4; i += 2 )
        {
            j = i / 2;

            if ( ( j & 0x3 ) == 0 )
            {
                indx = rndx;
                rndx += dx;
            }

            for ( j = 0; j < Nqy; j += 4 )
            {
                *icptr = ( indx + ( j * dy ) ) * sizeof( SAL_cf32 );
                icptr++;
            }

            for ( j = 0; j < Nqy; j += 4 )
            {
                *icptr = ( indx + ( NX / 2 ) + ( j * dy ) ) * sizeof( SAL_cf32 );
                icptr++;
            }

            indx += NX;
        }

    abytes = ( ( NX / 4 ) * ( Nqy / 4 ) * sizeof( SAL_i32 ) );
    abytes = ROUNDUP_16( abytes );
    alloc_bytes += abytes;

    brptr = iSy;
    tptr = iSy + ( NY / 4 );
    sal__fft_br_table_cf32( brptr, LNy );
    wbytes = sal__fftm_c_weights( Wy->Ws, Wy->Wsc, brptr, tptr, LNy );
    wbytes = ROUNDUP_16( wbytes );
    alloc_bytes += wbytes;

    j = 0;
    gptr = ITy->iG;

    for ( k = 1; k < NY / 16; k++ )
    {
        g = ( NY / 4 ) - brptr[k<<1];
        gc = brptr[g];
        gptr[k+( NY/16 )-1] = gc;

        if ( ( k & 0x1 ) == 0 )
        {
            gptr[j] = tptr[k];
            gptr[j+1] = tptr[gc>>1];
            j += 2;
        }
    }

    abytes = ( ( ( NY / 16 ) - 1 ) * 2 * sizeof( SAL_i32 ) );
    abytes = ROUNDUP_16( abytes );
    alloc_bytes += abytes;

    if ( LNy & 0x1 )
        nc = NY / 8;
    else
        nc = NY / 4;

    iaptr = ITy->iA;

    for ( i = 0; i < nc; i++ )
        for ( j = 0; j < Nqx; j += 4 )
        {
            *iaptr = ( ( i * NX ) + j ) * sizeof( SAL_cf32 );
            iaptr++;
        }

    abytes = ( ( nc ) * ( Nqx / 4 ) * sizeof( SAL_i32 ) );
    abytes = ROUNDUP_16( abytes );
    alloc_bytes += abytes;

    ibptr = ITy->iBr;
    iwptr = ITy->iW;

    for ( i = 0; i < NY / 4; i++ )
        for ( j = 0; j < Nqx; j += 4 )
        {
            k = brptr[i] << 2;
            *ibptr = ( ( k * Nqx ) + j ) * sizeof( SAL_cf32 );
            *iwptr = i * 48;
            ibptr++;
            iwptr++;
        }

    abytes = ( ( NY / 4 ) * ( Nqx / 4 ) * 2 * sizeof( SAL_i32 ) );
    abytes = ROUNDUP_16( abytes );
    alloc_bytes += abytes;

    icptr = ITy->iC;

    for ( i = 0; i < NY / 4; i++ )
        for ( j = 0; j < Nqx; j += 4 )
        {
            *icptr = ( ( i * NX ) + j ) * sizeof( SAL_cf32 );
            icptr++;
        }

    abytes = ( ( NY / 4 ) * ( Nqx / 4 ) * sizeof( SAL_i32 ) );
    abytes = ROUNDUP_16( abytes );
    alloc_bytes += abytes;

    return( alloc_bytes );
}

static SAL_i32  sal__fft2d_setup( FFT_C_TABLES *ITx,
                                  FFT_C_WEIGHTS *Wy, FFT_C_TABLES *ITy,
                                  SAL_i32  *iA, SAL_i32  *iC, SAL_i32  *iSx, SAL_i32  *iSy,
                                  SAL_i32  LNx, SAL_i32  LNqx, SAL_i32  LNy, SAL_i32  LNqy )
{
    SAL_i32  g, gc, i, j, k;
    SAL_i32  nc, NX, NY, Nqx, Nqy;
    SAL_i32  *tptr, *brptr, *icptr, *iaptr, *iwptr, *ibptr, *gptr;
    SAL_i32  abytes, alloc_bytes, wbytes;

    NX = 1 << LNx;
    NY = 1 << LNy;
    Nqx = 1 << LNqx;
    Nqy = 1 << LNqy;

    alloc_bytes = 1 << ( LNx + LNqy );

    if ( alloc_bytes < ( 1 << ( LNy + LNqx ) ) )
        alloc_bytes = ( 1 << ( LNy + LNqx ) );

    alloc_bytes *= sizeof( SAL_cf32 );

    brptr = iSx;
    tptr = iSx + ( NX / 4 );
    sal__fft_br_table_cf32( brptr, LNx );

    iaptr = ITx->iA;

    for ( j = 0; j < Nqy; j++ )
        for ( i = 0; i < NX / 16; i++ )
        {
            *iaptr = iA[i] + ( ( j * NX ) * sizeof( SAL_cf32 ) );
            iaptr++;
        }

    alloc_bytes += ( ( NX / 16 ) * Nqy * sizeof( SAL_i32 ) );

    ibptr = ITx->iBr;

    for ( i = 0; i < NX / 4; i++ )
        for ( j = 0; j < Nqy; j++ )
        {
            *ibptr = ( ( i * 4 ) + ( j * NX ) ) * sizeof( SAL_cf32 );
            ibptr++;
        }

    alloc_bytes += ( ( NX / 4 ) * Nqy * sizeof( SAL_i32 ) );

    iwptr = ITx->iW;

    for ( j = 0; j < Nqy; j++ )
        for ( i = 0; i < NX / 16; i++ )
        {
            *iwptr = ( i * WINC );
            iwptr++;
        }

    alloc_bytes += ( ( NX / 16 ) * Nqy * sizeof( SAL_i32 ) );

    icptr = ITx->iC;

    for ( j = 0; j < Nqy; j++ )
        for ( i = 0; i < NX / 16; i++ )
        {
            *icptr = iC[i] + ( ( j * NX ) * sizeof( SAL_cf32 ) );
            icptr++;
        }

    alloc_bytes += ( ( NX / 16 ) * Nqy * sizeof( SAL_i32 ) );

    brptr = iSy;
    tptr = iSy + ( NY / 4 );

    sal__fft_br_table_cf32( brptr, LNy );
    wbytes = sal__fftm_c_weights( Wy->Ws, Wy->Wsc, brptr, tptr, LNy );
    alloc_bytes += wbytes;

    j = 0;
    gptr = ITy->iG;

    for ( k = 1; k < NY / 16; k++ )
    {
        g = ( NY / 4 ) - brptr[k<<1];
        gc = brptr[g];
        gptr[k+( NY/16 )-1] = gc;

        if ( ( k & 0x1 ) == 0 )
        {
            gptr[j] = tptr[k];
            gptr[j+1] = tptr[gc>>1];
            j += 2;
        }
    }

    abytes = ( ( ( NY / 16 ) - 1 ) * 2 * sizeof( SAL_i32 ) );
    abytes = ROUNDUP_16( abytes );
    alloc_bytes += abytes;

    if ( LNy & 0x1 )
        nc = NY / 8;
    else
        nc = NY / 4;

    iaptr = ITy->iA;

    for ( i = 0; i < nc; i++ )
        for ( j = 0; j < Nqx; j += 4 )
        {
            *iaptr = ( ( i * NX ) + j ) * sizeof( SAL_cf32 );
            iaptr++;
        }

    alloc_bytes += ( nc * ( Nqx / 4 ) * sizeof( SAL_i32 ) );

    ibptr = ITy->iBr;
    iwptr = ITy->iW;

    for ( i = 0; i < NY / 4; i++ )
        for ( j = 0; j < Nqx; j += 4 )
        {
            k = brptr[i] << 2;
            *ibptr = ( ( k * Nqx ) + j ) * sizeof( SAL_cf32 );
            *iwptr = i * 48;
            ibptr++;
            iwptr++;
        }

    alloc_bytes += ( ( NY / 4 ) * ( Nqx / 4 ) * 2 * sizeof( SAL_i32 ) );

    icptr = ITy->iC;

    for ( i = 0; i < NY / 4; i++ )
        for ( j = 0; j < Nqx; j += 4 )
        {
            *icptr = ( ( i * NX ) + j ) * sizeof( SAL_cf32 );
            icptr++;
        }

    alloc_bytes += ( ( NY / 4 ) * ( Nqx / 4 ) * sizeof( SAL_i32 ) );

    return( alloc_bytes );
}

static SAL_i32  sal__fftm_c_weights( SAL_f32 *W, SAL_f32 *Wsc,
                                     SAL_i32  *BrT, SAL_i32  *S, SAL_i32  LN )
{
    SAL_i32  wsc_bytes, wbytes, No4;
    SAL_i32  jnum, is, k, j, N;
    SAL_f64 freq, a, b, c;
    SAL_f64 cos1, cos2, cos3, acos3;
    SAL_f64 sin1, sin2, sin3, asin3;
    SAL_f32 wt2r, w2r, wt1r, wt3r;
    SAL_f32 w3re, wt13r;
    SAL_f32 wr1, wr2, wr3;
    SAL_f32 wi1, wi2, wi3;
    SAL_f64 dtmp;

    N = 1 << LN;
    freq = TWOPI_CONSTANT / ( SAL_f64 )N;
    No4 = N >> 2;
    wbytes = 0;
    is = 0;
    S[is] = 0;
    is++;

    for ( j = 1; j < N / 16; j++ )
    {
        k = BrT[j];
        a = ( SAL_f64 )k * freq;
        b = a + a;
        c = a + b;

        cos1 = cos( a );
        cos2 = cos( b );
        cos3 = cos( c );
        sin1 = sin( a );
        sin2 = sin( b );
        sin3 = sin( c );

        if ( cos3 < 0 )
            acos3 = -cos3;
        else
            acos3 = cos3;

        if ( sin3 < 0 )
            asin3 = -sin3;
        else
            asin3 = sin3;

        jnum = j & 0x3;
        wt1r = 0;
        wt2r = 0;
        w2r = 0;
        wt3r = 0;
        wt13r = 0;
        w3re = 0;

        switch ( ( SAL_i32 )jnum )
        {
            case SC1_SC2_SC3:

                if ( asin3 > acos3 )
                {
                    dtmp = sin1 / cos1;
                    wt1r = ( SAL_f32 )dtmp;

                    dtmp = sin2 / cos2;
                    wt2r = ( SAL_f32 )dtmp;

                    w2r = ( SAL_f32 )cos2;

                    dtmp = cos3 / sin3;
                    wt3r = ( SAL_f32 )dtmp;

                    dtmp = sin3 / cos1;
                    wt13r = ( SAL_f32 )dtmp;
                    w3re = ( SAL_f32 )cos1;

                    S[is] = 0;
                    is++;
                }

                else
                {
                    dtmp = sin1 / cos1;
                    wt1r = ( SAL_f32 )dtmp;

                    dtmp = sin2 / cos2;
                    wt2r = ( SAL_f32 )dtmp;

                    w2r = ( SAL_f32 )cos2;

                    dtmp = sin3 / cos3;
                    wt3r = ( SAL_f32 )dtmp;

                    dtmp = cos3 / cos1;
                    wt13r = ( SAL_f32 )dtmp;
                    w3re = ( SAL_f32 )cos1;

                    S[is] = 1;
                    is++;
                }

                break;

            case CS1_CS2_SC3:
                dtmp = cos1 / sin1;
                wt1r = ( SAL_f32 )dtmp;

                dtmp = cos2 / sin2;
                wt2r = ( SAL_f32 )dtmp;

                w2r = ( SAL_f32 )sin2;

                dtmp = sin3 / cos3;
                wt3r = ( SAL_f32 )dtmp;

                dtmp = sin1 / cos3;
                wt13r = ( SAL_f32 )dtmp;
                w3re = ( SAL_f32 )cos3;

                break;

            case SC1_CS2_CS3:
                dtmp = sin1 / cos1;
                wt1r = ( SAL_f32 )dtmp;

                dtmp = cos2 / sin2;
                wt2r = ( SAL_f32 )dtmp;

                w2r = ( SAL_f32 )sin2;

                dtmp = cos3 / sin3;
                wt3r = ( SAL_f32 )dtmp;

                dtmp = cos1 / sin3;
                wt13r = ( SAL_f32 )dtmp;
                w3re = ( SAL_f32 )sin3;

                break;

            case CS1_SC2_SC3:

                if ( asin3 > acos3 )
                {
                    dtmp = cos1 / sin1;
                    wt1r = ( SAL_f32 )dtmp;

                    dtmp = sin2 / cos2;
                    wt2r = ( SAL_f32 )dtmp;

                    w2r = ( SAL_f32 )cos2;

                    dtmp = cos3 / sin3;
                    wt3r = ( SAL_f32 )dtmp;

                    dtmp = sin3 / sin1;
                    wt13r = ( SAL_f32 )dtmp;
                    w3re = ( SAL_f32 )sin1;

                    S[is] = 0;
                    is++;

                }
                else
                {
                    dtmp = cos1 / sin1;
                    wt1r = ( SAL_f32 )dtmp;

                    dtmp = sin2 / cos2;
                    wt2r = ( SAL_f32 )dtmp;

                    w2r = ( SAL_f32 )cos2;

                    dtmp = sin3 / cos3;
                    wt3r = ( SAL_f32 )dtmp;

                    dtmp = cos3 / sin1;
                    wt13r = ( SAL_f32 )dtmp;
                    w3re = ( SAL_f32 )sin1;

                    S[is] = 1;
                    is++;

                }

                break;
        }

        if ( ( j & 0x1 ) == 0 )
        {
            *W = wt1r;
            W++;
            *W = wt2r;
            W++;
            *W = wt3r;
            W++;
            *W = w2r;
            W++;
            *W = w3re;
            W++;
            *W = wt13r;
            W++;
            wbytes += 24;
        }
    }

    wbytes = ROUNDUP_16( wbytes );

    wsc_bytes = 0;

    for ( j = 0; j < No4; j++ )
    {
        a = ( SAL_f32 )j * freq;
        b = a + a;
        c = a + b;

        wr1 = ( SAL_f32 )cos( a );
        *Wsc = -wr1;
        *( Wsc + 1 ) = wr1;
        Wsc += 2;
        wbytes += 8;
        wsc_bytes += 8;

        wi1 = ( SAL_f32 )sin( a );
        *Wsc = -wi1;
        *( Wsc + 1 ) = -wi1;
        Wsc += 2;
        wbytes += 8;
        wsc_bytes += 8;

        wr2 = ( SAL_f32 )cos( b );
        *Wsc = wr2;
        *( Wsc + 1 ) = wr2;
        Wsc += 2;
        wbytes += 8;
        wsc_bytes += 8;

        wi2 = ( SAL_f32 )sin( b );
        *Wsc = wi2;
        *( Wsc + 1 ) = -wi2;
        Wsc += 2;
        wbytes += 8;
        wsc_bytes += 8;

        wr3 = ( SAL_f32 )cos( c );
        *Wsc = wr3;
        *( Wsc + 1 ) = wr3;
        Wsc += 2;
        wbytes += 8;
        wsc_bytes += 8;

        wi3 = ( SAL_f32 )sin( c );
        *Wsc = wi3;
        *( Wsc + 1 ) = -wi3;
        Wsc += 2;
        wbytes += 8;
        wsc_bytes += 8;
    }

    wbytes = ROUNDUP_16( wbytes );
    wsc_bytes = ROUNDUP_16( wsc_bytes );

    return( wbytes );
}

