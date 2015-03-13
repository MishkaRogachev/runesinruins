#ifndef AREA_PROXY_VOLUME_REPOSITORY_H
#define AREA_PROXY_VOLUME_REPOSITORY_H

#include "proxy_volume_repository.h"

namespace core
{
    class AreaProxyVolumeRepository: public ProxyVolumeRepository
    {
    public:
        AreaProxyVolumeRepository(const VolumeRepositoryPtr& sourceRepository =
                VolumeRepositoryPtr());
        virtual ~AreaProxyVolumeRepository() override;

    private:
        AreaPtr area;
    };
}

#endif // AREA_PROXY_VOLUME_REPOSITORY_H
