#ifndef ABSTRACT_VOLUME_GENERATOR_H
#define ABSTRACT_VOLUME_GENERATOR_H

#include "core_traits.h"

namespace core
{
    class AbstractVolumeGenerator
    {
    public:
        AbstractVolumeGenerator();
        virtual ~AbstractVolumeGenerator();

        virtual VolumePtr create(const Point3i& position) = 0;
        virtual bool canCreate(const Point3i& position) const = 0;
    };
}
#endif // ABSTRACTVOLUMEGENERATOR_H
