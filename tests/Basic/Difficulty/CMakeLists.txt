add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE Difficulty Difficulty/*)

source_group("" FILES ${Difficulty})

add_executable(Difficulty ${Difficulty})

target_link_libraries(Difficulty gtest_main Crypto Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Difficulty APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Difficulty)

set_property(TARGET
  tests
 
  Difficulty

PROPERTY FOLDER "tests")

set_property(TARGET Difficulty PROPERTY OUTPUT_NAME "difficulty")

add_test(Difficulty difficulty)