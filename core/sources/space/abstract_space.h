#ifndef ABSTRACTSPACE_H
#define ABSTRACTSPACE_H

#include "core_traits.h"

namespace core
{
    class AbstractSpace
    {
    public:
        AbstractSpace();
        virtual ~AbstractSpace();

        virtual Vec3iVec positions() const = 0;
        virtual VolumePtrVec volumes() const = 0;
        virtual VolumePtr volumeAt(const Vec3i& position) = 0;
        virtual bool hasVolume(const Vec3i& position) const= 0;

        virtual VolumePtr volumeAt(int x, int y, int z);
        virtual bool hasVolume(int x, int y, int z) const;
    };
}
#endif // ABSTRACTSPACE_H
