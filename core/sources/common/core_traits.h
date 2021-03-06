#ifndef CORE_TRAITS
#define CORE_TRAITS

#include <QSharedPointer>

#include "direction.h"
#include "point.h"

namespace core
{
    class AbstractPersister;
    class AbstractArea;
    class NodeObject;
    class Node;
    class Volume;
    class AbstractVolumeGenerator;
    class AbstractVolumeSerializer;
    class AbstractVolumeRepository;

    typedef Point<unsigned, 3> Point3u;
    typedef Point<int, 3> Point3i;

    typedef QSharedPointer<AbstractPersister> PersisterPtr;
    typedef QSharedPointer<AbstractArea> AreaPtr;
    typedef QSharedPointer<NodeObject> NodeObjectPtr;
    typedef QSharedPointer<Volume> VolumePtr;
    typedef QSharedPointer<AbstractVolumeGenerator> VolumeGeneratorPtr;
    typedef QSharedPointer<AbstractVolumeSerializer> VolumeSerializerPtr;
    typedef QSharedPointer<AbstractVolumeRepository> VolumeRepositoryPtr;

    typedef QList<Point3u> Point3uList;
    typedef QList<Point3i> Point3iList;

    typedef QList<VolumePtr> VolumePtrList;

    Point3i globalPoint(const Point3i& volumePos, const Point3u& inVolumePos,
                        const Point3u& volumeSize);
}

#endif // CORE_TRAITS

