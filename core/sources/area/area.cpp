#include "area.h"

#include <QHash>

uint qHash(const QPoint& p)
{
    return qHash(p.x()) ^ qHash(p.y());
}

using namespace core;

class Area::AreaPrivate
{
public:
    QHash<QPoint, VolumePtr> volumes;

    void linkVolumeRecursive(const QPoint& pos)
    {
        this->linkAndRepeat(pos, pos + QPoint(1, 0), Node::directionForward);
        this->linkAndRepeat(pos, pos + QPoint(-1, 0), Node::directionBackward);
        this->linkAndRepeat(pos, pos + QPoint(0, 1), Node::directionRight);
        this->linkAndRepeat(pos, pos + QPoint(0, -1), Node::directionLeft);
    }

private:
    void linkAndRepeat(const QPoint& pos,
                       const QPoint& rPos,
                       Node::Direction direction)
    {
        if (this->volumes.contains(rPos) &&
            !this->volumes.value(pos)->hasChain(direction))
        {
            this->volumes[pos]->chainTo(this->volumes[rPos].data(),
                                            direction);
            this->linkVolumeRecursive(rPos);
        }
    }
};

Area::Area():
    d(new AreaPrivate())
{}

Area::~Area()
{
    delete d;
}

QList<QPoint> Area::allPositions() const
{
    return d->volumes.keys();
}

QList<VolumePtr> Area::allVolumes() const
{
    return d->volumes.values();
}

void Area::insertVolume(const QPoint& position, const VolumePtr& volume)
{
    d->volumes[position] = volume;
}

VolumePtr Area::volume(const QPoint& position)
{
    if (d->volumes.contains(position))
    {
        return d->volumes[position];
    }
    else
    {
        return VolumePtr();
    }
}

void Area::linkVolumes()
{
    d->linkVolumeRecursive(d->volumes.begin().key());
}
