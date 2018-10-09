add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE TransactionUtils TransactionUtils/*)

source_group("" FILES ${TransactionUtils})

add_executable(TransactionUtils ${TransactionUtils})

target_link_libraries(TransactionUtils gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TransactionUtils APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TransactionUtils)

set_property(TARGET
  tests
 
  TransactionUtils

PROPERTY FOLDER "tests")

set_property(TARGET TransactionUtils PROPERTY OUTPUT_NAME "transactionUtils")

add_test(TransactionUtils transactionUtils)