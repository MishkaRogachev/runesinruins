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
    common/direction.cpp
    node/node.cpp
    volume/volume.cpp
    volume/volume_iterator.cpp
    volume_repositories/abstract_volume_repository.cpp
    volume_repositories/cache_volume_repository.cpp
    volume_repositories/proxy_volume_repository.cpp
    volume_repositories/persistent_volume_repository.cpp
    persisters/abstract_persister.cpp
    persisters/fs_persister.cpp
)

# Library target
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Use Qt5 modules
qt5_use_modules(${PROJECT} Core Network)

# Libraries
set (TEST_LIBRARIES ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES})
target_link_libraries (core_lib ${TEST_LIBRARIES})
