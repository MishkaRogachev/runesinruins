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

        virtual VolumePtr volumeAt(const Vec3i& point) = 0;
        virtual bool hasVolume(const Vec3i& point) const= 0;

        virtual bool hasVolume(int x, int y, int z) const;
    };
}
#endif // ABSTRACTSPACE_H
