add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE MessageQueue MessageQueue/*)

source_group("" FILES ${MessageQueue})

add_executable(MessageQueue ${MessageQueue})

target_link_libraries(MessageQueue gtest_main CryptoNoteCore System Crypto Serialization Logging Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main MessageQueue APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS MessageQueue)

set_property(TARGET
  tests
 
  MessageQueue

PROPERTY FOLDER "tests")

set_property(TARGET MessageQueue PROPERTY OUTPUT_NAME "messageQueue")

add_test(MessageQueue messageQueue)