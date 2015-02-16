#include "abstract_space.h"

using namespace core;

AbstractSpace::AbstractSpace()
{}

AbstractSpace::~AbstractSpace()
{}

VolumePtr AbstractSpace::volumeAt(int x, int y, int z)
{
     return this->volumeAt(Vec3i(x, y, z));
}

bool AbstractSpace::hasVolume(int x, int y, int z) const
{
    return this->hasVolume(Vec3i(x, y, z));
}
