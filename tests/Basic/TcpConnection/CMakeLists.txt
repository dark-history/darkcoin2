add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE TcpConnection TcpConnection/*)

source_group("" FILES ${TcpConnection})

add_executable(TcpConnection ${TcpConnection})

target_link_libraries(TcpConnection gtest_main System)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TcpConnection APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TcpConnection)

set_property(TARGET
  tests
 
  TcpConnection

PROPERTY FOLDER "tests")

set_property(TARGET TcpConnection PROPERTY OUTPUT_NAME "tcpConnection")

add_test(TcpConnection tcpConnection)