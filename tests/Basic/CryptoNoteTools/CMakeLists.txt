add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE CryptoNoteTools CryptoNoteTools/*)

source_group("" FILES ${CryptoNoteTools})

add_executable(CryptoNoteTools ${CryptoNoteTools})

target_link_libraries(CryptoNoteTools gtest_main CryptoNoteCore Serialization Common Crypto Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main CryptoNoteTools APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS CryptoNoteTools)

set_property(TARGET
  tests
 
  CryptoNoteTools

PROPERTY FOLDER "tests")

set_property(TARGET CryptoNoteTools PROPERTY OUTPUT_NAME "cryptoNoteTools")

add_test(CryptoNoteTools cryptoNoteTools)