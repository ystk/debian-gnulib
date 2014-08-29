/* Formatted output to UTF-32 strings.
   Copyright (C) 1999, 2002, 2006-2007, 2009-2014 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Tell glibc's <stdio.h> to provide a prototype for snprintf().
   This must come before <config.h> because <config.h> may include
   <features.h>, and once <features.h> has been included, it's too late.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE    1
#endif

#include <config.h>
#include <alloca.h>

/* Specification.  */
#include "unistdio.h"

#include "uniconv.h"
#include "unistr.h"
#include "unistdio/u-printf-parse.h"

#define VASNPRINTF u32_vasnprintf
#define FCHAR_T char
#define DIRECTIVE char_directive
#define DIRECTIVES char_directives
#define FCHAR_T_ONLY_ASCII 1
#define PRINTF_PARSE ulc_printf_parse
#define DCHAR_T uint32_t
#define DCHAR_T_IS_UINT32_T 1
#define DCHAR_CPY u32_cpy
#define DCHAR_SET u32_set
#define DCHAR_MBSNLEN u32_mbsnlen
#define DCHAR_IS_UINT32_T 1
#define U8_TO_DCHAR u8_to_u32
#define U16_TO_DCHAR u16_to_u32
#define DCHAR_CONV_FROM_ENCODING u32_conv_from_encoding
#define TCHAR_T char
#include "vasnprintf.c"
