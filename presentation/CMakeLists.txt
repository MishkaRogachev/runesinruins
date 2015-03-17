# CMake
cmake_minimum_required (VERSION 2.8.11)

# Project
project (presentation)

# Add compiler flags
add_definitions (-std=c++11 -Wall -fPIC)

# Qt5 Packages
find_package (Qt5 COMPONENTS Core Gui Quick Test REQUIRED)

# Subdirs
add_subdirectory (sources)
add_subdirectory (tests)
