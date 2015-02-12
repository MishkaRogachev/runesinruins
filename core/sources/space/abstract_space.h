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

//        virtual VolumePtr volumeAt(const SpacePoint& point) = 0;
        virtual bool hasVolume(const SpacePoint& point) const= 0;

        bool hasVolume(int x, int y, int z) const;

    private:
        class AbstractSpacePrivate;
        AbstractSpacePrivate* d;
    };
}
#endif // ABSTRACTSPACE_H
