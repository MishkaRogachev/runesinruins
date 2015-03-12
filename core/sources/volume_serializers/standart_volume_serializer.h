#ifndef STANDART_VOLUME_SERIALIZER_H
#define STANDART_VOLUME_SERIALIZER_H

#include "abstract_volume_serializer.h"

namespace core
{
    class StandartVolumeSerializer: public AbstractVolumeSerializer
    {
    public:
        StandartVolumeSerializer();
        virtual ~StandartVolumeSerializer() override;

        virtual QByteArray serialize(const VolumePtr& volume) const override;
        virtual VolumePtr unserialize(const QByteArray& data) const override;
    };
}

#endif // STANDARTVOLUMESERIALIZER_H
