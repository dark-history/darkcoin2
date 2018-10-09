add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE ContextGroupTimeout ContextGroupTimeout/*)

source_group("" FILES ${ContextGroupTimeout})

add_executable(ContextGroupTimeout ${ContextGroupTimeout})

target_link_libraries(ContextGroupTimeout gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ContextGroupTimeout APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS ContextGroupTimeout)

set_property(TARGET
  tests
 
  ContextGroupTimeout

PROPERTY FOLDER "tests")

set_property(TARGET ContextGroupTimeout PROPERTY OUTPUT_NAME "contextGroupTimeout")

add_test(ContextGroupTimeout contextGroupTimeout)