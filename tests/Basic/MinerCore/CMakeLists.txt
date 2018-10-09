add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE MinerCore MinerCore/*)

source_group("" FILES ${MinerCore})

add_executable(MinerCore ${MinerCore})

target_link_libraries(MinerCore gtest_main CryptoNoteCore Crypto Serialization Logging Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main MinerCore APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS MinerCore)

set_property(TARGET
  tests
 
  MinerCore

PROPERTY FOLDER "tests")

set_property(TARGET MinerCore PROPERTY OUTPUT_NAME "minerCore")

add_test(MinerCore minerCore)