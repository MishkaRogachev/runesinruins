#include "abstract_volume_repository_test.h"

#include "abstract_volume_repository.h"
#include "volume.h"

using namespace core;

void AbstractVolumeRepositoryTest::loadTest()
{
    VolumeRepositoryPtr volumeRepository = this->volumeRepository();

    QVERIFY(volumeRepository->allPositions().empty());
    QVERIFY(volumeRepository->allVolumes().empty());

    QVERIFY(!volumeRepository->canLoad(3, 4, 3));
    QVERIFY(!volumeRepository->canLoad(3, 3, 2));

    QVERIFY(!volumeRepository->load(3, 4, 3));
    QVERIFY(!volumeRepository->load(3, 3, 2));

    VolumePtr volume(new Volume(1, 1, 1));
    volumeRepository->save(volume, 3, 4, 3);

    QVERIFY(volumeRepository->canLoad(3, 4, 3));
    QVERIFY(!volumeRepository->canLoad(3, 3, 2));

    VolumePtr cmpVolume = volumeRepository->load(3, 4, 3);
    QVERIFY(cmpVolume);
    QCOMPARE(volume->size(), cmpVolume->size());
    QVERIFY(!volumeRepository->load(3, 3, 2));

    volumeRepository->clear();

    QVERIFY(!volumeRepository->canLoad(3, 4, 3));
    QVERIFY(!volumeRepository->canLoad(3, 3, 2));
}

void AbstractVolumeRepositoryTest::createTest()
{
    VolumeRepositoryPtr volumeRepository = this->volumeRepository();

    bool isNull = !volumeRepository->canCreate(1, 2, 3);
    QCOMPARE(volumeRepository->create(1, 2, 3).isNull(), isNull);

    isNull = !volumeRepository->canCreate(3, 4, 7);
    QCOMPARE(volumeRepository->create(3, 4, 7).isNull(), isNull);
}

void AbstractVolumeRepositoryTest::removeTest()
{
    VolumeRepositoryPtr volumeRepository = this->volumeRepository();

    QVERIFY(!volumeRepository->canLoad(2, 3, 1));
    QVERIFY(!volumeRepository->canLoad(2, 2, 1));

    volumeRepository->save(VolumePtr(new Volume(5, 5, 5)), 2, 3, 1);

    QVERIFY(volumeRepository->canLoad(2, 3, 1));
    QVERIFY(!volumeRepository->canLoad(2, 2, 1));

    volumeRepository->save(VolumePtr(new Volume(5, 5, 5)), 2, 2, 1);

    QVERIFY(volumeRepository->canLoad(2, 3, 1));
    QVERIFY(volumeRepository->canLoad(2, 2, 1));

    volumeRepository->remove(2, 3, 1);

    QVERIFY(!volumeRepository->canLoad(2, 3, 1));
    QVERIFY(volumeRepository->canLoad(2, 2, 1));

    volumeRepository->remove(2, 2, 1);

    QVERIFY(!volumeRepository->canLoad(2, 3, 1));
    QVERIFY(!volumeRepository->canLoad(2, 2, 1));
}
