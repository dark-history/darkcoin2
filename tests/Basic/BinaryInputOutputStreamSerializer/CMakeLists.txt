add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE BinaryInputOutputStreamSerializer BinaryInputOutputStreamSerializer/*)

source_group("" FILES ${BinaryInputOutputStreamSerializer})

add_executable(BinaryInputOutputStreamSerializer ${BinaryInputOutputStreamSerializer})

target_link_libraries(BinaryInputOutputStreamSerializer gtest_main Serialization)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main BinaryInputOutputStreamSerializer APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS BinaryInputOutputStreamSerializer)

set_property(TARGET
  tests
 
  BinaryInputOutputStreamSerializer

PROPERTY FOLDER "tests")

set_property(TARGET BinaryInputOutputStreamSerializer PROPERTY OUTPUT_NAME "binaryInputOutputStreamSerializer")

add_test(BinaryInputOutputStreamSerializer binaryInputOutputStreamSerializer)