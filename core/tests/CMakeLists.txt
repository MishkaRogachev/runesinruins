# Project
set (PROJECT core_test)
project (${PROJECT}) 

# Includes
include_directories(
    ../sources/common
    ../sources/persisters
    ../sources/areas
    ../sources/node
    ../sources/volume
    ../sources/volume_repositories
    ../sources/volume_serializers
    ../sources/volume_generators
    ../sources/node_objects
)

# Sources
set(TEST_SOURCES
    unit_tests/common_tests/direction_test.cpp
    unit_tests/common_tests/point_test.cpp
    unit_tests/common_tests/core_traits_test.cpp
    unit_tests/persisters_tests/abstract_persister_test.cpp
    unit_tests/persisters_tests/fs_persister_test.cpp
    unit_tests/areas_tests/abstract_area_test.cpp
    unit_tests/areas_tests/square_area_test.cpp
    unit_tests/node_tests/node_test.cpp
    unit_tests/volume_tests/volume_test.cpp
    unit_tests/volume_serializers_tests/abstract_volume_serializer_test.cpp
    unit_tests/volume_serializers_tests/standart_volume_serializer_test.cpp
    unit_tests/volume_generators_tests/abstract_volume_generator_test.cpp
    unit_tests/volume_generators_tests/standart_volume_generator_test.cpp
    unit_tests/volume_repositories_tests/abstract_volume_repository_test.cpp
    unit_tests/volume_repositories_tests/persistent_volume_repository_test.cpp
    unit_tests/volume_repositories_tests/cache_volume_repository_test.cpp
    unit_tests/volume_repositories_tests/proxy_volume_repository_test.cpp
    unit_tests/volume_repositories_tests/area_proxy_volume_repository_test.cpp
    unit_tests/node_objects_tests/node_object_test.cpp
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
