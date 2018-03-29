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
        fixr_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_internal.h"

SAL_i32 PREFIX( _csal_fixr_ieee )( SAL_f32 *fp )
{
    SAL_i32  i;
    SAL_f32  f;

    f = *fp;

    if ( f < ( SAL_f32 )0.0 )
        f = -f;

    f += ( SAL_f32 )0.5;
    i = ( SAL_i32 )f;

    if ( f == ( SAL_f32 )i )
        i &= -2;

    if ( *fp < ( SAL_f32 )0.0 )
        i = -i;

    SAL_SET_PATH_CSAL();

    return ( i );
}
