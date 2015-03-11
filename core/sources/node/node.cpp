#include "node.h"

using namespace core;

class Node::NodePrivate
{
public:
    ObjectPtr object;
    QHash<Direction, Node*> neighbours;

    NodePrivate(const ObjectPtr& object):
        object(object)
    {
        for (Direction dir: Direction::allDirections())
        {
            neighbours[dir] = nullptr;
        }
    }
};

Node::Node(const ObjectPtr& object):
    d(new NodePrivate(object))
{}

Node::~Node()
{
    for (Direction direction: Direction::allDirections())
    {
        if (this->neighbour(Direction(direction)) != nullptr)
        {
           this->breakChain(Direction(direction));
        }
    }
    delete d;
}

Node* Node::neighbour(Direction direction) const
{
    return d->neighbours.value(direction);
}

void Node::setObject(const ObjectPtr& object)
{
    d->object = object;
}

ObjectPtr Node::object() const
{
    return d->object;
}

void Node::chainTo(Node* other, Direction direction)
{
    Node::chain(this, other, direction);
}

void Node::breakChain(Direction direction)
{
    this->neighbour(direction)->setNeighbour(
                nullptr, Direction::invDirection(direction));
    this->setNeighbour(nullptr, direction);
}

void Node::chain(Node* first, Node* second, Direction direction)
{
    first->setNeighbour(second, direction);
    second->setNeighbour(first, Direction::invDirection(direction));
}

void Node::setNeighbour(Node* node, Direction direction)
{
    d->neighbours[direction] = node;
}
