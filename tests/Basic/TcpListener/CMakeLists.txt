add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE TcpListener TcpListener/*)

source_group("" FILES ${TcpListener})

add_executable(TcpListener ${TcpListener})

target_link_libraries(TcpListener gtest_main System)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TcpListener APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TcpListener)

set_property(TARGET
  tests
 
  TcpListener

PROPERTY FOLDER "tests")

set_property(TARGET TcpListener PROPERTY OUTPUT_NAME "tcpListener")

add_test(TcpListener tcpListener)