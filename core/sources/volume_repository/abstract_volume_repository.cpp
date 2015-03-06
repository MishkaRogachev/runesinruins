#include "abstract_volume_repository.h"

#include "volume.h"

using namespace core;

AbstractVolumeRepository::AbstractVolumeRepository()
{}

AbstractVolumeRepository::~AbstractVolumeRepository()
{}

VolumePtr AbstractVolumeRepository::load(int x, int y, int z)
{
    return this->load(Point3i(x, y, z));
}

void AbstractVolumeRepository::save(const VolumePtr& volume,
                                    int x, int y, int z)
{
    this->save(volume, Point3i(x, y, z));
}

bool AbstractVolumeRepository::canLoad(int x, int y, int z) const
{
    return this->canLoad(Point3i(x, y, z));
}

void AbstractVolumeRepository::chainVolume(const Point3i& position)
{
    VolumePtr current = this->load(position);

    for (Direction direction: Direction::allDirections())
    {
        Point3i neigbour = position.neighbour(direction);

        if (!current->hasChain(direction) && this->canLoad(neigbour))
        {
            current->chainTo(this->load(neigbour).get(), direction);
        }
    }
}

void AbstractVolumeRepository::breakVolumeChain(const Point3i& position)
{
    VolumePtr current = this->load(position);

    for (Direction direction: Direction::allDirections())
    {
        if (current->hasChain(direction))
        {
            current->breakChain(direction);
        }
    }
}
