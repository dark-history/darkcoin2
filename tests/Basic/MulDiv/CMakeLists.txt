add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE MulDiv MulDiv/*)

source_group("" FILES ${MulDiv})

add_executable(MulDiv ${MulDiv})

target_link_libraries(MulDiv gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main MulDiv APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS MulDiv)

set_property(TARGET
  tests
 
  MulDiv

PROPERTY FOLDER "tests")

set_property(TARGET MulDiv PROPERTY OUTPUT_NAME "mulDiv_test")

add_test(MulDiv mulDiv_test)