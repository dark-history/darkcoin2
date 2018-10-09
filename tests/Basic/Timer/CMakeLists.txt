add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE Timer Timer/*)

source_group("" FILES ${Timer})

add_executable(Timer ${Timer})

target_link_libraries(Timer gtest_main System)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Timer APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Timer)

set_property(TARGET
  tests
 
  Timer

PROPERTY FOLDER "tests")

set_property(TARGET Timer PROPERTY OUTPUT_NAME "timer")

add_test(Timer timer)