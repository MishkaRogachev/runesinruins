#include "standart_volume_generator_test.h"

#include "standart_volume_generator.h"

using namespace core;

VolumeGeneratorPtr StandartVolumeGeneratorTest::generator() const
{
    return VolumeGeneratorPtr(new StandartVolumeGenerator(16, 16, 16));
}
