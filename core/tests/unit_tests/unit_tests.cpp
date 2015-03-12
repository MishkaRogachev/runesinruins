#include <QtTest/QtTest>

#include "common_tests/direction_test.h"
#include "common_tests/point_test.h"
#include "node_tests/node_test.h"
#include "volume_tests/volume_test.h"
#include "volume_serializers_tests/standart_volume_serializer_test.h"
#include "volume_repositories_tests/cache_volume_repository_test.h"
#include "volume_repositories_tests/proxy_volume_repository_test.h"
#include "persisters_tests/fs_persister_test.h"

int main()
{
    FsPersisterTest fsPersisterTest;
    QTest::qExec(&fsPersisterTest);

    DirectionTest directionTest;
    QTest::qExec(&directionTest);

    PointTest pointTest;
    QTest::qExec(&pointTest);

    NodeTest nodeTest;
    QTest::qExec(&nodeTest);

    VolumeTest volumeTest;
    QTest::qExec(&volumeTest);

    StandartVolumeSerializerTest standartVolumeSerializerTest;
    QTest::qExec(&standartVolumeSerializerTest);

    CacheVolumeRepositoryTest cachedVolumeRepositoryTest;
    QTest::qExec(&cachedVolumeRepositoryTest);

    ProxyVolumeRepositoryTest proxyVolumeRepositoryTest;
    QTest::qExec(&proxyVolumeRepositoryTest);



    return 0;
}

 
