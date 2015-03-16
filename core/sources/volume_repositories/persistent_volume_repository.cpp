#include "persistent_volume_repository.h"

#include "../persisters/abstract_persister.h"

namespace
{
    const char separator = '_';
}

using namespace core;

PersistentVolumeRepository::PersistentVolumeRepository(
        const PersisterPtr& persister,
        const VolumeSerializerPtr& serilalizer,
        const VolumeGeneratorPtr& generator):
    AbstractVolumeRepository(generator),
    m_persister(persister),
    m_serilalizer(serilalizer)
{
    Q_ASSERT(persister);
    Q_ASSERT(serilalizer);
}

PersistentVolumeRepository::~PersistentVolumeRepository()
{}

Point3iList PersistentVolumeRepository::allPositions() const
{
    Point3iList vector;

    for (const QString& entry: m_persister->avalibleEntries())
        vector.append(this->entryToPosition(entry));

    return vector;
}

VolumePtrList PersistentVolumeRepository::allVolumes()
{
    VolumePtrList vector;

    for (const QString& entry: m_persister->avalibleEntries())
    {
        VolumePtr volume = m_serilalizer->unserialize(
                               m_persister->load(entry));
        if (volume) vector.append(volume);
    }
    return vector;
}

VolumePtr PersistentVolumeRepository::load(const Point3i& position)
{
    return m_serilalizer->unserialize(
                m_persister->load(this->positionToEntry(position)));
}

VolumePtr PersistentVolumeRepository::create(const Point3i& position)
{
    VolumePtr volume = AbstractVolumeRepository::create(position);

    if (volume) this->save(volume, position);
    return volume;
}

void PersistentVolumeRepository::save(const VolumePtr& volume,
                                      const Point3i& position)
{
    m_persister->save(this->positionToEntry(position),
                      m_serilalizer->serialize(volume));
}

void PersistentVolumeRepository::remove(const Point3i& position)
{
    m_persister->remove(this->positionToEntry(position));
}

bool PersistentVolumeRepository::canLoad(const Point3i& position) const
{
    return m_persister &&
            m_persister->hasEntry(this->positionToEntry(position));
}

QString PersistentVolumeRepository::positionToEntry(
        const Point3i& position) const
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
