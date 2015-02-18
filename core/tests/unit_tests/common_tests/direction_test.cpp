#include "direction_test.h"

#include "direction.h"

using namespace core;

void DirectionTest::testInversion()
{
    for (Direction dir: Direction::allDirections())
    {
        QVERIFY(dir != Direction::invDirection(dir));
    }

    for (Direction dir: Direction::allDirections())
    {
        QCOMPARE(dir, Direction::invDirection(Direction::invDirection(dir)));
    }
}

void DirectionTest::testStatic()
{
    QCOMPARE(Direction::forward, Direction::invDirection(Direction::backward));
    QCOMPARE(Direction::backward, Direction::invDirection(Direction::forward));
    QCOMPARE(Direction::right, Direction::invDirection(Direction::left));
    QCOMPARE(Direction::left, Direction::invDirection(Direction::right));
    QCOMPARE(Direction::up, Direction::invDirection(Direction::down));
    QCOMPARE(Direction::down, Direction::invDirection(Direction::up));
}
