add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)


file(GLOB_RECURSE BlockchainSynchronizer BlockchainSynchronizer/*)

source_group("" FILES ${BlockchainSynchronizer})

add_executable(BlockchainSynchronizer ${BlockchainSynchronizer})

target_link_libraries(BlockchainSynchronizer gtest_main Transfers CryptoNoteCore Crypto Serialization Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main BlockchainSynchronizer APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS BlockchainSynchronizer)

set_property(TARGET
  tests
 
  BlockchainSynchronizer

PROPERTY FOLDER "tests")

set_property(TARGET BlockchainSynchronizer PROPERTY OUTPUT_NAME "blockchainSynchronizer")

add_test(BlockchainSynchronizer blockchainSynchronizer)