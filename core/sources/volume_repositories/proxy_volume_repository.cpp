#include "proxy_volume_repository.h"

#include <algorithm>

using namespace core;

ProxyVolumeRepository::ProxyVolumeRepository(
        const VolumeRepositoryPtr& sourceRepository):
    CacheVolumeRepository(),
    m_sourceRepository(sourceRepository)
{}

ProxyVolumeRepository::~ProxyVolumeRepository()
{}

Point3iList ProxyVolumeRepository::allPositions() const
{
    Point3iList loaded = this->loadedPositions();
    if (!m_sourceRepository) return loaded;

    Point3iList unloaded = m_sourceRepository->allPositions();

    std::sort(loaded.begin(), loaded.end());
    std::sort(unloaded.begin(), unloaded.end());

    Point3iList all;

    std::merge(loaded.begin(), loaded.end(), unloaded.begin(), unloaded.end(),
        std::insert_iterator<Point3iList>(all, all.end()));

    all.erase(std::unique(all.begin(), all.end()), all.end());

    return all;
}

VolumePtrList ProxyVolumeRepository::allVolumes()
{
    VolumePtrList vector;

    for (const Point3i& position: this->allPositions())
    {
        vector.append(this->load(position));
    }

    return vector;
}

VolumePtr ProxyVolumeRepository::load(const Point3i& position)
{
    if (this->isLoaded(position))
    {
        return CacheVolumeRepository::load(position);
    }
    else
    {
        return this->reload(position);
    }
}

void ProxyVolumeRepository::save(const VolumePtr& volume,
                                 const Point3i& position)
{
    CacheVolumeRepository::save(volume, position);

    if (m_sourceRepository)
    {
        m_sourceRepository->save(volume, position);
    }
}

void ProxyVolumeRepository::remove(const Point3i& position)
{
    this->unload(position);
    if (m_sourceRepository) m_sourceRepository->remove(position);
}

bool ProxyVolumeRepository::canLoad(const Point3i& position) const
{
    return CacheVolumeRepository::canLoad(position) ||
            (m_sourceRepository ?
                 m_sourceRepository->canLoad(position) : false);
}

VolumePtr ProxyVolumeRepository::reload(const Point3i& position)
{
    if (m_sourceRepository && m_sourceRepository->canLoad(position))
    {
        CacheVolumeRepository::save(m_sourceRepository->load(position),
                                    position);
        return CacheVolumeRepository::load(position);
    }
    else
    {
        if (this->isLoaded(position)) CacheVolumeRepository::unload(position);
        return VolumePtr();
    }
}

void ProxyVolumeRepository::setSourceRepository(
        const VolumeRepositoryPtr& sourceRepository)
{
    this->unloadAll();
    m_sourceRepository = sourceRepository;
}

VolumePtr ProxyVolumeRepository::reload(int x, int y, int z)
{
    return this->reload(Point3i(x, y, z));
}
