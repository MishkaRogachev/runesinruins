#include "volume_test.h"

#include "volume.h"

using namespace core;

void VolumeTest::testInnerLinking()
{
    this->testVolume(1, 1, 1);
    this->testVolume(8, 1, 1);
    this->testVolume(1, 16, 32);
    this->testVolume(16, 24, 32);
    this->testVolume(16, 16, 256);
}

void VolumeTest::testLinkingVolumes()
{
    Volume vol1(8, 8, 8);
    Volume vol2(8, 8, 8);

    QVERIFY(vol1.hasChain(Node::directionForward) == false);

    vol1.chainTo(&vol2, Node::directionForward);

    QVERIFY(vol1.hasChain(Node::directionForward) == true);
    QVERIFY(vol2.hasChain(Node::directionBackward) == true);

    Node* node = vol1.begin().node();
    unsigned i = 1;

    while (node->neighbour(Node::directionForward))
    {
        node = node->neighbour(Node::directionForward);
        ++i;
    }
    QVERIFY(i == vol1.width() + vol2.width());

    vol1.breakChain(Node::directionForward);

    QVERIFY(vol1.hasChain(Node::directionForward) == false);
    QVERIFY(vol2.hasChain(Node::directionBackward) == false);
}

void VolumeTest::testLinkingVolumesWithDifferentSizes()
{
    Volume vol1(16, 32, 64);
    Volume vol2(16, 32, 64);

    vol1.chainTo(&vol2, Node::directionRight);

    QVERIFY(vol1.hasChain(Node::directionRight) == true);
    QVERIFY(vol2.hasChain(Node::directionLeft) == true);

    Node* node = vol1.begin().node();
    unsigned i = 1;

    while (node->neighbour(Node::directionRight))
    {
        node = node->neighbour(Node::directionRight);
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
