#ifndef POINT_H
#define POINT_H

#include <array>

#define STATIC_ASSERT( e ) static_assert( e, "!(" #e ")" ) //TODO: find a bit more beautifull solution

namespace core
{
    template< typename T, int dim = 3 >
    class Point
    {
    public:
        Point() { d.fill(0); }
        explicit Point(T x) : d( { x } ) { STATIC_ASSERT(dim == 1); }
        Point(T x, T y) : d( { x, y } ) { STATIC_ASSERT(dim == 2); }
        Point(T x, T y, T z) : d( { x, y, z } ) { STATIC_ASSERT(dim == 3); }

        T& operator[](int i) { return d[i]; }
        T operator[](int i) const { return d[i]; }

        T at(int i) const { return d.at(i); }
        T x() const { STATIC_ASSERT(dim > 0); return d[0]; }
        T y() const { STATIC_ASSERT(dim > 1); return d[1]; }
        T z() const { STATIC_ASSERT(dim > 2); return d[2]; }

        void setX(T x) { STATIC_ASSERT(dim > 0); d[0] = x; }
        void setY(T y) { STATIC_ASSERT(dim > 1); d[1] = y; }
        void setZ(T z) { STATIC_ASSERT(dim > 2); d[2] = z; }

        bool operator==(const Point<T, dim>& other) const { return d == other.d; }
        bool operator!=(const Point<T, dim>& other) const { return d != other.d; }

        Point offset(T x) const { return Point(d[0] + x); }
        Point offset(T x, T y) const { return Point(d[0] + x, d[1] + y); }
        Point offset(T x, T y, T z) const { return Point(d[0] + x, d[1] + y, d[2] + z); }

        Point up(int distance = 1) const { return offset(0, 0, distance); }
        Point down(int distance = 1) const { return offset(0, 0, -distance); }
        Point right(int distance = 1) const { return offset(0, distance, 0); }
        Point left(int distance = 1) const { return offset(0, -distance, 0); }
        Point forward(int distance = 1) const { return offset(distance, 0, 0); }
        Point backward(int distance = 1) const { return offset(-distance, 0, 0); }

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
            std::size_t size;
            for (int i = 0; i < dim; ++i)
            {
                size ^= typeHasher(point.at(i));
            }
            return size;
        }
    };

}

#endif // POINT_H
