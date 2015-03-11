#include "persistent_volume_repository.h"

#include "../persisters/abstract_persister.h"

using namespace core;

PersistentVolumeRepository::PersistentVolumeRepository(const PersisterPtr& persister):
    AbstractVolumeRepository(),
    m_persister(persister)
{}

Point3iVec PersistentVolumeRepository::allPositions() const
{
    Point3iVec vector;

    if (m_persister)
    {
        for (const std::string& entry: m_persister->avalibleEntries())
            vector.push_back(this->entryToPosition(entry));
    }
    return vector;
}

VolumePtrVec PersistentVolumeRepository::allVolumes()
{
    VolumePtrVec vector;

    if (m_persister)
    {
        for (const std::string& entry: m_persister->avalibleEntries())
            vector.push_back(this->load(this->entryToPosition(entry)));
    }
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
     return m_persister && m_persister->hasEntry(this->positionToEntry(position));
}

std::string PersistentVolumeRepository::positionToEntry(const Point3i& position) const
{
    return std::to_string(position.x()) +
           std::to_string(position.y()) +
           std::to_string(position.z());
}

Point3i PersistentVolumeRepository::entryToPosition(const std::string& string) const
{
    return Point3i();
    // TODO:
}
