# CMake
cmake_minimum_required (VERSION 2.8.9)

# Project
set (PROJECT core)
project (${PROJECT})

# Add compiler flags
add_definitions(-std=c++11 -Wall -fPIC)

# Qt5 Packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Test REQUIRED)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir,
# tell CMake to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Testing
enable_testing()

# Subdirs
add_subdirectory (sources build/sources)
add_subdirectory (tests build/tests)
