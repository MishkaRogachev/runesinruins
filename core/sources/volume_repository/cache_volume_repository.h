#ifndef CACHE_VOLUME_REPOSITORY_H
#define CACHE_VOLUME_REPOSITORY_H

#include "abstract_volume_repository.h"

#include <unordered_map>

namespace core
{
    class CacheVolumeRepository: public AbstractVolumeRepository
    {
    public:
        CacheVolumeRepository();
        ~CacheVolumeRepository();

        virtual Point3iVec allPositions() const override;
        virtual VolumePtrVec allVolumes() override;
        virtual VolumePtr load(const Point3i& position) override;
        virtual void save(const VolumePtr& volume,
                          const Point3i& position) override;
        virtual bool canLoad(const Point3i& position) const override;

        using AbstractVolumeRepository::load;
        using AbstractVolumeRepository::save;
        using AbstractVolumeRepository::canLoad;

        Point3iVec loadedPositions() const;
        VolumePtrVec loadedVolumes() const;
        void unload(const Point3i& position);
        bool isLoaded(const Point3i& position) const;

        void unload(int x, int y, int z);
        bool isLoaded(int x, int y, int z) const;

    private:
        std::unordered_map<Point3i, VolumePtr> m_cache;
    };
}

#endif // CACHE_VOLUME_REPOSITORY_H
