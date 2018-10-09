add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/Basic/HelperFunctions)

file(GLOB_RECURSE RpcServer RpcServer/*)

source_group("" FILES ${RpcServer})

add_executable(RpcServer ${RpcServer})

target_link_libraries(RpcServer gtest_main CryptoNoteCore BlockchainExplorer Crypto Serialization Logging System Common ${Boost_LIBRARIES})

if(NOT MSVC)
  set_property(TARGET gtest gtest_main RpcServer APPEND_STRING PROPERTY COMPILE_FLAGS " -Wno-undef -Wno-sign-compare -O0")
endif()

add_custom_target(Basic DEPENDS RpcServer)

set_property(TARGET
  Basic
 
  RpcServer

PROPERTY FOLDER "Basic")

set_property(TARGET RpcServer PROPERTY OUTPUT_NAME "RpcServer")

add_test(RpcServer RpcServer)