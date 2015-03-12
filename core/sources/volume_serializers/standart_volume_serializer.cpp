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

    return data;
}

VolumePtr StandartVolumeSerializer::unserialize(const QByteArray& data) const
{
    if (data.isEmpty()) return VolumePtr();

    QDataStream stream(data);
    Point3u size;
    stream >> size[0] >> size[1] >> size[2];

    VolumePtr volume(new Volume(size));

    return volume;
}

