#ifndef CORE_TRAITS
#define CORE_TRAITS

#include <memory>

#include "direction.h"

namespace core
{
    template< typename T, int dim >
    class Point;
    class ObjectInterface;
    class Node;
    class Volume;
    class AbstractVolumeRepository;
    class AbstractPersister;

    typedef Point<unsigned, 3> Point3u;
    typedef Point<int, 3> Point3i;

    typedef std::shared_ptr<Volume> VolumePtr;
    typedef std::shared_ptr<AbstractVolumeRepository> VolumeRepositoryPtr;
    typedef std::shared_ptr<AbstractPersister> PersisterPtr;

    typedef std::vector<Point3u> Point3uVec;
    typedef std::vector<Point3i> Point3iVec;

    typedef std::vector<VolumePtr> VolumePtrVec;
}

#endif // CORE_TRAITS

