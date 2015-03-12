#ifndef PROXYVOLUMEREPOSITORY_H
#define PROXYVOLUMEREPOSITORY_H

#include "cache_volume_repository.h"

namespace core
{
    class ProxyVolumeRepository: public CacheVolumeRepository
    {
    public:
        ProxyVolumeRepository(const VolumeRepositoryPtr& sourceRepository =
                VolumeRepositoryPtr());
        virtual ~ProxyVolumeRepository() override;

        virtual Point3iList allPositions() const override;
        virtual VolumePtrList allVolumes() override;
        virtual VolumePtr load(const Point3i& position) override;
        virtual void save(const VolumePtr& volume,
                          const Point3i& position) override;
        virtual void remove(const Point3i& position) override;
        virtual bool canLoad(const Point3i& position) const override;

        using AbstractVolumeRepository::load;
        using AbstractVolumeRepository::save;
        using AbstractVolumeRepository::remove;
        using AbstractVolumeRepository::canLoad;

        VolumePtr reload(const Point3i& position);
        void setSourceRepository(const VolumeRepositoryPtr& sourceRepository);

        VolumePtr reload(int x, int y, int z);

    private:
        VolumeRepositoryPtr m_sourceRepository;
    };
}
#endif // PROXYVOLUMEREPOSITORY_H
