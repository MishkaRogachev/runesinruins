#include "space_mock.h"

using namespace core;

SpaceMock::SpaceMock(const std::unordered_map<Point3i, VolumePtr>& map):
    AbstractSpace(),
    m_map(map)
{
    for (const auto& item: m_map)
    {
        this->chainVolume(item.first);
    }
}

Point3iVec SpaceMock::positions() const
{
    Point3iVec vector;
    for (const auto& item: m_map)
        vector.push_back(item.first);
    return vector;
}

VolumePtrVec SpaceMock::volumes() const
{
    VolumePtrVec vector;
    for (const auto& item: m_map)
        vector.push_back(item.second);
    return vector;
}

VolumePtr SpaceMock::volumeAt(const Point3i& position)
{
    return m_map[position];
}

bool SpaceMock::hasVolume(const Point3i& position) const
{
    return m_map.count(position) > 0;
}

void SpaceMock::remove(const Point3i& position)
{
    this->breakVolumeChain(position);
    m_map.erase(position);
}
