add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE HttpResponse HttpResponse/*)

source_group("" FILES ${HttpResponse})

add_executable(HttpResponse ${HttpResponse})

target_link_libraries(HttpResponse gtest_main Rpc)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main HttpResponse APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS HttpResponse)

set_property(TARGET
  tests
 
  HttpResponse

PROPERTY FOLDER "tests")

set_property(TARGET HttpResponse PROPERTY OUTPUT_NAME "httpResponse")

add_test(HttpResponse httpResponse)