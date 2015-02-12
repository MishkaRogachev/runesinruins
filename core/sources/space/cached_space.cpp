#include "cached_space.h"

#include <unordered_map>

using namespace core;

class CachedSpace::CachedSpacePrivate
{
public:
    std::unordered_map<SpacePoint, VolumePtr> map;
};

CachedSpace::CachedSpace():
    AbstractSpace(),
    d(new CachedSpacePrivate())
{}

CachedSpace::~CachedSpace()
{
    delete d;
}

//bool CachedSpace::hasVolume(const SpacePoint& point)
//{
//    return d->map.count(point) > 0;
//}

//VolumePtr CachedSpace::volumeAt(const SpacePoint& point)
//{
//     return d->map.at(point);
//}

