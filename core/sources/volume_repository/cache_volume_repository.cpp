#include "cache_volume_repository.h"

#include <unordered_map>

using namespace core;

class CacheVolumeRepository::CacheSpacePrivate
{
public:
    std::unordered_map<Point3i, VolumePtr> cache;
    VolumeRepositoryPtr proxySpace;

    CacheSpacePrivate(const VolumeRepositoryPtr& proxySpace):
        proxySpace(proxySpace)
    {}
};

CacheVolumeRepository::CacheVolumeRepository(const VolumeRepositoryPtr& proxySpace):
    AbstractVolumeRepository(),
    d(new CacheSpacePrivate(proxySpace))
{}

CacheVolumeRepository::~CacheVolumeRepository()
{
    delete d;
}

Point3iVec CacheVolumeRepository::allPositions() const
{
    Point3iVec vector;
    for (const auto& item: d->cache)
        vector.push_back(item.first);
    return vector;
}

VolumePtrVec CacheVolumeRepository::allVolumes() const
{
    VolumePtrVec vector;
    for (const auto& item: d->cache)
        vector.push_back(item.second);
    return vector;
}

bool CacheVolumeRepository::canLoad(const Point3i& position) const
{
    return this->isLoaded(position) || d->proxySpace->canLoad(position);
}

VolumePtr CacheVolumeRepository::load(const Point3i& position)
{
    if (this->isLoaded(position))
    {
        return d->cache[position];
    }
    else
    {
        return this->reload(position);
    }
}

void CacheVolumeRepository::save(const VolumePtr& volume, const Point3i& position)
{
    d->cache[position] = volume;
    d->proxySpace->save(volume, position);
}

VolumePtr CacheVolumeRepository::reload(const Point3i& position)
{
    if (!d->proxySpace->canLoad(position)) return VolumePtr();
    d->cache[position] = d->proxySpace->load(position);
    return d->cache[position];
}

void CacheVolumeRepository::unload(const Point3i& position)
{
    d->cache.erase(position);
}

bool CacheVolumeRepository::isLoaded(const Point3i& position) const
{
    return d->cache.count(position) > 0;
}

VolumePtr CacheVolumeRepository::reload(int x, int y, int z)
{
    return this->reload(Point3i(x, y, z));
}

void CacheVolumeRepository::unload(int x, int y, int z)
{
    this->unload(Point3i(x, y, z));
}

bool CacheVolumeRepository::isLoaded(int x, int y, int z) const
{
    return this->isLoaded(Point3i(x, y, z));
}
