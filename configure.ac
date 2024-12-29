dnl Process this file with autoconf to produce a configure script.

dnl Copyright (C) 2024 Ivan Guerreschi.

dnl This file is free software; as a special exception the author gives
dnl unlimited permission to copy and/or distribute it, with or without
dnl modifications, as long as this notice is preserved.
dnl
dnl This program is distributed in the hope that it will be useful, but
dnl WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
dnl implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

AC_PREREQ([2.69])
AC_INIT([spielterminal], [0.1], [ivan.guerreschi.dev@gmail.com])
AM_INIT_AUTOMAKE([subdir-objects])

dnl Minimum Autoconf version required.
AC_PREREQ([2.69])

dnl Where to generate output; srcdir location.
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/main.c])

dnl Checks for programs.
dnl We need a C compiler.
AC_PROG_CC
AC_PROG_RANLIB

AC_CONFIG_FILES([Makefile
	lib/Makefile
	src/Makefile])

AC_OUTPUT
