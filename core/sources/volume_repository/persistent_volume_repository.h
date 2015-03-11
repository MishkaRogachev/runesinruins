#ifndef PERSISTENT_VOLUME_REPOSITORY_H
#define PERSISTENT_VOLUME_REPOSITORY_H

#include "abstract_volume_repository.h"

namespace core
{
    class PersistentVolumeRepository: public AbstractVolumeRepository
    {
    public:
        PersistentVolumeRepository(const PersisterPtr& persister);

        virtual Point3iVec allPositions() const override;
        virtual VolumePtrVec allVolumes() override;
        virtual VolumePtr load(const Point3i& position) override;
        virtual void save(const VolumePtr& volume, const Point3i& position) override;
        virtual void remove(const Point3i& position) override;
        virtual bool canLoad(const Point3i& position) const override;

        using AbstractVolumeRepository::load;
        using AbstractVolumeRepository::save;
        using AbstractVolumeRepository::remove;
        using AbstractVolumeRepository::canLoad;

    protected:
        virtual std::string positionToEntry(const Point3i& position) const;
        virtual Point3i entryToPosition(const std::string& string) const;

    private:
        PersisterPtr m_persister;
    };
}

#endif // PERSISTENT_VOLUME_REPOSITORY_H
