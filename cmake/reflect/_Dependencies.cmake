# This file will be regenerated by `mulle-sourcetree-to-cmake` via
# `mulle-sde reflect` and any edits will be lost.
#
# This file will be included by cmake/share/Files.cmake
#
# Disable generation of this file with:
#
# mulle-sde environment set MULLE_SOURCETREE_TO_CMAKE_DEPENDENCIES_FILE DISABLE
#
if( MULLE_TRACE_INCLUDE)
   message( STATUS "# Include \"${CMAKE_CURRENT_LIST_FILE}\"" )
endif()

#
# Generated from sourcetree: DA632302-CC77-41E3-A7C2-16F226549339;mulle-utf;no-all-load,no-cmake-searchpath,no-import,no-singlephase;
# Disable with : `mulle-sourcetree mark mulle-utf no-link`
# Disable for this platform: `mulle-sourcetree mark mulle-utf no-cmake-platform-${MULLE_UNAME}`
# Disable for a sdk: `mulle-sourcetree mark mulle-utf no-cmake-sdk-<name>`
#
if( COLLECT_DEPENDENCY_LIBRARIES_AS_NAMES)
   list( APPEND DEPENDENCY_LIBRARIES "mulle-utf")
else()
   if( NOT MULLE__UTF_LIBRARY)
      find_library( MULLE__UTF_LIBRARY NAMES
         ${CMAKE_STATIC_LIBRARY_PREFIX}mulle-utf${CMAKE_DEBUG_POSTFIX}${CMAKE_STATIC_LIBRARY_SUFFIX}
         ${CMAKE_STATIC_LIBRARY_PREFIX}mulle-utf${CMAKE_STATIC_LIBRARY_SUFFIX}
         mulle-utf
         NO_CMAKE_SYSTEM_PATH NO_SYSTEM_ENVIRONMENT_PATH
      )
      if( NOT MULLE__UTF_LIBRARY AND NOT DEPENDENCY_IGNORE_SYSTEM_LIBARIES)
         find_library( MULLE__UTF_LIBRARY NAMES
            ${CMAKE_STATIC_LIBRARY_PREFIX}mulle-utf${CMAKE_DEBUG_POSTFIX}${CMAKE_STATIC_LIBRARY_SUFFIX}
            ${CMAKE_STATIC_LIBRARY_PREFIX}mulle-utf${CMAKE_STATIC_LIBRARY_SUFFIX}
            mulle-utf
         )
      endif()
      message( STATUS "MULLE__UTF_LIBRARY is ${MULLE__UTF_LIBRARY}")
      #
      # The order looks ascending, but due to the way this file is read
      # it ends up being descending, which is what we need.
      #
      if( MULLE__UTF_LIBRARY)
         #
         # Add MULLE__UTF_LIBRARY to DEPENDENCY_LIBRARIES list.
         # Disable with: `mulle-sourcetree mark mulle-utf no-cmake-add`
         #
         list( APPEND DEPENDENCY_LIBRARIES ${MULLE__UTF_LIBRARY})
         #
         # Inherit information from dependency.
         # Encompasses: no-cmake-searchpath,no-cmake-dependency,no-cmake-loader
         # Disable with: `mulle-sourcetree mark mulle-utf no-cmake-inherit`
         #
         # temporarily expand CMAKE_MODULE_PATH
         get_filename_component( _TMP_MULLE__UTF_ROOT "${MULLE__UTF_LIBRARY}" DIRECTORY)
         get_filename_component( _TMP_MULLE__UTF_ROOT "${_TMP_MULLE__UTF_ROOT}" DIRECTORY)
         #
         #
         # Search for "Definitions.cmake" and "DependenciesAndLibraries.cmake" to include.
         # Disable with: `mulle-sourcetree mark mulle-utf no-cmake-dependency`
         #
         foreach( _TMP_MULLE__UTF_NAME "mulle-utf")
            set( _TMP_MULLE__UTF_DIR "${_TMP_MULLE__UTF_ROOT}/include/${_TMP_MULLE__UTF_NAME}/cmake")
            # use explicit path to avoid "surprises"
            if( IS_DIRECTORY "${_TMP_MULLE__UTF_DIR}")
               list( INSERT CMAKE_MODULE_PATH 0 "${_TMP_MULLE__UTF_DIR}")
               # we only want top level INHERIT_OBJC_LOADERS, so disable them
               if( NOT NO_INHERIT_OBJC_LOADERS)
                  set( NO_INHERIT_OBJC_LOADERS OFF)
               endif()
               list( APPEND _TMP_INHERIT_OBJC_LOADERS ${NO_INHERIT_OBJC_LOADERS})
               set( NO_INHERIT_OBJC_LOADERS ON)
               #
               include( "${_TMP_MULLE__UTF_DIR}/DependenciesAndLibraries.cmake" OPTIONAL)
               #
               list( GET _TMP_INHERIT_OBJC_LOADERS -1 NO_INHERIT_OBJC_LOADERS)
               list( REMOVE_AT _TMP_INHERIT_OBJC_LOADERS -1)
               list( REMOVE_ITEM CMAKE_MODULE_PATH "${_TMP_MULLE__UTF_DIR}")
               #
               unset( MULLE__UTF_DEFINITIONS)
               include( "${_TMP_MULLE__UTF_DIR}/Definitions.cmake" OPTIONAL)
               list( APPEND INHERITED_DEFINITIONS ${MULLE__UTF_DEFINITIONS})
               break()
            else()
               message( STATUS "${_TMP_MULLE__UTF_DIR} not found")
            endif()
         endforeach()
      else()
         # Disable with: `mulle-sourcetree mark mulle-utf no-require-link`
         message( SEND_ERROR "MULLE__UTF_LIBRARY was not found")
      endif()
   endif()
endif()
