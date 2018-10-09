add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE ConsoleTools ConsoleTools/*)

source_group("" FILES ${ConsoleTools})

add_executable(ConsoleTools ${ConsoleTools})

target_link_libraries(ConsoleTools gtest_main Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ConsoleTools APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS ConsoleTools)

set_property(TARGET
  tests
 
  ConsoleTools

PROPERTY FOLDER "tests")

set_property(TARGET ConsoleTools PROPERTY OUTPUT_NAME "consoleTools")

add_test(ConsoleTools consoleTools)