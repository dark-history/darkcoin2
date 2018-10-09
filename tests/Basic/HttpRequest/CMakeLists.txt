add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE HttpRequest HttpRequest/*)

source_group("" FILES ${HttpRequest})

add_executable(HttpRequest ${HttpRequest})

target_link_libraries(HttpRequest gtest_main Rpc)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main HttpRequest APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS HttpRequest)

set_property(TARGET
  tests
 
  HttpRequest

PROPERTY FOLDER "tests")

set_property(TARGET HttpRequest PROPERTY OUTPUT_NAME "httpRequest")

add_test(HttpRequest httpRequest)