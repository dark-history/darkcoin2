add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE LevinProtocol LevinProtocol/*)

source_group("" FILES ${LevinProtocol})

add_executable(LevinProtocol ${LevinProtocol})

target_link_libraries(LevinProtocol gtest_main CryptoNoteCore P2p Rpc Serialization System Logging Common Crypto upnpc-static ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main LevinProtocol APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS LevinProtocol)

set_property(TARGET
  tests
 
  LevinProtocol

PROPERTY FOLDER "tests")

set_property(TARGET LevinProtocol PROPERTY OUTPUT_NAME "levinProtocol")

add_test(LevinProtocol levinProtocol)