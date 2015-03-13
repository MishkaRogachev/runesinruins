#ifndef SQUARE_AREA_H
#define SQUARE_AREA_H

#include "abstract_area.h"

namespace core
{
    class SquareArea : public AbstractArea
    {
    public:
        SquareArea(int size = 1, const Point3i& position = Point3i());
        virtual ~SquareArea() override;

    protected:
        virtual void updatePositions() const override;
    };
}
#endif // SQUARE_AREA_H
