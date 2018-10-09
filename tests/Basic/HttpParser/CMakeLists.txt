add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE HttpParser HttpParser/*)

source_group("" FILES ${HttpParser})

add_executable(HttpParser ${HttpParser})

target_link_libraries(HttpParser gtest_main Rpc)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main HttpParser APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS HttpParser)

set_property(TARGET
  tests
 
  HttpParser

PROPERTY FOLDER "tests")

set_property(TARGET HttpParser PROPERTY OUTPUT_NAME "httpParser")

add_test(HttpParser httpParser)