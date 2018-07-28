/*
 * mulle_unicode_regex_substitute
 */
#include "mulle-utf32regex.h"
#include "mulle-utf32regex-private.h"

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int  octal( mulle_utf32_t **src_p)
{
   mulle_utf32_t   buf[ 5];
   mulle_utf32_t   *src;
   mulle_utf32_t   c;
   int             i;
   int             no;

   src = *src_p;

   buf[ 0] = '0';
   for( i = 1; i <= 3; i++)
   {
      c = *src++;
      if( c < '0' || c > '7')
         return( 0);

      buf[ i] = c;
   }
   buf[ 4] = 0;

   no = mulle_utf32_atoi( buf);
   if( no < 1 || no >= NSUBEXP)
      return( 0);

   *src_p = src;
   return( no);
}


/*
 *  - mulle_unicode_regex_substitute - perform substitutions after a regexp match
 */
int   mulle_utf32regex_substitute( struct mulle_utf32regex *rp, mulle_utf32_t *src, mulle_utf32_t *dst, size_t dst_len)
{
   regexp          *prog = (regexp *) rp;
   mulle_utf32_t   c;
   mulle_utf32_t   d;
   int             no;
   size_t          len;
   mulle_utf32_t   *dst_sentinel;

   assert( prog);
   assert( src);
   assert( dst);

   if( *((mulle_utf32_t *) prog->program) != MAGIC)
   {
      errno = EFAULT;
      return( -EFAULT);
   }

   dst_sentinel = &dst[ dst_len];
   while( dst < dst_sentinel)
   {
      c = *src++;
      if( ! c)
      {
         *dst = 0;
         return( 0);
      }

      no = 0;
      switch( c)
      {
      case '&'  : break;
      case '\\' : d = *src++;
                  switch( d)
                  {
                  case 0   : errno = EFAULT;
                             return( -EFAULT);
                  default  : *dst++ = d;
                             continue;

                  case '1' :
                  case '2' :
                  case '3' :
                  case '4' :
                  case '5' :
                  case '6' :
                  case '7' :
                  case '8' :
                  case '9' : no = d - '0';
                             break;

                        /* MUST be octal like this 0nnn */
                  case '0' : no = octal( &src);
                             if( ! no)
                             {
                                errno = EPERM;
                                return( -EPERM);
                             }
                             break;
                  }
                  break;

         default : *dst++ = c;
                    continue;
      }

      /* is that even an allowed index ? */
      if( ! prog->startp[ no])
         continue;

      assert( prog->endp[ no]);

      len = prog->endp[ no] - prog->startp[ no];
      if( ! len)
         continue;

      if( &dst[ len] >= dst_sentinel)
         break;

      (void) mulle_utf32_strncpy( dst, prog->startp[ no], len);
      dst += len;

      if( ! dst[ -1])   /* strncpy hit NUL. */
      {
         errno = EFAULT;
         return( -EFAULT);
      }
   }

   errno = E2BIG;
   return( -E2BIG);
}


size_t   mulle_utf32regex_substitution_buffer_size( struct mulle_utf32regex *rp, mulle_utf32_t *src)
{
   regexp          *prog = (regexp *) rp;
   mulle_utf32_t   c;
   mulle_utf32_t   d;
   int             no;
   size_t          dst_len;
   size_t          len;

   assert( prog);
   assert( src);
   assert( *((mulle_utf32_t *) prog->program) == MAGIC);

   dst_len = 1;  /* space for trailing 0 */
   for(;;)
   {
      c = *src++;
      if( ! c)
         return( dst_len);

      no = 0;
      switch( c)
      {
      case '&'  : break;
      case '\\' : d = *src++;
                  switch( d)
                  {
                  case 0   : return( 0);
                  default  : dst_len++;
                             continue;

                  case '1' :
                  case '2' :
                  case '3' :
                  case '4' :
                  case '5' :
                  case '6' :
                  case '7' :
                  case '8' :
                  case '9' : no = d - '0';
                             break;

                        /* MUST be octal like this 0nnn */
                  case '0' : no = octal( &src);
                             if( ! no)
                             {
                                errno = EPERM;
                                return( 0);
                             }
                             break;
                  }
                  break;

         default : dst_len++;
                   continue;
      }

      /* this is actually allowable */
      if( ! prog->startp[ no])
         continue;

      assert( prog->endp[ no]);

      len      = prog->endp[ no] - prog->startp[ no];
      dst_len += len;
   }
   return( 0);
}