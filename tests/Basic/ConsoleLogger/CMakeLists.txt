add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE ConsoleLogger ConsoleLogger/*)

source_group("" FILES ${ConsoleLogger})

add_executable(ConsoleLogger ${ConsoleLogger})

target_link_libraries(ConsoleLogger gtest_main Logging Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ConsoleLogger APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS ConsoleLogger)

set_property(TARGET
  tests
 
  ConsoleLogger

PROPERTY FOLDER "tests")

set_property(TARGET ConsoleLogger PROPERTY OUTPUT_NAME "consoleLogger")

add_test(ConsoleLogger consoleLogger)