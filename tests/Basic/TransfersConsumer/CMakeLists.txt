add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE TransfersConsumer TransfersConsumer/*)

source_group("" FILES ${TransfersConsumer})

add_executable(TransfersConsumer ${TransfersConsumer})

target_link_libraries(TransfersConsumer gtest_main Transfers CryptoNoteCore Crypto Serialization Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TransfersConsumer APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TransfersConsumer)

set_property(TARGET
  tests
 
  TransfersConsumer

PROPERTY FOLDER "tests")

set_property(TARGET TransfersConsumer PROPERTY OUTPUT_NAME "transfersConsumer")

add_test(TransfersConsumer transfersConsumer)