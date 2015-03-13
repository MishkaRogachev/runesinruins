#include "square_area.h"

using namespace core;

SquareArea::SquareArea(int size, const Point3i& position):
    AbstractArea(size, position)
{}

SquareArea::~SquareArea()
{}

void SquareArea::updatePositions() const
{
    m_positions.clear();

    for (int x = m_centerPosition.x() - m_size;
         x < m_centerPosition.x() + m_size + 1; ++x)
    {
        for (int y = m_centerPosition.y() - m_size;
             y < m_centerPosition.y() + m_size + 1; ++y)
        {
            m_positions.append(Point3i(x, y, m_centerPosition.z()));
        }
    }
}
