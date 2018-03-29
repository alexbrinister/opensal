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
        zmat_svdx_aux_csal.h

----------------------------------------------------------------------------
*/

#ifndef ZMAT_SVDX_AUX_CSAL_H
#define ZMAT_SVDX_AUX_CSAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <csal_internal.h>

    static SAL_i32 PREFIX( zmat_gs_xtend ) ( SAL_zf32 *Q, SAL_i32 tcols, SAL_i32 m, SAL_i32 n, SAL_i32 nx );

#define MACHEPS_SP 1.2e-7
#define ROW_THRESH1 5.e-1

#define ROW_THRESH2 0.05*MACHEPS_SP

#define MAX_ORTHOG_ITER 5

    static SAL_i32 PREFIX( zmat_gs_xtend ) ( SAL_zf32 *Q, SAL_i32 tcols, SAL_i32 m, SAL_i32 n, SAL_i32 nx )
    {

        SAL_i32 i, k, l, ei_index;
        SAL_i32 new_row_index;
        SAL_f32 *new_row_rp, *new_row_ip, sum_rp, sum_ip, norm, nu, nu_scale, sigma;
        SAL_f32 *Qrp, *Qip;
        SAL_i32 retval = 0;

        Qrp = Q->realp;
        Qip = Q->imagp;

        if ( ( nx <= n ) | ( nx > m ) )
        {
            retval = 1;
        }
        else
        {
            ei_index = 0;
            new_row_index = n;

            while ( new_row_index < nx )
            {
                new_row_rp = &Q->realp[new_row_index*tcols];
                new_row_ip = &Q->imagp[new_row_index*tcols];

                for ( i = 0; i < m; i++ )
                {
                    new_row_rp[i] = new_row_ip[i] = 0.0;
                }

                new_row_rp[ei_index] = 1.0;

                nu = sigma = 1.0;

                for ( l = 0; l < MAX_ORTHOG_ITER; l++ )
                {
                    for ( k = 0; k < new_row_index; k++ )
                    {

                        sum_rp = sum_ip = 0.0;

                        for ( i = 0; i < m; i++ )
                        {
                            sum_rp +=   Qrp[k*tcols+i] * new_row_rp[i]
                                        + Qip[k*tcols+i] * new_row_ip[i];
                            sum_ip +=   Qrp[k*tcols+i] * new_row_ip[i]
                                        - Qip[k*tcols+i] * new_row_rp[i];
                        }

                        for ( i = 0; i < m; i++ )
                        {
                            new_row_rp[i] -=   sum_rp * Qrp[k*tcols + i]
                                               - sum_ip * Qip[k*tcols + i];
                            new_row_ip[i] -=   sum_rp * Qip[k*tcols + i]
                                               + sum_ip * Qrp[k*tcols + i];
                        }
                    }

                    norm = 0.0;

                    for ( i = 0; i < m; i++ )
                    {
                        norm += new_row_rp[i] * new_row_rp[i] + new_row_ip[i] * new_row_ip[i];
                    }

                    norm = sqrt( norm );

                    if ( norm / sigma > ROW_THRESH1 )
                    {
                        break;
                    }

                    nu_scale = nu * ROW_THRESH2;

                    if ( norm > nu_scale )
                    {

                        sigma = norm;
                    }
                    else
                    {
                        nu = sigma = nu_scale;
                        ei_index++;

                        if ( ++ei_index >= m )
                        {
                            return 1;
                        }

                        for ( i = 0; i < m; i++ )
                        {
                            new_row_rp[i] = new_row_ip[i] = 0.0;
                        }

                        new_row_rp[ei_index] = sigma;
                    }
                }

                for ( i = 0; i < m; i++ )
                {
                    new_row_rp[i] /= norm;
                    new_row_ip[i] /= norm;
                }

                new_row_index++;

                if ( ++ei_index >= m )
                {
                    return 1;
                }

            }

        }

        SAL_SET_PATH_CSAL();
        return retval;
    }

#ifdef __cplusplus
}
#endif

#endif
