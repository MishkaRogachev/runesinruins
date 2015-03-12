#ifndef PERSISTENT_VOLUME_REPOSITORY_H
#define PERSISTENT_VOLUME_REPOSITORY_H

#include "abstract_volume_repository.h"
#include "fs_persister.h"
#include "standart_volume_serializer.h"

namespace core
{
    class PersistentVolumeRepository: public AbstractVolumeRepository
    {
    public:
        PersistentVolumeRepository(const PersisterPtr& persister =
                PersisterPtr(new FsPersister("vol")),
                                   const VolumeSerializerPtr& serilalizer =
                VolumeSerializerPtr(new StandartVolumeSerializer()));
        virtual ~PersistentVolumeRepository() override;

        virtual Point3iList allPositions() const override;
        virtual VolumePtrList allVolumes() override;
        virtual VolumePtr load(const Point3i& position) override;
        virtual void save(const VolumePtr& volume,
                          const Point3i& position) override;
        virtual void remove(const Point3i& position) override;
        virtual bool canLoad(const Point3i& position) const override;

        using AbstractVolumeRepository::load;
        using AbstractVolumeRepository::save;
        using AbstractVolumeRepository::remove;
        using AbstractVolumeRepository::canLoad;

    protected:
        virtual QString positionToEntry(const Point3i& position) const;
        virtual Point3i entryToPosition(const QString& string) const;

    private:
        PersisterPtr m_persister;
        VolumeSerializerPtr m_serilalizer;
    };
}

#endif // PERSISTENT_VOLUME_REPOSITORY_H
