#ifndef ABSTRACT_VOLUME_SERIALIZER_H
#define ABSTRACT_VOLUME_SERIALIZER_H

#include "core_traits.h"

namespace core
{
    class AbstractVolumeSerializer
    {
    public:
        AbstractVolumeSerializer();
        virtual ~AbstractVolumeSerializer();

        virtual QByteArray serialize(const VolumePtr& volume) const = 0;
        virtual VolumePtr unserialize(const QByteArray& data) const = 0;
    };
}

#endif // ABSTRACT_VOLUME_SERIALIZER_H
