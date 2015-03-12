#include "abstract_volume_repository.h"

using namespace core;

AbstractVolumeRepository::AbstractVolumeRepository()
{}

AbstractVolumeRepository::~AbstractVolumeRepository()
{}

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
