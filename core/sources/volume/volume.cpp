#include "volume.h"

#include <vector>
#include <algorithm>

#include "node.h"

using namespace core;

class Volume::VolumePrivate
{
public:
    Point3u size;
    std::vector< Node* > nodes;

    VolumePrivate(const Point3u& size):
        size(size),
        nodes(size.product(), nullptr)
    {
        std::generate(nodes.begin(), nodes.end(), [](){ return new Node(); });
    }
};

Volume::Volume(const Point3u& size):
    d(new VolumePrivate(size))
{
    this->chainInnerNodes();
}

Volume::Volume(unsigned x, unsigned y, unsigned z):
    d(new VolumePrivate(Point3u(x, y, z)))
{
    this->chainInnerNodes();
}

Volume::~Volume()
{
    for (auto& node: d->nodes)
    {
        delete node;
    }
    delete d;
}

Node* Volume::nodeAt(unsigned x, unsigned y, unsigned z) const
{
    return this->nodeAt(Point3u(x, y, z));
}

Node* Volume::nodeAt(const Point3u& point) const
{
    return d->nodes.at(this->indexFromPosition(point));
}

Point3u Volume::size() const
{
    return d->size;
}

unsigned Volume::width() const
{
    return d->size.x();
}

unsigned Volume::height() const
{
    return d->size.y();
}

unsigned Volume::depth() const
{
    return d->size.z();
}

void Volume::chainTo(Volume* other, Node::Direction direction)
{
    for (VolumeIterator it = this->cornerBegin(direction);
         it != this->end();
         it.increasePositionPerpendicularDirection(direction))
    {
        const VolumeIterator& invIt = it.invIterator(direction);
        it.node()->chainTo(other->nodeAt(invIt.position()), direction);
    }
}

void Volume::breakChain(Node::Direction direction)
{
    for (VolumeIterator it = this->cornerBegin(direction);
         it != this->end();
         it.increasePositionPerpendicularDirection(direction))
    {
        it.node()->breakChain(direction);
    }
}

bool Volume::hasChain(Node::Direction direction) const
{
    return this->cornerBegin(direction).node()->neighbour(direction) != nullptr;
}

VolumeIterator Volume::begin() const
{
    return VolumeIterator(this);
}

VolumeIterator Volume::end() const
{
    return VolumeIterator(this, d->size);
}

VolumeIterator Volume::cornerBegin(Node::Direction direction) const
{
    return VolumeIterator(this,
                         direction == Node::directionForward ? d->size.x() - 1 : 0,
                         direction == Node::directionRight ? d->size.y() - 1 : 0,
                         direction == Node::directionUp ? d->size.z() - 1 : 0);
}

void Volume::chainInnerNodes() const
{
    for (const VolumeIterator& it: *this)
    {
        const VolumeIterator& up = it.up();
        const VolumeIterator& right = it.right();
        const VolumeIterator& forward = it.forward();

        if (up.z() < d->size.z())
        {
            it.node()->chainTo(up.node(), Node::directionUp);
        }

        if (right.y() < d->size.y())
        {
            it.node()->chainTo(right.node(), Node::directionRight);
        }

        if (forward.x() < d->size.x())
        {
            it.node()->chainTo(forward.node(), Node::directionForward);
        }
    }
}

unsigned Volume::indexFromPosition(const Point3u& position) const
{
    return position.x() +
           position.y() * d->size.x() +
           position.z() * d->size.x() * d->size.y();
}
