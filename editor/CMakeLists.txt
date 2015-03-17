# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
project(editor)

# Qt5 Packages
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# Includes
include_directories(
    ../presentation/sources/volume_render_item/
    sources
)

# Sources
file (GLOB_RECURSE SOURCES "*.h" "*.cpp")

# Resources
set(RESOURCES
    resources.qrc
)

# Compile resources to QRC_SOURCES and add it to include path
qt5_add_resources(QRC_SOURCES ${RESOURCES})

# Add compiler flags
add_definitions(-std=c++11 -Wall -fPIC)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${QRC_SOURCES})

# Libraries
set (LIBRARIES core presentation Qt5::Core Qt5::Quick)
target_link_libraries (${PROJECT_NAME} ${LIBRARIES})
