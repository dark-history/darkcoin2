add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE Event Event/*)

source_group("" FILES ${Event})

add_executable(Event ${Event})

target_link_libraries(Event gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Event APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Event)

set_property(TARGET
  tests
 
  Event

PROPERTY FOLDER "tests")

set_property(TARGET Event PROPERTY OUTPUT_NAME "event")

add_test(Event event)