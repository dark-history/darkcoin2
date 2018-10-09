add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE P2pConnectionProxy P2pConnectionProxy/*)

source_group("" FILES ${P2pConnectionProxy})

add_executable(P2pConnectionProxy ${P2pConnectionProxy})

target_link_libraries(P2pConnectionProxy gtest_main P2p CryptoNoteCore Crypto Serialization Logging System Common upnpc-static ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main P2pConnectionProxy APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS P2pConnectionProxy)

set_property(TARGET
  tests
 
  P2pConnectionProxy

PROPERTY FOLDER "tests")

set_property(TARGET P2pConnectionProxy PROPERTY OUTPUT_NAME "p2pConnectionProxy")

add_test(P2pConnectionProxy p2pConnectionProxy)