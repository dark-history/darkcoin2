add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE CryptoNoteBasicImpl CryptoNoteBasicImpl/*)

source_group("" FILES ${CryptoNoteBasicImpl})

add_executable(CryptoNoteBasicImpl ${CryptoNoteBasicImpl})

target_link_libraries(CryptoNoteBasicImpl gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main CryptoNoteBasicImpl APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS CryptoNoteBasicImpl)

set_property(TARGET
  tests
 
  CryptoNoteBasicImpl

PROPERTY FOLDER "tests")

set_property(TARGET CryptoNoteBasicImpl PROPERTY OUTPUT_NAME "cryptoNoteBasicImpl")

add_test(CryptoNoteBasicImpl cryptoNoteBasicImpl)