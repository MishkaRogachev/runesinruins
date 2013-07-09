#ifndef VOLUME_TEST_H
#define VOLUME_TEST_H

#include <QtTest/QtTest>

class VolumeTest: public QObject
{
    Q_OBJECT

private slots:
    void testInnerLinking();
    void testLinkingVolumes();

private:
    void testVolume(int i, int j, int k);
};
#endif // VOLUME_TEST_H
