/*
 * Definitions etc. for regexp(3) routines.
 *
 * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],
 * not the System V one.
 */
#ifndef mulle_utf32regex_h__
#define mulle_utf32regex_h__

#include <mulle_utf/mulle_utf.h>
#include <stdlib.h>

 
struct mulle_utf32regex;

struct mulle_utf32range
{
   unsigned long   location;
   unsigned long   length;
};


// think of the parameters as
//
//   dst = `echo src | sed  's/pattern/replacement/'
//

/* may return NULL on failure (malformed regular expression) */
struct mulle_utf32regex   *mulle_utf32regex_compile( mulle_utf32_t *pattern);

static inline void   mulle_utf32regex_free( struct mulle_utf32regex *regex)
{
   free( regex);
}


/* returns < 0 on failure, 1 on match, 0 on no match */
int   mulle_utf32regex_execute(  struct mulle_utf32regex *regex, mulle_utf32_t *src);

/* returns < 0 on failure, 0 otherwise
 */
int   mulle_utf32regex_substitute( struct mulle_utf32regex *regex,
                                   mulle_utf32_t *replacement,
                                   mulle_utf32_t *dst,
                                   size_t dst_len);


// returns malloced buffer, or NULL
// convenience for doing compile/match in one step
//
mulle_utf32_t   *mulle_utf32_match( mulle_utf32_t *pattern, mulle_utf32_t *src);

// returns malloced buffer, or NULL
// convenience for doing compile/substitute in one step
//
mulle_utf32_t   *mulle_utf32_substitute( mulle_utf32_t *pattern,
                                         mulle_utf32_t *replacement,
                                         mulle_utf32_t *src);
                                       
size_t   mulle_utf32regex_substitution_buffer_size( struct mulle_utf32regex *regex, mulle_utf32_t *replacement);

struct mulle_utf32range   mulle_utf32regex_range_for_index( struct mulle_utf32regex *regex, unsigned int i);



#if MULLE_UTF_VERSION  < ((0 << 20) | (5 << 8) | 0)
# error "mulle_utf is too old
#endif

#endif

/* extern void regerror(char *message); */
