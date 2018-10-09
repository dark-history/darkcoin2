add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE Ipv4Address Ipv4Address/*)

source_group("" FILES ${Ipv4Address})

add_executable(Ipv4Address ${Ipv4Address})

target_link_libraries(Ipv4Address gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Ipv4Address APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Ipv4Address)

set_property(TARGET
  tests
 
  Ipv4Address

PROPERTY FOLDER "tests")

set_property(TARGET Ipv4Address PROPERTY OUTPUT_NAME "ipv4Address")

add_test(Ipv4Address ipv4Address)