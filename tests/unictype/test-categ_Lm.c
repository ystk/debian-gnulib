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

    { 0x02B0, 0x02C1 },
    { 0x02C6, 0x02D1 },
    { 0x02E0, 0x02E4 },
    { 0x02EC, 0x02EC },
    { 0x02EE, 0x02EE },
    { 0x0374, 0x0374 },
    { 0x037A, 0x037A },
    { 0x0559, 0x0559 },
    { 0x0640, 0x0640 },
    { 0x06E5, 0x06E6 },
    { 0x07F4, 0x07F5 },
    { 0x07FA, 0x07FA },
    { 0x0971, 0x0971 },
    { 0x0E46, 0x0E46 },
    { 0x0EC6, 0x0EC6 },
    { 0x10FC, 0x10FC },
    { 0x17D7, 0x17D7 },
    { 0x1843, 0x1843 },
    { 0x1C78, 0x1C7D },
    { 0x1D2C, 0x1D61 },
    { 0x1D78, 0x1D78 },
    { 0x1D9B, 0x1DBF },
    { 0x2090, 0x2094 },
    { 0x2C7D, 0x2C7D },
    { 0x2D6F, 0x2D6F },
    { 0x2E2F, 0x2E2F },
    { 0x3005, 0x3005 },
    { 0x3031, 0x3035 },
    { 0x303B, 0x303B },
    { 0x309D, 0x309E },
    { 0x30FC, 0x30FE },
    { 0xA015, 0xA015 },
    { 0xA60C, 0xA60C },
    { 0xA67F, 0xA67F },
    { 0xA717, 0xA71F },
    { 0xA770, 0xA770 },
    { 0xA788, 0xA788 },
    { 0xFF70, 0xFF70 },
    { 0xFF9E, 0xFF9F }

#define PREDICATE(c) uc_is_general_category (c, UC_CATEGORY_Lm)
#include "test-predicate-part2.h"
