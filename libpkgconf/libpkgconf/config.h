/* file      : libpkgconf/config.h -*- C -*-
 * copyright : Copyright (c) 2016-2019 Code Synthesis Ltd
 * license   : ISC; see accompanying COPYING file
 */
#ifndef LIBPKGCONF_CONFIG_H
#define LIBPKGCONF_CONFIG_H

/*
 * For the semantics of the following macros refer to config.h.cmake.in.orig
 * and upstream's CMakeList.txt.
 *
 * Note that we will explicitly undefine macros that are present in the
 * libpkgconf source code but should not be defined. While this is not
 * technically required, it simplifies the change tracking (see README-DEV).
 * As a bonus we also make sure that they are not get eventually defined by
 * some system headers.
 */

/*
 * Auto-generated. Defines the following configuration macros:

#define PACKAGE_VERSION

  * Keep all the macros listed (in this exact form) for the change tracking
  * (see README-DEV).
  */
#include <libpkgconf/version.h>

/*
 * strndup() is not present on Windows, for gcc and clang if compile with
 * -std=C99, except for FreeBSD and MacOS.
 *
 * strl*() are only present on FreeBSD and MacOS.
 */
#if defined(__FreeBSD__) || defined(__APPLE__)
#  define HAVE_STRNDUP 1
#  define HAVE_STRLCPY 1
#  define HAVE_STRLCAT 1
#endif

/*
 * Let's assume cygwin_conv_path() is always available if compile with MSYS
 * gcc.
 */
#if defined(__MSYS__)
# define HAVE_CYGWIN_CONV_PATH 1
#endif

/*
 * We don't consider such an outdated environments.
 */
#define HAVE_SYS_STAT_H 1

#define PACKAGE_BUGREPORT "https://git.dereferenced.org/pkgconf/pkgconf/issues"

#endif /* LIBPKGCONF_CONFIG_H */
