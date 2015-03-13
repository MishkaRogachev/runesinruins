#include "square_area_test.h"

#include "square_area.h"

using namespace core;

AreaPtr SquareAreaTest::area()
{
    return AreaPtr(new SquareArea());
}
