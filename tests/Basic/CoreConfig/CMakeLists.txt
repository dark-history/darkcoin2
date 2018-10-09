add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

file(GLOB_RECURSE CoreConfig CoreConfig/*)

source_group("" FILES ${CoreConfig})

add_executable(CoreConfig ${CoreConfig})

target_link_libraries(CoreConfig gtest_main CryptoNoteCore Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main CoreConfig APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS CoreConfig)

set_property(TARGET
  tests
 
  CoreConfig

PROPERTY FOLDER "tests")

set_property(TARGET CoreConfig PROPERTY OUTPUT_NAME "coreConfig")

add_test(CoreConfig coreConfig)