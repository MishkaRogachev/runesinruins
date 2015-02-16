#include "cached_space_test.h"

#include "cached_space.h"

using namespace core;

void CachedSpaceTest::creation()
{
    CachedSpace space(nullptr);

    QVERIFY(!space.hasVolume(Vec3i(8, 2, 4)));
    QVERIFY(!space.hasVolume(-4, -2, 5));
}
