add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/Basic/HelperFunctions)

file(GLOB_RECURSE P2pNodeConfig P2pNodeConfig/*)

source_group("" FILES ${P2pNodeConfig})

add_executable(P2pNodeConfig ${P2pNodeConfig})

target_link_libraries(P2pNodeConfig gtest_main P2p CryptoNoteCore Crypto Serialization Logging System Common upnpc-static ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main P2pNodeConfig APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(Basic DEPENDS P2pNodeConfig)

set_property(TARGET
  Basic
 
  P2pNodeConfig

PROPERTY FOLDER "Basic")

set_property(TARGET P2pNodeConfig PROPERTY OUTPUT_NAME "P2pNodeConfig")

add_test(P2pNodeConfig P2pNodeConfig)