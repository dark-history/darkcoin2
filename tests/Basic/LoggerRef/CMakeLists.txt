add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE LoggerRef LoggerRef/*)

source_group("" FILES ${LoggerRef})

add_executable(LoggerRef ${LoggerRef})

target_link_libraries(LoggerRef gtest_main Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main LoggerRef APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS LoggerRef)

set_property(TARGET
  tests
 
  LoggerRef

PROPERTY FOLDER "tests")

set_property(TARGET LoggerRef PROPERTY OUTPUT_NAME "loggerRef")

add_test(LoggerRef loggerRef)