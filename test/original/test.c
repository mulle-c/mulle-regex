/*
 * Simple test program for regexp(3) stuff.  Knows about debugging hooks.
 * Usage: try re [string [output [-]]]
 * The re is compiled and dumped, regexeced against the string, the result
 * is applied to output using regsub().  The - triggers a running narrative
 * from regexec().  Dumping and narrative don't happen unless DEBUG.
 *
 * If there are no arguments, fp is assumed to be a stream of lines with
 * five fields:  a r.e., a string to match it against, a result code, a
 * source string for regsub, and the proper result.  Result codes are 'c'
 * for compile failure, 'y' for match success, 'n' for match failure.
 * Field separator is tab.
 */

#include <mulle-regex/mulle-regex.h>
#include <mulle-regex/private/mulle-utf32regex-private.h>
#include <stdio.h>


static void   try( char *fields[ 5], int lineno)
{
   mulle_utf32_t            dbuf[BUFSIZ];
   int                      expected_success;
   int                      expected_failure;
   int                      result;
   regexp                   *r;
   mulle_utf32_t            *replacement;
   mulle_utf32_t            *pattern;
   mulle_utf32_t            *input;
   mulle_utf32_t            *expect;
   struct mulle_utf_information   info;

   printf( "\n%d: %s %s %s %s %s: ", lineno, fields[ 0], fields[ 1], fields[ 2], fields[ 3], fields[ 4]);

   pattern = mulle_utf8_convert_to_utf32( fields[ 0], -1, NULL);
   r       = mulle_utf32regex_compile( pattern);

   expected_success = r != NULL && *fields[2] != 'c';
   expected_failure = r == NULL && *fields[2] == 'c';

   if( ! expected_success || expected_failure)
   {
      printf( "%sexpected compilation failure", expected_failure ? "" : "un");

      mulle_allocator_free( NULL, pattern);
      mulle_utf32regex_free( r);
      return;
   }

//   mulle_utf32regex_dump( r);


   input  = mulle_utf8_convert_to_utf32( fields[ 1], -1, NULL);
   result = mulle_utf32regex_execute( r, input);

   expected_success = result == 1 && *fields[2] != 'n';
   expected_failure = result == 0 && *fields[2] == 'n';

   if( ! expected_success || expected_failure)
   {
      printf( "%sexpected execution failure", expected_failure ? "" : "un");

      mulle_allocator_free( NULL, input);
      mulle_allocator_free( NULL, pattern);
      mulle_utf32regex_free( r);
      return;
   }

   expected_failure = ! strcmp( "@", fields[ 4]);

   replacement = mulle_utf8_convert_to_utf32( fields[ 3], -1, NULL);
   result      = mulle_utf32regex_substitute( r, replacement, dbuf, BUFSIZ);

   if( result == 0)
   {
      expect =  mulle_utf8_convert_to_utf32( fields[4], -1, NULL);
      printf( "%s match",  ! mulle_utf32_strcmp( expect, dbuf) ? "" : "no ");
      mulle_allocator_free( NULL, expect);
   }
   else
      printf( "%sexpected substitution failure", expected_failure ? "" : "un");

   mulle_allocator_free( NULL, input);
   mulle_allocator_free( NULL, pattern);
   mulle_allocator_free( NULL, replacement);
   mulle_utf32regex_free( r);
}


static void   multiple( FILE *fp)
{
   char rbuf[BUFSIZ];
   char *field[5];
   char *scan;
   int i;
   int lineno;
//   regexp *r;
   extern char *strchr();

   lineno = 0;
   while (fgets(rbuf, sizeof(rbuf), fp) != NULL) {
      rbuf[strlen(rbuf)-1] = '\0';	/* Dispense with \n. */
      lineno++;
      scan = rbuf;
      for (i = 0; i < 5; i++) {
         field[i] = scan;
         if (field[i] == NULL) {
            fprintf( stderr, "bad testfile format", "");
            exit(1);
         }
         scan = strchr(scan, '\t');
         if (scan != NULL)
            *scan++ = '\0';
      }
      try( field, lineno);
   }

//   /* And finish up with some internal testing... */
//   lineno = 9990;
//   errseen = NULL;
//   if (mulle_unicode_regex_compile((char *)NULL) != NULL || errseen == NULL)
//      complain("mulle_unicode_regex_compile(NULL) doesn't complain", "");
//   lineno = 9991;
//   errseen = NULL;
//   if (regexec((regexp *)NULL, "foo") || errseen == NULL)
//      complain("regexec(NULL, ...) doesn't complain", "");
//   lineno = 9992;
//   r = mulle_unicode_regex_compile("foo");
//   if (r == NULL) {
//      complain("mulle_unicode_regex_compile(\"foo\") fails", "");
//      return;
//   }
//   lineno = 9993;
//   errseen = NULL;
//   if (regexec(r, (char *)NULL) || errseen == NULL)
//      complain("regexec(..., NULL) doesn't complain", "");
//   lineno = 9994;
//   errseen = NULL;
//   regsub((regexp *)NULL, "foo", rbuf);
//   if (errseen == NULL)
//      complain("regsub(NULL, ..., ...) doesn't complain", "");
//   lineno = 9995;
//   errseen = NULL;
//   regsub(r, (char *)NULL, rbuf);
//   if (errseen == NULL)
//      complain("regsub(..., NULL, ...) doesn't complain", "");
//   lineno = 9996;
//   errseen = NULL;
//   regsub(r, "foo", (char *)NULL);
//   if (errseen == NULL)
//      complain("regsub(..., ..., NULL) doesn't complain", "");
//   lineno = 9997;
//   errseen = NULL;
//   if (regexec(&badregexp, "foo") || errseen == NULL)
//      complain("regexec(nonsense, ...) doesn't complain", "");
//   lineno = 9998;
//   errseen = NULL;
//   regsub(&badregexp, "foo", rbuf);
//   if (errseen == NULL)
//      complain("regsub(nonsense, ..., ...) doesn't complain", "");
}

static void   test( void)
{
   char       *path;
   FILE       *fp;

   path = "tests.txt";
   fp   = fopen( path, "r");

   if( ! fp)
   {
      fprintf( stderr, "tests file \"%s\" not found \n", path);
      abort();
   }

   multiple( fp);
   fclose( fp);
}



int   main( int argc, char *argv[])
{
   test();
   printf( "\n");
}