add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE NetNodeConfig NetNodeConfig/*)

source_group("" FILES ${NetNodeConfig})

add_executable(NetNodeConfig ${NetNodeConfig})

target_link_libraries(NetNodeConfig gtest_main P2p CryptoNoteCore Crypto Serialization Logging System Common upnpc-static ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main NetNodeConfig APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS NetNodeConfig)

set_property(TARGET
  tests
 
  NetNodeConfig

PROPERTY FOLDER "tests")

set_property(TARGET NetNodeConfig PROPERTY OUTPUT_NAME "netNodeConfig")

add_test(NetNodeConfig netNodeConfig)