#ifndef STANDART_VOLUME_GENERATOR_H
#define STANDART_VOLUME_GENERATOR_H

#include "abstract_volume_generator.h"

namespace core
{
    class StandartVolumeGenerator: public AbstractVolumeGenerator
    {
    public:
        StandartVolumeGenerator(const Point3u& volumeSize,
                                const AreaPtr& avalibleArea = AreaPtr());
        StandartVolumeGenerator(unsigned width, unsigned height, unsigned depth,
                                const AreaPtr& avalibleArea = AreaPtr());
        ~StandartVolumeGenerator() override;

        virtual VolumePtr generate(const Point3i& position) override;

    protected:
        virtual NodeObjectPtr nodeForPosition(const Point3i& position);
    };
}
#endif // STANDART_VOLUME_GENERATOR_H
