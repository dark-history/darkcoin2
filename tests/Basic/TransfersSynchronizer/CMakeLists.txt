add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE TransfersSynchronizer TransfersSynchronizer/*)

source_group("" FILES ${TransfersSynchronizer})

add_executable(TransfersSynchronizer ${TransfersSynchronizer})

target_link_libraries(TransfersSynchronizer gtest_main Transfers CryptoNoteCore Crypto Serialization Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main TransfersSynchronizer APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS TransfersSynchronizer)

set_property(TARGET
  tests
 
  TransfersSynchronizer

PROPERTY FOLDER "tests")

set_property(TARGET TransfersSynchronizer PROPERTY OUTPUT_NAME "transfersSynchronizer")

add_test(TransfersSynchronizer transfersSynchronizer)