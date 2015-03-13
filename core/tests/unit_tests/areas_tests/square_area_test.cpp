#include "square_area_test.h"

#include "square_area.h"

using namespace core;

AreaPtr SquareAreaTest::area(int size)
{
    return AreaPtr(new SquareArea(size));
}
