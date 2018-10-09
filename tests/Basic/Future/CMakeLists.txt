add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE Future Future/*)

source_group("" FILES ${Future})

add_executable(Future ${Future})

target_link_libraries(Future gtest_main System)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Future APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Future)

set_property(TARGET
  tests
 
  Future

PROPERTY FOLDER "tests")

set_property(TARGET Future PROPERTY OUTPUT_NAME "future")

add_test(Future future)