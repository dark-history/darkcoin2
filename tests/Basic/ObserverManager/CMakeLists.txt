add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include)

file(GLOB_RECURSE ObserverManager ObserverManager/*)

source_group("" FILES ${ObserverManager})

add_executable(ObserverManager ${ObserverManager})

target_link_libraries(ObserverManager gtest_main Common)

if(NOT MSVC)
  set_property(TARGET gtest gtest_main ObserverManager APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(tests DEPENDS ObserverManager)

set_property(TARGET
  tests
 
  ObserverManager

PROPERTY FOLDER "tests")

set_property(TARGET ObserverManager PROPERTY OUTPUT_NAME "observerManager")

add_test(ObserverManager observerManager)