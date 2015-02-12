#ifndef POINT_H
#define POINT_H

#include <array>

namespace core
{
    template< typename T, int dim = 3 >
    class Point
    {
    public:
        Point();
        Point(T x);
        Point(T x, T y);
        Point(T x, T y, T z);

        ~Point();

        T& operator[](int i);
        const T& operator[](int i) const;

        const T& at(int i) const;

        bool operator==(const Point& other) const;

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
