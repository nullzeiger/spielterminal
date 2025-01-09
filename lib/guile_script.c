/* Guile Scheme function for run script.
   
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

#include "guile_script.h"
#include <libguile.h>
#include <stdio.h>

static void
*run_script (void *data)
{
  /* Load and evaluate Guile Scheme code.  */
  scm_c_primitive_load (data);

  /* Checks if a Scheme function named "main" is defined
     in the current Guile environment and, if so, calls it with no arguments.
     scm_is_true (SCM obj) Return 0 if obj is #f, else return 1.
     scm_procedure_p (obj) Return #t if obj is a procedure.
     scm_variable_ref (var) Dereference var and return its value.
     scm_c_lookup (const char *name) Return the variable bound to the symbol
     indicated by name in the current module.  */
  if (scm_is_true (scm_procedure_p (scm_variable_ref (scm_c_lookup ("main")))))
    {
      /* If the "main" variable exists and is a procedure, call it with no arguments.
	 This effectively executes the Scheme function.
	 scm_call_0 (proc) Call proc with any number of arguments.
	 scm_variable_ref (var) Dereference var and return its value.
	 scm_c_lookup (const char *name) Return the variable bound to the symbol
	 indicated by name in the current module.  */
      scm_call_0 (scm_variable_ref (scm_c_lookup ("main")));
    }
  
  return NULL;
}

int
load_guile_script (char *scriptname)
{
  /* Check that the filename is not NULL.  */
  if (!scriptname)
    {
      fprintf (stderr, "No filename provided\n");
      return 1;
    }

  /* Initialize the Guile environment and execute C code within the Guile context.  */
  scm_with_guile (run_script, scriptname);
  
  return 0;
}
