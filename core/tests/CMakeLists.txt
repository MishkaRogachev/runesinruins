# Project
set (PROJECT core_test)
project (${PROJECT}) 

# Includes
include_directories(
    ../sources/cubic_structure/node
    ../sources/cubic_structure/volume
    ../sources/cubic_structure/area
)

# Sources
set(TEST_SOURCES
    unit_tests/cubic_structure/node_test/node_test.cpp
    unit_tests/cubic_structure/volume_test/volume_test.cpp
    unit_tests/cubic_structure/area_test/area_test.cpp
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
