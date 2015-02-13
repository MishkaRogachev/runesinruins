#include "volume_iterator.h"

#include "volume.h"

using namespace core;

class VolumeIterator::VolumeIteratorPrivate
{
public:
    const Volume* volume;
    Vec3u position;

    VolumeIteratorPrivate(const Volume* volume, const Vec3u& point):
        volume(volume),
        position(point)
    {}
};

VolumeIterator::VolumeIterator(const Volume* volume, const Vec3u& point):
    d(new VolumeIteratorPrivate(volume, point))
{}

VolumeIterator::VolumeIterator(const Volume* volume,
                               unsigned x, unsigned y, unsigned z):
    d(new VolumeIteratorPrivate(volume, Vec3u(x, y, z)))
{}

VolumeIterator::VolumeIterator(const VolumeIterator& other):
    d(new VolumeIteratorPrivate(other.volume(),
                                other.position()))
{}

VolumeIterator::~VolumeIterator()
{
    delete d;
}

Node* VolumeIterator::node() const
{
    return d->volume->nodeAt(d->position);
}

const Volume* VolumeIterator::volume() const
{
    return d->volume;
}

unsigned VolumeIterator::x() const
{
    return d->position.at(0);
}

unsigned VolumeIterator::y() const
{
    return d->position.at(1);
}

unsigned VolumeIterator::z() const
{
    return d->position.at(2);
}

Vec3u VolumeIterator::position() const
{
    return d->position;
}

void VolumeIterator::setPoint(unsigned x, unsigned y, unsigned z)
{
    this->setPoint(Vec3u(x, y, z));
}

void VolumeIterator::setPoint(const Vec3u& point)
{
    d->position = point;
}

VolumeIterator VolumeIterator::up() const
{
    return VolumeIterator(d->volume, d->position.up());
}

VolumeIterator VolumeIterator::down() const
{
    return VolumeIterator(d->volume, d->position.down());
}

VolumeIterator VolumeIterator::right() const
{
    return VolumeIterator(d->volume, d->position.right());
}

VolumeIterator VolumeIterator::left() const
{
    return VolumeIterator(d->volume, d->position.left());
}

VolumeIterator VolumeIterator::forward() const
{
    return VolumeIterator(d->volume, d->position.forward());
}

VolumeIterator VolumeIterator::backward() const
{
    return VolumeIterator(d->volume, d->position.backward());
}

VolumeIterator VolumeIterator::invIterator(Node::Direction direction) const
{
    Vec3u point(d->position);

    if (direction == Node::directionForward ||
        direction == Node::directionBackward)
    {
        point.setX(d->volume->width() - d->position.x() - 1);
    }
    else if (direction == Node::directionRight ||
             direction == Node::directionLeft)
    {
        point.setY(d->volume->height() - d->position.y() - 1);
    }
    else if (direction == Node::directionUp ||
             direction == Node::directionDown)
    {
        point.setZ(d->volume->depth() - d->position.z() - 1);
    }
    return VolumeIterator(d->volume, point);
}

void VolumeIterator::increasePosition()
{
    if (this->forward().x() < d->volume->width())
    {
        this->setPoint(Vec3u(d->position.x() + 1, d->position.y(), d->position.z()));
    }
    else if (this->right().y() < d->volume->height())
    {
        this->setPoint(Vec3u(0, d->position.y() + 1, d->position.z()));
    }
    else if (this->up().z() < d->volume->depth())
    {
        this->setPoint(Vec3u(0, 0, d->position.z() + 1));
    }
    else this->setPoint(d->volume->width(),
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
        this->setPoint(Vec3u(d->position.x() + 1, d->position.y(), d->position.z()));
    }
    else if (!yAxis && this->right().y() < d->volume->height())
    {
        this->setPoint(Vec3u(xAxis ? d->position.x() : 0, d->position.y() + 1, d->position.z()));
    }
    else if (!zAxis && this->up().z() < d->volume->depth())
    {
        this->setPoint(Vec3u(xAxis ? d->position.x() : 0, yAxis ? d->position.y() : 0, d->position.z() + 1));
    }
    else this->setPoint(d->volume->width(), d->volume->height(), d->volume->depth());
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
    return this->position() == other.position();
}

VolumeIterator VolumeIterator::operator =(const VolumeIterator& other)
{
    d->volume = other.volume();
    d->position = other.position();
    return *this;
}

VolumeIterator VolumeIterator::operator *() const
{
    return *this;
}
