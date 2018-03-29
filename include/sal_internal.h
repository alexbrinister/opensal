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
        sal_internal.h

----------------------------------------------------------------------------
*/

#ifndef SAL_INTERNAL_H
#define SAL_INTERNAL_H

#include <stdlib.h>
#include "sal.h"

#if defined(BUILD_CNTR)
#include "sal_cntr.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#define SAL_NX 0

#define SAL_RETURN(code) ;
#define SAL_CALL_RETURN(code)  (code);
#define SAL_CALL_RETURN_INT(code) { \
        code; \
        return 0; \
    }

#define SAL_RINFO_INIT(r_info) { \
        r_info.code = SAL_SUCCESS; \
        r_info.path = SAL_PATH_NOTHING; \
    }

#define SAL_RINFO_SET_PATH(r_info, p) { \
        r_info->path = p; \
    }

#define SAL_RINFO_SET_CODE(r_info, c) { \
        r_info->code = c; \
    }

#define SAL_RINFO_RETURN(r_info)  return;
#define SAL_RINFO_RETURN_INT(r_info) return (r_info.code);
#define SAL_RINFO_PTR_RETURN_INT(r_info) return (r_info->code);

#define SAL_RINFO_CHECK_CODE(r_info) {  \
        if (r_info->code != SAL_SUCCESS ) { \
            return;                           \
        }                                   \
    }

#define SAL_RINFO_CHECK_CODE_INT(r_info) { \
        if (r_info->code != SAL_SUCCESS) {     \
            return (r_info)->code;               \
        }                                      \
    }

    typedef struct
    {
        SAL_i32  code;
        SAL_i32  path;
    } Return_info;

    typedef struct
    {
        SAL_i32  code;
        SAL_i32  path;
    } SAL__return_info;

#define  SAL_LOG_TATL_TRACE_BEGIN( SAL_OP )  ;

#define  SAL_LOG_TATL_TRACE_END( SAL_OP, r_info )  ;

#ifdef __cplusplus
}
#endif

#endif

