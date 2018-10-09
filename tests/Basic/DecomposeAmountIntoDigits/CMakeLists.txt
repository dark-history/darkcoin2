add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE DecomposeAmountIntoDigits DecomposeAmountIntoDigits/*)

source_group("" FILES ${DecomposeAmountIntoDigits})

add_executable(DecomposeAmountIntoDigits ${DecomposeAmountIntoDigits})

target_link_libraries(DecomposeAmountIntoDigits gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main DecomposeAmountIntoDigits APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS DecomposeAmountIntoDigits)

set_property(TARGET
  tests
 
  DecomposeAmountIntoDigits

PROPERTY FOLDER "tests")

set_property(TARGET DecomposeAmountIntoDigits PROPERTY OUTPUT_NAME "decomposeAmountIntoDigits_test")

add_test(DecomposeAmountIntoDigits decomposeAmountIntoDigits_test)