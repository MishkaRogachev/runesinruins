#ifndef STANDART_VOLUME_GENERATOR_TEST_H
#define STANDART_VOLUME_GENERATOR_TEST_H

#include "abstract_volume_generator_test.h"

class StandartVolumeGeneratorTest: public AbstractVolumeGeneratorTest
{
    Q_OBJECT

public:
    virtual core::VolumeGeneratorPtr generator() const override;
};

#endif // STANDART_VOLUME_GENERATOR_TEST_H
