add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE TransfersContainer TransfersContainer/*)

source_group("" FILES ${TransfersContainer})

add_executable(TransfersContainer ${TransfersContainer})

target_link_libraries(TransfersContainer gtest_main CryptoNoteCore Crypto Serialization Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TransfersContainer APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TransfersContainer)

set_property(TARGET
  tests
 
  TransfersContainer

PROPERTY FOLDER "tests")

set_property(TARGET TransfersContainer PROPERTY OUTPUT_NAME "transfersContainer")

add_test(TransfersContainer transfersContainer)