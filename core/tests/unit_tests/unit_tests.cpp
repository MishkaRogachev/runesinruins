 #include <QtTest/QtTest>

#include "common_tests/point_test.h"
#include "node_tests/node_test.h"
#include "volume_tests/volume_test.h"
#include "space_tests/cache_space_test.h"

int main()
{
    PointTest vecTest;
    QTest::qExec(&vecTest);

    NodeTest nodeTest;
    QTest::qExec(&nodeTest);

    VolumeTest volumeTest;
    QTest::qExec(&volumeTest);

    CacheSpaceTest cachedSpaceTest;
    QTest::qExec(&cachedSpaceTest);

    return 0;
}

 
