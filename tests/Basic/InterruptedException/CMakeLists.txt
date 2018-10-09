add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE InterruptedException InterruptedException/*)

source_group("" FILES ${InterruptedException})

add_executable(InterruptedException ${InterruptedException})

target_link_libraries(InterruptedException gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main InterruptedException APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS InterruptedException)

set_property(TARGET
  tests
 
  InterruptedException

PROPERTY FOLDER "tests")

set_property(TARGET InterruptedException PROPERTY OUTPUT_NAME "interruptedException")

add_test(InterruptedException interruptedException)