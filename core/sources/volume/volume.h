#ifndef VOLUME_H
#define VOLUME_H

#include "../common/core_traits.h"
#include "volume_iterator.h"

namespace core
{
    class Volume
    {
    public:
        Volume(const Point3u& size);
        Volume(unsigned x, unsigned y, unsigned z);
        virtual ~Volume();

        Node* nodeAt(unsigned x, unsigned y, unsigned z) const;
        Node* nodeAt(const Point3u& point) const;

        Point3u size() const;
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
        unsigned indexFromPosition(const Point3u& position) const;

    private:
        class VolumePrivate;
        VolumePrivate* d;

        Volume(const Volume& other) = delete;
        const Volume& operator = (const Volume& vol) = delete;
    };
}
#endif // VOLUME_H
