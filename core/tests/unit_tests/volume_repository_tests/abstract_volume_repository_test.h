#ifndef ABSTRACT_VOLUME_REPOSITORY_TEST_H
#define ABSTRACT_VOLUME_REPOSITORY_TEST_H

#include <QtTest/QtTest>


class AbstractVolumeRepositoryTest : public QObject
{
    Q_OBJECT

private slots:
    void testIntegrity();
    void testChaning2D();
};

#endif // ABSTRACT_VOLUME_REPOSITORY_TEST_H
