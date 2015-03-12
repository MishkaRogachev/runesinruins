#ifndef PROXY_VOLUMERE_POSITORY_TEST_H
#define PROXY_VOLUMERE_POSITORY_TEST_H

#include "cache_volume_repository_test.h"

class ProxyVolumeRepositoryTest: public CacheVolumeRepositoryTest
{
    Q_OBJECT

protected:
    virtual core::VolumeRepositoryPtr volumeRepository() const override;

private slots:
    void canLoadisLoadedTest();
    void proxySaveTest();
    void reloadTest();
};

#endif // PROXY_VOLUMERE_POSITORY_TEST_H
