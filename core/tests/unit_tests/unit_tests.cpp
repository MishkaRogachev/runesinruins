#include <QtTest/QtTest>

#include "persisters_tests/fs_persister_test.h"
#include "common_tests/direction_test.h"
#include "common_tests/point_test.h"
#include "areas_tests/square_area_test.h"
#include "node_tests/node_test.h"
#include "volume_tests/volume_test.h"
#include "volume_serializers_tests/standart_volume_serializer_test.h"
#include "volume_repositories_tests/persistent_volume_repository_test.h"
#include "volume_repositories_tests/cache_volume_repository_test.h"
#include "volume_repositories_tests/proxy_volume_repository_test.h"
#include "volume_repositories_tests/area_proxy_volume_repository_test.h"

int main()
{
    FsPersisterTest fsPersisterTest;
    QTest::qExec(&fsPersisterTest);

    DirectionTest directionTest;
    QTest::qExec(&directionTest);

    PointTest pointTest;
    QTest::qExec(&pointTest);

    SquareAreaTest squareAreaTest;
    QTest::qExec(&squareAreaTest);

    NodeTest nodeTest;
    QTest::qExec(&nodeTest);

    VolumeTest volumeTest;
    QTest::qExec(&volumeTest);

    StandartVolumeSerializerTest standartVolumeSerializerTest;
    QTest::qExec(&standartVolumeSerializerTest);

    PersistentVolumeRepositoryTest persistentVolumeRepositoryTest;
    QTest::qExec(&persistentVolumeRepositoryTest);

    CacheVolumeRepositoryTest cachedVolumeRepositoryTest;
    QTest::qExec(&cachedVolumeRepositoryTest);

    ProxyVolumeRepositoryTest proxyVolumeRepositoryTest;
    QTest::qExec(&proxyVolumeRepositoryTest);

    AreaProxyVolumeRepositoryTest areaProxyVolumeRepositoryTest;
    QTest::qExec(&areaProxyVolumeRepositoryTest);

    return 0;
}

 
