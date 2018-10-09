add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE BlockReward BlockReward/*)

source_group("" FILES ${BlockReward})

add_executable(BlockReward ${BlockReward})

target_link_libraries(BlockReward gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main BlockReward APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS BlockReward)

set_property(TARGET
  tests
 
  BlockReward

PROPERTY FOLDER "tests")

set_property(TARGET BlockReward PROPERTY OUTPUT_NAME "blockReward_test")

add_test(BlockReward blockReward_test)