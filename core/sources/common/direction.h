#ifndef DIRECTION_H
#define DIRECTION_H

#include <vector>

namespace core
{
    class Direction
    {
    public:
        Direction();

        static const int count = 6; // must be vivible for constant expressions
        static const Direction forward;
        static const Direction backward;
        static const Direction right;
        static const Direction left;
        static const Direction up;
        static const Direction down;

        static std::vector< Direction > allDirections();
        static Direction invDirection(Direction dir);

        bool operator==(Direction other) const;
        bool operator!=(Direction other) const;

        friend struct std::hash<core::Direction>;

    private:
        unsigned index;
        Direction(unsigned index);
    };
}

namespace std // Hash function for Direction class
{
    template<>
    struct hash<core::Direction>
    {
        std::size_t operator()(const core::Direction& direction) const
        {
            std::hash<unsigned> unsignedHasher;
            return unsignedHasher(direction.index);
        }
    };
}

#endif // DIRECTION_H
