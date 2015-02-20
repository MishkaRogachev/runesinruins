#ifndef SPACEMOCK_H
#define SPACEMOCK_H

#include <unordered_map>
#include "abstract_space.h"

namespace core
{
    class SpaceMock: public AbstractSpace
    {
    public:
        SpaceMock(const std::unordered_map<Point3i, VolumePtr>& m_map =
                std::unordered_map<Point3i, VolumePtr>());

        virtual Point3iVec positions() const override;
        virtual VolumePtrVec volumes() const override;
        virtual VolumePtr volumeAt(const Point3i& position) override;
        virtual bool hasVolume(const Point3i& position) const override;

        void remove(const Point3i& position);

    private:
        std::unordered_map<Point3i, VolumePtr> m_map;
    };
}
#endif // SPACEMOCK_H
