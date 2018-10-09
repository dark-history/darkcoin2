add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE LoggerMessage LoggerMessage/*)

source_group("" FILES ${LoggerMessage})

add_executable(LoggerMessage ${LoggerMessage})

target_link_libraries(LoggerMessage gtest_main Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main LoggerMessage APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS LoggerMessage)

set_property(TARGET
  tests
 
  LoggerMessage

PROPERTY FOLDER "tests")

set_property(TARGET LoggerMessage PROPERTY OUTPUT_NAME "loggerMessage")

add_test(LoggerMessage loggerMessage)