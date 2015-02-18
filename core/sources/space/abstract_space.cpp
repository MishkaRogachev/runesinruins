#include "abstract_space.h"

#include "volume.h"

using namespace core;

AbstractSpace::AbstractSpace()
{}

AbstractSpace::~AbstractSpace()
{}

VolumePtr AbstractSpace::volumeAt(int x, int y, int z)
{
     return this->volumeAt(Point3i(x, y, z));
}

bool AbstractSpace::hasVolume(int x, int y, int z) const
{
    return this->hasVolume(Point3i(x, y, z));
}

void AbstractSpace::chainVolume(const Point3i& position)
{
    VolumePtr current = this->volumeAt(position);

//    for (const Point3i& neighbourPosition: position.neighbours())
//    {
//        if (this->hasVolume(neighbourPosition))
//        {
////            current->chainTo();// TODO: coomon direction
//        }
//    }
}

void AbstractSpace::breakVolumeChain(const Point3i& position)
{

}
