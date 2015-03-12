#include "standart_volume_serializer_test.h"

#include "standart_volume_serializer.h"

using namespace core;

VolumeSerializerPtr StandartVolumeSerializerTest::serializer() const
{
    return VolumeSerializerPtr(new StandartVolumeSerializer());
}
