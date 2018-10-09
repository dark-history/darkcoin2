add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE OperationTimeout OperationTimeout/*)

source_group("" FILES ${OperationTimeout})

add_executable(OperationTimeout ${OperationTimeout})

target_link_libraries(OperationTimeout gtest_main P2p Serialization System Logging Common Crypto ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main OperationTimeout APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS OperationTimeout)

set_property(TARGET
  tests
 
  OperationTimeout

PROPERTY FOLDER "tests")

set_property(TARGET OperationTimeout PROPERTY OUTPUT_NAME "operationTimeout")

add_test(OperationTimeout operationTimeout)