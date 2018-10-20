add_definitions(-DSTATICLIB)

file(GLOB_RECURSE CommandLine CommandLine/*)

source_group("" FILES ${CommandLine})

add_executable(CommandLine ${CommandLine})

target_link_libraries(CommandLine gtest_main Common ${Boost_LIBRARIES})

add_custom_target(Basic DEPENDS CommandLine)

set_property(TARGET Basic CommandLine PROPERTY FOLDER "Basic")

set_property(TARGET CommandLine PROPERTY OUTPUT_NAME "CommandLine")

if(NOT MSVC)
  # suppress warnings from gtest
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -Wno-sign-compare -O0")
endif()

add_test(CommandLine CommandLine)