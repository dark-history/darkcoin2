add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE NetNode NetNode/*)

source_group("" FILES ${NetNode})

add_executable(NetNode ${NetNode})

target_link_libraries(NetNode gtest_main P2p CryptoNoteCore Crypto Serialization Logging System Common upnpc-static ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main NetNode APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS NetNode)

set_property(TARGET
  tests
 
  NetNode

PROPERTY FOLDER "tests")

set_property(TARGET NetNode PROPERTY OUTPUT_NAME "netNode")

add_test(NetNode netNode)