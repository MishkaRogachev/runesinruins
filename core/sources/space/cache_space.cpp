#include "cache_space.h"

#include <unordered_map>

using namespace core;

class CacheSpace::CacheSpacePrivate
{
public:
    std::unordered_map<Point3i, VolumePtr> cache;
    AbstractSpace* proxySpace;

    CacheSpacePrivate(AbstractSpace* proxySpace):
        proxySpace(proxySpace)
    {}
};

CacheSpace::CacheSpace(AbstractSpace* proxySpace):
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
        if (d->proxySpace->hasVolume(position))
            this->load(position);
        else
            return VolumePtr();
    }
    return d->cache.at(position);
}

void CacheSpace::load(const Point3i& position)
{
    d->cache[position] = d->proxySpace->volumeAt(position);
}

void CacheSpace::unload(const Point3i& position)
{
    d->cache.erase(position);
}

bool CacheSpace::isLoaded(const Point3i& position) const
{
     return d->cache.count(position) > 0;
}

