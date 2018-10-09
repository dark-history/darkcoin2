add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE CommandLine CommandLine/*)

source_group("" FILES ${CommandLine})

add_executable(CommandLine ${CommandLine})

target_link_libraries(CommandLine gtest_main Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main CommandLine APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS CommandLine)

set_property(TARGET
  tests
 
  CommandLine

PROPERTY FOLDER "tests")

set_property(TARGET CommandLine PROPERTY OUTPUT_NAME "commandLine")

add_test(CommandLine commandLine)