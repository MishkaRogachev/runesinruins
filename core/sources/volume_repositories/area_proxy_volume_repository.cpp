#include "area_proxy_volume_repository.h"

using namespace core;

AreaProxyVolumeRepository::AreaProxyVolumeRepository(
        const VolumeRepositoryPtr& sourceRepository, const AreaPtr& area):
    ProxyVolumeRepository(sourceRepository),
    m_area(area)
{
    Q_ASSERT(area);
}

AreaProxyVolumeRepository::~AreaProxyVolumeRepository()
{}

Point3i AreaProxyVolumeRepository::position() const
{
    return m_area->centerPosition();
}

Point3i& AreaProxyVolumeRepository::position()
{
    return m_area->centerPosition();
}

void AreaProxyVolumeRepository::setPosition(const Point3i& position)
{
    m_area->setCenterPosition(position);
}

void AreaProxyVolumeRepository::setPosition(int x, int y, int z)
{
    this->setPosition(Point3i(x, y, z));
}

int AreaProxyVolumeRepository::size() const
{
    return m_area->size();
}

void AreaProxyVolumeRepository::setSize(int size)
{
    m_area->setSize(size);
}

void AreaProxyVolumeRepository::checkLoadedVolumes()
{
    Point3iList oldPositions = this->loadedPositions();
    Point3iList newPositions = m_area->positions();

    while (!newPositions.empty())
    {
        Point3i newPosition = newPositions.takeLast();

        oldPositions.contains(newPosition) ?
                    oldPositions.removeOne(newPosition) :
                    this->load(newPosition);
    }

    while (!oldPositions.empty())
    {
        this->unload(oldPositions.takeLast());
    }
}

