dnl configure.ac for spielterminal
dnl
dnl Process this file with autoconf to produce a configure script.

dnl Copyright (C) 2025 Ivan Guerreschi.

dnl This file is free software; as a special exception the author gives
dnl unlimited permission to copy and/or distribute it, with or without
dnl modifications, as long as this notice is preserved.
dnl
dnl This program is distributed in the hope that it will be useful, but
dnl WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
dnl implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

dnl Minimum Autoconf version required.
AC_PREREQ([2.71])

dnl Package information
AC_INIT([spielterminal],
        [0.1],
        [ivan.guerreschi.dev@gmail.com],
        [spielterminal],
        [https://github.com/ivanGuerreschi/spielterminal])

dnl Safety checks
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

dnl Initialize automake
AM_INIT_AUTOMAKE([1.16 subdir-objects -Wall -Werror])

dnl Ensure $MAKE is set
AC_PROG_MAKE_SET

dnl Generate config.h
AC_CONFIG_HEADERS([config.h])

dnl Checks for programs
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_RANLIB
AM_PROG_AR
AC_PROG_MKDIR_P

dnl Checks for header files
AC_CHECK_HEADERS([stdlib.h stdio.h string.h getopt.h])

# Check for Guile
PKG_CHECK_MODULES([GUILE], [guile-3.0])

dnl Checks for help2man
AC_CHECK_PROG([HELP2MAN], [help2man], [help2man], [no])
if test "x$HELP2MAN" = xno; then
    AC_MSG_ERROR([help2man is required])
fi

dnl Checks for typedefs, structures, and compiler characteristics
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T

dnl Checks for library functions
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset strdup])

dnl Configure Makefile outputs
AC_CONFIG_FILES([
	Makefile
	lib/Makefile
	src/Makefile
	man/Makefile
	doc/Makefile
])

AC_OUTPUT

dnl Display configuration
AC_MSG_NOTICE([

${PACKAGE_NAME} version ${PACKAGE_VERSION}

Prefix: '${prefix}'
Compiler: '${CC}'
CFLAGS: '${CFLAGS}'
])
