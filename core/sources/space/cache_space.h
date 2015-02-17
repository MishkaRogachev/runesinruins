#ifndef CACHE_SPACE_H
#define CACHE_SPACE_H

#include "abstract_space.h"

namespace core
{
    class CacheSpace : public AbstractSpace
    {
    public:
        CacheSpace(const SpacePtr& proxySpace);
        ~CacheSpace();

        virtual Point3iVec positions() const override;
        virtual VolumePtrVec volumes() const override;
        virtual VolumePtr volumeAt(const Point3i& position) override;
        virtual bool hasVolume(const Point3i& position) const override;

        using AbstractSpace::volumeAt;
        using AbstractSpace::hasVolume;

        bool load(const Point3i& position);
        void unload(const Point3i& position);
        bool isLoaded(const Point3i& position) const;

        bool load(int x, int y, int z);
        void unload(int x, int y, int z);
        bool isLoaded(int x, int y, int z) const;

    private:
        class CacheSpacePrivate;
        CacheSpacePrivate* d;

        CacheSpace(const Volume& other) = delete;
        const CacheSpace& operator = (const CacheSpace& other) = delete;
    };
}

#endif // CACHE_SPACE_H
