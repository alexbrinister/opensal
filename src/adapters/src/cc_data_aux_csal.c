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
        cc_data_aux_csal.c

----------------------------------------------------------------------------
*/

#include "csal_internal.h"

CC_DATA PREFIX( cc_data )[] =
{
    {   32, ( SAL_f32 )    4.568},
    {   64, ( SAL_f32 )    8.144},
    {  128, ( SAL_f32 )   15.369},
    {  256, ( SAL_f32 )   32.410},
    {  512, ( SAL_f32 )   66.630},
    { 1024, ( SAL_f32 )  145.830},
    { 2048, ( SAL_f32 )  304.880},
    { 4096, ( SAL_f32 )  665.130},
    { 8192, ( SAL_f32 ) 1395.100},
    {16384, ( SAL_f32 ) 3018.200}
};

