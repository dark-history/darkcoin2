add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE BlockIndex BlockIndex/*)

source_group("" FILES ${BlockIndex})

add_executable(BlockIndex ${BlockIndex})

target_link_libraries(BlockIndex gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main BlockIndex APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS BlockIndex)

set_property(TARGET
  tests
 
  BlockIndex

PROPERTY FOLDER "tests")

set_property(TARGET BlockIndex PROPERTY OUTPUT_NAME "blockIndex")

add_test(BlockIndex blockIndex)