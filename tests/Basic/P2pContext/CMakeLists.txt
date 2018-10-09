add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE P2pContext P2pContext/*)

source_group("" FILES ${P2pContext})

add_executable(P2pContext ${P2pContext})

target_link_libraries(P2pContext gtest_main P2p CryptoNoteCore Crypto Serialization Logging System Common upnpc-static ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main P2pContext APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS P2pContext)

set_property(TARGET
  tests
 
  P2pContext

PROPERTY FOLDER "tests")

set_property(TARGET P2pContext PROPERTY OUTPUT_NAME "p2pContext")

add_test(P2pContext p2pContext)