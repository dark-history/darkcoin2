add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE StreamLogger StreamLogger/*)

source_group("" FILES ${StreamLogger})

add_executable(StreamLogger ${StreamLogger})

target_link_libraries(StreamLogger gtest_main Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main StreamLogger APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS StreamLogger)

set_property(TARGET
  tests
 
  StreamLogger

PROPERTY FOLDER "tests")

set_property(TARGET StreamLogger PROPERTY OUTPUT_NAME "StreamLogger")

add_test(StreamLogger StreamLogger)