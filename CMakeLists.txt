cmake_minimum_required (VERSION 3.0)

project( mulle-regex C)


set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/mulle-configuration/cmake)
message(STATUS "CMAKE_MODULE_PATH is ${CMAKE_MODULE_PATH}")
message(STATUS "CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  include( Debug)
else()
  include( Release)
endif()

set( MULLE_REGEX_LIBRARY ON)
include( CMakeSourcesAndHeaders.txt)
include( CMakeDependencies.txt)

include_directories( ${INCLUDE_DIRS})


set( DEPENDENCY_LIBRARIES
${MULLE_ALLOCATOR_LIBRARY}
${MULLE_BUFFER_LIBRARY}
${MULLE_TEST_ALLOCATOR_LIBRARY}
${MULLE_THREAD_LIBRARY}
${MULLE_UTF_LIBRARY}
)


add_library( mulle_regex
${SOURCES}
)


set( STANDALONE_BASE_NAME "mulle_regex")
set( STANDALONE_NAME "mulle_regex_standalone")
set( STANDALONE_DEFINITIONS ${MULLE_REGEX_DEFINITIONS})
set( STANDALONE_ALL_LOAD_LIBRARIES
$<TARGET_FILE:mulle_regex>
${C_DEPENDENCY_LIBRARIES}
)

include( Standalone)

INSTALL( TARGETS mulle_regex_standalone mulle_regex DESTINATION "lib")
INSTALL( FILES ${HEADERS} DESTINATION "include/mulle_regex")

include( MulleTest)


