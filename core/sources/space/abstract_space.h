#ifndef ABSTRACT_SPACE_H
#define ABSTRACT_SPACE_H

#include "core_traits.h"

namespace core
{
    class AbstractSpace
    {
    public:
        AbstractSpace();
        virtual ~AbstractSpace();

        virtual Point3iVec positions() const = 0;
        virtual VolumePtrVec volumes() const = 0;
        virtual VolumePtr volumeAt(const Point3i& position) = 0;
        virtual bool hasVolume(const Point3i& position) const= 0;

        virtual VolumePtr volumeAt(int x, int y, int z);
        virtual bool hasVolume(int x, int y, int z) const;
    };
}
#endif // ABSTRACT_SPACE_H
