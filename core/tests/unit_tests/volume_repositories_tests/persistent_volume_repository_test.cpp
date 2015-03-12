#include "persistent_volume_repository_test.h"

#include "persistent_volume_repository.h"

using namespace core;

VolumeRepositoryPtr PersistentVolumeRepositoryTest::volumeRepository() const
{
    return VolumeRepositoryPtr(new PersistentVolumeRepository());
}
