add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE PathTools PathTools/*)

source_group("" FILES ${PathTools})

add_executable(PathTools ${PathTools})

target_link_libraries(PathTools gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main PathTools APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS PathTools)

set_property(TARGET
  tests
 
  PathTools

PROPERTY FOLDER "tests")

set_property(TARGET PathTools PROPERTY OUTPUT_NAME "pathTools")

add_test(PathTools pathTools)