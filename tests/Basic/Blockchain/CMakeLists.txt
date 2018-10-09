add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE Blockchain Blockchain/*)

source_group("" FILES ${Blockchain})

add_executable(Blockchain ${Blockchain})

target_link_libraries(Blockchain gtest_main CryptoNoteCore Crypto Serialization Logging BlockchainExplorer System Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Blockchain APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Blockchain)

set_property(TARGET
  tests
 
  Blockchain

PROPERTY FOLDER "tests")

set_property(TARGET Blockchain PROPERTY OUTPUT_NAME "blockchain")

add_test(Blockchain blockchain)