#ifndef DIRECTION_H
#define DIRECTION_H

#include <QVector>
#include <QHash>

namespace core
{
    class Direction
    {
    public:
        Direction();

        static const int count = 6; // must be visible for constant expressions
        static const Direction forward;
        static const Direction backward;
        static const Direction right;
        static const Direction left;
        static const Direction up;
        static const Direction down;

        static QVector< Direction > allDirections();
        static Direction invDirection(Direction dir);

        bool operator==(Direction other) const;
        bool operator!=(Direction other) const;

        friend uint qHash(const core::Direction& direction)
        {
            return qHash(direction.index);
        }

    private:
        unsigned index;
        Direction(unsigned index);
    };
}

#endif // DIRECTION_H
