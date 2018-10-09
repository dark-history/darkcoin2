add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE CryptoNoteProtocolHandler CryptoNoteProtocolHandler/*)

source_group("" FILES ${CryptoNoteProtocolHandler})

add_executable(CryptoNoteProtocolHandler ${CryptoNoteProtocolHandler})

target_link_libraries(CryptoNoteProtocolHandler gtest_main CryptoNoteCore Crypto Serialization Logging System Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main CryptoNoteProtocolHandler APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS CryptoNoteProtocolHandler)

set_property(TARGET
  tests
 
  CryptoNoteProtocolHandler

PROPERTY FOLDER "tests")

set_property(TARGET CryptoNoteProtocolHandler PROPERTY OUTPUT_NAME "cryptoNoteProtocolHandler")

add_test(CryptoNoteProtocolHandler cryptoNoteProtocolHandler)