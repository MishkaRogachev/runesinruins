#ifndef SQUARE_AREA_H
#define SQUARE_AREA_H

#include "abstract_area.h"

namespace core
{
    class SquareArea : public AbstractArea
    {
    public:
        SquareArea();
        virtual ~SquareArea() override;
    };
}
#endif // SQUARE_AREA_H
