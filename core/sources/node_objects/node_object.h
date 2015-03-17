#ifndef NODEOBJECT_H
#define NODEOBJECT_H

#include "core_traits.h"

namespace core
{
    class NodeObject
    {
    public:
        NodeObject(Node* rootNode = nullptr);
        virtual ~NodeObject();

        Node* rootNode() const;
        NodeObjectPtr neighbour(Direction direction) const;

    private:
        friend class Node;
        void setRootNode(Node* rootNode);

        Node* m_rootNode;
    };
}

#endif // NODEOBJECT_H
