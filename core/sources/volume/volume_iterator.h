#ifndef VOLUME_ITERATOR_H
#define VOLUME_ITERATOR_H

#include "core_traits.h"
#include "node.h"

namespace core
{
    class VolumeIterator
    {
    public:
        VolumeIterator(const Volume* volume,
                       const Point3u& position = Point3u());
        VolumeIterator(const Volume* volume,
                       unsigned x, unsigned y, unsigned z);
        VolumeIterator(const VolumeIterator& other);
        ~VolumeIterator();

        Node* node() const;
        const Volume* volume() const;

        unsigned x() const;
        unsigned y() const;
        unsigned z() const;
        Point3u position() const;
        void setPosition(unsigned x, unsigned y, unsigned z);
        void setPosition(const Point3u& position);

        VolumeIterator up() const;
        VolumeIterator down() const;
        VolumeIterator right() const;
        VolumeIterator left() const;
        VolumeIterator forward() const;
        VolumeIterator backward() const;

        VolumeIterator invIterator(Direction direction) const;

        void increasePosition();
        void increasePositionPerpendicularDirection(Direction direction);

        const VolumeIterator& operator ++();

        bool operator !=(const VolumeIterator& other) const;
        bool operator ==(const VolumeIterator& other) const;
        VolumeIterator operator =(const VolumeIterator& other);

        VolumeIterator operator*() const;

    private:
        class VolumeIteratorPrivate;
        VolumeIteratorPrivate* d;
    };
}
#endif // VOLUME_ITERATOR_H
