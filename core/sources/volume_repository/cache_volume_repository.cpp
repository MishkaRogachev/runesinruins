#include "cache_volume_repository.h"

#include "volume.h"

using namespace core;

CacheVolumeRepository::CacheVolumeRepository():
    AbstractVolumeRepository()
{}

CacheVolumeRepository::~CacheVolumeRepository()
{}

Point3iList CacheVolumeRepository::allPositions() const
{
    return this->loadedPositions();
}

VolumePtrList CacheVolumeRepository::allVolumes()
{
    return this->loadedVolumes();
}

bool CacheVolumeRepository::canLoad(const Point3i& position) const
{
    return this->isLoaded(position);
}

Point3iList CacheVolumeRepository::loadedPositions() const
{
    return m_cache.keys();
}

VolumePtrList CacheVolumeRepository::loadedVolumes() const
{
    return m_cache.values();
}

VolumePtr CacheVolumeRepository::load(const Point3i& position)
{
    VolumePtr current;
    if (m_cache.contains(position)) current = m_cache[position];

    if (current) this->chain(current, position);
    return current;
}

void CacheVolumeRepository::save(const VolumePtr& volume,
                                 const Point3i& position)
{
    m_cache[position] = volume;
    this->chain(volume, position);
}

void CacheVolumeRepository::remove(const Point3i& position)
{
    this->unload(position);
}

void CacheVolumeRepository::unload(const Point3i& position)
{
    VolumePtr current;
    if (m_cache.contains(position)) current = m_cache[position];

    if (!current) return;

    this->breakChain(current);

    m_cache.remove(position);
}

void CacheVolumeRepository::unloadAll()
{
    for (const Point3i& position: this->loadedPositions())
    {
        this->unload(position);
    }
}

bool CacheVolumeRepository::isLoaded(const Point3i& position) const
{
    return m_cache.contains(position);
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
            volume->chainTo(m_cache[neigbour].data(), direction);
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
