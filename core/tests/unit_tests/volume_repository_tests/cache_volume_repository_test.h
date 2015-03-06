#ifndef CACHE_VOLUME_REPOSITORY_TEST_H
#define CACHE_VOLUME_REPOSITORY_TEST_H

#include <QtTest/QtTest>

class CacheVolumeRepositoryTest : public QObject
{
    Q_OBJECT

private slots:
    void testConstructors();
    void testAbstractInterface();
    void testLoading();
};

#endif // CACHE_VOLUME_REPOSITORY_TEST_H
