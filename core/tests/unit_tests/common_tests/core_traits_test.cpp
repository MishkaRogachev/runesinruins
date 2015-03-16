#include "core_traits_test.h"

#include "core_traits.h"

using namespace core;

void CoreTraitsTest::testGlobalPoint()
{
    QCOMPARE(globalPoint(Point3i(3, 4, 3),
                         Point3u(2, 1, 4),
                         Point3u(10, 10, 10)),
             Point3i(32, 41, 34));

    QCOMPARE(globalPoint(Point3i(-1, 0, 2),
                         Point3u(9, 9, 0),
                         Point3u(10, 10, 256)),
             Point3i(-1, 9, 512));
}
