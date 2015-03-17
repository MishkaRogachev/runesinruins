# Project
set (PROJECT core)
project (${PROJECT})

# Includes
include_directories(
    common
    persisters
    areas
    node
    volume
    volume_serializers
    volume_generators
    volume_repositories
    node_objects
)

# Sources
file (GLOB_RECURSE SOURCES "*.h" "*.cpp")

# Output path for library target
set(LIBRARY_OUTPUT_PATH ${RESULT_DIR})

# Library target
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Libraries
target_link_libraries (core Qt5::Core Qt5::Network Qt5::Test)
