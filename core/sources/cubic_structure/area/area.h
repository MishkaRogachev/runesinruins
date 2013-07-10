#ifndef AREA_H
#define AREA_H

#include "volume.h"

#include <QList>
#include <QPoint>
#include <QSharedPointer>

namespace cubic_structure_layer
{
    typedef QSharedPointer<Volume> VolumePtr;

    class Area
    {
    public:
        Area();
        virtual ~Area();

        QList<QPoint> allPositions() const;
        QList<VolumePtr> allVolumes() const;

        void insertVolume(const QPoint& position, const VolumePtr& volume);
        VolumePtr volume(const QPoint& position);

        void linkVolumes();

    private:
        class AreaPrivate;
        AreaPrivate* d;
    };
}

uint qHash(const QPoint& p);

#endif // AREA_H
