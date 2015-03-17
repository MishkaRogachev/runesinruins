# Project
set (PROJECT presentation)
project (${PROJECT})

# Includes
include_directories(
)

# Sources
set(SOURCES
    volume_renderers/abstract_volume_renderer.cpp
)

# Output path for library target
set(LIBRARY_OUTPUT_PATH ${RESULT_DIR})

# Library target
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Use Qt5 modules
qt5_use_modules(${PROJECT} Core Gui Quick)

# Libraries
set (TEST_LIBRARIES ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES})
target_link_libraries (core ${TEST_LIBRARIES})
