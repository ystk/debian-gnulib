# rijndael.m4 serial 2
dnl Copyright (C) 2005, 2006, 2009, 2010 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_RIJNDAEL],
[
  AC_LIBOBJ([rijndael-alg-fst])
  AC_LIBOBJ([rijndael-api-fst])
])
