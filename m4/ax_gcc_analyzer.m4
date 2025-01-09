dnl Check if the C compiler supports -fanalyzer  -*- Autoconf -*-
dnl Sets HAVE_GCC_ANALYZER to yes/no
dnl Adds -fanalyzer to CFLAGS if supported
dnl
dnl Copyright (C) 2025 Ivan Guerreschi.
dnl
dnl This file is free software; as a special exception the author gives
dnl unlimited permission to copy and/or distribute it, with or without
dnl modifications, as long as this notice is preserved.
dnl
dnl This program is distributed in the hope that it will be useful, but
dnl WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
dnl implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

dnl Defines a new Autoconf macro named AX_CHECK_GCC_ANALYZER
dnl AC_DEFUN(macro-name, macro-body)
AC_DEFUN([AX_CHECK_GCC_ANALYZER], [
  dnl AC_MSG_CHECKING (feature-description)
  dnl Notify the user that configure is checking for a particular feature.
  AC_MSG_CHECKING([whether ${CC} supports -fanalyzer])

  dnl Try compiling with -fanalyzer
  dnl AC_COMPILE_IFELSE (input, [action-if-true], [action-if-false])
  dnl Run the compiler and compilation flags of the current language
  dnl on the input, run the shell commands action-if-true on success, action-if-false otherwise.  
  AC_COMPILE_IFELSE([
    dnl AC_LANG_PROGRAM (prologue, body)
    dnl Expands into a source file which consists of the prologue,
    dnl and then body as body of the main function (e.g., main in C).
    dnl Since it uses AC_LANG_SOURCE, the features of the latter are available. 
    AC_LANG_PROGRAM([[]])], [
    dnl AC_MSG_RESULT (result-description)
    AC_MSG_RESULT([yes])
      HAVE_GCC_ANALYZER=yes
    ], [
      AC_MSG_RESULT([no])
      HAVE_GCC_ANALYZER=no
  ])

  dnl User configurable option.
  dnl AC_ARG_ENABLE (feature, help-string, [action-if-given], [action-if-not-given])
  dnl If the user gave configure the option --enable-feature or --disable-feature,
  dnl run shell commands action-if-given.  
  AC_ARG_ENABLE([gcc-analyzer],
    dnl AS_HELP_STRING (left-hand-side, right-hand-side [indent-column = `26'], [wrap-column = `79'])
    dnl Expands into an help string that looks pretty when the user executes `configure --help'. 
    [AS_HELP_STRING([--enable-gcc-analyzer],
        [Enable GCC analyzer support (default: auto)])],
    [want_analyzer=$enableval],
    [want_analyzer=auto
  ])

  dnl Disable if requested by user.
  dnl AS_IF (test1, [run-if-true1], …, [run-if-false])
  dnl Run shell code test1.
  dnl If test1 exits with a zero status then run shell code run-if-true1, else examine further tests.
  dnl If no test exits with a zero status, run shell code run-if-false,
  dnl with simplifications if either run-if-true1 or run-if-false is empty. 
  AS_IF([test "x$want_analyzer" = "xno"], [
      HAVE_GCC_ANALYZER=no
  ])

  dnl Error if requested but not supported.
  AS_IF([test "x$want_analyzer" = "xyes" -a "x$HAVE_GCC_ANALYZER" = "xno"], [
    dnl AC_MSG_ERROR (error-description, [exit-status])
    dnl Notify the user of an error that prevents configure from completing.
    dnl This macro prints an error messagel to the standard error output and
    dnl exits configure with exit-status (1 by default)
    AC_MSG_ERROR([GCC analyzer requested but not supported])
  ])

  dnl Export the variable for the Makefile.
  dnl AC_SUBST (variable, [value])
  dnl Create an output variable from a shell variable.
  dnl Make AC_OUTPUT substitute the variable variable into output files.
  AC_SUBST([HAVE_GCC_ANALYZER])
  dnl AM_CONDITIONAL (conditional, condition)
  dnl The conditional name, conditional, should be a simple string starting
  dnl with a letter and containing only letters, digits, and underscores.
  dnl It must be different from ‘TRUE’ and ‘FALSE’, which are reserved by Automake 
  AM_CONDITIONAL([HAVE_GCC_ANALYZER], [test "x$HAVE_GCC_ANALYZER" = "xyes"])
])
