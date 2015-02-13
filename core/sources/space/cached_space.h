#ifndef CACHEDSPACE_H
#define CACHEDSPACE_H

#include "abstract_space.h"

namespace core
{
    class CachedSpace : public AbstractSpace
    {
    public:
        CachedSpace();
        ~CachedSpace();

        virtual VolumePtr volumeAt(const Vec3i& point) override;
        virtual bool hasVolume(const Vec3i& point) const override;

        using AbstractSpace::hasVolume;

    private:
        class CachedSpacePrivate;
        CachedSpacePrivate* d;
    };
}

#endif // CACHEDSPACE_H
