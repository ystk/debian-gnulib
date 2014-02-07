/* Sequential list data type implemented by a hash table with another list.
   Copyright (C) 2006, 2009-2012 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2006.

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

/* Common code of
   gl_linkedhash_list.c, gl_avltreehash_list.c, gl_rbtreehash_list.c.  */

/* Array of primes, approximately in steps of factor 1.2.
   This table was computed by executing the Common Lisp expression
     (dotimes (i 244) (format t "nextprime(~D)~%" (ceiling (expt 1.2d0 i))))
   and feeding the result to PARI/gp.  */
static const size_t primes[] =
  {
    11, 13, 17, 19, 23, 29, 37, 41, 47, 59, 67, 83, 97, 127, 139, 167, 199,
    239, 293, 347, 419, 499, 593, 709, 853, 1021, 1229, 1471, 1777, 2129, 2543,
    3049, 3659, 4391, 5273, 6323, 7589, 9103, 10937, 13109, 15727, 18899,
    22651, 27179, 32609, 39133, 46957, 56359, 67619, 81157, 97369, 116849,
    140221, 168253, 201907, 242309, 290761, 348889, 418667, 502409, 602887,
    723467, 868151, 1041779, 1250141, 1500181, 1800191, 2160233, 2592277,
    3110741, 3732887, 4479463, 5375371, 6450413, 7740517, 9288589, 11146307,
    13375573, 16050689, 19260817, 23112977, 27735583, 33282701, 39939233,
    47927081, 57512503, 69014987, 82818011, 99381577, 119257891, 143109469,
    171731387, 206077643, 247293161, 296751781, 356102141, 427322587,
    512787097, 615344489, 738413383, 886096061, 1063315271, 1275978331,
    1531174013, 1837408799, 2204890543UL, 2645868653UL, 3175042391UL,
    3810050851UL,
#if SIZE_MAX > 4294967295UL
    4572061027UL, 5486473229UL, 6583767889UL, 7900521449UL, 9480625733UL,
    11376750877UL, 13652101063UL, 16382521261UL, 19659025513UL, 23590830631UL,
    28308996763UL, 33970796089UL, 40764955463UL, 48917946377UL, 58701535657UL,
    70441842749UL, 84530211301UL, 101436253561UL, 121723504277UL,
    146068205131UL, 175281846149UL, 210338215379UL, 252405858521UL,
    302887030151UL, 363464436191UL, 436157323417UL, 523388788231UL,
    628066545713UL, 753679854847UL, 904415825857UL, 1085298991109UL,
    1302358789181UL, 1562830547009UL, 1875396656429UL, 2250475987709UL,
    2700571185239UL, 3240685422287UL, 3888822506759UL, 4666587008147UL,
    5599904409713UL, 6719885291641UL, 8063862349969UL, 9676634819959UL,
    11611961783951UL, 13934354140769UL, 16721224968907UL, 20065469962669UL,
    24078563955191UL, 28894276746229UL, 34673132095507UL, 41607758514593UL,
    49929310217531UL, 59915172260971UL, 71898206713183UL, 86277848055823UL,
    103533417666967UL, 124240101200359UL, 149088121440451UL, 178905745728529UL,
    214686894874223UL, 257624273849081UL, 309149128618903UL, 370978954342639UL,
    445174745211143UL, 534209694253381UL, 641051633104063UL, 769261959724877UL,
    923114351670013UL, 1107737222003791UL, 1329284666404567UL,
    1595141599685509UL, 1914169919622551UL, 2297003903547091UL,
    2756404684256459UL, 3307685621107757UL, 3969222745329323UL,
    4763067294395177UL, 5715680753274209UL, 6858816903929113UL,
    8230580284714831UL, 9876696341657791UL, 11852035609989371UL,
    14222442731987227UL, 17066931278384657UL, 20480317534061597UL,
    24576381040873903UL, 29491657249048679UL, 35389988698858471UL,
    42467986438630267UL, 50961583726356109UL, 61153900471627387UL,
    73384680565952851UL, 88061616679143347UL, 105673940014972061UL,
    126808728017966413UL, 152170473621559703UL, 182604568345871671UL,
    219125482015045997UL, 262950578418055169UL, 315540694101666193UL,
    378648832921999397UL, 454378599506399233UL, 545254319407679131UL,
    654305183289214771UL, 785166219947057701UL, 942199463936469157UL,
    1130639356723763129UL, 1356767228068515623UL, 1628120673682218619UL,
    1953744808418662409UL, 2344493770102394881UL, 2813392524122873857UL,
    3376071028947448339UL, 4051285234736937517UL, 4861542281684325481UL,
    5833850738021191727UL, 7000620885625427969UL, 8400745062750513217UL,
    10080894075300616261UL, 12097072890360739951UL, 14516487468432885797UL,
    17419784962119465179UL,
#endif
    SIZE_MAX /* sentinel, to ensure the search terminates */
  };

/* Return a suitable prime >= ESTIMATE.  */
static size_t
next_prime (size_t estimate)
{
  size_t i;

  for (i = 0; i < sizeof (primes) / sizeof (primes[0]); i++)
    if (primes[i] >= estimate)
      return primes[i];
  return SIZE_MAX; /* not a prime, but better than nothing */
}

/* Resize the hash table with a new estimated size.  */
static void
hash_resize (gl_list_t list, size_t estimate)
{
  size_t new_size = next_prime (estimate);

  if (new_size > list->table_size)
    {
      gl_hash_entry_t *old_table = list->table;
      /* Allocate the new table.  */
      gl_hash_entry_t *new_table;
      size_t i;

      if (size_overflow_p (xtimes (new_size, sizeof (gl_hash_entry_t))))
        goto fail;
      new_table =
        (gl_hash_entry_t *) calloc (new_size, sizeof (gl_hash_entry_t));
      if (new_table == NULL)
        goto fail;

      /* Iterate through the entries of the old table.  */
      for (i = list->table_size; i > 0; )
        {
          gl_hash_entry_t node = old_table[--i];

          while (node != NULL)
            {
              gl_hash_entry_t next = node->hash_next;
              /* Add the entry to the new table.  */
              size_t bucket = node->hashcode % new_size;
              node->hash_next = new_table[bucket];
              new_table[bucket] = node;

              node = next;
            }
        }

      list->table = new_table;
      list->table_size = new_size;
      free (old_table);
    }
  return;

 fail:
  /* Just continue without resizing the table.  */
  return;
}
