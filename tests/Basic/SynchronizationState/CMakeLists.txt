add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE SynchronizationState SynchronizationState/*)

source_group("" FILES ${SynchronizationState})

add_executable(SynchronizationState ${SynchronizationState})

target_link_libraries(SynchronizationState gtest_main Transfers CryptoNoteCore Crypto Serialization Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main SynchronizationState APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS SynchronizationState)

set_property(TARGET
  tests
 
  SynchronizationState

PROPERTY FOLDER "tests")

set_property(TARGET SynchronizationState PROPERTY OUTPUT_NAME "synchronizationState")

add_test(SynchronizationState synchronizationState)