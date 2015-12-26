set(GWEN_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/gwen/include")
set(GWEN_INCLUDE_DIRS ${GWEN_INCLUDE_DIR})
set(GWEN_LIBRARY "GWEN")
set(GWEN_LIBRARIES ${GWEN_LIBRARY})

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/external/gwen")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GWEN DEFAULT_MSG GWEN_LIBRARIES GWEN_INCLUDE_DIR GWEN_INCLUDE_DIRS)

mark_as_advanced(GWEN_LIBRARY GWEN_LIBRARIES GWEN_INCLUDE_DIR GWEN_INCLUDE_DIRS)