#include <QtTest/QtTest>

#include "common_tests/direction_test.h"
#include "common_tests/point_test.h"
#include "node_tests/node_test.h"
#include "volume_tests/volume_test.h"
#include "space_tests/cache_space_test.h"

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

    CacheSpaceTest cachedSpaceTest;
    QTest::qExec(&cachedSpaceTest);

    return 0;
}

 
