add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE Context Context/*)

source_group("" FILES ${Context})

add_executable(Context ${Context})

target_link_libraries(Context gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Context APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Context)

set_property(TARGET
  tests
 
  Context

PROPERTY FOLDER "tests")

set_property(TARGET Context PROPERTY OUTPUT_NAME "context")

add_test(Context context)