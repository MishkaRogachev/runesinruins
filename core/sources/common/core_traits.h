#ifndef CORE_TRAITS
#define CORE_TRAITS

#include <memory>
#include <vector>

#include "point.h"

namespace core
{
    class ObjectInterface;
    class Node;
    class Volume;

    typedef Point<unsigned, 3> Point3u;
    typedef Point<int, 3> Point3i;

    typedef std::shared_ptr<Volume> VolumePtr;

    typedef std::vector<Point3u> Point3uVec;
    typedef std::vector<Point3i> Point3iVec;

    typedef std::vector<VolumePtr> VolumePtrVec;
}

#endif // CORE_TRAITS

