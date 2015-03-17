# Project
set (PROJECT presentation)
project (${PROJECT})

# Includes
include_directories(
    volume_renderers
)

# Sources
set(SOURCES
    volume_renderers/abstract_volume_renderer.cpp
)

# Output path for library target
set(LIBRARY_OUTPUT_PATH ${RESULT_DIR})

# Library target
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Libraries
target_link_libraries (presentation core Qt5::Core Qt5::Gui Qt5::Quick)
