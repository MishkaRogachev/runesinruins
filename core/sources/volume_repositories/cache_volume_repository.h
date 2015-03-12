#ifndef CACHE_VOLUME_REPOSITORY_H
#define CACHE_VOLUME_REPOSITORY_H

#include "abstract_volume_repository.h"

namespace core
{
    class CacheVolumeRepository: public AbstractVolumeRepository
    {
    public:
        CacheVolumeRepository();
        virtual ~CacheVolumeRepository() override;

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

        Point3iList loadedPositions() const;
        VolumePtrList loadedVolumes() const;
        void unload(const Point3i& position);
        void unloadAll();
        bool isLoaded(const Point3i& position) const;

        void unload(int x, int y, int z);
        bool isLoaded(int x, int y, int z) const;

    protected:
        void chain(const VolumePtr& volume, const Point3i& position);
        void breakChain(const VolumePtr& volume);

    private:
        QHash<Point3i, VolumePtr> m_cache;
    };
}

#endif // CACHE_VOLUME_REPOSITORY_H
