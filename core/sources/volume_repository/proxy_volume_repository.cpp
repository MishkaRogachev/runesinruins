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

Point3iVec ProxyVolumeRepository::allPositions() const
{
    Point3iVec v1 = this->loadedPositions();
    if (!m_sourceRepository) return v1;

    Point3iVec v2 = m_sourceRepository->allPositions();

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    Point3iVec mergeTarget;

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(),
        std::insert_iterator<Point3iVec>(mergeTarget, mergeTarget.end()));

    mergeTarget.erase(
        std::unique(mergeTarget.begin(), mergeTarget.end()),
        mergeTarget.end());

    return mergeTarget;
}

VolumePtrVec ProxyVolumeRepository::allVolumes()
{
    VolumePtrVec vector;

    for (const Point3i& position: this->allPositions())
    {
        vector.push_back(this->load(position));
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
    m_sourceRepository->save(volume, position);
}

bool ProxyVolumeRepository::canLoad(const Point3i& position) const
{
    return CacheVolumeRepository::canLoad(position) || (
                m_sourceRepository ?
                    m_sourceRepository->canLoad(position) :
                    false);
}

VolumePtr ProxyVolumeRepository::reload(const Point3i& position)
{
    if (m_sourceRepository->canLoad(position))
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

VolumePtr ProxyVolumeRepository::reload(int x, int y, int z)
{
    return this->reload(Point3i(x, y, z));
}


