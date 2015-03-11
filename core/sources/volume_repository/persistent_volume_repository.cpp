#include "persistent_volume_repository.h"

#include "../persisters/abstract_persister.h"

using namespace core;

PersistentVolumeRepository::PersistentVolumeRepository(const PersisterPtr& persister):
    AbstractVolumeRepository(),
    m_persister(persister)
{}

Point3iList PersistentVolumeRepository::allPositions() const
{
    Point3iList vector;

//    if (m_persister)
//    {
//        for (const std::string& entry: m_persister->avalibleEntries())
//            vector.push_back(this->entryToPosition(entry));
//    }
    return vector;
}

VolumePtrList PersistentVolumeRepository::allVolumes()
{
    VolumePtrList vector;

//    if (m_persister)
//    {
//        for (const std::string& entry: m_persister->avalibleEntries())
//            vector.push_back(this->load(this->entryToPosition(entry)));
//    }
    return vector;
}

VolumePtr PersistentVolumeRepository::load(const Point3i& position)
{

    // TODO: deserialize
    return VolumePtr();
}

void PersistentVolumeRepository::save(const VolumePtr& volume, const Point3i& position)
{
    // TODO: serialize
}

void PersistentVolumeRepository::remove(const Point3i& position)
{
    // TODO: remove
}

bool PersistentVolumeRepository::canLoad(const Point3i& position) const
{
    //return m_persister && m_persister->hasEntry(this->positionToEntry(position));
}

QString PersistentVolumeRepository::positionToEntry(const Point3i& position) const
{
    // TODO:
}

Point3i PersistentVolumeRepository::entryToPosition(const QString& string) const
{
    return Point3i();
    // TODO:
}
