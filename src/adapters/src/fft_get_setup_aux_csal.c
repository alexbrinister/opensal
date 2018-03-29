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
        fft_get_setup_aux_csal.c

----------------------------------------------------------------------------
*/

#include "fft_internal.h"

void fft_get_setup_aux_complex_twidp( FFT_setup *usr_setupp, SAL_zf32 *twidp_p )
{
    SAL__fft_setup_csal  *setupp = ( *usr_setupp )->csal_fft_setup;

    *twidp_p = setupp->aux.complex_twidp;
}

void fft_get_setup_aux_complex_log( FFT_setup *usr_setupp, SAL_ui32 *log2x_p, SAL_ui32 *log2y_p )
{
    SAL__fft_setup_csal  *setupp = ( *usr_setupp )->csal_fft_setup;

    *log2x_p = setupp->aux.complex_log2x;
    *log2y_p = setupp->aux.complex_log2y;
}

void fft_get_setup_aux_real_twidp( FFT_setup *usr_setupp, SAL_zf32 *twidp_p )
{
    SAL__fft_setup_csal  *setupp = ( *usr_setupp )->csal_fft_setup;

    *twidp_p = setupp->aux.real_twidp;
}

void fft_get_setup_aux_real_log( FFT_setup *usr_setupp, SAL_ui32 *log2x_p, SAL_ui32 *log2y_p )
{
    SAL__fft_setup_csal  *setupp = ( *usr_setupp )->csal_fft_setup;

    *log2x_p = setupp->aux.real_log2x;
    *log2y_p = setupp->aux.real_log2y;
}

void fft_get_setup_aux_tempp( FFT_setup *usr_setupp, void **tempp_p )
{
    SAL__fft_setup_csal  *setupp = ( *usr_setupp )->csal_fft_setup;

    *tempp_p = setupp->aux.tempp;
}

void fft_get_setup_vmx_setup_ct_1dxy( FFT_setup *usr_setupp, FFT_C_XY **setup_ct_1dxy_p )
{
    SAL__fft_setup_csal  *setupp = ( *usr_setupp )->csal_fft_setup;

    *setup_ct_1dxy_p = setupp->vmx.setup_ct_1dxy;
}
