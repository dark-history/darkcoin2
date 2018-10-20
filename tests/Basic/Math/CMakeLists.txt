add_definitions(-DSTATICLIB)

file(GLOB_RECURSE Math Math/*)

source_group("" FILES ${Math})

add_executable(Math ${Math})

target_link_libraries(Math gtest_main Logging Common ${Boost_LIBRARIES})

add_custom_target(Basic DEPENDS Math)

set_property(TARGET Basic Math PROPERTY FOLDER "Basic")

set_property(TARGET Math PROPERTY OUTPUT_NAME "Math")

if(NOT MSVC)
  # suppress warnings from gtest
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -Wno-sign-compare -O0")
endif()

add_test(Math Math)