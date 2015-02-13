#include "abstract_space.h"

using namespace core;

AbstractSpace::AbstractSpace()
{}

AbstractSpace::~AbstractSpace()
{
}

bool AbstractSpace::hasVolume(int x, int y, int z) const
{
    return this->hasVolume(Vec3i(x, y, z));
}
