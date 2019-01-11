#
# cmake/_Headers.cmake is generated by `mulle-sde`. Edits will be lost.
#
if( MULLE_TRACE_INCLUDE)
   MESSAGE( STATUS "# Include \"${CMAKE_CURRENT_LIST_FILE}\"" )
endif()

set( INCLUDE_DIRS
src
)

set( PRIVATE_HEADERS
src/include-private.h
src/mulle-utf32regex-private.h
)

set( PUBLIC_HEADERS
src/include.h
src/mulle-regex.h
src/mulle-utf32regex.h
src/version.h
)

