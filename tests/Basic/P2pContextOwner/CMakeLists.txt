add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE P2pContextOwner P2pContextOwner/*)

source_group("" FILES ${P2pContextOwner})

add_executable(P2pContextOwner ${P2pContextOwner})

target_link_libraries(P2pContextOwner gtest_main P2p CryptoNoteCore Crypto Serialization Logging System Common upnpc-static ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main P2pContextOwner APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS P2pContextOwner)

set_property(TARGET
  tests
 
  P2pContextOwner

PROPERTY FOLDER "tests")

set_property(TARGET P2pContextOwner PROPERTY OUTPUT_NAME "p2pContextOwner")

add_test(P2pContextOwner p2pContextOwner)