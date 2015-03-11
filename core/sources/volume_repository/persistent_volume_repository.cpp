#include "persistent_volume_repository.h"

#include "../persisters/abstract_persister.h"

namespace
{
    const char separator = '_';
}

using namespace core;

PersistentVolumeRepository::PersistentVolumeRepository(const PersisterPtr& persister):
    AbstractVolumeRepository(),
    m_persister(persister)
{}

Point3iList PersistentVolumeRepository::allPositions() const
{
    Point3iList vector;

    if (m_persister)
    {
        for (const QString& entry: m_persister->avalibleEntries())
            vector.append(this->entryToPosition(entry));
    }
    return vector;
}

VolumePtrList PersistentVolumeRepository::allVolumes()
{
    VolumePtrList vector;

    if (m_persister)
    {
        for (const QString& entry: m_persister->avalibleEntries())
        {
            QByteArray data = m_persister->load(entry);
            VolumePtr volume; // = VolumeSerializer::deserialise(data) TODO: deserialize
            vector.append(volume);
        }
    }
    return vector;
}

VolumePtr PersistentVolumeRepository::load(const Point3i& position)
{
    QByteArray data = m_persister->load(this->positionToEntry(position));
    return VolumePtr(/*VolumeSerializer::deserialise(data)*/); // TODO: deserialize
}

void PersistentVolumeRepository::save(const VolumePtr& volume, const Point3i& position)
{
    QByteArray data; // = VolumeSerializer::serialise(volume); TODO: serialize
    m_persister->save(this->positionToEntry(position), data);
}

void PersistentVolumeRepository::remove(const Point3i& position)
{
    m_persister->remove(this->positionToEntry(position));
}

bool PersistentVolumeRepository::canLoad(const Point3i& position) const
{
    return m_persister && m_persister->hasEntry(this->positionToEntry(position));
}

QString PersistentVolumeRepository::positionToEntry(const Point3i& position) const
{
    QStringList list;

    for (int i: position.array())
    {
        list.append(QString::number(i));
    }
    return list.join(::separator);
}

Point3i PersistentVolumeRepository::entryToPosition(const QString& string) const
{
    Point3i result;

    QStringList list = string.split(::separator);
    for (int i = 0; i < list.count(); ++i)
    {
        result[i] = list.at(i).toInt();
    }
    return result;
}
