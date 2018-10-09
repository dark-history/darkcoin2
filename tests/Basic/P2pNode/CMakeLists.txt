add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE P2pNode P2pNode/*)

source_group("" FILES ${P2pNode})

add_executable(P2pNode ${P2pNode})

target_link_libraries(P2pNode gtest_main P2p CryptoNoteCore Crypto Serialization Logging System Common upnpc-static ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main P2pNode APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS P2pNode)

set_property(TARGET
  tests
 
  P2pNode

PROPERTY FOLDER "tests")

set_property(TARGET P2pNode PROPERTY OUTPUT_NAME "p2pNode")

add_test(P2pNode p2pNode)