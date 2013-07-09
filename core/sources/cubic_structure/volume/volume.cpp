#include "volume.h"

#include <vector>

#include "volume_iterator.h"

#include <QDebug>

using namespace cubic_structure_layer;

class Volume::VolumePrivate
{
public:
    unsigned width;
    unsigned height;
    unsigned depth;
    std::vector< Node* > nodes;

    VolumePrivate(unsigned width, unsigned height, unsigned depth):
        width(width),
        height(height),
        depth(depth)
    {}
};

Volume::Volume(unsigned width, unsigned height, unsigned depth):
    d(new VolumePrivate(width, height, depth))
{
    for (unsigned i = 0; i < width * height * depth; ++i)
    {
        d->nodes.push_back(new Node());
    }
    this->linkInnerNodes();
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
    return d->nodes.at(this->indexFromPosition(x, y, z));
}

unsigned Volume::width() const
{
    return d->width;
}

unsigned Volume::height() const
{
    return d->height;
}

unsigned Volume::depth() const
{
    return d->depth;
}

void Volume::linkTo(Volume* other, Node::Direction direction)
{
    for (VolumeIterator it = this->cornerBegin(direction);
         it != this->end();
         it.increasePositionPerpendicularDirection(direction))
    {
        const VolumeIterator& invIt = it.invIterator(direction);
        it.node()->linkTo(other->nodeAt(invIt.x(),
                                        invIt.y(),
                                        invIt.z()), direction);
    }
}

void Volume::breakLink(Node::Direction direction)
{
    for (VolumeIterator it = this->cornerBegin(direction);
         it != this->end();
         it.increasePositionPerpendicularDirection(direction))
    {
        it.node()->breakLink(direction);
    }
}

bool Volume::hasLink(Node::Direction direction) const
{
    return this->cornerBegin(direction).node()->neighbour(direction) != nullptr;
}

VolumeIterator Volume::begin() const
{
    return VolumeIterator(this);
}

VolumeIterator Volume::end() const
{
    return VolumeIterator(this, d->width, d->height, d->depth);
}

VolumeIterator Volume::cornerBegin(Node::Direction direction) const
{
    return VolumeIterator(this,
                         direction == Node::directionForward ? d->width - 1 : 0,
                         direction == Node::directionRight ? d->height - 1 : 0,
                         direction == Node::directionUp ? d->depth - 1 : 0);
}

void Volume::linkInnerNodes() const
{
    for (VolumeIterator it: *this)
    {
        const VolumeIterator& up = it.up();
        const VolumeIterator& right = it.right();
        const VolumeIterator& forward = it.forward();

        if (up.z() < d->depth)
        {
            it.node()->linkTo(up.node(), Node::directionUp);
        }

        if (right.y() < d->height)
        {
            it.node()->linkTo(right.node(), Node::directionRight);
        }

        if (forward.x() < d->width )
        {
            it.node()->linkTo(forward.node(), Node::directionForward);
        }
    }
}

unsigned Volume::indexFromPosition(unsigned x, unsigned y, unsigned z) const
{
    return x + y * d->width + z * d->width * d->height;
}
