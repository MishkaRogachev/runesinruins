#include "node.h"

#include <memory>
#include <array>

using namespace core;
using namespace core;

class Node::NodePrivate
{
public:
    std::auto_ptr<ObjectInterface> object;
    std::array< Node*, directionCount > neighbours;

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
    for (unsigned direction = 0; direction < directionCount; ++direction)
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
    return d->neighbours.at(static_cast<unsigned>(direction));
}

void Node::setObject(ObjectInterface* object)
{
    d->object.reset(object);
}

ObjectInterface* Node::object() const
{
    return d->object.get();
}

void Node::chainTo(Node* other, Direction direction)
{
    Node::chain(this, other, direction);
}

void Node::breakChain(Direction direction)
{
    this->neighbour(direction)->setNeighbour(nullptr, invDirection(direction));
    this->setNeighbour(nullptr, direction);
}

void Node::chain(Node* first, Node* second, Direction direction)
{
    first->setNeighbour(second, direction);
    second->setNeighbour(first, invDirection(direction));
}

void Node::setNeighbour(Node* node, Direction direction)
{
    d->neighbours[static_cast<unsigned>(direction)] = node;
}
