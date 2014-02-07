/* Grapheme cluster breaks in Unicode strings.
   Copyright (C) 2010-2012 Free Software Foundation, Inc.
   Written by Ben Pfaff <blp@cs.stanford.edu>, 2010.

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

#ifndef _UNIGBRK_H
#define _UNIGBRK_H

/* Get bool.  */
#include <stdbool.h>

/* Get size_t. */
#include <stddef.h>

#include "unitypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================= */

/* Property defined in Unicode Standard Annex #29, section "Grapheme Cluster
   Boundaries"
   <http://unicode.org/reports/tr29/#Grapheme_Cluster_Boundaries> */

/* Possible values of the Grapheme_Cluster_Break property.
   This enumeration may be extended in the future.  */
enum
{
  GBP_OTHER        = 0,
  GBP_CR           = 1,
  GBP_LF           = 2,
  GBP_CONTROL      = 3,
  GBP_EXTEND       = 4,
  GBP_PREPEND      = 5,
  GBP_SPACINGMARK  = 6,
  GBP_L            = 7,
  GBP_V            = 8,
  GBP_T            = 9,
  GBP_LV           = 10,
  GBP_LVT          = 11
};

/* Return the Grapheme_Cluster_Break property of a Unicode character. */
extern int
       uc_graphemeclusterbreak_property (ucs4_t uc);

/* ========================================================================= */

/* Grapheme cluster breaks.  */

/* Returns true if there is a grapheme cluster boundary between Unicode code
   points A and B.  A "grapheme cluster" is an approximation to a
   user-perceived character, which sometimes corresponds to multiple code
   points.  For example, an English letter followed by an acute accent can be
   expressed as two consecutive Unicode code points, but it is perceived by the
   user as only a single character and therefore constitutes a single grapheme
   cluster.

   Implements extended (not legacy) grapheme cluster rules, because UAX #29
   indicates that they are preferred.

   Use A == 0 or B == 0 to indicate start of text or end of text,
   respectively. */
extern bool
       uc_is_grapheme_break (ucs4_t a, ucs4_t b);

/* Returns the start of the next grapheme cluster following S, or NULL if the
   end of the string has been reached. */
extern const uint8_t *
       u8_grapheme_next (const uint8_t *s, const uint8_t *end);
extern const uint16_t *
       u16_grapheme_next (const uint16_t *s, const uint16_t *end);
extern const uint32_t *
       u32_grapheme_next (const uint32_t *s, const uint32_t *end);

/* Returns the start of the previous grapheme cluster before S, or NULL if the
   start of the string has been reached. */
extern const uint8_t *
       u8_grapheme_prev (const uint8_t *s, const uint8_t *start);
extern const uint16_t *
       u16_grapheme_prev (const uint16_t *s, const uint16_t *start);
extern const uint32_t *
       u32_grapheme_prev (const uint32_t *s, const uint32_t *start);

/* Determine the grapheme cluster boundaries in S, and store the result at
   p[0..n-1].  p[i] = 1 means that a new grapheme cluster begins at s[i].  p[i]
   = 0 means that s[i-1] and s[i] are part of the same grapheme cluster.  p[0]
   will always be 1.
 */
extern void
       u8_grapheme_breaks (const uint8_t *s, size_t n, char *p);
extern void
       u16_grapheme_breaks (const uint16_t *s, size_t n, char *p);
extern void
       u32_grapheme_breaks (const uint32_t *s, size_t n, char *p);
extern void
       ulc_grapheme_breaks (const char *s, size_t n, char *p);

/* ========================================================================= */

#ifdef __cplusplus
}
#endif


#endif /* _UNIGBRK_H */
