/* Target-dependent code for Windows CE running on SuperH (SH-4).

   Copyright (C) 2026 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "osabi.h"
#include "gdbarch.h"
#include "windows-tdep.h"

/* sh4-mingw32ce images are pei-sh4-wince-little; the SH code itself
   is handled by sh-tdep.c.  */

static void
sh_wince_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch)
{
  windows_init_abi (info, gdbarch);

  /* GCC and MSVC both make plain char signed on SH Windows CE.  */
  set_gdbarch_char_signed (gdbarch, 1);
}

static enum gdb_osabi
sh_wince_osabi_sniffer (bfd *abfd)
{
  const char *target_name = bfd_get_target (abfd);

  if (strcmp (target_name, "pei-sh4-wince-little") == 0
      || strcmp (target_name, "pe-sh4-wince-little") == 0)
    return GDB_OSABI_WINCE;

  return GDB_OSABI_UNKNOWN;
}

void _initialize_sh_wince_tdep ();
void
_initialize_sh_wince_tdep ()
{
  gdbarch_register_osabi_sniffer (bfd_arch_sh, bfd_target_coff_flavour,
				  sh_wince_osabi_sniffer);

  gdbarch_register_osabi (bfd_arch_sh, 0, GDB_OSABI_WINCE,
			  sh_wince_init_abi);
}
