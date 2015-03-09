#ifndef ABSTRACT_VOLUME_REPOSITORY_TEST_H
#define ABSTRACT_VOLUME_REPOSITORY_TEST_H

#include <QtTest/QtTest>

#include "core_traits.h"

class AbstractVolumeRepositoryTest : public QObject
{
    Q_OBJECT

protected:
    virtual core::VolumeRepositoryPtr volumeRepository() const;

private slots:
    void testAbstractVolumeRepositoryInterface();

};

#endif // ABSTRACT_VOLUME_REPOSITORY_TEST_H
