add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE LoggerGroup LoggerGroup/*)

source_group("" FILES ${LoggerGroup})

add_executable(LoggerGroup ${LoggerGroup})

target_link_libraries(LoggerGroup gtest_main Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main LoggerGroup APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS LoggerGroup)

set_property(TARGET
  tests
 
  LoggerGroup

PROPERTY FOLDER "tests")

set_property(TARGET LoggerGroup PROPERTY OUTPUT_NAME "loggerGroup")

add_test(LoggerGroup loggerGroup)