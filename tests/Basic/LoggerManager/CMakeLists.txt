add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE LoggerManager LoggerManager/*)

source_group("" FILES ${LoggerManager})

add_executable(LoggerManager ${LoggerManager})

target_link_libraries(LoggerManager gtest_main Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main LoggerManager APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS LoggerManager)

set_property(TARGET
  tests
 
  LoggerManager

PROPERTY FOLDER "tests")

set_property(TARGET LoggerManager PROPERTY OUTPUT_NAME "loggerManager")

add_test(LoggerManager loggerManager)