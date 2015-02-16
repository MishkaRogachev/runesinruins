#ifndef CACHEDSPACE_H
#define CACHEDSPACE_H

#include "abstract_space.h"

namespace core
{
    class CachedSpace : public AbstractSpace
    {
    public:
        CachedSpace(AbstractSpace* proxySpace);
        ~CachedSpace();

        virtual Vec3iVec positions() const override;
        virtual VolumePtrVec volumes() const override;
        virtual VolumePtr volumeAt(const Vec3i& position) override;
        virtual bool hasVolume(const Vec3i& position) const override;

        using AbstractSpace::volumeAt;
        using AbstractSpace::hasVolume;

        void load(const Vec3i& position);
        void unload(const Vec3i& position);

    private:
        class CachedSpacePrivate;
        CachedSpacePrivate* d;
    };
}

#endif // CACHEDSPACE_H
