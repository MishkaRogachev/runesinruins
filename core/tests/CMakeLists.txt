# Project
set (PROJECT core_test)
project (${PROJECT}) 

# Includes
include_directories(
    ../sources/common
    ../sources/node
    ../sources/volume
    ../sources/volume_repositories
    ../sources/persisters
)

# Sources
set(TEST_SOURCES
    unit_tests/common_tests/direction_test.cpp
    unit_tests/common_tests/point_test.cpp
    unit_tests/node_tests/node_test.cpp
    unit_tests/volume_tests/volume_test.cpp
    unit_tests/volume_repositories_tests/abstract_volume_repository_test.cpp
    unit_tests/volume_repositories_tests/cache_volume_repository_test.cpp
    unit_tests/volume_repositories_tests/proxy_volume_repository_test.cpp
    unit_tests/persisters_tests/abstract_persister_test.cpp
    unit_tests/persisters_tests/fs_persister_test.cpp
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
