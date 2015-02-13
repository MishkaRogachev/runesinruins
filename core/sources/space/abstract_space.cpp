#include "abstract_space.h"

using namespace core;

class AbstractSpace::AbstractSpacePrivate
{
public:

};

AbstractSpace::AbstractSpace():
    d(new AbstractSpacePrivate())
{}

AbstractSpace::~AbstractSpace()
{
    delete d;
}

bool AbstractSpace::hasVolume(int x, int y, int z) const
{
    return this->hasVolume(SpacePoint(x, y, z));
}
