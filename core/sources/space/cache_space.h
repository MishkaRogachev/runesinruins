#ifndef CACHE_SPACE_H
#define CACHE_SPACE_H

#include "abstract_space.h"

namespace core
{
    class CacheSpace : public AbstractSpace
    {
    public:
        CacheSpace(AbstractSpace* proxySpace);
        ~CacheSpace();

        virtual Point3iVec positions() const override;
        virtual VolumePtrVec volumes() const override;
        virtual VolumePtr volumeAt(const Point3i& position) override;
        virtual bool hasVolume(const Point3i& position) const override;

        using AbstractSpace::volumeAt;
        using AbstractSpace::hasVolume;

        void load(const Point3i& position);
        void unload(const Point3i& position);
        bool isLoaded(const Point3i& position) const;

    private:
        class CacheSpacePrivate;
        CacheSpacePrivate* d;
    };
}

#endif // CACHE_SPACE_H
