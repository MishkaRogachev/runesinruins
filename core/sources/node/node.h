#ifndef NODE_H
#define NODE_H

namespace object_layer
{
    class ObjectInterface;
}

namespace core
{
    class Node
    {
    public:
        enum Direction
        {
            directionForward,
            directionRight,
            directionUp,
            directionDown,
            directionLeft,
            directionBackward,
            directionCount
        };

        Node(object_layer::ObjectInterface* object = nullptr);
        ~Node();

        Node* neighbour(Direction direction) const;

        void setObject(object_layer::ObjectInterface* object);
        object_layer::ObjectInterface* object() const;

        void chainTo(Node *other, Direction direction);
        void breakChain(Direction direction);

        static Direction invDirection(Direction direction);
        static void chain(Node* first, Node* second, Direction direction);

    private:
        void setNeighbour(Node* node, Direction direction);

        class NodePrivate;
        NodePrivate* d;
    };
}
#endif // NODE_H
