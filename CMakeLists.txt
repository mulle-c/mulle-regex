cmake_minimum_required (VERSION 3.0)

project (mulle-regex)

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/mulle-configuration)
message(STATUS "CMAKE_MODULE_PATH is ${CMAKE_MODULE_PATH}")
message(STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  include( Debug)
else()
  include( Release)
endif()

# using include_directories is a little bit shitty
include_directories( src
)

set( HEADERS
src/mulle_regex.h
src/mulle_utf32regex.h
src/mulle_utf32regex+private.h
)

add_library( mulle_regex
src/mulle_utf32regex.c
src/mulle_utf32regex_substitute.c
)

add_library( mulle_regex_standalone SHARED
src/mulle_regex_standalone.c
)

add_dependencies( mulle_regex_standalone mulle_regex)

TARGET_LINK_LIBRARIES( mulle_regex_standalone
${BEGIN_ALL_LOAD}
mulle_regex
mulle_utf
mulle_allocator
mulle_test_allocator
${END_ALL_LOAD}
)


INSTALL( TARGETS mulle_regex_standalone mulle_regex DESTINATION "lib")
INSTALL( FILES ${HEADERS} DESTINATION "include/mulle_regex")


