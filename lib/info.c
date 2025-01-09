/* Print spielterminal info.
   
   Copyright (C) 2025 Ivan Guerreschi.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
 
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "info.h"
#include <string.h>

/* Returns the version string from a pre-defined macro VERSION. */
const char *
version (void)
{
  return VERSION;
}

/* Returns the package name string from a pre-defined macro PACKAGE_STRING.  */
const char *
package (void)
{
  return PACKAGE_STRING;
}

/* Returns the bug report address string from a pre-defined macro PACKAGE_BUGREPORT. */
const char *
bugreport (void)
{
  return PACKAGE_BUGREPORT;
}

/* Returns the full GNU General Public License. */
const char *
license (void)
{
  return "This program is free software: you can redistribute it and/or "
    "modify\n"
    "it under the terms of the GNU General Public License as published "
    "by\n"
    "the Free Software Foundation, either version 3 of the License, or\n"
    "(at your option) any later version.\n\n"
    "This program is distributed in the hope that it will be useful,\n"
    "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
    "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
    "GNU General Public License for more details.\n\n"
    "You should have received a copy of the GNU General Public License\n"
    "along with this program.  If not, see " "<https://www.gnu.org/licenses/>.\n";
}

/* Returns a string containing the help message describing
   the program's usage and available options. */
const char *
help (void)
{
  return "spielterminal\n"
    "Options:\n"
    "  -h --help    Help\n"
    "  -l --load    Load Guile scheme script\n"
    "  -v --version Program version\n";
}
