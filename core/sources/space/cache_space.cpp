#include "cache_space.h"

#include <unordered_map>

using namespace core;

class CacheSpace::CacheSpacePrivate
{
public:
    std::unordered_map<Point3i, VolumePtr> cache;
    SpacePtr proxySpace;

    CacheSpacePrivate(const SpacePtr& proxySpace):
        proxySpace(proxySpace)
    {}
};

CacheSpace::CacheSpace(const SpacePtr& proxySpace):
    AbstractSpace(),
    d(new CacheSpacePrivate(proxySpace))
{}

CacheSpace::~CacheSpace()
{
    delete d;
}

Point3iVec CacheSpace::positions() const
{
    Point3iVec vector;
    for (const auto& item: d->cache)
        vector.push_back(item.first);
    return vector;
}

VolumePtrVec CacheSpace::volumes() const
{
    VolumePtrVec vector;
    for (const auto& item: d->cache)
        vector.push_back(item.second);
    return vector;
}

bool CacheSpace::hasVolume(const Point3i& position) const
{
    return this->isLoaded(position);
}

VolumePtr CacheSpace::volumeAt(const Point3i& position)
{
    if (!this->hasVolume(position))
    {
        if (!this->load(position))
            return VolumePtr();
    }
    return d->cache.at(position);
}

bool CacheSpace::load(const Point3i& position)
{
    if (!d->proxySpace->hasVolume(position)) return false;
    return (d->cache[position] = d->proxySpace->volumeAt(position)) != nullptr;
}

void CacheSpace::unload(const Point3i& position)
{
    d->cache.erase(position);
}

bool CacheSpace::isLoaded(const Point3i& position) const
{
    return d->cache.count(position) > 0;
}

bool CacheSpace::load(int x, int y, int z)
{
    return this->load(Point3i(x, y, z));
}

void CacheSpace::unload(int x, int y, int z)
{
    this->unload(Point3i(x, y, z));
}

bool CacheSpace::isLoaded(int x, int y, int z) const
{
    return this->isLoaded(Point3i(x, y, z));
}
