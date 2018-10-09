add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE CryptoNoteBasic CryptoNoteBasic/*)

source_group("" FILES ${CryptoNoteBasic})

add_executable(CryptoNoteBasic ${CryptoNoteBasic})

target_link_libraries(CryptoNoteBasic gtest_main CryptoNoteCore Crypto Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main CryptoNoteBasic APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS CryptoNoteBasic)

set_property(TARGET
  tests
 
  CryptoNoteBasic

PROPERTY FOLDER "tests")

set_property(TARGET CryptoNoteBasic PROPERTY OUTPUT_NAME "cryptoNoteBasic")

add_test(CryptoNoteBasic cryptoNoteBasic)