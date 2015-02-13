# Project
set (PROJECT core_test)
project (${PROJECT}) 

# Includes
include_directories(
    ../sources/common
    ../sources/node
    ../sources/volume
    ../sources/space
)

# Sources
set(TEST_SOURCES
    unit_tests/common_tests/vec_test.cpp
    unit_tests/node_tests/node_test.cpp
    unit_tests/volume_tests/volume_test.cpp
    unit_tests/space_tests/cached_space_test.cpp
    unit_tests/unit_tests.cpp
)

# Executable
add_executable(core_test ${TEST_SOURCES})

# Use Qt5 modules
qt5_use_modules(${PROJECT} Core Test)

# Libraries
set (TEST_LIBRARIES core_lib ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES})
target_link_libraries (core_test ${TEST_LIBRARIES})

# Tests
add_test (NAME core_test COMMAND core_test)
