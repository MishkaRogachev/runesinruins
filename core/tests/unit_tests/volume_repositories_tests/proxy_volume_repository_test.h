#ifndef PROXYVOLUMEREPOSITORYTEST_H
#define PROXYVOLUMEREPOSITORYTEST_H

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

#endif // PROXYVOLUMEREPOSITORYTEST_H
