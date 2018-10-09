add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE Account Account/*)

source_group("" FILES ${Account})

add_executable(Account ${Account})

target_link_libraries(Account gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Account APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Account)

set_property(TARGET
  tests
 
  Account

PROPERTY FOLDER "tests")

set_property(TARGET Account PROPERTY OUTPUT_NAME "account_test")

add_test(Account account_test)