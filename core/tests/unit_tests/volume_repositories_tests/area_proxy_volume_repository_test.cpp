#include "area_proxy_volume_repository_test.h"

#include "area_proxy_volume_repository.h"

using namespace core;


VolumeRepositoryPtr AreaProxyVolumeRepositoryTest::volumeRepository() const
{
    return VolumeRepositoryPtr(new AreaProxyVolumeRepository());
}
