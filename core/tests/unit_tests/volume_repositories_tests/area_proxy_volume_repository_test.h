#ifndef AREAPROXYVOLUMEREPOSITORYTEST_H
#define AREAPROXYVOLUMEREPOSITORYTEST_H

#include "proxy_volume_repository_test.h"

class AreaProxyVolumeRepositoryTest : public ProxyVolumeRepositoryTest
{
    Q_OBJECT

protected:
    virtual core::VolumeRepositoryPtr volumeRepository() const override;
};

#endif // AREAPROXYVOLUMEREPOSITORYTEST_H
