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

    { 0x0041, 0x005A },
    { 0x0061, 0x007A },
    { 0x00B5, 0x00B5 },
    { 0x00C0, 0x00D6 },
    { 0x00D8, 0x00F6 },
    { 0x00F8, 0x0137 },
    { 0x0139, 0x018C },
    { 0x018E, 0x019A },
    { 0x019C, 0x01A9 },
    { 0x01AC, 0x01B9 },
    { 0x01BC, 0x01BD },
    { 0x01BF, 0x01BF },
    { 0x01C4, 0x0220 },
    { 0x0222, 0x0233 },
    { 0x023A, 0x0254 },
    { 0x0256, 0x0257 },
    { 0x0259, 0x0259 },
    { 0x025B, 0x025B },
    { 0x0260, 0x0260 },
    { 0x0263, 0x0263 },
    { 0x0265, 0x0265 },
    { 0x0268, 0x0269 },
    { 0x026B, 0x026B },
    { 0x026F, 0x026F },
    { 0x0271, 0x0272 },
    { 0x0275, 0x0275 },
    { 0x027D, 0x027D },
    { 0x0280, 0x0280 },
    { 0x0283, 0x0283 },
    { 0x0288, 0x028C },
    { 0x0292, 0x0292 },
    { 0x0345, 0x0345 },
    { 0x0370, 0x0373 },
    { 0x0376, 0x0377 },
    { 0x037B, 0x037D },
    { 0x0386, 0x0386 },
    { 0x0388, 0x038A },
    { 0x038C, 0x038C },
    { 0x038E, 0x03A1 },
    { 0x03A3, 0x03D1 },
    { 0x03D5, 0x03F2 },
    { 0x03F4, 0x03F5 },
    { 0x03F7, 0x03FB },
    { 0x03FD, 0x0481 },
    { 0x048A, 0x0527 },
    { 0x0531, 0x0556 },
    { 0x0561, 0x0587 },
    { 0x10A0, 0x10C5 },
    { 0x1D79, 0x1D79 },
    { 0x1D7D, 0x1D7D },
    { 0x1E00, 0x1E9B },
    { 0x1E9E, 0x1E9E },
    { 0x1EA0, 0x1F15 },
    { 0x1F18, 0x1F1D },
    { 0x1F20, 0x1F45 },
    { 0x1F48, 0x1F4D },
    { 0x1F50, 0x1F57 },
    { 0x1F59, 0x1F59 },
    { 0x1F5B, 0x1F5B },
    { 0x1F5D, 0x1F5D },
    { 0x1F5F, 0x1F7D },
    { 0x1F80, 0x1FB4 },
    { 0x1FB6, 0x1FBC },
    { 0x1FBE, 0x1FBE },
    { 0x1FC2, 0x1FC4 },
    { 0x1FC6, 0x1FCC },
    { 0x1FD0, 0x1FD3 },
    { 0x1FD6, 0x1FDB },
    { 0x1FE0, 0x1FEC },
    { 0x1FF2, 0x1FF4 },
    { 0x1FF6, 0x1FFC },
    { 0x2126, 0x2126 },
    { 0x212A, 0x212B },
    { 0x2132, 0x2132 },
    { 0x214E, 0x214E },
    { 0x2160, 0x217F },
    { 0x2183, 0x2184 },
    { 0x24B6, 0x24E9 },
    { 0x2C00, 0x2C2E },
    { 0x2C30, 0x2C5E },
    { 0x2C60, 0x2C70 },
    { 0x2C72, 0x2C73 },
    { 0x2C75, 0x2C76 },
    { 0x2C7E, 0x2CE3 },
    { 0x2CEB, 0x2CEE },
    { 0x2D00, 0x2D25 },
    { 0xA640, 0xA66D },
    { 0xA680, 0xA697 },
    { 0xA722, 0xA72F },
    { 0xA732, 0xA76F },
    { 0xA779, 0xA787 },
    { 0xA78B, 0xA78D },
    { 0xA790, 0xA791 },
    { 0xA7A0, 0xA7A9 },
    { 0xFB00, 0xFB06 },
    { 0xFB13, 0xFB17 },
    { 0xFF21, 0xFF3A },
    { 0xFF41, 0xFF5A },
    { 0x10400, 0x1044F }

#define PREDICATE(c) uc_is_property_changes_when_casemapped (c)
#include "test-predicate-part2.h"
