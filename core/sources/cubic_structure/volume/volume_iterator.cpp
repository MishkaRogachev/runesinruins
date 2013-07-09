#include "volume_iterator.h"

#include "volume.h"

using namespace cubic_structure_layer;

class VolumeIterator::VolumeIteratorPrivate
{
public:
    const Volume* volume;
    unsigned x;
    unsigned y;
    unsigned z;

    VolumeIteratorPrivate(const Volume* volume,
                          unsigned x,
                          unsigned y,
                          unsigned z):
        volume(volume),
        x(x),
        y(y),
        z(z)
    {}
};

VolumeIterator::VolumeIterator(const Volume* volume,
                               unsigned x,
                               unsigned y,
                               unsigned z):
    d(new VolumeIteratorPrivate(volume, x, y, z))
{}

VolumeIterator::VolumeIterator(const VolumeIterator& other):
    d(new VolumeIteratorPrivate(other.volume(),
                                other.x(),
                                other.y(),
                                other.z()))
{}

VolumeIterator::~VolumeIterator()
{
    delete d;
}

Node* VolumeIterator::node() const
{
    return d->volume->nodeAt(d->x, d->y, d->z);
}

const Volume* VolumeIterator::volume() const
{
    return d->volume;
}

unsigned VolumeIterator::x() const
{
    return d->x;
}

unsigned VolumeIterator::y() const
{
    return d->y;
}

unsigned VolumeIterator::z() const
{
    return d->z;
}

void VolumeIterator::setPosition(unsigned x, unsigned y, unsigned z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

VolumeIterator VolumeIterator::up() const
{
    return VolumeIterator(d->volume, d->x, d->y, d->z + 1);
}

VolumeIterator VolumeIterator::down() const
{
    return VolumeIterator(d->volume, d->x, d->y, d->z - 1);
}

VolumeIterator VolumeIterator::right() const
{
    return VolumeIterator(d->volume, d->x, d->y + 1, d->z);
}

VolumeIterator VolumeIterator::left() const
{
    return VolumeIterator(d->volume, d->x, d->y - 1, d->z);
}

VolumeIterator VolumeIterator::forward() const
{
    return VolumeIterator(d->volume, d->x + 1, d->y, d->z);
}

VolumeIterator VolumeIterator::backward() const
{
    return VolumeIterator(d->volume, d->x - 1, d->y, d->z);
}

VolumeIterator VolumeIterator::invIterator(Node::Direction direction) const
{
    unsigned x = d->x;
    unsigned y = d->y;
    unsigned z = d->z;

    if (direction == Node::directionForward ||
        direction == Node::directionBackward)
    {
        x = d->volume->width() - d->x - 1;
    }
    else if (direction == Node::directionRight ||
             direction == Node::directionLeft)
    {
        y = d->volume->height() - d->y - 1;
    }
    else if (direction == Node::directionUp ||
             direction == Node::directionDown)
    {
        z = d->volume->depth() - d->z - 1;
    }
    return VolumeIterator(d->volume, x, y, z);
}

void VolumeIterator::increasePosition()
{
    if (this->forward().x() < d->volume->width())
    {
        this->setPosition(d->x + 1, d->y, d->z);
    }
    else if (this->right().y() < d->volume->height())
    {
        this->setPosition(0, d->y + 1, d->z);
    }
    else if (this->up().z() < d->volume->depth())
    {
        this->setPosition(0, 0, d->z + 1);
    }
    else this->setPosition(d->volume->width(),
                           d->volume->height(),
                           d->volume->depth());
}

void VolumeIterator::
    increasePositionPerpendicularDirection(Node::Direction direction)
{
    const bool xAxis = (direction == Node::directionForward) ||
                       (direction == Node::directionBackward);
    const bool yAxis = (direction == Node::directionRight) ||
                       (direction == Node::directionLeft);
    const bool zAxis = (direction == Node::directionUp) ||
                       (direction == Node::directionDown);

    if (!xAxis && this->forward().x() < d->volume->width())
    {
        this->setPosition(d->x + 1, d->y, d->z);
    }
    else if (!yAxis && this->right().y() < d->volume->height())
    {
        this->setPosition(xAxis ? d->x : 0, d->y + 1, d->z);
    }
    else if (!zAxis && this->up().z() < d->volume->depth())
    {
        this->setPosition(xAxis ? d->x : 0, yAxis ? d->y : 0, d->z + 1);
    }
    else this->setPosition(d->volume->width(),
                           d->volume->height(),
                           d->volume->depth());
}

const VolumeIterator& VolumeIterator::operator ++()
{
    this->increasePosition();
    return *this;
}

bool VolumeIterator::operator !=(const VolumeIterator& other) const
{
    return !(other == *this);
}

bool VolumeIterator::operator ==(const VolumeIterator& other) const
{
    return (this->x() == other.x()) &&
           (this->y() == other.y()) &&
            (this->z() == other.z());
}

VolumeIterator VolumeIterator::operator =(const VolumeIterator& other)
{
    d->volume = other.volume();
    d->x = other.x();
    d->y = other.y();
    d->z = other.z();
    return *this;
}

VolumeIterator VolumeIterator::operator *() const
{
    return *this;
}
