#ifndef CACHE_VOLUME_REPOSITORY_TEST_H
#define CACHE_VOLUME_REPOSITORY_TEST_H

#include "abstract_volume_repository_test.h"

class CacheVolumeRepositoryTest : public AbstractVolumeRepositoryTest
{
    Q_OBJECT

protected:
    virtual core::VolumeRepositoryPtr volumeRepository() const override;

private slots:
//    void testConstructors();
//    void testAbstractInterface();
//    void testLoading();
};

#endif // CACHE_VOLUME_REPOSITORY_TEST_H
