add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE Util Util/*)

source_group("" FILES ${Util})

add_executable(Util ${Util})

target_link_libraries(Util gtest_main Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Util APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Util)

set_property(TARGET
  tests
 
  Util

PROPERTY FOLDER "tests")

set_property(TARGET Util PROPERTY OUTPUT_NAME "util")

add_test(Util util)