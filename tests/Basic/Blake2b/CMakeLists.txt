add_definitions(-DSTATICLIB)

include_directories(${CMAKE_SOURCE_DIR}/tests/Basic/HelperFunctions)

file(GLOB_RECURSE Blake2b Blake2b/*)

source_group("" FILES ${Blake2b})

add_executable(Blake2b ${Blake2b})

target_link_libraries(Blake2b gtest_main CryptoNoteCore BlockchainExplorer Crypto Serialization Logging System Common ${Boost_LIBRARIES})

add_custom_target(Basic DEPENDS Blake2b)

set_property(TARGET Basic Blake2b PROPERTY FOLDER "Basic")

set_property(TARGET Blake2b PROPERTY OUTPUT_NAME "Blake2b")

if(NOT MSVC)
  # suppress warnings from gtest
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -Wno-sign-compare -O0")
endif()

add_test(Blake2b Blake2b)