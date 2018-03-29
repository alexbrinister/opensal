#  ----------------------------------------------------------------------------
#  
#      The Open Source Scientific Algorithms Library (OpenSAL) consists
#      of an API for several hundred math functions. The library is
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
#      along with this program. If not, see <http://www.gnu.org/licenses/>.
#  
#  ----------------------------------------------------------------------------
#  
#      Filename:
#          README
#  
#      Description:
#          Illustrates package structure, describes package contents, and 
#          provides instructions for building the library using the supplied
#          Makefile.
#
#      Part number:
#          DOC-RLD-OPENSAL1-V1.0
#          
#  ----------------------------------------------------------------------------


Package Structure
=================

${install_dir}/ +
                |- opensal-x.x.x/ +
                                  |- OpenSALWebhelp/
                                  |- README
                                  |- Makefile
                                  |- include/
                                  |- src/ +
                                          |- api/
                                          |- adapters/ +
                                          |            |- include/adapters.h
                                          |            |- src/
                                          |
                                          |- selectors/ +
                                                        |- include/


Package Contents
================

* OpenSALWebhelp

    The documentation for OpenSAL.

* README

    This document.

* Makefile

    Can be used to build OpenSAL.

* include/

    Contains global header files, including "sal.h" - the API header file.

* src/

    Contains OpenSAL sources: API layer, adapters layer and selectors.

* src/api/
* src/adapters/
* src/selectors/include/

    Contains OpenSAL source code for the API layer, adapters layer and 
    selectors.

    The API is abstracted-away from the actual implementation of the functions 
    via the API-adapter distinction.  The former wraps the latter, always 
    presenting an API conforming to "sal.h".  An "adapter" embodies the 
    algorithm implementation.  Multiple adapters may be provided for a single 
    entry-point in the API.  The adapter to use can be selected at run time 
    using "selector" functions,  implemented in header files that are
    inlined in the implementation of the API layer.


Instructions for Building OpenSAL
=================================

* "make" will build both the 32- and 64-bit libraries for your platform, 
  using the native GCC toolchain.  Alternatively, "make libsal" and
  "make libsal64" may be used to build only the 32- or 64-bit library,
  respectively.  The library archive files - libsal.a and libsal64.a - will 
  be co-located with the Makefile.

* The "TARGET_ARCH" variable atop the Makefile may be modified to suit, or
  removed altogether, without hindering the build process.

* "clean" or "clean_all" will remove all 32- and 64-bit OpenSAL object and 
  library archive files from the system.  "clean_libsal" and "clean_libsal64"
  are also available for convenience.


Documentation
=============

* The OpenSAL documentation is provided in a browser-based format. To open the 
  documentation, open the OpenSALWebhelp directory and then open the 
  DOC_HLP_OPENSAL.htm file in a browser.

###############################################################################

