#include "volume_test.h"

#include "volume.h"

using namespace core;

void VolumeTest::testInnerLinking()
{
//    this->testVolume(1, 1, 1);
//    this->testVolume(8, 1, 1);
//    this->testVolume(1, 16, 32);
    this->testVolume(16, 24, 32);
//    this->testVolume(16, 16, 256);
}

void VolumeTest::testLinkingVolumes()
{
    Volume vol1(8, 8, 8);
    Volume vol2(8, 8, 8);

    QVERIFY(vol1.hasChain(Direction::forward) == false);

    vol1.chainTo(&vol2, Direction::forward);

    QVERIFY(vol1.hasChain(Direction::forward) == true);
    QVERIFY(vol2.hasChain(Direction::backward) == true);

    Node* node = vol1.begin().node();
    unsigned i = 1;

    while (node->neighbour(Direction::forward))
    {
        node = node->neighbour(Direction::forward);
        ++i;
    }
    QVERIFY(i == vol1.width() + vol2.width());

    vol1.breakChain(Direction::forward);

    QVERIFY(vol1.hasChain(Direction::forward) == false);
    QVERIFY(vol2.hasChain(Direction::backward) == false);
}

void VolumeTest::testLinkingVolumesWithDifferentSizes()
{
    Volume vol1(16, 32, 64);
    Volume vol2(16, 32, 64);

    vol1.chainTo(&vol2, Direction::right);

    QVERIFY(vol1.hasChain(Direction::right) == true);
    QVERIFY(vol2.hasChain(Direction::left) == true);

    Node* node = vol1.begin().node();
    unsigned i = 1;

    while (node->neighbour(Direction::right))
    {
        node = node->neighbour(Direction::right);
        ++i;
    }
    QVERIFY(i == vol1.height() + vol2.height());
}

void VolumeTest::testVolume(int i, int j, int k)
{
    Volume vol(i, j, k);

    for (const auto& it: vol)
    {
        if (it.x() > 0)
        {
            QVERIFY(it.backward().node() ==
                    vol.nodeAt(it.x() - 1, it.y(), it.z()));
        }
        if (it.x() < vol.width() - 1)
        {
            QVERIFY(it.forward().node() ==
                    vol.nodeAt(it.x() + 1, it.y(), it.z()));
        }
        if (it.y() > 0)
        {
            QVERIFY(it.left().node() ==
                    vol.nodeAt(it.x(), it.y() - 1, it.z()));
        }
        if (it.y() < vol.height() - 1)
        {
            QVERIFY(it.right().node() ==
                    vol.nodeAt(it.x(), it.y() + 1, it.z()));
        }
        if (it.z() > 0)
        {
            QVERIFY(it.down().node() ==
                    vol.nodeAt(it.x(), it.y(), it.z() - 1));
        }
        if (it.z() < vol.depth() - 1)
        {
            QVERIFY(it.up().node() ==
                    vol.nodeAt(it.x(), it.y(), it.z() + 1));
        }
    }
}
