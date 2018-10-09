add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE Chacha8 Chacha8/*)

source_group("" FILES ${Chacha8})

add_executable(Chacha8 ${Chacha8})

target_link_libraries(Chacha8 gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Chacha8 APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Chacha8)

set_property(TARGET
  tests
 
  Chacha8

PROPERTY FOLDER "tests")

set_property(TARGET Chacha8 PROPERTY OUTPUT_NAME "chacha8_test")

add_test(Chacha8 chacha8_test)