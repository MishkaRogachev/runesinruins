#ifndef STANDARTVOLUMESERIALIZERTEST_H
#define STANDARTVOLUMESERIALIZERTEST_H

#include "abstract_volume_serializer_test.h"

class StandartVolumeSerializerTest: public AbstractVolumeSerializerTest
{
    Q_OBJECT

protected:
    virtual core::VolumeSerializerPtr serializer() const override;
};

#endif // STANDARTVOLUMESERIALIZERTEST_H
