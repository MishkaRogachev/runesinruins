#include "standart_volume_serializer.h"

#include <QDataStream>

#include "volume.h"

using namespace core;

StandartVolumeSerializer::StandartVolumeSerializer():
    AbstractVolumeSerializer()
{}

StandartVolumeSerializer::~StandartVolumeSerializer()
{}

QByteArray StandartVolumeSerializer::serialize(const VolumePtr& volume) const
{
    if (volume.isNull()) return QByteArray();

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    stream << volume->width() << volume->height() << volume->depth();

    for (const auto& it: *volume)
    {
        if (it.node()->object())
        {
            stream << it.x() << it.y() << it.z();

            //TODO: serialize node's object
        }
    }

    return data;
}

VolumePtr StandartVolumeSerializer::unserialize(const QByteArray& data) const
{
    if (data.isEmpty()) return VolumePtr();

    QDataStream stream(data);
    Point3u size;
    stream >> size[0] >> size[1] >> size[2];

    VolumePtr volume(new Volume(size));

    while (!stream.atEnd())
    {
        Point3u position;
        stream >> position[0] >> position[1] >> position[2];

        //TODO: unserialize node's object
    }

    return volume;
}

