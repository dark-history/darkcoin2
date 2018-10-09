add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE ParseAmount ParseAmount/*)

source_group("" FILES ${ParseAmount})

add_executable(ParseAmount ${ParseAmount})

target_link_libraries(ParseAmount gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ParseAmount APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS ParseAmount)

set_property(TARGET
  tests
 
  ParseAmount

PROPERTY FOLDER "tests")

set_property(TARGET ParseAmount PROPERTY OUTPUT_NAME "parseAmount_test")

add_test(ParseAmount parseAmount_test)