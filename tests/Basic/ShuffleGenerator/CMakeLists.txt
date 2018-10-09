add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE ShuffleGenerator ShuffleGenerator/*)

source_group("" FILES ${ShuffleGenerator})

add_executable(ShuffleGenerator ${ShuffleGenerator})

target_link_libraries(ShuffleGenerator gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ShuffleGenerator APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS ShuffleGenerator)

set_property(TARGET
  tests
 
  ShuffleGenerator

PROPERTY FOLDER "tests")

set_property(TARGET ShuffleGenerator PROPERTY OUTPUT_NAME "shuffleGenerator")

add_test(ShuffleGenerator shuffleGenerator)