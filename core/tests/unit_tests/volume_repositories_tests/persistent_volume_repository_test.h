#ifndef PERSISTENT_VOLUME_REPOSITORY_TEST_H
#define PERSISTENT_VOLUME_REPOSITORY_TEST_H

#include "abstract_volume_repository_test.h"

class PersistentVolumeRepositoryTest: public AbstractVolumeRepositoryTest
{
    Q_OBJECT

protected:
    virtual core::VolumeRepositoryPtr volumeRepository() const override;
};

#endif // PERSISTENTVOLUMEREPOSITORYTEST_H
