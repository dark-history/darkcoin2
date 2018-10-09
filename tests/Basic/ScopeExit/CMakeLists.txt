add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE ScopeExit ScopeExit/*)

source_group("" FILES ${ScopeExit})

add_executable(ScopeExit ${ScopeExit})

target_link_libraries(ScopeExit gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ScopeExit APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(Basic DEPENDS ScopeExit)

set_property(TARGET
  Basic
 
  ScopeExit

PROPERTY FOLDER "Basic")

set_property(TARGET ScopeExit PROPERTY OUTPUT_NAME "scopeExit")

add_test(ScopeExit scopeExit)