#include "cache_space_test.h"

#include "cache_space.h"

using namespace core;

class SpaceMock: public AbstractSpace
{
    Point3iVec m_positions = { { 2, 3, 0 }, { 2, 2, 0 }, { 3, 2, 0 } };

public:
    virtual Point3iVec positions() const override
    {
        return m_positions;
    }

    virtual VolumePtrVec volumes() const override
    {
        return { VolumePtr(), VolumePtr() , VolumePtr() };
    }

    virtual VolumePtr volumeAt(const Point3i& position) override
    {
        return VolumePtr();
    }

    virtual bool hasVolume(const Point3i& position) const override
    {
        return true;
    }
};

void CacheSpaceTest::creation()
{
    SpaceMock mock;
    CacheSpace space(&mock);

    Point3i p1(0, 1, 2);
    space.load(p1);
    Q_ASSERT(!space.isLoaded(p1));

    Point3i p2(2, 3, 0);
    space.load(p2);
    Q_ASSERT(space.isLoaded(p2));

    QVERIFY(!space.hasVolume(Point3i(8, 2, 4)));
    QVERIFY(!space.hasVolume(-4, -2, 5));
}
