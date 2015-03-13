#ifndef ABSTRACT_VOLUME_SARIALIZER_TEST_H
#define ABSTRACT_VOLUME_SARIALIZER_TEST_H

#include <QtTest/QtTest>

#include "core_traits.h"

class AbstractVolumeSerializerTest: public QObject
{
    Q_OBJECT

protected:
    virtual core::VolumeSerializerPtr serializer() const = 0;

private slots:
    void testSerialization();
};

#endif // ABSTRACT_VOLUME_SARIALIZER_TEST_H
