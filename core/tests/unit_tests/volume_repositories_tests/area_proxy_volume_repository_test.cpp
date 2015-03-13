#include "area_proxy_volume_repository_test.h"

#include "area_proxy_volume_repository.h"
#include "volume.h"

using namespace core;

VolumeRepositoryPtr AreaProxyVolumeRepositoryTest::volumeRepository() const
{
    return VolumeRepositoryPtr(new AreaProxyVolumeRepository());
}

void AreaProxyVolumeRepositoryTest::checkLoadedVolumesTest()
{
    VolumeRepositoryPtr sourceRepository(new CacheVolumeRepository());

    for (int x = 0; x < 7; ++x)
    {
        for (int y = 0; y < 9; ++y)
        {
            sourceRepository->save(VolumePtr(new Volume(5, 5, 5)), x, y, 1);
        }
    }

    AreaProxyVolumeRepository areaRepository(sourceRepository);

    areaRepository.setPosition(3435, 5134, -234);
    areaRepository.setSize(666);

    QVERIFY(!areaRepository.isLoaded(3, 5, 1));
    QVERIFY(!areaRepository.isLoaded(1, 3, 1));
    QVERIFY(!areaRepository.isLoaded(5, 7, 1));

    areaRepository.setPosition(3, 5, 1);
    areaRepository.setSize(2);

    areaRepository.checkLoadedVolumes();

    QVERIFY(areaRepository.isLoaded(3, 5, 1));
    QVERIFY(areaRepository.isLoaded(1, 3, 1));
    QVERIFY(areaRepository.isLoaded(5, 7, 1));

    areaRepository.position().goForward();
    areaRepository.checkLoadedVolumes();

    QVERIFY(!areaRepository.isLoaded(1, 3, 1));
    QVERIFY(areaRepository.isLoaded(2, 3, 1));
    QVERIFY(areaRepository.isLoaded(5, 7, 1));
    QVERIFY(areaRepository.isLoaded(6, 7, 1));

    areaRepository.position().goRight();
    areaRepository.checkLoadedVolumes();

    QVERIFY(!areaRepository.isLoaded(3, 3, 1));
    QVERIFY(!areaRepository.isLoaded(1, 5, 1));
    QVERIFY(areaRepository.isLoaded(6, 8, 1));

    areaRepository.position().goRight();
    areaRepository.checkLoadedVolumes();

    QVERIFY(!areaRepository.isLoaded(6, 9, 1));
}
