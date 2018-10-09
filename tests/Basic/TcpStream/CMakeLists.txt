add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE TcpStream TcpStream/*)

source_group("" FILES ${TcpStream})

add_executable(TcpStream ${TcpStream})

target_link_libraries(TcpStream gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TcpStream APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TcpStream)

set_property(TARGET
  tests
 
  TcpStream

PROPERTY FOLDER "tests")

set_property(TARGET TcpStream PROPERTY OUTPUT_NAME "tcpStream")

add_test(TcpStream tcpStream)