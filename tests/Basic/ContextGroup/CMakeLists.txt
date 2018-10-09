add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE ContextGroup ContextGroup/*)

source_group("" FILES ${ContextGroup})

add_executable(ContextGroup ${ContextGroup})

target_link_libraries(ContextGroup gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ContextGroup APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS ContextGroup)

set_property(TARGET
  tests
 
  ContextGroup

PROPERTY FOLDER "tests")

set_property(TARGET ContextGroup PROPERTY OUTPUT_NAME "contextGroup")

add_test(ContextGroup contextGroup)