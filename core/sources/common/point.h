#ifndef POINT_H
#define POINT_H

#include <array>

namespace core
{
    template< typename T, int dim = 3 >
    class Point
    {
    public:
        Point() {}
        Point(T x) : data( { x } ) {}
        Point(T x, T y) : data( { x, y } ) {}
        Point(T x, T y, T z) : data( { x, y, z } ) {}

        T& operator[](int i) { return data[i]; }
        const T& operator[](int i) const  { return data[i]; }

        const T& at(int i) const { return data.at(i); }

        bool operator==(const Point<T, dim>& other) const
        {
            return data == other.data;
        }

    private:
        std::array< T, dim > data;
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