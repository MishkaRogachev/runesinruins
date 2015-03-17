#ifndef NODE_OBJECT_TEST_H
#define NODE_OBJECT_TEST_H

#include <QtTest/QTest>

class NodeObjectTest: public QObject
{
    Q_OBJECT

private slots:
    void testNeighbours();
};

#endif // NODE_OBJECT_TEST_H
