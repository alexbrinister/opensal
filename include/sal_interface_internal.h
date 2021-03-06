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
        sal_interface_internal.h

----------------------------------------------------------------------------
*/

#ifndef SAL_INTERFACE_INTERNAL_H
#define SAL_INTERFACE_INTERNAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "sal.h"
#include "sal_macros.h"

    extern void PREFIX( fft_setup_thread_safe_ ) ( SAL_ui32 *LOG2M, SAL_i32 *FLAG, FFT_setup *SETUPP, SAL_ui32 *NBYTESP, void *BUFFERP, SAL_ui32 *NTHREADS );
    extern void PREFIX( fft_setup_thread_safed_ ) ( SAL_ui32 *LOG2M, SAL_i32 *FLAG, FFT_setupd *SETUPP, SAL_ui32 *NBYTESP, void *BUFFERP, SAL_ui32 *NTHREADS );
    extern void PREFIX( fft_setup_thread_safe ) ( SAL_ui32 LOG2M, SAL_i32 FLAG, FFT_setup *SETUPP, SAL_ui32 *NBYTESP, void *BUFFERP, SAL_ui32 NTHREADS );
    extern void PREFIX( fft_setup_thread_safed ) ( SAL_ui32 LOG2M, SAL_i32 FLAG, FFT_setupd *SETUPP, SAL_ui32 *NBYTESP, void *BUFFERP, SAL_ui32 NTHREADS );

    extern void PREFIX( sal_get_fft_setup_by_rank_ ) ( FFT_setup *SETUPP, SAL_ui32 *RANK, FFT_setup *WSETUPP );
    extern void PREFIX( sal_get_fft_setup_by_rankd_ ) ( FFT_setupd *SETUPP, SAL_ui32 *RANK, FFT_setupd *WSETUPP );
    extern void PREFIX( sal_get_fft_setup_by_rank ) ( FFT_setup *SETUPP, SAL_ui32 RANK, FFT_setup *WSETUPP );
    extern void PREFIX( sal_get_fft_setup_by_rankd ) ( FFT_setupd *SETUPP, SAL_ui32 RANK, FFT_setupd *WSETUPP );

#ifdef __cplusplus
}
#endif

#endif

