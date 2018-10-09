add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE StringView StringView/*)

source_group("" FILES ${StringView})

add_executable(StringView ${StringView})

target_link_libraries(StringView gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main StringView APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS StringView)

set_property(TARGET
  tests
 
  StringView

PROPERTY FOLDER "tests")

set_property(TARGET StringView PROPERTY OUTPUT_NAME "stringView")

add_test(StringView stringView)