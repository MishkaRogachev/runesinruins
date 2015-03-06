#include "volume_repository.h"

using namespace core;

VolumeRepository::VolumeRepository():
    AbstractVolumeRepository()
{}

Point3iVec VolumeRepository::allPositions() const
{

}

VolumePtrVec VolumeRepository::allVolumes()
{

}

VolumePtr VolumeRepository::load(const Point3i& position)
{

}

void VolumeRepository::save(const VolumePtr& volume, const Point3i& position)
{

}

bool VolumeRepository::canLoad(const Point3i& position) const
{

}
