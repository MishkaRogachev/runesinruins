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

        virtual VolumePtr volumeAt(const SpacePoint& point) override;
        virtual bool hasVolume(const SpacePoint& point) const override;

        using AbstractSpace::hasVolume;

    private:
        class CachedSpacePrivate;
        CachedSpacePrivate* d;
    };
}

#endif // CACHEDSPACE_H
