#include "area_proxy_volume_repository.h"

using namespace core;

AreaProxyVolumeRepository::AreaProxyVolumeRepository(
        const VolumeRepositoryPtr& sourceRepository):
    ProxyVolumeRepository(sourceRepository)
{}

AreaProxyVolumeRepository::~AreaProxyVolumeRepository()
{}

