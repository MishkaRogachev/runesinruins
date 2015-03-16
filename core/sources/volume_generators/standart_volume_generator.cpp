#include "standart_volume_generator.h"

#include "volume.h"
#include "volume_iterator.h"

using namespace core;

StandartVolumeGenerator::StandartVolumeGenerator(const Point3u& volumeSize,
                                                 const AreaPtr& avalibleArea):
    AbstractVolumeGenerator(volumeSize, avalibleArea)
{}

StandartVolumeGenerator::StandartVolumeGenerator(
        unsigned width, unsigned height, unsigned depth,
        const AreaPtr& avalibleArea):
    StandartVolumeGenerator(Point3u(width, height, depth), avalibleArea)
{}

StandartVolumeGenerator::~StandartVolumeGenerator()
{}

VolumePtr StandartVolumeGenerator::generate(const Point3i& position)
{
    VolumePtr volume(new Volume(m_volumeSize));

    for (const auto& it: *volume)
    {
        it.node()->setObject(this->nodeForPosition(
                        globalPoint(position, it.position(), m_volumeSize)));
    }
    return volume;
}

NodeObjectPtr StandartVolumeGenerator::nodeForPosition(const Point3i& position)
{
    NodeObjectPtr object;

    //TODO: NodeObject generator

    return object;
}

