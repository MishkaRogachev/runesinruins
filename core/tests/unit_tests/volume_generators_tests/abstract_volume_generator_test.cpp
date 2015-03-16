#include "abstract_volume_generator_test.h"

#include "abstract_volume_generator.h"

using namespace core;

void AbstractVolumeGeneratorTest::testCreation()
{
    VolumeGeneratorPtr generator = this->generator();

    for (int i = 0; i < 50; ++i)
    {
        Point3i position(25 - qrand() % 51,
                         25 - qrand() % 51,
                         25 - qrand() % 51);
        if (generator->canGenerate(position))
        {
            generator->generate(position);
        }
    }
}
