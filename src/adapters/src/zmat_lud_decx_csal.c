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
        zmat_lud_decx_csal.c

----------------------------------------------------------------------------
*/

#include "sal_internal.h"
#include "adapters.h"
#include <stdlib.h>
#include "csal_internal.h"
#include "sal_csal_common_internal.h"

#define MODSQR( zrp, zip )    ( (zrp)*(zrp) + (zip)*(zip) )
#define COMPLEX_SPLIT_ASSIGN( wrp, wip, zrp, zip ) \
    wrp = zrp; \
    wip = zip;

void PREFIX( zvnsmam )( SAL_f32 *Arp, SAL_f32 *Aip, SAL_f32 *Brp, SAL_f32 *Bip, SAL_f32 *Crp, SAL_f32 *Cip, SAL_i32 Ctcols, SAL_i32 n, SAL_i32 m );

void PREFIX( zmat_lud_decx_csal )(
    SAL_zf32 *A,
    SAL_i32 Atcols,
    SAL_i32 *VPerm,
    SAL_i32 n,
    SAL_f32 *rcond_est,

    SAL_zf32 *v,

    SAL_i32 flag,

    SAL_i32 XFLAG,
    SAL__return_info *r_info
)
{
    ( void ) XFLAG;

    SAL_i32 i, k;
    SAL_f32 max_elem_modsqr, temp_modsqr;
    SAL_f32 max_elem_rp, max_elem_ip, temp_rp, temp_ip;
    SAL_i32 max_index;
    SAL_i32 tmpi;
    SAL_f32 *Arp, *Aip, *Brp, *Bip;

    if ( n < 2 )
    {
        SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
        SAL_RINFO_SET_CODE( r_info, SAL_SUCCESS + 1 );
        return;
    }

    Arp = A->realp;
    Aip = A->imagp;

    PREFIX( _csal_malloc_mat_float ) ( &Brp, n, 1 );
    PREFIX( _csal_malloc_mat_float ) ( &Bip, n, 1 );

    for ( i = 0; i < n; i++ )
    {
        VPerm[i] = i;
    }

    for ( k = 0; k < n - 1 ; k++ )
    {

        for ( i = k; i < n; i++ )
        {
            COMPLEX_SPLIT_ASSIGN( Brp[i], Bip[i], Arp[i*Atcols + k], Aip[i*Atcols + k] )
        }

        COMPLEX_SPLIT_ASSIGN( max_elem_rp, max_elem_ip, Brp[k], Bip[k] )
        max_index = k;

        for ( i = k + 1; i < n; i++ )
        {
            if ( MODSQR ( Brp[i], Bip[i] )
                 > MODSQR ( max_elem_rp, max_elem_ip ) )
            {
                COMPLEX_SPLIT_ASSIGN( max_elem_rp, max_elem_ip, Brp[i], Bip[i] )
                max_index = i;
            }
        }

        tmpi = VPerm[k];
        VPerm[k] = VPerm[max_index];
        VPerm[max_index] = tmpi;

        max_elem_modsqr = MODSQR ( max_elem_rp, max_elem_ip );

        if ( max_elem_modsqr > 0.0 )
        {

            if ( max_index != k )
            {
                for ( i = 0; i < n; i++ )
                {
                    COMPLEX_SPLIT_ASSIGN( temp_rp, temp_ip, Arp[k*Atcols + i], Aip[k*Atcols + i] )
                    COMPLEX_SPLIT_ASSIGN( Arp[k*Atcols + i], Aip[k*Atcols + i], Arp[max_index*Atcols + i], Aip[max_index*Atcols + i] )
                    COMPLEX_SPLIT_ASSIGN( Arp[max_index*Atcols + i], Aip[max_index*Atcols + i], temp_rp, temp_ip )
                }

                COMPLEX_SPLIT_ASSIGN( temp_rp, temp_ip, Brp[k], Bip[k] )
                COMPLEX_SPLIT_ASSIGN( Brp[k], Bip[k], Brp[max_index], Bip[max_index] )
                COMPLEX_SPLIT_ASSIGN( Brp[max_index], Bip[max_index], temp_rp, temp_ip )
            }

            Brp[k] = Arp[k*Atcols + k] = max_elem_rp / max_elem_modsqr;
            Bip[k] = Aip[k*Atcols + k] = -max_elem_ip / max_elem_modsqr;

            for ( i = k + 1; i < n; i++ )
            {
                temp_rp = Brp[i] * Brp[k] - Bip[i] * Bip[k];
                Bip[i] = Brp[i] * Bip[k] + Bip[i] * Brp[k];
                Brp[i] = temp_rp;
                COMPLEX_SPLIT_ASSIGN( Arp[i*Atcols + k], Aip[i*Atcols + k], Brp[i], Bip[i] )
            }

            if ( n - k - 1 > 0  &&  n - k - 1 > 0 )
            {
                PREFIX( zvnsmam )( &Arp[k*Atcols + k + 1], &Aip[k*Atcols + k + 1], &Brp[k+1], &Bip[k+1], &Arp[( k+1 )*Atcols + k + 1], &Aip[( k+1 )*Atcols + k + 1], Atcols, n - k - 1, n - k - 1 );
            }
        }

    }

    k = n - 1;

    temp_modsqr = MODSQR( Arp[k*Atcols + k], Aip[k*Atcols + k] );

    if ( temp_modsqr > 0.0 )
    {
        Arp[k*Atcols + k] = Arp[k*Atcols + k] / temp_modsqr;
        Aip[k*Atcols + k] = -Aip[k*Atcols + k] / temp_modsqr;
    }

    free( Bip );
    free( Brp );

    SAL_RINFO_SET_PATH( r_info, SAL_PATH_CSAL );
    SAL_RINFO_SET_CODE( r_info, 0 );
    return;
}

void PREFIX( zvnsmam )( SAL_f32 *Arp, SAL_f32 *Aip, SAL_f32 *Brp, SAL_f32 *Bip, SAL_f32 *Crp, SAL_f32 *Cip, SAL_i32 Ctcols, SAL_i32 n, SAL_i32 m )
{
    SAL_i32 i, j;

    for ( i = 0; i < m; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            Crp[i*Ctcols + j] = -( Arp[j] * Brp[i] - Aip[j] * Bip[i] ) + Crp[i*Ctcols + j];
            Cip[i*Ctcols + j] = -( Arp[j] * Bip[i] + Aip[j] * Brp[i] ) + Cip[i*Ctcols + j];
        }
    }

    return;
}
