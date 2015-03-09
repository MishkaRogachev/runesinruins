#include "abstract_volume_repository_test.h"

#include "abstract_volume_repository.h"
#include "volume.h"

using namespace core;

class AbstractVolumeRepositoryMock: public AbstractVolumeRepository
{
public:
    virtual Point3iVec allPositions() const override { return Point3iVec(); }
    virtual VolumePtrVec allVolumes() override { return VolumePtrVec(); }
    virtual VolumePtr load(const Point3i&) override { return VolumePtr(); }
    virtual void save(const VolumePtr&, const Point3i&) override {}
    virtual bool canLoad(const Point3i&) const override { return false; }
};

VolumeRepositoryPtr AbstractVolumeRepositoryTest::volumeRepository() const
{
    return VolumeRepositoryPtr(new AbstractVolumeRepositoryMock());
}

void AbstractVolumeRepositoryTest::testAbstractVolumeRepositoryInterface()
{
    VolumeRepositoryPtr volumeRepository = this->volumeRepository();

    QVERIFY(volumeRepository->allPositions().empty());
    QVERIFY(volumeRepository->allVolumes().empty());

    QVERIFY(!volumeRepository->canLoad(3, 4, 3));
    QVERIFY(!volumeRepository->canLoad(3, 3, 2));
    QVERIFY(!volumeRepository->canLoad(4, 3, 2));

    QVERIFY(!volumeRepository->load(3, 4, 3));
    QVERIFY(!volumeRepository->load(3, 3, 2));
    QVERIFY(!volumeRepository->load(4, 3, 2));
}
