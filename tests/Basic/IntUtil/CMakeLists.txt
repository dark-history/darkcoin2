add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE IntUtil IntUtil/*)

source_group("" FILES ${IntUtil})

add_executable(IntUtil ${IntUtil})

target_link_libraries(IntUtil gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main IntUtil APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS IntUtil)

set_property(TARGET
  tests
 
  IntUtil

PROPERTY FOLDER "tests")

set_property(TARGET IntUtil PROPERTY OUTPUT_NAME "intUtil")

add_test(IntUtil intUtil)