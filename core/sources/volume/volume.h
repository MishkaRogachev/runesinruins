#ifndef VOLUME_H
#define VOLUME_H

#include "../common/core_traits.h"
#include "volume_iterator.h"

namespace core
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

        void chainTo(Volume* other, Node::Direction direction);
        void breakChain(Node::Direction direction);
        bool hasChain(Node::Direction direction) const;

        VolumeIterator begin() const;
        VolumeIterator end() const;
        VolumeIterator cornerBegin(Node::Direction direction) const;

    protected:
        void chainInnerNodes() const;
        unsigned indexFromPosition(unsigned x, unsigned y, unsigned z) const;

    private:
        class VolumePrivate;
        VolumePrivate* d;

        Volume(const Volume& other);
        const Volume& operator = (const Volume& vol) {return vol;}
    };
}
#endif // VOLUME_H
