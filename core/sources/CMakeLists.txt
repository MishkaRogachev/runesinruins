# Project
set (PROJECT core_lib)
project (${PROJECT})

# Includes
include_directories(
    common
    node
    volume
    space
)

# Sources
set(SOURCES
    common/point.cpp
    node/node.cpp
    volume/volume.cpp
    volume/volume_iterator.cpp
    space/abstract_space.cpp
    space/cached_space.cpp
)

# Library target
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Use Qt5 modules
qt5_use_modules(${PROJECT} Core Network)

# Libraries
set (TEST_LIBRARIES ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES})
target_link_libraries (core_lib ${TEST_LIBRARIES})
