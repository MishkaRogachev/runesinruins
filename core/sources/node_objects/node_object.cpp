#include "node_object.h"

#include "node.h"

using namespace core;

NodeObject::NodeObject(Node* rootNode):
    m_rootNode(rootNode)
{}

NodeObject::~NodeObject()
{}

Node* NodeObject::rootNode() const
{
    return m_rootNode;
}

void NodeObject::setRootNode(Node* rootNode)
{
    m_rootNode = rootNode;
}

NodeObjectPtr NodeObject::neighbour(Direction direction) const
{
    if (!m_rootNode || !m_rootNode->neighbour(direction))
        return NodeObjectPtr();

    return m_rootNode->neighbour(direction)->object();
}

