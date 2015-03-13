#include "abstract_area_test.h"

#include "abstract_area.h"

using namespace core;

void AbstractAreaTest::testSizes()
{
    Point3iList positions;

    for(int size = 0; size < 16; ++size)
    {
        AreaPtr area = this->area(size);
        QVERIFY(positions.count() < area->positions().count());
        positions = area->positions();
    }
}

void AbstractAreaTest::testPositions()
{
    AreaPtr area = this->area(3);

    Point3iList positions = area->positions();

    area->centerPosition().goForward(3).goRight(2);

    QCOMPARE(positions.count(), area->positions().count());
    QVERIFY(positions != area->positions());

    area->centerPosition().goLeft(2).goBackward(3);

    QCOMPARE(positions, area->positions());
}
