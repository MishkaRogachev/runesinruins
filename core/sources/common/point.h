#ifndef POINT_H
#define POINT_H

#include <cassert>
#include <array>

#include "core_traits.h"

namespace core
{
    template< typename T, int dim = 3 >
    class Point
    {
    public:
        Point() { d.fill(0); }
        explicit Point(T x) : d( { x } ) { assert(dim == 1); }
        Point(T x, T y) : d( { x, y } ) { assert(dim == 2); }
        Point(T x, T y, T z) : d( { x, y, z } ) { assert(dim == 3); }

        T& operator[](int i) { return d[i]; }
        T operator[](int i) const { return d[i]; }

        T at(int i) const { return d.at(i); }
        T x() const { assert(dim > 0); return d[0]; }
        T y() const { assert(dim > 1); return d[1]; }
        T z() const { assert(dim > 2); return d[2]; }

        void setX(T x) { assert(dim > 0); d[0] = x; }
        void setY(T y) { assert(dim > 1); d[1] = y; }
        void setZ(T z) { assert(dim > 2); d[2] = z; }

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

        T product() const { T ret = 1; for (T v: d) { ret *= v; } return ret; }

    private:
        std::array< T, dim > d;
    };
}

namespace std // Hash function templete for Point class
{
    template< typename T, int dim >
    struct hash<core::Point< T, dim > >
    {
        std::size_t operator()(const core::Point< T, dim >& point) const
        {
            std::hash<T> typeHasher;
            std::size_t size = 0;
            for (int i = 0; i < dim; ++i)
            {
                size ^= typeHasher(point.at(i));
            }
            return size;
        }
    };
}

#endif // POINT_H
