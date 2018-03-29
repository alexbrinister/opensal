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
        herm_schur_1s_row_aux_csal.c

----------------------------------------------------------------------------
*/

#include <math.h>
#include "csal_internal.h"

#define MACHEPS_SP 1.2e-7
#define ABS( a )         ( ( (a) >= (0.0) ) ? (a) : -(a) )

SAL_i32 PREFIX( _csal_herm_schur_1s_row )( SAL_zf32 *U, SAL_i32 Utcols, SAL_i32 n, SAL_i32 p, SAL_i32 q, SAL_f32 *Pret )
{
    SAL_f32 dotpqabs = 0.0, dotpqrp = 0.0, dotpqip = 0.0, dotpp = 0.0, dotqq = 0.0, tau, t;
    SAL_i32 i, retval = 0;
    SAL_f32 *urp, *uip;

    urp = U->realp;
    uip = U->imagp;

    for ( i = 0; i < n; i++ )
    {
        dotpqrp += urp[p*Utcols + i] * urp[q*Utcols + i]
                   + uip[p*Utcols + i] * uip[q*Utcols + i];
        dotpqip += -urp[p*Utcols + i] * uip[q*Utcols + i]
                   + uip[p*Utcols + i] * urp[q*Utcols + i];
        dotpp +=   urp[p*Utcols + i] * urp[p*Utcols + i]
                   + uip[p*Utcols + i] * uip[p*Utcols + i];
        dotqq +=   urp[q*Utcols + i] * urp[q*Utcols + i]
                   + uip[q*Utcols + i] * uip[q*Utcols + i];
    }

    dotpqabs = PREFIX( _csal_cmodulus )( &dotpqrp, &dotpqip );
    Pret[0] = 1.0;
    Pret[1] = 0.0;
    Pret[2] = 0.0;
    Pret[3] = 0.0;

    if ( dotpqabs != 0.0 )
    {
        tau = ( dotpp - dotqq ) / ( 2.0 * dotpqabs );

        if ( dotpqabs > MACHEPS_SP * sqrt( dotpp ) * sqrt( dotqq ) )
        {
            Pret[2] = dotpqrp / dotpqabs;
            Pret[3] = dotpqip / dotpqabs;
            tau = ( dotpp - dotqq ) / ( 2.0 * dotpqabs );

            if ( tau >= 0.0 )
            {
                retval = 1;

                t = 1.0 / ( tau + sqrt( tau ) * sqrt( tau + 1.0 / tau ) );
            }
            else
            {
                retval = -1;

                t = -1.0 / ( -tau + sqrt( -tau ) * sqrt( -tau - 1.0 / tau ) );
            }

            Pret[0] = 1.0 / sqrt( 1.0 + t * t );
            Pret[1] = t * Pret[0];
        }
    }

    Pret[2] *= Pret[1];
    Pret[3] *= Pret[1];

    return( retval );
}

SAL_f32 PREFIX( _csal_cmodulus )( SAL_f32 *v1, SAL_f32 *v2 )
{
    SAL_f32 a, b, c, rho;

    a = *v1;
    b = *v2;

    if ( a == 0 && b == 0 )
    {
        c = 0.0;
    }
    else
    {
        a = ABS( a );
        b = ABS( b );

        if ( a > b )
        {
            rho = b / a;
            c = a * sqrt( 1.0 + rho * rho );
        }
        else
        {
            rho = a / b;
            c = b * sqrt( 1.0 + rho * rho );
        }
    }

    return c;
}
