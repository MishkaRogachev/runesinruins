#ifndef ABSTRACT_VOLUME_GENERATOR_TEST_H
#define ABSTRACT_VOLUME_GENERATOR_TEST_H

#include <QtTest/QtTest>

#include "core_traits.h"

class AbstractVolumeGeneratorTest: public QObject
{
    Q_OBJECT

public:
    virtual core::VolumeGeneratorPtr generator() const = 0;

private slots:
    void testCreation();
};

#endif // ABSTRACT_VOLUME_GENERATOR_TEST_H
