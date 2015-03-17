# Project
set (PROJECT core)
project (${PROJECT})

# Includes
include_directories(
    common
    persisters
    areas
    node
    volume
    volume_serializers
    volume_generators
    volume_repositories
    node_objects
)

# Sources
set(SOURCES
    common/direction.cpp
    common/core_traits.cpp
    persisters/abstract_persister.cpp
    persisters/fs_persister.cpp
    areas/abstract_area.cpp
    areas/square_area.cpp
    node/node.cpp
    volume/volume.cpp
    volume/volume_iterator.cpp
    volume_serializers/abstract_volume_serializer.cpp
    volume_serializers/standart_volume_serializer.cpp
    volume_generators/abstract_volume_generator.cpp
    volume_generators/standart_volume_generator.cpp
    volume_repositories/abstract_volume_repository.cpp
    volume_repositories/persistent_volume_repository.cpp
    volume_repositories/cache_volume_repository.cpp
    volume_repositories/proxy_volume_repository.cpp
    volume_repositories/area_proxy_volume_repository.cpp
    node_objects/node_object.cpp
)

# Output path for library target
set(LIBRARY_OUTPUT_PATH ${RESULT_DIR})

# Library target
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Use Qt5 modules
qt5_use_modules(${PROJECT} Core Network)

# Libraries
set (TEST_LIBRARIES ${QT_QTTEST_LIBRARY} ${QT_LIBRARIES})
target_link_libraries (core ${TEST_LIBRARIES})
