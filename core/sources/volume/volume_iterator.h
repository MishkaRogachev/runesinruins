#ifndef VOLUME_ITERATOR_H
#define VOLUME_ITERATOR_H

#include "node.h"

namespace core
{
    class Volume;

    class VolumeIterator
    {
    public:
        explicit VolumeIterator(const Volume* volume,
                       unsigned x = 0,
                       unsigned y = 0,
                       unsigned z = 0);
        VolumeIterator(const VolumeIterator& other);
        ~VolumeIterator();

        Node* node() const;
        const Volume* volume() const;

        unsigned x() const;
        unsigned y() const;
        unsigned z() const;
        void setPosition(unsigned x, unsigned y, unsigned z);

        VolumeIterator up() const;
        VolumeIterator down() const;
        VolumeIterator right() const;
        VolumeIterator left() const;
        VolumeIterator forward() const;
        VolumeIterator backward() const;

        VolumeIterator invIterator(Node::Direction direction) const;

        void increasePosition();
        void increasePositionPerpendicularDirection(Node::Direction direction);

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
