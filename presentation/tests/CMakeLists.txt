# Project
set (PROJECT presentation_test)
project (${PROJECT})

# Includes
include_directories(
    ../sources/
)

# Sources
set(TEST_SOURCES
    unit_tests/unit_tests.cpp
)

# Output path for executable target
set(EXECUTABLE_OUTPUT_PATH ${RESULT_DIR})

# Executable target
add_executable(presentation_test ${TEST_SOURCES})

# Use Qt5 modules
qt5_use_modules(${PROJECT} Core Gui Quick Test)

# Libraries
set (TEST_LIBRARIES core presentation ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES})
target_link_libraries (presentation_test ${TEST_LIBRARIES})

# Tests
add_test (NAME presentation_test COMMAND presentation_test)
