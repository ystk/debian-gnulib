/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
/* Test the Unicode character type functions.
   Copyright (C) 2007 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "test-predicate-part1.h"

    { 0x002B, 0x002B },
    { 0x003C, 0x003E },
    { 0x007C, 0x007C },
    { 0x007E, 0x007E },
    { 0x00AC, 0x00AC },
    { 0x00B1, 0x00B1 },
    { 0x00D7, 0x00D7 },
    { 0x00F7, 0x00F7 },
    { 0x03F6, 0x03F6 },
    { 0x0606, 0x0608 },
    { 0x2044, 0x2044 },
    { 0x2052, 0x2052 },
    { 0x207A, 0x207C },
    { 0x208A, 0x208C },
    { 0x2118, 0x2118 },
    { 0x2140, 0x2144 },
    { 0x214B, 0x214B },
    { 0x2190, 0x2194 },
    { 0x219A, 0x219B },
    { 0x21A0, 0x21A0 },
    { 0x21A3, 0x21A3 },
    { 0x21A6, 0x21A6 },
    { 0x21AE, 0x21AE },
    { 0x21CE, 0x21CF },
    { 0x21D2, 0x21D2 },
    { 0x21D4, 0x21D4 },
    { 0x21F4, 0x22FF },
    { 0x2308, 0x230B },
    { 0x2320, 0x2321 },
    { 0x237C, 0x237C },
    { 0x239B, 0x23B3 },
    { 0x23DC, 0x23E1 },
    { 0x25B7, 0x25B7 },
    { 0x25C1, 0x25C1 },
    { 0x25F8, 0x25FF },
    { 0x266F, 0x266F },
    { 0x27C0, 0x27C4 },
    { 0x27C7, 0x27CA },
    { 0x27CC, 0x27CC },
    { 0x27CE, 0x27E5 },
    { 0x27F0, 0x27FF },
    { 0x2900, 0x2982 },
    { 0x2999, 0x29D7 },
    { 0x29DC, 0x29FB },
    { 0x29FE, 0x2AFF },
    { 0x2B30, 0x2B44 },
    { 0x2B47, 0x2B4C },
    { 0xFB29, 0xFB29 },
    { 0xFE62, 0xFE62 },
    { 0xFE64, 0xFE66 },
    { 0xFF0B, 0xFF0B },
    { 0xFF1C, 0xFF1E },
    { 0xFF5C, 0xFF5C },
    { 0xFF5E, 0xFF5E },
    { 0xFFE2, 0xFFE2 },
    { 0xFFE9, 0xFFEC },
    { 0x1D6C1, 0x1D6C1 },
    { 0x1D6DB, 0x1D6DB },
    { 0x1D6FB, 0x1D6FB },
    { 0x1D715, 0x1D715 },
    { 0x1D735, 0x1D735 },
    { 0x1D74F, 0x1D74F },
    { 0x1D76F, 0x1D76F },
    { 0x1D789, 0x1D789 },
    { 0x1D7A9, 0x1D7A9 },
    { 0x1D7C3, 0x1D7C3 }

#define PREDICATE(c) uc_is_general_category (c, UC_CATEGORY_Sm)
#include "test-predicate-part2.h"
