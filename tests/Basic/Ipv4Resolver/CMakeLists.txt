add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE Ipv4Resolver Ipv4Resolver/*)

source_group("" FILES ${Ipv4Resolver})

add_executable(Ipv4Resolver ${Ipv4Resolver})

target_link_libraries(Ipv4Resolver gtest_main System)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Ipv4Resolver APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Ipv4Resolver)

set_property(TARGET
  tests
 
  Ipv4Resolver

PROPERTY FOLDER "tests")

set_property(TARGET Ipv4Resolver PROPERTY OUTPUT_NAME "ipv4Resolver")

add_test(Ipv4Resolver ipv4Resolver)