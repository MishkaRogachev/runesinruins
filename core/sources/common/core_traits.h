#ifndef CORE_TRAITS
#define CORE_TRAITS

#include <memory>
#include <vector>

#include "vec.h"

namespace core
{
    class ObjectInterface;
    class Node;
    class Volume;

    typedef Vec<unsigned, 3> Vec3u;
    typedef Vec<int, 3> Vec3i;

    typedef std::shared_ptr<Volume> VolumePtr;

    typedef std::vector<Vec3u> Vec3uVec;
    typedef std::vector<Vec3i> Vec3iVec;

    typedef std::vector<VolumePtr> VolumePtrVec;
}

#endif // CORE_TRAITS

