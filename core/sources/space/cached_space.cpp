#include "cached_space.h"

#include <unordered_map>

using namespace core;

class CachedSpace::CachedSpacePrivate
{
public:
    std::unordered_map<Vec3i, VolumePtr> cache;
    AbstractSpace* proxySpace;

    CachedSpacePrivate(AbstractSpace* proxySpace):
        proxySpace(proxySpace)
    {}
};

CachedSpace::CachedSpace(AbstractSpace* proxySpace):
    AbstractSpace(),
    d(new CachedSpacePrivate(proxySpace))
{}

CachedSpace::~CachedSpace()
{
    delete d;
}

Vec3iVec CachedSpace::positions() const
{
    Vec3iVec vector;
    for (const auto& item: d->cache)
        vector.push_back(item.first);
    return vector;
}

VolumePtrVec CachedSpace::volumes() const
{
    VolumePtrVec vector;
    for (const auto& item: d->cache)
        vector.push_back(item.second);
    return vector;
}

bool CachedSpace::hasVolume(const Vec3i& position) const
{
    return d->cache.count(position) > 0;
}

VolumePtr CachedSpace::volumeAt(const Vec3i& position)
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

void CachedSpace::load(const Vec3i& position)
{
    d->cache[position] = d->proxySpace->volumeAt(position);
}

void CachedSpace::unload(const Vec3i& position)
{
    d->cache.erase(position);
}

