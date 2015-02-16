#include "cache_space_test.h"

#include "cache_space.h"

using namespace core;

void CacheSpaceTest::creation()
{
    CacheSpace space(nullptr);

    QVERIFY(!space.hasVolume(Point3i(8, 2, 4)));
    QVERIFY(!space.hasVolume(-4, -2, 5));
}
