## Usage


Without error checks, this is how you might code a replacement function:


``` c
   mulle_utf32_t             *s;    // input string       (with terminating 0)
   mulle_utf32_t             *p;    // pattern            (with terminating 0)
   mulle_utf32_t             *r;    // replacement string (with terminating 0)
...
   mulle_utf32_t             *dst;  // output string (will contain term. 0)
...
   struct mulle_utf32regex   *regex;
   struct range              fullRange;
   struct range              matchedRange;
   struct range              affixRanges[ 2];
   unsigned int              dst_length;
   int                       result;

   regex  = mulle_utf32regex_compile( p);           // could return NULL
   result = mulle_utf32regex_execute( regex, s);    // could return -1 (FAIL)
   if( result > 0)
   {
      fullRange    = mulle_range_make( 0, mulle_utf32_strlen( s));
      matchedRange = mulle_utf32regex_range_for_index( regex, 0);

      dst_length = mulle_utf32regex_substitution_length( regex, r);
      dst        = mulle_malloc( sizeof( mulle_utf32_t) * dst_length);
      result     = mulle_utf32regex_substitute( regex, r, dst, dst_length);
      if( result >= 0) // could return < 0 (FAIL)
      {
         // add non-replaced parts for output
         mulle_range_subtract( fullRange, matchedRange, affixRanges);
         mulle_printf( "%.*lS%lS%.*lS\n",
                           (int) affixRanges[ 0].length, &s[ affixRanges[ 0].location],
                           dst,
                           (int) affixRanges[ 1].length, &s[ affixRanges[ 1].location]);
      }
      mulle_free( dst);
   }
   else
      mulle_printf( "%lS\n", s);  // no match

   mulle_utf32regex_free( regex);
...
```
