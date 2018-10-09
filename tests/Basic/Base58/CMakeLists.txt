add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE Base58 Base58/*)

source_group("" FILES ${Base58})

add_executable(Base58 ${Base58})

target_link_libraries(Base58 gtest_main CryptoNoteCore Crypto Serialization Logging Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Base58 APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Base58)

set_property(TARGET
  tests
 
  Base58

PROPERTY FOLDER "tests")

set_property(TARGET Base58 PROPERTY OUTPUT_NAME "base58")

add_test(Base58 base58)