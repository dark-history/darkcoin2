add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE ArrayRef ArrayRef/*)

source_group("" FILES ${ArrayRef})

add_executable(ArrayRef ${ArrayRef})

target_link_libraries(ArrayRef gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ArrayRef APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(Basic DEPENDS ArrayRef)

set_property(TARGET
  Basic
 
  ArrayRef

PROPERTY FOLDER "Basic")

set_property(TARGET ArrayRef PROPERTY OUTPUT_NAME "arrayRef")

add_test(ArrayRef arrayRef)