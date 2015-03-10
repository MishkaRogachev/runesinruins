#include "cache_volume_repository_test.h"

#include "cache_volume_repository.h"
#include "volume.h"

using namespace core;

VolumeRepositoryPtr CacheVolumeRepositoryTest::volumeRepository() const
{
    return VolumeRepositoryPtr(new CacheVolumeRepository());
}

void CacheVolumeRepositoryTest::unloadTest()
{
    CacheVolumeRepository volumeRepository;

    VolumePtr volume(new Volume(1, 1, 1));
    volumeRepository.save(volume, -2, 3, 1);
    volumeRepository.save(volume, 0, 1, 2);

    QVERIFY(volumeRepository.isLoaded(-2, 3, 1));
    QVERIFY(volumeRepository.isLoaded(0, 1, 2));

    volumeRepository.unload(-2, 3, 1);

    QVERIFY(!volumeRepository.isLoaded(-2, 3, 1));
    QVERIFY(volumeRepository.isLoaded(0, 1, 2));

    volumeRepository.unload(0, 1, 2);

    QVERIFY(!volumeRepository.isLoaded(-2, 3, 1));
    QVERIFY(!volumeRepository.isLoaded(0, 1, 2));

    QVERIFY(volumeRepository.allVolumes().empty());

}

void CacheVolumeRepositoryTest::chainingTest()
{
    CacheVolumeRepository volumeRepository;

    VolumePtr v1(new Volume(4, 4, 4));
    VolumePtr v2(new Volume(4, 4, 4));
    VolumePtr v3(new Volume(4, 4, 4));
    VolumePtr v4(new Volume(4, 4, 4));

    volumeRepository.save(v1, 3, 2, 0);

    QVERIFY(!v1->hasChain(Direction::forward));
    QVERIFY(!v2->hasChain(Direction::backward));

    volumeRepository.save(v2, 4, 2, 0);

    QVERIFY(v1->hasChain(Direction::forward));
    QVERIFY(v2->hasChain(Direction::backward));

    volumeRepository.save(v3, 3, 3, 0);

    QVERIFY(v1->hasChain(Direction::right));
    QVERIFY(v3->hasChain(Direction::left));

    volumeRepository.save(v4, 4, 3, 0);

    QVERIFY(v2->hasChain(Direction::right));
    QVERIFY(v4->hasChain(Direction::left));
    QVERIFY(v3->hasChain(Direction::forward));
    QVERIFY(v4->hasChain(Direction::backward));

    volumeRepository.unload(3, 2, 0);

    QVERIFY(!v1->hasChain(Direction::forward));
    QVERIFY(!v2->hasChain(Direction::backward));
    QVERIFY(!v1->hasChain(Direction::right));
    QVERIFY(!v3->hasChain(Direction::left));
}
