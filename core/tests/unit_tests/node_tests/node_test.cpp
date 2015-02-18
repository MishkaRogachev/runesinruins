#include "node_test.h"

#include "node.h"

using namespace core;

void NodeTest::directions()
{
    for (unsigned i = 0; i < directionCount; ++i)
    {
        QCOMPARE(Direction(i), invDirection(invDirection(Direction(i))));
    }
}

void NodeTest::linkAndBreak()
{
    Node first;
    Node second;

    for (unsigned i = 0; i < directionCount; ++i)
    {
        first.chainTo(&second, Direction(i));
        QVERIFY(first.neighbour(Direction(i)) == &second);
        QVERIFY(second.neighbour(invDirection(Direction(i))) ==
                 &first);

        first.breakChain(Direction(i));
        QVERIFY(first.neighbour(Direction(i)) == nullptr);
        QVERIFY(second.neighbour(invDirection(Direction(i))) ==
                 nullptr);
    }
}

void NodeTest::autoCleaningLinks()
{
    Node* first = new Node();
    Node* second = new Node();

    first->chainTo(second, Direction::forward);

    delete second;

    QVERIFY(first->neighbour(Direction::forward) == nullptr);

    delete first;
}
