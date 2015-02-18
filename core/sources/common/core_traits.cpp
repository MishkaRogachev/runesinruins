#include "core_traits.h"

using namespace core;

Direction core::invDirection(Direction dir)
{
    switch (dir)
    {
    case Direction::forward: return Direction::backward;
    case Direction::backward: return Direction::forward;
    case Direction::right: return Direction::left;
    case Direction::left: return Direction::right;
    case Direction::up: return Direction::down;
    case Direction::down: return Direction::up;
    }
    return Direction();
}
