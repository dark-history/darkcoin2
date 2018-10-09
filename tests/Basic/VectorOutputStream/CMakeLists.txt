add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE VectorOutputStream VectorOutputStream/*)

source_group("" FILES ${VectorOutputStream})

add_executable(VectorOutputStream ${VectorOutputStream})

target_link_libraries(VectorOutputStream gtest_main Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main VectorOutputStream APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS VectorOutputStream)

set_property(TARGET
  tests
 
  VectorOutputStream

PROPERTY FOLDER "tests")

set_property(TARGET VectorOutputStream PROPERTY OUTPUT_NAME "vectorOutputStream")

add_test(VectorOutputStream vectorOutputStream)