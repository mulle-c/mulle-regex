/*
 *  (c) 2018 nat 
 *
 *  version:  major, minor, patch
 */
#define MULLE_REGEX_VERSION  ((0 << 20) | (7 << 8) | 56)


static inline unsigned int   mulle_regex_get_version_major( void)
{
   return( MULLE_REGEX_VERSION >> 20);
}


static inline unsigned int   mulle_regex_get_version_minor( void)
{
   return( (MULLE_REGEX_VERSION >> 8) & 0xFFF);
}


static inline unsigned int   mulle_regex_get_version_patch( void)
{
   return( MULLE_REGEX_VERSION & 0xFF);
}
