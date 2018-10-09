add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE MemoryInputStream MemoryInputStream/*)

source_group("" FILES ${MemoryInputStream})

add_executable(MemoryInputStream ${MemoryInputStream})

target_link_libraries(MemoryInputStream gtest_main Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main MemoryInputStream APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS MemoryInputStream)

set_property(TARGET
  tests
 
  MemoryInputStream

PROPERTY FOLDER "tests")

set_property(TARGET MemoryInputStream PROPERTY OUTPUT_NAME "memoryInputStream")

add_test(MemoryInputStream memoryInputStream)