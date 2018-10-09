add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE FileLogger FileLogger/*)

source_group("" FILES ${FileLogger})

add_executable(FileLogger ${FileLogger})

target_link_libraries(FileLogger gtest_main Logging Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main FileLogger APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS FileLogger)

set_property(TARGET
  tests
 
  FileLogger

PROPERTY FOLDER "tests")

set_property(TARGET FileLogger PROPERTY OUTPUT_NAME "fileLogger")

add_test(FileLogger fileLogger)