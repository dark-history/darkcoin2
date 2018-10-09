add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE BlockchainMessages BlockchainMessages/*)

source_group("" FILES ${BlockchainMessages})

add_executable(BlockchainMessages ${BlockchainMessages})

target_link_libraries(BlockchainMessages gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main BlockchainMessages APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS BlockchainMessages)

set_property(TARGET
  tests
 
  BlockchainMessages

PROPERTY FOLDER "tests")

set_property(TARGET BlockchainMessages PROPERTY OUTPUT_NAME "blockchainMessages")

add_test(BlockchainMessages blockchainMessages)