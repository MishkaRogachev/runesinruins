#ifndef CORE_TRAITS
#define CORE_TRAITS

#include <memory>

#include "point.h"

namespace core
{
    class Node;
    class Volume;

    typedef std::shared_ptr<Volume> VolumePtr;

    typedef Vec<unsigned, 3> Vec3u;
    typedef Vec<int, 3> Vec3i;
}

#endif // CORE_TRAITS

