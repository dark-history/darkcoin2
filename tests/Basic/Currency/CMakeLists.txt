add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE Currency Currency/*)

source_group("" FILES ${Currency})

add_executable(Currency ${Currency})

target_link_libraries(Currency gtest_main CryptoNoteCore Serialization Common Crypto Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Currency APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Currency)

set_property(TARGET
  tests
 
  Currency

PROPERTY FOLDER "tests")

set_property(TARGET Currency PROPERTY OUTPUT_NAME "currency")

add_test(Currency currency)