/* BFD back-end for Windows CE SH-4 PECOFF object files
   (IMAGE_FILE_MACHINE_SH4, 0x01a6).
   Copyright (C) 1995-2020 Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"

#define TARGET_SHL_SYM sh4_pe_wince_le_vec
#define TARGET_SHL_NAME "pe-sh4-wince-little"
#define COFF_SH4_WINCE
#define COFF_WITH_PE
#define PCRELOFFSET true
#define TARGET_UNDERSCORE '_'
#define COFF_LONG_SECTION_NAMES

#include "coff-sh.c"
