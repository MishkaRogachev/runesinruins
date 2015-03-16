#include "core_traits.h"

using namespace core;

Point3i core::globalPoint(const Point3i& volumePos, const Point3u& inVolumePos,
                          const Point3u& volumeSize)
{
    return Point3i(volumePos.x() * volumeSize.x() + inVolumePos.x(),
                   volumePos.y() * volumeSize.y() + inVolumePos.y(),
                   volumePos.z() * volumeSize.z() + inVolumePos.z());
}
