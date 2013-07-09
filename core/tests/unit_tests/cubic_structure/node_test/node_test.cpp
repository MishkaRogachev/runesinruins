#include "node_test.h"

#include "node.h"

using namespace cubic_structure_layer;

void NodeTest::directions()
{
    for (int i = Node::directionForward; i < Node::directionCount; ++i)
    {
        QCOMPARE(Node::Direction(i),
                 Node::invDirection(Node::invDirection(Node::Direction(i))));
    }
}

void NodeTest::linkAndBreak()
{
    Node first;
    Node second;

    for (int i = Node::directionForward; i < Node::directionCount; ++i)
    {
        first.linkTo(&second, Node::Direction(i));
        QVERIFY(first.neighbour(Node::Direction(i)) == &second);
        QVERIFY(second.neighbour(Node::invDirection(Node::Direction(i))) ==
                 &first);

        first.breakLink(Node::Direction(i));
        QVERIFY(first.neighbour(Node::Direction(i)) == nullptr);
        QVERIFY(second.neighbour(Node::invDirection(Node::Direction(i))) ==
                 nullptr);
    }
}

void NodeTest::autoCleaningLinks()
{
    Node* first = new Node();
    Node* second = new Node();

    first->linkTo(second, Node::directionForward);

    delete second;

    QVERIFY(first->neighbour(Node::directionForward) == nullptr);

    delete first;
}