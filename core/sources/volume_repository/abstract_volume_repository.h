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

        virtual Point3iList allPositions() const = 0;
        virtual VolumePtrList allVolumes() = 0;
        virtual VolumePtr load(const Point3i& position) = 0;
        virtual void save(const VolumePtr& volume, const Point3i& position) = 0;
        virtual void remove(const Point3i& position) = 0;
        virtual bool canLoad(const Point3i& position) const = 0;

        VolumePtr load(int x, int y, int z);
        void save(const VolumePtr& volume, int x, int y, int z);
        void remove(int x, int y, int z);
        bool canLoad(int x, int y, int z) const;
    };
}
#endif // ABSTRACT_VOLUME_REPOSITORY_H
