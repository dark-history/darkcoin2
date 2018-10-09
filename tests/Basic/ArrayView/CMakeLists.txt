add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE ArrayView ArrayView/*)

source_group("" FILES ${ArrayView})

add_executable(ArrayView ${ArrayView})

target_link_libraries(ArrayView gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ArrayView APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(Basic DEPENDS ArrayView)

set_property(TARGET
  Basic
 
  ArrayView

PROPERTY FOLDER "Basic")

set_property(TARGET ArrayView PROPERTY OUTPUT_NAME "arrayView")

add_test(ArrayView arrayView)