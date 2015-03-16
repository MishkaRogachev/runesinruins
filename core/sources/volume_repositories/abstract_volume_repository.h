#ifndef ABSTRACT_VOLUME_REPOSITORY_H
#define ABSTRACT_VOLUME_REPOSITORY_H

#include "core_traits.h"

namespace core
{
    class AbstractVolumeRepository
    {
    public:
        AbstractVolumeRepository(const VolumeGeneratorPtr& generator);
        virtual ~AbstractVolumeRepository();

        virtual Point3iList allPositions() const = 0;
        virtual VolumePtrList allVolumes() = 0;
        virtual VolumePtr load(const Point3i& position) = 0;
        virtual VolumePtr create(const Point3i& position);
        virtual void save(const VolumePtr& volume, const Point3i& position) = 0;
        virtual void remove(const Point3i& position) = 0;
        virtual bool canLoad(const Point3i& position) const = 0;
        virtual bool canCreate(const Point3i& position) const;

        bool isEmpty() const;
        void clear();

        VolumePtr load(int x, int y, int z);
        VolumePtr create(int x, int y, int z);
        void save(const VolumePtr& volume, int x, int y, int z);
        void remove(int x, int y, int z);
        bool canLoad(int x, int y, int z) const;
        bool canCreate(int x, int y, int z) const;

    private:
        VolumeGeneratorPtr m_generator;
    };
}
#endif // ABSTRACT_VOLUME_REPOSITORY_H
