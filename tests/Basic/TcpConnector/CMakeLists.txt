add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE TcpConnector TcpConnector/*)

source_group("" FILES ${TcpConnector})

add_executable(TcpConnector ${TcpConnector})

target_link_libraries(TcpConnector gtest_main System)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TcpConnector APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TcpConnector)

set_property(TARGET
  tests
 
  TcpConnector

PROPERTY FOLDER "tests")

set_property(TARGET TcpConnector PROPERTY OUTPUT_NAME "tcpConnector")

add_test(TcpConnector tcpConnector)