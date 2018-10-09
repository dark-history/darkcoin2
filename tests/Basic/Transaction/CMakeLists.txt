add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE Transaction Transaction/*)

source_group("" FILES ${Transaction})

add_executable(Transaction ${Transaction})

target_link_libraries(Transaction gtest_main CryptoNoteCore Crypto Serialization Logging Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Transaction APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Transaction)

set_property(TARGET
  tests
 
  Transaction

PROPERTY FOLDER "tests")

set_property(TARGET Transaction PROPERTY OUTPUT_NAME "Transaction")

add_test(Transaction Transaction)