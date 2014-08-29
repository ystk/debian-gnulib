/* Test of u8_next() function.
   Copyright (C) 2010-2014 Free Software Foundation, Inc.

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

/* Written by Bruno Haible <bruno@clisp.org>, 2010.  */

#include <config.h>

#include "unistr.h"

#include "macros.h"

int
main ()
{
  ucs4_t uc;
  const uint8_t *ret;

  /* Test NUL unit input.  */
  {
    static const uint8_t input[] = "";
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0);
  }

  /* Test ISO 646 unit input.  */
  {
    ucs4_t c;
    uint8_t buf[2];

    for (c = 1; c < 0x80; c++)
      {
        buf[0] = c;
        buf[1] = 0;
        uc = 0xBADFACE;
        ret = u8_next (&uc, buf);
        ASSERT (ret == buf + 1);
        ASSERT (uc == c);
      }
  }

  /* Test 2-byte character input.  */
  {
    static const uint8_t input[] = { 0xC3, 0x97, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == input + 2);
    ASSERT (uc == 0x00D7);
  }

  /* Test 3-byte character input.  */
  {
    static const uint8_t input[] = { 0xE2, 0x82, 0xAC, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == input + 3);
    ASSERT (uc == 0x20AC);
  }

  /* Test 4-byte character input.  */
  {
    static const uint8_t input[] = { 0xF4, 0x8F, 0xBF, 0xBD, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == input + 4);
    ASSERT (uc == 0x10FFFD);
  }

  /* Test incomplete/invalid 1-byte input.  */
  {
    static const uint8_t input[] = { 0xC1, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xC3, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xE2, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xF4, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xFE, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }

  /* Test incomplete/invalid 2-byte input.  */
  {
    static const uint8_t input[] = { 0xE0, 0x9F, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xE2, 0x82, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xE2, 0xD0, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xF0, 0x8F, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xF3, 0x8F, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xF3, 0xD0, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }

  /* Test incomplete/invalid 3-byte input.  */
  {
    static const uint8_t input[] = { 0xF3, 0x8F, 0xBF, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xF3, 0xD0, 0xBF, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }
  {
    static const uint8_t input[] = { 0xF3, 0x8F, 0xD0, 0 };
    uc = 0xBADFACE;
    ret = u8_next (&uc, input);
    ASSERT (ret == NULL);
    ASSERT (uc == 0xFFFD);
  }

  return 0;
}
