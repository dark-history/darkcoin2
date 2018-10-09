add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/Basic/HelperFunctions)

file(GLOB_RECURSE Checkpoints Checkpoints/*)

source_group("" FILES ${Checkpoints})

add_executable(Checkpoints ${Checkpoints})

target_link_libraries(Checkpoints gtest_main CryptoNoteCore Crypto Common Serialization Logging)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Checkpoints APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(Basic DEPENDS Checkpoints)

set_property(TARGET
  Basic
 
  Checkpoints

PROPERTY FOLDER "Basic")

set_property(TARGET Checkpoints PROPERTY OUTPUT_NAME "checkpoints")

add_test(Checkpoints checkpoints)