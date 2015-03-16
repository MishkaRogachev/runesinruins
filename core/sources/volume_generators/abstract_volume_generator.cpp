#include "abstract_volume_generator.h"

#include "abstract_area.h"

using namespace core;

AbstractVolumeGenerator::AbstractVolumeGenerator(const Point3u& volumeSize,
                                                 const AreaPtr& avalibleArea):
    m_volumeSize(volumeSize),
    m_avalibleArea(avalibleArea)
{}

AbstractVolumeGenerator::~AbstractVolumeGenerator()
{}

bool AbstractVolumeGenerator::canGenerate(const Point3i& position) const
{
    if (m_avalibleArea.isNull()) return true;

    return m_avalibleArea->positions().contains(position);
}

Point3u AbstractVolumeGenerator::volumeSize() const
{
    return m_volumeSize;
}

void AbstractVolumeGenerator::setVolumeSize(const Point3u& volumeSize)
{
    m_volumeSize = volumeSize;
}


