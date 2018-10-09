add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE EventLock EventLock/*)

source_group("" FILES ${EventLock})

add_executable(EventLock ${EventLock})

target_link_libraries(EventLock gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main EventLock APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS EventLock)

set_property(TARGET
  tests
 
  EventLock

PROPERTY FOLDER "tests")

set_property(TARGET EventLock PROPERTY OUTPUT_NAME "eventLock")

add_test(EventLock eventLock)