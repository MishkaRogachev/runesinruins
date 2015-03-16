#include "abstract_volume_repository.h"

#include "abstract_volume_generator.h"

using namespace core;

AbstractVolumeRepository::AbstractVolumeRepository(
        const VolumeGeneratorPtr& generator):
    m_generator(generator)
{}

AbstractVolumeRepository::~AbstractVolumeRepository()
{}

VolumePtr AbstractVolumeRepository::create(const Point3i& position)
{
    return !m_generator.isNull() ? m_generator->create(position) : VolumePtr();
}

bool AbstractVolumeRepository::canCreate(const Point3i& position) const
{
    return !m_generator.isNull() && m_generator->canCreate(position);
}

bool AbstractVolumeRepository::isEmpty() const
{
    return this->allPositions().isEmpty();
}

void AbstractVolumeRepository::clear()
{
    for (const Point3i& position: this->allPositions())
    {
        this->remove(position);
    }
}

VolumePtr AbstractVolumeRepository::load(int x, int y, int z)
{
    return this->load(Point3i(x, y, z));
}

VolumePtr AbstractVolumeRepository::create(int x, int y, int z)
{
    return this->create(Point3i(x, y, z));
}

void AbstractVolumeRepository::save(const VolumePtr& volume,
                                    int x, int y, int z)
{
    this->save(volume, Point3i(x, y, z));
}

void AbstractVolumeRepository::remove(int x, int y, int z)
{
    this->remove(Point3i(x, y, z));
}

bool AbstractVolumeRepository::canLoad(int x, int y, int z) const
{
    return this->canLoad(Point3i(x, y, z));
}

bool AbstractVolumeRepository::canCreate(int x, int y, int z) const
{
    return this->canCreate(Point3i(x, y, z));
}
