#include "proxy_volume_repository_test.h"

#include "proxy_volume_repository.h"

using namespace core;


VolumeRepositoryPtr ProxyVolumeRepositoryTest::volumeRepository() const
{
    return VolumeRepositoryPtr(new ProxyVolumeRepository());
}
