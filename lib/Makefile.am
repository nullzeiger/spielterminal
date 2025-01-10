# Makefile.am for lib dir.
#
# Copyright (C) 2025 Ivan Guerreschi
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Include custom make rules for flymake.
include $(top_srcdir)/flymake.mk

# Library definition.
noinst_LIBRARIES = libspielterminal.a

# Headers.
noinst_HEADERS = \
	guile_script.h \
	info.h \
	user_input.h \
	$(NULL)

# Library sources.
libspielterminal_a_SOURCES = \
	guile_script.c \
	info.c \
	user_input.c \
        $(noinst_HEADERS) \
	$(NULL)

# Additional include paths.
libspielterminal_a_CFLAGS = \
	$(GUILE_CFLAGS) \
	$(AM_CFLAGS) \
	$(NULL)

# Compiler warnings and debug flags.
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
	$(NULL)

# Debug flags.
AM_CFLAGS += -ggdb

# Add -fanalyzer flag to AM_CFLAGS if available.
if HAVE_GCC_ANALYZER
AM_CFLAGS += -fanalyzer
endif

# Clean generated files.
CLEANFILES = \
	*~ \
	*.bak \
	*.o \
	*.a \
	core \
	*.core \
	$(NULL)

# Maintainer clean.
MAINTAINERCLEANFILES = \
	Makefile.in \
	$(NULL)
