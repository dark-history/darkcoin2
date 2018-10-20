add_definitions(-DSTATICLIB)

file(GLOB_RECURSE StdInputStream StdInputStream/*)

source_group("" FILES ${StdInputStream})

add_executable(StdInputStream ${StdInputStream})

target_link_libraries(StdInputStream gtest_main Common)

add_custom_target(Basic DEPENDS StdInputStream)

set_property(TARGET Basic StdInputStream PROPERTY FOLDER "Basic")

set_property(TARGET StdInputStream PROPERTY OUTPUT_NAME "StdInputStream")

if(NOT MSVC)
  # suppress warnings from gtest
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -Wno-sign-compare -O0")
endif()

add_test(StdInputStream StdInputStream)