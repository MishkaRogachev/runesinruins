#include "node.h"

#include <memory>
#include <array>

using namespace cubic_structure_layer;
using namespace object_layer;

class Node::NodePrivate
{
public:
    std::auto_ptr<ObjectInterface> object;
    std::array< Node*, Node::directionCount > neighbours;

    NodePrivate(ObjectInterface* object):
        object(object)
    {
        for (auto& node: neighbours)
        {
            node = nullptr;
        }
    }
};

Node::Node(ObjectInterface* object):
    d(new NodePrivate(object))
{}

Node::~Node()
{
    for (int direction = directionForward;
         direction < directionCount;
         ++direction)
    {
        if (this->neighbour(Direction(direction)) != nullptr)
        {
           this->breakLink(Direction(direction));
        }
    }
    delete d;
}

Node* Node::neighbour(Node::Direction direction) const
{
    return d->neighbours.at(direction);
}

void Node::setObject(ObjectInterface* object)
{
    d->object.reset(object);
}

ObjectInterface* Node::object() const
{
    return d->object.get();
}

void Node::linkTo(Node* other, Direction direction)
{
    Node::link(this, other, direction);
}

void Node::breakLink(Direction direction)
{
    this->neighbour(direction)->setNeighbour(nullptr,
                                             Node::invDirection(direction));
    this->setNeighbour(nullptr, direction);
}

Node::Direction Node::invDirection(Direction direction)
{
    return Direction(directionCount - direction - 1);
}

void Node::link(Node* first, Node* second, Direction direction)
{
    first->setNeighbour(second, direction);
    second->setNeighbour(first, Node::invDirection(direction));
}

void Node::setNeighbour(Node* node, Node::Direction direction)
{
    d->neighbours[direction] = node;
}
