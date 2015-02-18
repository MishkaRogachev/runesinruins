#include "direction.h"

using namespace core;

const Direction Direction::forward = Direction(0);
const Direction Direction::backward = Direction(1);
const Direction Direction::right = Direction(2);
const Direction Direction::left = Direction(3);
const Direction Direction::up = Direction(4);
const Direction Direction::down = Direction(5);

Direction::Direction():
    index(0)
{}

std::vector<Direction> Direction::allDirections()
{
    return std::vector<Direction>({ forward, backward, right, left, up, down });
}

Direction Direction::invDirection(Direction dir)
{
    if (dir == forward) return backward;
    if (dir == backward) return forward;
    if (dir == right) return left;
    if (dir == left) return right;
    if (dir == up) return down;
    if (dir == down) return up;
    return Direction();
}

bool Direction::operator==(Direction other) const
{
    return index == other.index;
}

bool Direction::operator!=(Direction other) const
{
    return index != other.index;
}

Direction::Direction(unsigned index):
    index(index)
{}
