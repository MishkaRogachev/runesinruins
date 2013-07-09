# Project
set (PROJECT core_lib)
project (${PROJECT})

# Includes
include_directories(
    cubic_structure/node
    cubic_structure/volume
)

# Sources
set(SOURCES
  cubic_structure/node/node.cpp
  cubic_structure/volume/volume.cpp
  cubic_structure/volume/volume_iterator.cpp
)

# Library target
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Use Qt5 modules
qt5_use_modules(${PROJECT} Core)

# Libraries
set (TEST_LIBRARIES ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES})
target_link_libraries (core_lib ${TEST_LIBRARIES})
