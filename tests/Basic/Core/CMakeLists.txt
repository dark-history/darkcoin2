add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/HelperFunctions)

file(GLOB_RECURSE Core Core/*)

source_group("" FILES ${Core})

add_executable(Core ${Core})

target_link_libraries(Core gtest_main CryptoNoteCore Crypto Serialization Logging System Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main Core APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS Core)

set_property(TARGET
  tests
 
  Core

PROPERTY FOLDER "tests")

set_property(TARGET Core PROPERTY OUTPUT_NAME "core")

add_test(Core core)