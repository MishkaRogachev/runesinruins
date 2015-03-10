#include "proxy_volume_repository_test.h"

#include "cache_volume_repository.h"
#include "proxy_volume_repository.h"
#include "volume.h"

using namespace core;

VolumeRepositoryPtr ProxyVolumeRepositoryTest::volumeRepository() const
{
    return VolumeRepositoryPtr(new ProxyVolumeRepository());
}

void ProxyVolumeRepositoryTest::canLoadisLoadedTest()
{
    VolumeRepositoryPtr sourceRepository(new CacheVolumeRepository());

    VolumePtr v1(new Volume(16, 16, 16));
    VolumePtr v2(new Volume(16, 16, 16));

    sourceRepository->save(v1, 1, 2, 0);
    sourceRepository->save(v2, 2, 1, 0);

    ProxyVolumeRepository proxyRepository(sourceRepository);

    QVERIFY(!proxyRepository.isLoaded(1, 2, 0));
    QVERIFY(!proxyRepository.isLoaded(2, 1, 0));
    QVERIFY(!proxyRepository.isLoaded(2, 2, 0));
    QVERIFY(proxyRepository.canLoad(1, 2, 0));
    QVERIFY(proxyRepository.canLoad(2, 1, 0));
    QVERIFY(!proxyRepository.canLoad(2, 2, 0));

    QCOMPARE(proxyRepository.load(1, 2, 0), v1);

    QVERIFY(proxyRepository.isLoaded(1, 2, 0));
    QVERIFY(!proxyRepository.isLoaded(2, 1, 0));
    QVERIFY(!proxyRepository.isLoaded(2, 2, 0));
    QVERIFY(proxyRepository.canLoad(1, 2, 0));
    QVERIFY(proxyRepository.canLoad(2, 1, 0));
    QVERIFY(!proxyRepository.canLoad(2, 2, 0));
}

void ProxyVolumeRepositoryTest::proxySaveTest()
{
    VolumeRepositoryPtr sourceRepository(new CacheVolumeRepository());
    ProxyVolumeRepository proxyRepository(sourceRepository);

    QVERIFY(!proxyRepository.isLoaded(3, 2, 5));
    QVERIFY(!proxyRepository.canLoad(3, 2, 5));
    QVERIFY(!proxyRepository.isLoaded(7, 1, 3));
    QVERIFY(!proxyRepository.canLoad(7, 1, 3));

    proxyRepository.save(VolumePtr(new Volume(32, 32, 32)), 3, 2, 5);
    proxyRepository.save(VolumePtr(new Volume(32, 32, 32)), 7, 1, 3);

    QVERIFY(proxyRepository.isLoaded(3, 2, 5));
    QVERIFY(proxyRepository.canLoad(3, 2, 5));
    QVERIFY(proxyRepository.isLoaded(7, 1, 3));
    QVERIFY(proxyRepository.canLoad(7, 1, 3));

    proxyRepository.unload(3, 2, 5);

    QVERIFY(!proxyRepository.isLoaded(3, 2, 5));
    QVERIFY(proxyRepository.canLoad(3, 2, 5));
    QVERIFY(proxyRepository.isLoaded(7, 1, 3));
    QVERIFY(proxyRepository.canLoad(7, 1, 3));

    proxyRepository.remove(3, 2, 5);
    proxyRepository.remove(7, 1, 3);

    QVERIFY(!proxyRepository.isLoaded(3, 2, 5));
    QVERIFY(!proxyRepository.canLoad(3, 2, 5));
    QVERIFY(!proxyRepository.isLoaded(7, 1, 3));
    QVERIFY(!proxyRepository.canLoad(7, 1, 3));
}

void ProxyVolumeRepositoryTest::reloadTest()
{
    VolumeRepositoryPtr sourceRepository(new CacheVolumeRepository());
    ProxyVolumeRepository proxyRepository(sourceRepository);

    VolumePtr v1(new Volume(16, 16, 16));
    VolumePtr v2(new Volume(16, 16, 16));

    sourceRepository->save(v1, 1, 2, 0);

    QCOMPARE(proxyRepository.load(1, 2, 0), v1);

    sourceRepository->save(v2, 1, 2, 0);

    QCOMPARE(proxyRepository.load(1, 2, 0), v1);
    QCOMPARE(proxyRepository.reload(1, 2, 0), v2);
    QCOMPARE(proxyRepository.load(1, 2, 0), v2);

}
