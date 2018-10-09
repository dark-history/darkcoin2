add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE ErrorMessage ErrorMessage/*)

source_group("" FILES ${ErrorMessage})

add_executable(ErrorMessage ${ErrorMessage})

target_link_libraries(ErrorMessage gtest_main System)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ErrorMessage APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS ErrorMessage)

set_property(TARGET
  tests
 
  ErrorMessage

PROPERTY FOLDER "tests")

set_property(TARGET ErrorMessage PROPERTY OUTPUT_NAME "errorMessage")

add_test(ErrorMessage errorMessage)