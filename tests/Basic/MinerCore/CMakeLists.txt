add_definitions(-DSTATICLIB)

file(GLOB_RECURSE MinerCore MinerCore/*)

source_group("" FILES ${MinerCore})

add_executable(MinerCore ${MinerCore})

target_link_libraries(MinerCore gtest_main CryptoNoteCore Crypto Serialization Logging Common ${Boost_LIBRARIES})

add_custom_target(Basic DEPENDS MinerCore)

set_property(TARGET Basic MinerCore PROPERTY FOLDER "Basic")

set_property(TARGET MinerCore PROPERTY OUTPUT_NAME "MinerCore")

if(NOT MSVC)
  # suppress warnings from gtest
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -Wno-sign-compare -O0")
endif()

add_test(MinerCore MinerCore)