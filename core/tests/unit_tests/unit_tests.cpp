 #include <QtTest/QtTest>

#include "node_tests/node_test.h"
#include "volume_tests/volume_test.h"
#include "space_tests/cached_space_test.h"

int main()
{
    NodeTest nodeTest;
    QTest::qExec(&nodeTest);

    VolumeTest volumeTest;
    QTest::qExec(&volumeTest);

    CachedSpaceTest cachedSpaceTest;
    QTest::qExec(&cachedSpaceTest);

    return 0;
}

 
