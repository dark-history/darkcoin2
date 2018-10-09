add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE TransactionExtra TransactionExtra/*)

source_group("" FILES ${TransactionExtra})

add_executable(TransactionExtra ${TransactionExtra})

target_link_libraries(TransactionExtra gtest_main CryptoNoteCore Crypto Serialization Logging Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TransactionExtra APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TransactionExtra)

set_property(TARGET
  tests
 
  TransactionExtra

PROPERTY FOLDER "tests")

set_property(TARGET TransactionExtra PROPERTY OUTPUT_NAME "transactionExtra")

add_test(TransactionExtra transactionExtra)