#ifndef CORE_TRAITS
#define CORE_TRAITS

#include <QSharedPointer>

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

    typedef QSharedPointer<ObjectInterface> ObjectPtr;
    typedef QSharedPointer<Volume> VolumePtr;
    typedef QSharedPointer<AbstractVolumeRepository> VolumeRepositoryPtr;
    typedef QSharedPointer<AbstractPersister> PersisterPtr;

    typedef QList<Point3u> Point3uList;
    typedef QList<Point3i> Point3iList;

    typedef QList<VolumePtr> VolumePtrList;
}

#endif // CORE_TRAITS

