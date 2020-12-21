#
# This file will be included by cmake/share/Headers.cmake
#
# cmake/reflect/_Headers.cmake is generated by `mulle-sde reflect`.
# Edits will be lost.
#
if( MULLE_TRACE_INCLUDE)
   MESSAGE( STATUS "# Include \"${CMAKE_CURRENT_LIST_FILE}\"" )
endif()

#
# contents are derived from the file locations

set( INCLUDE_DIRS
src
src/reflect
)

#
# contents selected with patternfile ??-header--private-generated-headers
#
set( PRIVATE_GENERATED_HEADERS
src/reflect/_mulle-regex-include-private.h
)

#
# contents selected with patternfile ??-header--private-generic-headers
#
set( PRIVATE_GENERIC_HEADERS
src/include-private.h
)

#
# contents selected with patternfile ??-header--private-headers
#
set( PRIVATE_HEADERS
src/mulle-utf32regex-private.h
)

#
# contents selected with patternfile ??-header--public-generated-headers
#
set( PUBLIC_GENERATED_HEADERS
src/reflect/_mulle-regex-include.h
src/reflect/_mulle-regex-provide.h
)

#
# contents selected with patternfile ??-header--public-generic-headers
#
set( PUBLIC_GENERIC_HEADERS
src/include.h
)

#
# contents selected with patternfile ??-header--public-headers
#
set( PUBLIC_HEADERS
src/mulle-regex.h
src/mulle-utf32regex.h
src/version.h
)

