#include "area_test.h"

using namespace core;

void AreaTest::creationAndLinking()
{
    Area area;

    area.insertVolume(QPoint(4, 4), VolumePtr(new Volume(16, 16, 256)));
    area.insertVolume(QPoint(3, 4), VolumePtr(new Volume(16, 16, 256)));

    area.linkVolumes();

    QVERIFY(area.volume(QPoint(3, 4))->nodeAt(15,0,0)->neighbour(
                Node::directionForward) ==
            area.volume(QPoint(4, 4))->nodeAt(0,0,0));
}
