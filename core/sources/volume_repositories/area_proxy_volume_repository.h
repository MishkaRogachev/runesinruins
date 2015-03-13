#ifndef AREAPROXYVOLUMEREPOSITORY_H
#define AREAPROXYVOLUMEREPOSITORY_H

#include "proxy_volume_repository.h"

namespace core
{
    class AreaProxyVolumeRepository: public ProxyVolumeRepository
    {
    public:
        AreaProxyVolumeRepository(const VolumeRepositoryPtr& sourceRepository =
                VolumeRepositoryPtr());
        virtual ~AreaProxyVolumeRepository() override;
    };
}

#endif // AREAPROXYVOLUMEREPOSITORY_H
