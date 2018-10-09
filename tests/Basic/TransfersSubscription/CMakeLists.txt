add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE TransfersSubscription TransfersSubscription/*)

source_group("" FILES ${TransfersSubscription})

add_executable(TransfersSubscription ${TransfersSubscription})

target_link_libraries(TransfersSubscription gtest_main Transfers CryptoNoteCore Crypto Serialization Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TransfersSubscription APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TransfersSubscription)

set_property(TARGET
  tests
 
  TransfersSubscription

PROPERTY FOLDER "tests")

set_property(TARGET TransfersSubscription PROPERTY OUTPUT_NAME "transfersSubscription")

add_test(TransfersSubscription transfersSubscription)