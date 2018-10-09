add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE StdInputStream StdInputStream/*)

source_group("" FILES ${StdInputStream})

add_executable(StdInputStream ${StdInputStream})

target_link_libraries(StdInputStream gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main StdInputStream APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS StdInputStream)

set_property(TARGET
  tests
 
  StdInputStream

PROPERTY FOLDER "tests")

set_property(TARGET StdInputStream PROPERTY OUTPUT_NAME "stdInputStream")

add_test(StdInputStream stdInputStream)