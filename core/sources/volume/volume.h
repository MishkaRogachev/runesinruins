#ifndef VOLUME_H
#define VOLUME_H

#include "volume_iterator.h"

namespace core
{
    class Volume
    {
    public:
        Volume(const Point3u& size);
        Volume(unsigned x, unsigned y, unsigned z);
        ~Volume();

        Node* nodeAt(unsigned x, unsigned y, unsigned z) const;
        Node* nodeAt(const Point3u& point) const;

        Point3u size() const;
        unsigned width() const;
        unsigned height() const;
        unsigned depth() const;

        void chainTo(Volume* other, Direction direction);
        void breakChain(Direction direction);
        void breakAllChains();
        bool hasChain(Direction direction) const;

        VolumeIterator begin() const;
        VolumeIterator end() const;
        VolumeIterator cornerBegin(Direction direction) const;

    protected:
        void chainInnerNodes() const;
        unsigned indexFromPosition(const Point3u& position) const;

    private:
        class VolumePrivate;
        VolumePrivate* d;

        Volume(const Volume& other) = delete;
        const Volume& operator = (const Volume& other) = delete;
    };
}
#endif // VOLUME_H
