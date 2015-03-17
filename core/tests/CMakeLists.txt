# Project
set (PROJECT core_test)
project (${PROJECT})

# Includes
include_directories(
    ../sources/common
    ../sources/persisters
    ../sources/areas
    ../sources/node
    ../sources/volume
    ../sources/volume_repositories
    ../sources/volume_serializers
    ../sources/volume_generators
    ../sources/node_objects
)

# Sources
file (GLOB_RECURSE TEST_SOURCES "*.h" "*.cpp")

# Output path for executable target
set(EXECUTABLE_OUTPUT_PATH ${RESULT_DIR})

# Executable target
add_executable(core_test ${TEST_SOURCES})

# Libraries
target_link_libraries (core_test core Qt5::Core Qt5::Network Qt5::Test)

# Tests
add_test (NAME core_test COMMAND core_test)
