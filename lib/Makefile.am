## lib/Makefile.am

## Include custom flymake rules
include $(top_srcdir)/flymake.mk

## Optionally, build as a shared library with libtool:
if BUILD_STATIC_ONLY
noinst_LIBRARIES = libspielterminal.a
libspielterminal_a_SOURCES = \
    info.c \
    user_input.c
libspielterminal_a_CPPFLAGS = \
    -I$(top_srcdir)/lib
else
## Build a shared library using libtool
lib_LTLIBRARIES = libspielterminal.la
libspielterminal_la_SOURCES = \
    info.c \
    user_input.c
libspielterminal_la_CPPFLAGS = \
    -I$(top_srcdir)/lib
## If you want to explicitly enable/disable shared or static
libspielterminal_la_LDFLAGS = -version-info 1:0:0
endif

## Development warnings and debug flags
AM_CFLAGS = \
    -Wall \
    -Wextra \
    -Wdouble-promotion \
    -Wformat-security \
    -Wformat-signedness \
    -Winit-self \
    -Wshift-overflow=2 \
    -Wswitch-default \
    -Wstrict-overflow=4 \
    -Warith-conversion \
    -Wduplicated-branches \
    -Wduplicated-cond \
    -Wshadow \
    -Wcast-qual \
    -Wconversion \
    -Wdate-time \
    -Wstrict-prototypes \
    -Wmissing-prototypes \
    -Winvalid-pch \
    -Wredundant-decls \
    -Wformat-nonliteral \
    -ggdb

## If coverage is enabled from configure
if ENABLE_COVERAGE
AM_CFLAGS += -fprofile-arcs -ftest-coverage
AM_LDFLAGS += -fprofile-arcs -ftest-coverage
endif

## Headers remain private for now
noinst_HEADERS = info.h user_input.h

## Cleaning rules
CLEANFILES = \
    *~ \
    *.bak \
    *.o \
    *.lo \
    *.la \
    *.a \
    core \
    *.core

MAINTAINERCLEANFILES = \
    Makefile.in

## Optionally define 'check' or 'lint' targets if needed
## e.g. 'make lint' using flymake or other static checks.
