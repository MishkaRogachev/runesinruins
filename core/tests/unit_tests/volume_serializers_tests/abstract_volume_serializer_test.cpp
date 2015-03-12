#include "abstract_volume_serializer_test.h"

#include "abstract_volume_serializer.h"
#include "volume.h"

using namespace core;

void AbstractVolumeSerializerTest::testSerialization()
{
    VolumeSerializerPtr serializer = this->serializer();

    QCOMPARE(serializer->serialize(VolumePtr()), QByteArray());
    QCOMPARE(serializer->unserialize(serializer->serialize(
                                         VolumePtr())), VolumePtr());

    VolumePtr vol1(new Volume(5, 5, 5));
    QCOMPARE(serializer->unserialize(serializer->serialize(vol1))->size(),
             vol1->size());

    VolumePtr vol2(new Volume(7, 7, 7));
    QCOMPARE(serializer->unserialize(serializer->serialize(vol2))->size(),
             vol2->size());
}
