#ifndef CORE_TRAITS
#define CORE_TRAITS

#include <memory>
#include <vector>

namespace core
{
    enum class Direction
    {
        forward,
        backward,
        right,
        left,
        up,
        down
    };

    const unsigned directionCount = static_cast<unsigned>(Direction::down) + 1;

    Direction invDirection(Direction dir);

    template< typename T, int dim >
    class Point;
    class ObjectInterface;
    class Node;
    class Volume;
    class AbstractSpace;

    typedef Point<unsigned, 3> Point3u;
    typedef Point<int, 3> Point3i;

    typedef std::shared_ptr<Volume> VolumePtr;
    typedef std::shared_ptr<AbstractSpace> SpacePtr;

    typedef std::vector<Point3u> Point3uVec;
    typedef std::vector<Point3i> Point3iVec;

    typedef std::vector<VolumePtr> VolumePtrVec;
}

#endif // CORE_TRAITS

