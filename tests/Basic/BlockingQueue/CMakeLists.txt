add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE BlockingQueue BlockingQueue/*)

source_group("" FILES ${BlockingQueue})

add_executable(BlockingQueue ${BlockingQueue})

target_link_libraries(BlockingQueue gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main BlockingQueue APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS BlockingQueue)

set_property(TARGET
  tests
 
  BlockingQueue

PROPERTY FOLDER "tests")

set_property(TARGET BlockingQueue PROPERTY OUTPUT_NAME "blockingQueue")

add_test(BlockingQueue blockingQueue)