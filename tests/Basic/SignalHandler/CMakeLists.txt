add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE SignalHandler SignalHandler/*)

source_group("" FILES ${SignalHandler})

add_executable(SignalHandler ${SignalHandler})

target_link_libraries(SignalHandler gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main SignalHandler APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS SignalHandler)

set_property(TARGET
  tests
 
  SignalHandler

PROPERTY FOLDER "tests")

set_property(TARGET SignalHandler PROPERTY OUTPUT_NAME "signalHandler")

add_test(SignalHandler signalHandler)