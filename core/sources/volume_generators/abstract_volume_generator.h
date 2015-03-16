#ifndef ABSTRACT_VOLUME_GENERATOR_H
#define ABSTRACT_VOLUME_GENERATOR_H

#include "core_traits.h"

namespace core
{
    class AbstractVolumeGenerator
    {
    public:
        AbstractVolumeGenerator(const Point3u& volumeSize,
                                const AreaPtr& avalibleArea = AreaPtr());
        virtual ~AbstractVolumeGenerator();

        virtual VolumePtr generate(const Point3i& position) = 0;
        virtual bool canGenerate(const Point3i& position) const;

        Point3u volumeSize() const;
        void setVolumeSize(const Point3u& volumeSize);

    protected:
        Point3u m_volumeSize;
        AreaPtr m_avalibleArea;
    };
}
#endif // ABSTRACTVOLUMEGENERATOR_H
