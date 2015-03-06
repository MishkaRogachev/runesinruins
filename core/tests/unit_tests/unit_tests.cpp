#include <QtTest/QtTest>

#include "common_tests/direction_test.h"
#include "common_tests/point_test.h"
#include "node_tests/node_test.h"
#include "volume_tests/volume_test.h"
#include "volume_repository_tests/abstract_volume_repository_test.h"
#include "volume_repository_tests/cache_volume_repository_test.h"

int main()
{
    DirectionTest directionTest;
    QTest::qExec(&directionTest);

    PointTest pointTest;
    QTest::qExec(&pointTest);

    NodeTest nodeTest;
    QTest::qExec(&nodeTest);

    VolumeTest volumeTest;
    QTest::qExec(&volumeTest);

    AbstractVolumeRepositoryTest abstractVolumeRepositoryTest;
    QTest::qExec(&abstractVolumeRepositoryTest);

    CacheVolumeRepositoryTest cachedVolumeRepositoryTest;
    QTest::qExec(&cachedVolumeRepositoryTest);

    return 0;
}

 
