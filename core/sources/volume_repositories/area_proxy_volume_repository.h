#ifndef AREA_PROXY_VOLUME_REPOSITORY_H
#define AREA_PROXY_VOLUME_REPOSITORY_H

#include "proxy_volume_repository.h"
#include "square_area.h"

namespace core
{
    class AreaProxyVolumeRepository: public ProxyVolumeRepository
    {
    public:
        AreaProxyVolumeRepository(const VolumeRepositoryPtr& sourceRepository =
                VolumeRepositoryPtr(),
                                  const AreaPtr& area = AreaPtr(new SquareArea),
                                  const VolumeGeneratorPtr& generator =
                VolumeGeneratorPtr());
        virtual ~AreaProxyVolumeRepository() override;

        using AbstractVolumeRepository::load;
        using AbstractVolumeRepository::create;
        using AbstractVolumeRepository::save;
        using AbstractVolumeRepository::remove;
        using AbstractVolumeRepository::canLoad;
        using AbstractVolumeRepository::canCreate;

        Point3i position() const;
        Point3i& position();
        void setPosition(const Point3i& position);
        void setPosition(int x, int y, int z);

        int size() const;
        void setSize(int size);

        void checkLoadedVolumes();

    private:
        AreaPtr m_area;
    };
}

#endif // AREA_PROXY_VOLUME_REPOSITORY_H
