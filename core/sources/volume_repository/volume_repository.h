#ifndef VOLUME_REPOSITORY_H
#define VOLUME_REPOSITORY_H

#include "abstract_volume_repository.h"

namespace core
{
    class VolumeRepository: public AbstractVolumeRepository
    {
    public:
        VolumeRepository();

        virtual Point3iVec allPositions() const override;
        virtual VolumePtrVec allVolumes() override;
        virtual VolumePtr load(const Point3i& position) override;
        virtual void save(const VolumePtr& volume, const Point3i& position) override;
        virtual bool canLoad(const Point3i& position) const override;

        using AbstractVolumeRepository::load;
        using AbstractVolumeRepository::save;
        using AbstractVolumeRepository::canLoad;
    };
}

#endif // VOLUME_REPOSITORY_H
