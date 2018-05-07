#  ----------------------------------------------------------------------------
#  
#      OpenSAL is an Open Source Scientific Algorithms Library consisting
#      of an API for several hundred math functions. The Library is
#      composed of a C source code reference implementation. Commercial
#      versions of this library are used as performance accelerators in
#      HPEC applications.
#  
#      Copyright (C) 2010 Mercury Computer Systems, Inc.
#  
#      This program is free software: you can redistribute it and/or modify
#      it under the terms of the GNU General Public License as published by
#      the Free Software Foundation, either version 3 of the License, or
#      (at your option) any later version.
#  
#      This program is distributed in the hope that it will be useful,
#      but WITHOUT ANY WARRANTY; without even the implied warranty of
#      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#      GNU General Public License for more details.
#  
#      You should have received a copy of the GNU General Public License
#      along with this program. If not, see <http://www.gnu.org/licenses/
#  
#  ----------------------------------------------------------------------------
#  
#      Filename:
#          Makefile
#  
#      Description:
#          Makefile for building OpenSAL library archives.
#  
#  ----------------------------------------------------------------------------

TARGET_ARCH := "\"Linux-Intel-X86/X86_64\""

TOOLS_DIR := /usr/bin

# ----- archiver ----- #

AR := $(TOOLS_DIR)/ar

ARFLAGS := -cru

# ----- compiler ----- #

CC := $(TOOLS_DIR)/gcc

CCFLAGS_COMMON := -g -Wall -Werror -Wextra

ifdef TARGET_ARCH
	CCFLAGS_COMMON += -DSAL_ARCH=$(TARGET_ARCH)
endif

CCFLAGS_32 := $(CCFLAGS_COMMON) -m32
CCFLAGS_64 := $(CCFLAGS_COMMON) -m64 -DBUILD_64

# ----- header file search paths ----- #

INCL_PATHS := \
  -I./src/selectors/include \
  -I./src/adapters/include \
  -I./include

# ----- library object files ----- #

OBJ_SUFFIX_32 := o_sal
OBJ_SUFFIX_64 := o_sal64

ADAPTER_SRCS := $(shell find ./src/adapters/src/ -name "*.c")

ADAPTER_OBJS_32 := $(strip $(ADAPTER_SRCS:%.c=%.$(OBJ_SUFFIX_32)))
ADAPTER_OBJS_64 := $(strip $(ADAPTER_SRCS:%.c=%.$(OBJ_SUFFIX_64)))

API_SRCS := $(shell find ./src/api/ -name "*.c")

API_OBJS_32 := $(strip $(API_SRCS:%.c=%.$(OBJ_SUFFIX_32)))
API_OBJS_64 := $(strip $(API_SRCS:%.c=%.$(OBJ_SUFFIX_64)))

# ----- build goals ----- #

default: libsal libsal64

libsal: libsal.a

libsal64: libsal64.a

# ----- build rules (32-bit) ----- #

libsal.a: $(API_OBJS_32) $(ADAPTER_OBJS_32)
	$(AR) $(ARFLAGS) $@ $^

%.$(OBJ_SUFFIX_32): %.c
	$(CC) $(CCFLAGS_32) $(INCL_PATHS) -o $@ -c $<

# ----- build rules (64-bit) ----- #

libsal64.a: $(API_OBJS_64) $(ADAPTER_OBJS_64)
	$(AR) $(ARFLAGS) $@ $^

%.$(OBJ_SUFFIX_64): %.c
	$(CC) $(CCFLAGS_64) $(INCL_PATHS) -o $@ -c $<

# ----- clean rules ----- #

clean clean_all: clean_libsal clean_libsal64

clean_libsal: FORCE
	rm -f $(ADAPTER_OBJS_32) $(API_OBJS_32) libsal.a

clean_libsal64: FORCE
	rm -f $(ADAPTER_OBJS_64) $(API_OBJS_64) libsal64.a

FORCE:

###############################################################################

