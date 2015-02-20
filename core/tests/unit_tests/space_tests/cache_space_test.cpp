#include "cache_space_test.h"

#include "cache_space.h"
#include "volume.h"
#include "space_mock.h"

using namespace core;

void CacheSpaceTest::testConstructors()
{
    CacheSpace space(SpacePtr(new SpaceMock()));
    Q_UNUSED(space)
}

void CacheSpaceTest::testAbstractInterface()
{
    SpacePtr mock(new SpaceMock({ { { 12, 34, 1 }, VolumePtr(new Volume(1, 1, 1)) },
                                  { { 43, -5, 0 }, VolumePtr(new Volume(1, 1, 1)) },
                                  { { -7, 69, 7 }, VolumePtr(new Volume(1, 1, 1)) }}));
    CacheSpace space(mock);

    QVERIFY(space.positions().empty());
    QVERIFY(space.volumes().empty());

    QCOMPARE(space.volumeAt(32, 11, 4), VolumePtr());
    QVERIFY(space.volumeAt(12, 34, 1) != VolumePtr());
}

void CacheSpaceTest::testLoading()
{
    SpacePtr mock(new SpaceMock({ { { 4, 4, -4 }, VolumePtr(new Volume(1, 1, 1)) },
                                  { { 5, -5, 0 }, VolumePtr(new Volume(1, 1, 1)) } }));
    CacheSpace space(mock);

    QVERIFY(!space.load(0, 1, 2));
    QVERIFY(space.load(4, 4, -4));

    QVERIFY(!space.isLoaded(0, 1, 2));
    QVERIFY(space.isLoaded(4, 4, -4));

    QVERIFY(!space.volumes().empty());

    QCOMPARE(space.volumeAt(0, 1, 2), VolumePtr());
    QVERIFY(space.volumeAt(4, 4, -4) != VolumePtr());

    space.unload(4, 4, -4);

    QVERIFY(space.volumes().empty());
    QVERIFY(!space.isLoaded(4, 4, -4));
}
