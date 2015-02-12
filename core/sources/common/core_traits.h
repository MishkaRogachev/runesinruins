#ifndef CORE_TRAITS
#define CORE_TRAITS

#include <memory>

#include "point.h"

namespace core
{
    class Node;
    class Volume;

    typedef std::shared_ptr<Volume> VolumePtr;

//    typedef Point<unsigned, 2> VolumePoint;
//    typedef Point<int, 3> SpacePoint;
}

#endif // CORE_TRAITS

