#include "cache_volume_repository.h"

#include "volume.h"

using namespace core;

CacheVolumeRepository::CacheVolumeRepository():
    AbstractVolumeRepository()
{}

CacheVolumeRepository::~CacheVolumeRepository()
{}

Point3iVec CacheVolumeRepository::allPositions() const
{
    return this->loadedPositions();
}

VolumePtrVec CacheVolumeRepository::allVolumes()
{
    return this->loadedVolumes();
}

bool CacheVolumeRepository::canLoad(const Point3i& position) const
{
    return this->isLoaded(position);
}

Point3iVec CacheVolumeRepository::loadedPositions() const
{
    Point3iVec vector;
    for (const auto& item: m_cache)
        vector.push_back(item.first);
    return vector;
}

VolumePtrVec CacheVolumeRepository::loadedVolumes() const
{
    VolumePtrVec vector;
    for (const auto& item: m_cache)
        vector.push_back(item.second);
    return vector;
}

VolumePtr CacheVolumeRepository::load(const Point3i& position)
{
    VolumePtr current;
    if (m_cache.count(position) > 0) current = m_cache[position];

    if (current) this->chain(current, position);
    return current;
}

void CacheVolumeRepository::save(const VolumePtr& volume,
                                 const Point3i& position)
{
    m_cache[position] = volume;
    this->chain(volume, position);
}

void CacheVolumeRepository::unload(const Point3i& position)
{
    VolumePtr current;
    if (m_cache.count(position) > 0) current = m_cache[position];

    if (!current) return;

    this->breakChain(current);

    m_cache.erase(position);
}

bool CacheVolumeRepository::isLoaded(const Point3i& position) const
{
    return m_cache.count(position) > 0;
}

void CacheVolumeRepository::unload(int x, int y, int z)
{
    this->unload(Point3i(x, y, z));
}

bool CacheVolumeRepository::isLoaded(int x, int y, int z) const
{
    return this->isLoaded(Point3i(x, y, z));
}

void CacheVolumeRepository::chain(const VolumePtr& volume, const Point3i& position)
{
    for (Direction direction: Direction::allDirections())
    {
        Point3i neigbour = position.neighbour(direction);

        if (!volume->hasChain(direction) && this->isLoaded(neigbour))
        {
            volume->chainTo(m_cache[neigbour].get(), direction);
        }
    }
}

void CacheVolumeRepository::breakChain(const VolumePtr& volume)
{
    for (Direction direction: Direction::allDirections())
    {
        if (volume->hasChain(direction))
        {
            volume->breakChain(direction);
        }
    }
}
