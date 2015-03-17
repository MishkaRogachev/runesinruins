#include "node_object_test.h"

#include <QScopedPointer>

#include "node.h"
#include "node_object.h"

using namespace core;

void NodeObjectTest::testNeighbours()
{
    QScopedPointer<Node> node1(new Node());
    QScopedPointer<Node> node2(new Node());

    NodeObjectPtr object1(new NodeObject());
    NodeObjectPtr object2(new NodeObject());

    node1->setObject(object1);

    QCOMPARE(object1->rootNode(), node1.data());

    node2->setObject(object2);

    QCOMPARE(object2->rootNode(), node2.data());

    node1->chainTo(node2.data(), Direction::forward);

    QCOMPARE(object1->neighbour(Direction::forward).data(), object2.data());
}
