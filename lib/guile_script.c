/* guile_script.c  */
   
/* Copyright (C) 2025 Ivan Guerreschi. */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "guile_script.h"
#include <libguile.h>

static SCM
hello_scheme (void)
{
  scm_display (scm_from_utf8_string ("Hello, World\n"), scm_current_output_port ());
  return SCM_UNSPECIFIED;
}

void
print_hello (void)
{
  scm_init_guile ();
  scm_c_define_gsubr ("hello", 0, 0, 0, hello_scheme);
  scm_c_eval_string ("(hello)");
}
