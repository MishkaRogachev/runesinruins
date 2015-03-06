#ifndef ABSTRACT_VOLUME_REPOSITORY_H
#define ABSTRACT_VOLUME_REPOSITORY_H

#include "core_traits.h"
#include "point.h"

namespace core
{
    class AbstractVolumeRepository
    {
    public:
        AbstractVolumeRepository();
        virtual ~AbstractVolumeRepository();

        virtual Point3iVec allPositions() const = 0;
        virtual VolumePtrVec allVolumes() const = 0;
        virtual VolumePtr load(const Point3i& position) = 0;
        virtual void save(const VolumePtr& volume, const Point3i& position) = 0;
        virtual bool canLoad(const Point3i& position) const = 0;

        VolumePtr load(int x, int y, int z);
        void save(const VolumePtr& volume, int x, int y, int z);
        bool canLoad(int x, int y, int z) const;

    protected:
        void chainVolume(const Point3i& position);
        void breakVolumeChain(const Point3i& position);
    };
}
#endif // ABSTRACT_VOLUME_REPOSITORY_H
