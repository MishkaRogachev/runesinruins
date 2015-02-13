#include "cached_space.h"

#include <unordered_map>

using namespace core;

class CachedSpace::CachedSpacePrivate
{
public:
    std::unordered_map<Vec3i, VolumePtr> cache;
};

CachedSpace::CachedSpace():
    AbstractSpace(),
    d(new CachedSpacePrivate())
{}

CachedSpace::~CachedSpace()
{
    delete d;
}

bool CachedSpace::hasVolume(const Vec3i& point) const
{
    return d->cache.count(point) > 0;
}

VolumePtr CachedSpace::volumeAt(const Vec3i& point)
{
     return d->cache.at(point);
}

