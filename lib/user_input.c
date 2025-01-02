/* user_input.c  */
   
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

#include "info.h"
#include "user_input.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/* This function is responsible for parsing the command-line
   arguments provided to the program.  */
void
parsing (int argc, char **argv)
{
  int opt;

  /* Define short option string  */
  const char *short_opts = ":h:v";

  /* Define long options array  */
  static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {"version", no_argument, 0, 'v'},
    {0, 0, 0, 0}
  };

  while (1)
    {
      /* Get the next option using getopt_long */
      opt = getopt_long (argc, argv, short_opts, long_options, 0);

      /* If there are no more options, break the loop */
      if (opt == -1)
	break;

      /* Switch statement to handle different options */
      switch (opt)
	{
	case 'h':
	  printf ("%s\n%s\n%s\n", help (), license (), bugreport ());
	  break;
	case 'v':
	  printf ("%s\n", package ());
	  break;
	case '?':
	  printf ("%s\n", help ());
	  break;
	default:
	  abort ();
	}
    }
}
