add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE BlockchainIndices BlockchainIndices/*)

source_group("" FILES ${BlockchainIndices})

add_executable(BlockchainIndices ${BlockchainIndices})

target_link_libraries(BlockchainIndices gtest_main CryptoNoteCore BlockchainExplorer Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main BlockchainIndices APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS BlockchainIndices)

set_property(TARGET
  tests
 
  BlockchainIndices

PROPERTY FOLDER "tests")

set_property(TARGET BlockchainIndices PROPERTY OUTPUT_NAME "blockchainIndices")

add_test(BlockchainIndices blockchainIndices)