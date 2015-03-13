#ifndef SQUARE_AREA_TEST_H
#define SQUARE_AREA_TEST_H

#include "abstract_area_test.h"

class SquareAreaTest: public AbstractAreaTest
{
    Q_OBJECT

protected:
    virtual core::AreaPtr area() override;
};

#endif // SQUARE_AREA_TEST_H
