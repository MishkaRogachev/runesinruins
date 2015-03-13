#ifndef POINT_H
#define POINT_H

#include <QHash>
#include <array>

#include "direction.h"

namespace core
{
    template< typename T, int dim = 3 >
    class Point
    {
    public:
        Point() { d.fill(0); }
        explicit Point(T x) : d( { x } ) { Q_ASSERT(dim == 1); }
        Point(T x, T y) : d( { x, y } ) { Q_ASSERT(dim == 2); }
        Point(T x, T y, T z) : d( { x, y, z } ) { Q_ASSERT(dim == 3); }

        T& operator[](int i) { Q_ASSERT(dim > i); return d[i]; }
        T operator[](int i) const { Q_ASSERT(dim > i); return d[i]; }

        T at(int i) const { Q_ASSERT(dim > i); return d.at(i); }
        T x() const { Q_ASSERT(dim > 0); return d[0]; }
        T y() const { Q_ASSERT(dim > 1); return d[1]; }
        T z() const { Q_ASSERT(dim > 2); return d[2]; }

        const std::array< T, dim >& array() const { return d; }
        std::array< T, dim >& array() { return d; }

        void setX(T x) { Q_ASSERT(dim > 0); d[0] = x; }
        void setY(T y) { Q_ASSERT(dim > 1); d[1] = y; }
        void setZ(T z) { Q_ASSERT(dim > 2); d[2] = z; }

        bool operator==(const Point<T, dim>& other) const
        {
            return d == other.d;
        }

        bool operator!=(const Point<T, dim>& other) const
        {
            return d != other.d;
        }

        bool operator >(const Point<T, dim>& other) const
        {
            for (int i = 0; i < dim; ++i)
            {
                if (this->at(i) > other.at(i)) return true;
                if (this->at(i) < other.at(i)) return false;
            }
            return false;
        }

        bool operator <(const Point<T, dim>& other) const
        {
            for (int i = 0; i < dim; ++i)
            {
                if (this->at(i) < other.at(i)) return true;
                if (this->at(i) > other.at(i)) return false;
            }
            return false;
        }

        Point offset(T x) const
        {
            return Point(d[0] + x);
        }

        Point offset(T x, T y) const
        {
            return Point(d[0] + x, d[1] + y);
        }

        Point offset(T x, T y, T z) const
        {
            return Point(d[0] + x, d[1] + y, d[2] + z);
        }

        Point up(int distance = 1) const
        {
            return this->offset(0, 0, distance);
        }

        Point down(int distance = 1) const
        {
            return this->offset(0, 0, -distance);
        }

        Point right(int distance = 1) const
        {
            return this->offset(0, distance, 0);
        }

        Point left(int distance = 1) const
        {
            return this->offset(0, -distance, 0);
        }

        Point forward(int distance = 1) const
        {
            return this->offset(distance, 0, 0);
        }

        Point backward(int distance = 1) const
        {
            return this->offset(-distance, 0, 0);
        }

        Point neighbour(Direction dir, int distance = 1) const
        {
            if (dir == Direction::forward) return this->forward(distance);
            if (dir == Direction::backward) return this->backward(distance);
            if (dir == Direction::right) return this->right(distance);
            if (dir == Direction::left) return this->left(distance);
            if (dir == Direction::up) return this->up(distance);
            if (dir == Direction::down) return this->down(distance);
            return Point();
        }

        Point& move(T x)
        {
            Q_ASSERT(dim == 1);
            d[0] += x;
            return *this;
        }

        Point& move(T x, T y)
        {
            Q_ASSERT(dim == 2);
            d[0] += x;
            d[1] += y;
            return *this;
        }

        Point& move(T x, T y, T z)
        {
            Q_ASSERT(dim == 3);
            d[0] += x;
            d[1] += y;
            d[2] += z;
            return *this;
        }

        Point& goUp(int distance = 1)
        {
            return this->move(0, 0, distance);
        }

        Point& goDown(int distance = 1)
        {
            return this->move(0, 0, -distance);
        }

        Point& goRight(int distance = 1)
        {
            return this->move(0, distance, 0);
        }

        Point& goLeft(int distance = 1)
        {
            return this->move(0, -distance, 0);
        }

        Point& goForward(int distance = 1)
        {
            return this->move(distance, 0, 0);
        }

        Point& goBackward(int distance = 1)
        {
            return this->move(-distance, 0, 0);
        }

        Point& go(Direction dir, int distance = 1)
        {
            if (dir == Direction::forward) return this->goForward(distance);
            if (dir == Direction::backward) return this->goBackward(distance);
            if (dir == Direction::right) return this->goRight(distance);
            if (dir == Direction::left) return this->goLeft(distance);
            if (dir == Direction::up) return this->goUp(distance);
            if (dir == Direction::down) return this->goDown(distance);
            return *this;
        }

        T product() const { T ret = 1; for (T v: d) { ret *= v; } return ret; }

        friend uint qHash(const Point& point)
        {
            uint result = 0;
            for (int i = 0; i < dim; ++i)
            {
                result ^= qHash(point.at(i));
            }
            return result;
        }

    private:
        std::array< T, dim > d;
    };
}

#endif // POINT_H
