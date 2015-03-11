#ifndef NODE_H
#define NODE_H

#include "core_traits.h"

namespace core
{
    class Node
    {
    public:
        Node(const ObjectPtr& object = ObjectPtr());
        ~Node();

        Node* neighbour(Direction direction) const;

        void setObject(const ObjectPtr& object);
        ObjectPtr object() const;

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
