add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE TransactionPrefixImpl TransactionPrefixImpl/*)

source_group("" FILES ${TransactionPrefixImpl})

add_executable(TransactionPrefixImpl ${TransactionPrefixImpl})

target_link_libraries(TransactionPrefixImpl gtest_main CryptoNoteCore Crypto Serialization Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TransactionPrefixImpl APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TransactionPrefixImpl)

set_property(TARGET
  tests
 
  TransactionPrefixImpl

PROPERTY FOLDER "tests")

set_property(TARGET TransactionPrefixImpl PROPERTY OUTPUT_NAME "transactionPrefixImpl")

add_test(TransactionPrefixImpl transactionPrefixImpl)