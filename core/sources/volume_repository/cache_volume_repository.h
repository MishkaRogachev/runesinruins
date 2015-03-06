#ifndef CACHE_VOLUME_REPOSITORY_H
#define CACHE_VOLUME_REPOSITORY_H

#include "abstract_volume_repository.h"

namespace core
{
    class CacheVolumeRepository: public AbstractVolumeRepository
    {
    public:
        CacheVolumeRepository(const VolumeRepositoryPtr& proxySpace);
        ~CacheVolumeRepository();

        virtual Point3iVec allPositions() const override;
        virtual VolumePtrVec allVolumes() const override;
        virtual VolumePtr load(const Point3i& position) override;
        virtual void save(const VolumePtr& volume, const Point3i& position) override;
        virtual bool canLoad(const Point3i& position) const override;

        using AbstractVolumeRepository::load;
        using AbstractVolumeRepository::save;
        using AbstractVolumeRepository::canLoad;

        VolumePtr reload(const Point3i& position);
        void unload(const Point3i& position);
        bool isLoaded(const Point3i& position) const;

        VolumePtr reload(int x, int y, int z);
        void unload(int x, int y, int z);
        bool isLoaded(int x, int y, int z) const;

    private:
        class CacheSpacePrivate;
        CacheSpacePrivate* d;

        CacheVolumeRepository(const Volume& other) = delete;
        const CacheVolumeRepository& operator = (const CacheVolumeRepository& other) = delete;
    };
}

#endif // CACHE_VOLUME_REPOSITORY_H
