add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE Dispatcher Dispatcher/*)

source_group("" FILES ${Dispatcher})

add_executable(Dispatcher ${Dispatcher})

target_link_libraries(Dispatcher gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Dispatcher APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Dispatcher)

set_property(TARGET
  tests
 
  Dispatcher

PROPERTY FOLDER "tests")

set_property(TARGET Dispatcher PROPERTY OUTPUT_NAME "dispatcher")

add_test(Dispatcher dispatcher)