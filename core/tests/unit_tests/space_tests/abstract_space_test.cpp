#include "abstract_space_test.h"

#include "abstract_space.h"
#include "volume.h"
#include "space_mock.h"

using namespace core;


void AbstractSpaceTest::testIntegrity()
{
    VolumePtr v1(new Volume(5, 5, 5));
    VolumePtr v2(new Volume(5, 5, 5));
    VolumePtr v3(new Volume(5, 5, 5));

    SpacePtr mock(new SpaceMock({ { { 1, 1, 1 }, v1 },
                                  { { 2, 1, 1 }, v2 },
                                  { { 1, 2, 1 }, v3 } }));

    QVERIFY(mock->hasVolume(1, 1, 1));
    QVERIFY(mock->hasVolume(2, 1, 1));
    QVERIFY(mock->hasVolume(1, 2, 1));
    QVERIFY(!mock->hasVolume(2, 2, 1));

    QCOMPARE(v1, mock->volumeAt(1, 1, 1));
    QCOMPARE(v2, mock->volumeAt(2, 1, 1));
    QCOMPARE(v3, mock->volumeAt(1, 2, 1));
}

void AbstractSpaceTest::testChaning2D()
{
    VolumePtr v1(new Volume(5, 5, 5));
    VolumePtr v2(new Volume(5, 5, 5));
    VolumePtr v3(new Volume(5, 5, 5));
    VolumePtr v4(new Volume(5, 5, 5));
    VolumePtr v5(new Volume(5, 5, 5));
    VolumePtr v6(new Volume(5, 5, 5));
    VolumePtr v7(new Volume(5, 5, 5));
    VolumePtr v8(new Volume(5, 5, 5));
    VolumePtr v9(new Volume(5, 5, 5));

    SpaceMock mock({ { { 0, 0, 0 }, v1 }, { { 0, 1, 0 }, v2 }, { { 0, 2, 0 }, v3 },
                     { { 1, 0, 0 }, v4 }, { { 1, 1, 0 }, v5 }, { { 1, 2, 0 }, v6 },
                     { { 2, 0, 0 }, v7 }, { { 2, 1, 0 }, v8 }, { { 2, 2, 0 }, v9 } });

    QVERIFY(v1->hasChain(Direction::forward));
    QVERIFY(!v1->hasChain(Direction::backward));
    QVERIFY(v1->hasChain(Direction::right));
    QVERIFY(!v1->hasChain(Direction::left));

    QVERIFY(v3->hasChain(Direction::forward));
    QVERIFY(!v3->hasChain(Direction::backward));
    QVERIFY(!v3->hasChain(Direction::right));
    QVERIFY(v3->hasChain(Direction::left));

    QVERIFY(v5->hasChain(Direction::forward));
    QVERIFY(v5->hasChain(Direction::backward));
    QVERIFY(v5->hasChain(Direction::right));
    QVERIFY(v5->hasChain(Direction::left));

    QVERIFY(!v7->hasChain(Direction::forward));
    QVERIFY(v7->hasChain(Direction::backward));
    QVERIFY(v7->hasChain(Direction::right));
    QVERIFY(!v7->hasChain(Direction::left));

    QVERIFY(!v9->hasChain(Direction::forward));
    QVERIFY(v9->hasChain(Direction::backward));
    QVERIFY(!v9->hasChain(Direction::right));
    QVERIFY(v9->hasChain(Direction::left));

    QVERIFY(v2->hasChain(Direction::forward));
    QVERIFY(v4->hasChain(Direction::right));
    QVERIFY(v6->hasChain(Direction::left));
    QVERIFY(v8->hasChain(Direction::backward));

    QVERIFY(v5->hasChain(Direction::forward));
    QVERIFY(v5->hasChain(Direction::right));
    QVERIFY(v5->hasChain(Direction::left));
    QVERIFY(v5->hasChain(Direction::backward));

    mock.remove(Point3i(1, 1, 0));

    QVERIFY(!v2->hasChain(Direction::forward));
    QVERIFY(!v4->hasChain(Direction::right));
    QVERIFY(!v6->hasChain(Direction::left));
    QVERIFY(!v8->hasChain(Direction::backward));

    QVERIFY(!v5->hasChain(Direction::forward));
    QVERIFY(!v5->hasChain(Direction::right));
    QVERIFY(!v5->hasChain(Direction::left));
    QVERIFY(!v5->hasChain(Direction::backward));
}
