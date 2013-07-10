#ifndef VOLUME_H
#define VOLUME_H

#include "node.h"
#include "volume_iterator.h"

namespace cubic_structure_layer
{
    class Volume
    {
    public:
        Volume(unsigned width, unsigned height, unsigned depth);

        virtual ~Volume();

        Node* nodeAt(unsigned x, unsigned y, unsigned z) const;

        unsigned width() const;
        unsigned height() const;
        unsigned depth() const;

        void linkTo(Volume* other, Node::Direction direction);
        void breakLink(Node::Direction direction);
        bool hasLink(Node::Direction direction) const;

        VolumeIterator begin() const;
        VolumeIterator end() const;
        VolumeIterator cornerBegin(Node::Direction direction) const;

    protected:
        void linkInnerNodes() const;
        unsigned indexFromPosition(unsigned x, unsigned y, unsigned z) const;

    private:
        class VolumePrivate;
        VolumePrivate* d;

        Volume(const Volume& other);
        const Volume& operator = (const Volume& vol) {return vol;}
    };
}
#endif // VOLUME_H
