# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
project(runesinruins)

# Tell CMake to run moc when necessary:
set (CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir,
# tell CMake to always look for includes there:
set (CMAKE_INCLUDE_CURRENT_DIR ON)

set (RESULT_DIR ${CMAKE_SOURCE_DIR}/result)

# Testing
enable_testing()

# Subprojects
add_subdirectory(core)
add_subdirectory(presentation)
add_subdirectory(editor)
