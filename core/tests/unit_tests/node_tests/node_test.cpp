#include "node_test.h"

#include "node.h"

using namespace core;

void NodeTest::testChaining()
{
    Node first;
    Node second;

    for (Direction dir: Direction::allDirections())
    {
        first.chainTo(&second, dir);
        QVERIFY(first.neighbour(dir) == &second);
        QVERIFY(second.neighbour(Direction::invDirection(dir)) ==
                 &first);

        first.breakChain(dir);
        QVERIFY(first.neighbour(dir) == nullptr);
        QVERIFY(second.neighbour(Direction::invDirection(dir)) ==
                 nullptr);
    }
}

void NodeTest::testCleaningChains()
{
    Node* first = new Node();
    Node* second = new Node();

    first->chainTo(second, Direction::forward);

    delete second;

    QVERIFY(first->neighbour(Direction::forward) == nullptr);

    delete first;
}
