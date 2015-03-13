#ifndef STANDART_VOLUME_SERIALIZER_TEST_H
#define STANDART_VOLUME_SERIALIZER_TEST_H

#include "abstract_volume_serializer_test.h"

class StandartVolumeSerializerTest: public AbstractVolumeSerializerTest
{
    Q_OBJECT

protected:
    virtual core::VolumeSerializerPtr serializer() const override;
};

#endif // STANDART_VOLUME_SERIALIZER_TEST_H
