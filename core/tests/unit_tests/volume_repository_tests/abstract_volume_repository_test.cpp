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

    QCOMPARE(volume, volumeRepository->load(3, 4, 3));
    QVERIFY(!volumeRepository->load(3, 3, 2));
}
