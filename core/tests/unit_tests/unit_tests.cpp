 #include <QtTest/QtTest>

#include "cubic_structure/node_test/node_test.h"
#include "cubic_structure/volume_test/volume_test.h"

int main()
{
    NodeTest nodeTest;
    QTest::qExec(&nodeTest);

    VolumeTest volumeTest;
    QTest::qExec(&volumeTest);

    return 0;
}

 
