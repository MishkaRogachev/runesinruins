#ifndef ABSTRACT_AREA_H
#define ABSTRACT_AREA_H

#include "core_traits.h"

namespace core
{
    class AbstractArea
    {
    public:
        AbstractArea(int size, const Point3i& position);
        virtual ~AbstractArea();

        int size() const;
        void setSize(int size);

        Point3i centerPosition() const;
        Point3i& centerPosition();
        const Point3iList& positions() const;
        void setCenterPosition(const Point3i& position);

    protected:
        virtual void updatePositions() const = 0;

        int m_size;
        Point3i m_centerPosition;
        mutable Point3iList m_positions;
        mutable bool m_needUpdate;
    };
}

#endif // ABSTRACT_AREA_H
