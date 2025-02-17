/* Header for spielterminal info.
   
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

#ifndef INFO_H
#define INFO_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/* Returns the version string of the package. */
const char *version (void);
/* Returns the package name of the package. */
const char *package (void);
/* Returns the bug report address for the package. */
const char *bugreport (void);
/* Returns the license information for the package. */
const char *license (void);
/* Returns the help text for the package. */
const char *help (void);

#endif /* INFO_H */
