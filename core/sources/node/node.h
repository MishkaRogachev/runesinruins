#ifndef NODE_H
#define NODE_H

#include "core_traits.h"

namespace core
{
    class Node
    {
    public:

        Node(core::ObjectInterface* object = nullptr);
        ~Node();

        Node* neighbour(Direction direction) const;

        void setObject(core::ObjectInterface* object);
        core::ObjectInterface* object() const;

        void chainTo(Node *other, Direction direction);
        void breakChain(Direction direction);

        static void chain(Node* first, Node* second, Direction direction);

    private:
        void setNeighbour(Node* node, Direction direction);

        class NodePrivate;
        NodePrivate* d;
    };
}
#endif // NODE_H
