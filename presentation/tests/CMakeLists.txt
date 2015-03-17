# Project
set (PROJECT presentation_test)
project (${PROJECT})

# Includes
include_directories(
    ../sources/volume_renderers
)

# Sources
file (GLOB_RECURSE TEST_SOURCES "*.h" "*.cpp")

# Output path for executable target
set(EXECUTABLE_OUTPUT_PATH ${RESULT_DIR})

# Executable target
add_executable(presentation_test ${TEST_SOURCES})

# Libraries
set (TEST_LIBRARIES core presentation ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES})
target_link_libraries (presentation_test presentation core
                       Qt5::Core Qt5::Gui Qt5::Quick Qt5::Test)

# Tests
add_test (NAME presentation_test COMMAND presentation_test)
