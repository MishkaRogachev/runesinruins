#ifndef AREA_PROXY_VOLUME_REPOSITORY_TEST_H
#define AREA_PROXY_VOLUME_REPOSITORY_TEST_H

#include "proxy_volume_repository_test.h"

class AreaProxyVolumeRepositoryTest : public ProxyVolumeRepositoryTest
{
    Q_OBJECT

protected:
    virtual core::VolumeRepositoryPtr volumeRepository() const override;

private slots:
    void checkLoadedVolumesTest();
};

#endif // AREA_PROXY_VOLUME_REPOSITORY_TEST_H
