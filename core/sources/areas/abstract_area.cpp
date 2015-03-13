#include "abstract_area.h"

using namespace core;

AbstractArea::AbstractArea(int size, const Point3i& position):
    m_size(size),
    m_centerPosition(position),
    m_needUpdate(true)
{}

AbstractArea::~AbstractArea()
{}

int AbstractArea::size() const
{
    return m_size;
}

void AbstractArea::setSize(int size)
{
    if (m_size == size) return;

    m_size = size;
    m_needUpdate = true;
}

Point3i AbstractArea::centerPosition() const
{
    return m_centerPosition;
}

Point3i& AbstractArea::centerPosition()
{
    m_needUpdate = true;
    return m_centerPosition;
}

const Point3iList& AbstractArea::positions() const
{
    if (m_needUpdate)
    {
        this->updatePositions();
        m_needUpdate = false;
    }
    return m_positions;
}

void AbstractArea::setCenterPosition(const Point3i& position)
{
    if (m_centerPosition == position) return;

    m_centerPosition = position;
    m_needUpdate = true;
}
