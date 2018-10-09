add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE StringTools StringTools/*)

source_group("" FILES ${StringTools})

add_executable(StringTools ${StringTools})

target_link_libraries(StringTools gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main StringTools APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS StringTools)

set_property(TARGET
  tests
 
  StringTools

PROPERTY FOLDER "tests")

set_property(TARGET StringTools PROPERTY OUTPUT_NAME "stringTools")

add_test(StringTools stringTools)