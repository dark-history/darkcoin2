add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE StringBuffer StringBuffer/*)

source_group("" FILES ${StringBuffer})

add_executable(StringBuffer ${StringBuffer})

target_link_libraries(StringBuffer gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main StringBuffer APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(Basic DEPENDS StringBuffer)

set_property(TARGET
  Basic
 
  StringBuffer

PROPERTY FOLDER "Basic")

set_property(TARGET StringBuffer PROPERTY OUTPUT_NAME "stringBuffer")

add_test(StringBuffer stringBuffer)