add_definitions(-DSTATICLIB)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../version)

include_directories(${CMAKE_SOURCE_DIR}/tests/Basic/HelperFunctions)

file(GLOB_RECURSE BlockchainIndices BlockchainIndices/*)

source_group("" FILES ${BlockchainIndices})

add_executable(BlockchainIndices ${BlockchainIndices})

target_link_libraries(BlockchainIndices gtest_main CryptoNoteCore BlockchainExplorer Crypto Common Serialization Logging)

add_custom_target(Basic DEPENDS BlockchainIndices)

set_property(TARGET Basic BlockchainIndices PROPERTY FOLDER "Basic")

set_property(TARGET BlockchainIndices PROPERTY OUTPUT_NAME "BlockchainIndices")

if(NOT MSVC)
  # suppress warnings from gtest
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -Wno-sign-compare -O0")
endif()