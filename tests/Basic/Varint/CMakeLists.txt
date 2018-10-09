add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE Varint Varint/*)

source_group("" FILES ${Varint})

add_executable(Varint ${Varint})

target_link_libraries(Varint gtest_main Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Varint APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Varint)

set_property(TARGET
  tests
 
  Varint

PROPERTY FOLDER "tests")

set_property(TARGET Varint PROPERTY OUTPUT_NAME "varint")

add_test(Varint varint)