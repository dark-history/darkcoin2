add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE TransactionApiExtra TransactionApiExtra/*)

source_group("" FILES ${TransactionApiExtra})

add_executable(TransactionApiExtra ${TransactionApiExtra})

target_link_libraries(TransactionApiExtra gtest_main CryptoNoteCore Crypto Serialization Logging Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TransactionApiExtra APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TransactionApiExtra)

set_property(TARGET
  tests
 
  TransactionApiExtra

PROPERTY FOLDER "tests")

set_property(TARGET TransactionApiExtra PROPERTY OUTPUT_NAME "transactionApiExtra")

add_test(TransactionApiExtra transactionApiExtra)