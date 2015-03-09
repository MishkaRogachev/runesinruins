#include "cache_volume_repository_test.h"

#include "cache_volume_repository.h"
#include "volume.h"

#include <QDebug>

using namespace core;


VolumeRepositoryPtr CacheVolumeRepositoryTest::volumeRepository() const
{
    return VolumeRepositoryPtr(new CacheVolumeRepository());
}

//void CacheVolumeRepositoryTest::testConstructors()
//{
////    CacheVolumeRepository space(SpacePtr(new SpaceMock()));
////    Q_UNUSED(space)
//}

//void CacheVolumeRepositoryTest::testAbstractInterface()
//{
////    SpacePtr mock(new SpaceMock({ { { 12, 34, 1 }, VolumePtr(new Volume(1, 1, 1)) },
////                                  { { 43, -5, 0 }, VolumePtr(new Volume(1, 1, 1)) },
////                                  { { -7, 69, 7 }, VolumePtr(new Volume(1, 1, 1)) }}));
////    CacheVolumeRepository space(mock);

////    QVERIFY(space.allPositions().empty());
////    QVERIFY(space.allVolumes().empty());

////    QCOMPARE(space.load(32, 11, 4), VolumePtr());
////    QVERIFY(space.load(12, 34, 1) != VolumePtr());
//}

//void CacheVolumeRepositoryTest::testLoading()
//{
////    SpacePtr mock(new SpaceMock({ { { 4, 4, -4 }, VolumePtr(new Volume(1, 1, 1)) },
////                                  { { 5, -5, 0 }, VolumePtr(new Volume(1, 1, 1)) } }));
////    CacheVolumeRepository space(mock);

////    QVERIFY(!space.load(0, 1, 2).get());
////    QVERIFY(space.load(4, 4, -4).get());

////    QVERIFY(!space.isLoaded(0, 1, 2));
////    QVERIFY(space.isLoaded(4, 4, -4));

////    QVERIFY(!space.allVolumes().empty());

////    QCOMPARE(space.load(0, 1, 2), VolumePtr());
////    QVERIFY(space.load(4, 4, -4) != VolumePtr());

////    space.unload(4, 4, -4);

////    QVERIFY(space.allVolumes().empty());
////    QVERIFY(!space.isLoaded(4, 4, -4));
//}
