#ifndef VEC_H
#define VEC_H

#include <array>

#define STATIC_ASSERT( e ) static_assert( e, "!(" #e ")" ) //TODO: find a bit more beautifull solution

namespace core
{
    template< typename T, int dim = 3 >
    class Vec
    {
    public:
        Vec() { d.fill(0); }
        explicit Vec(T x) : d( { x } ) { STATIC_ASSERT(dim == 1); }
        Vec(T x, T y) : d( { x, y } ) { STATIC_ASSERT(dim == 2); }
        Vec(T x, T y, T z) : d( { x, y, z } ) { STATIC_ASSERT(dim == 3); }

        T& operator[](int i) { return d[i]; }
        T operator[](int i) const { return d[i]; }

        T at(int i) const { return d.at(i); }
        T x() const { STATIC_ASSERT(dim > 0); return d[0]; }
        T y() const { STATIC_ASSERT(dim > 1); return d[1]; }
        T z() const { STATIC_ASSERT(dim > 2); return d[2]; }

        void setX(T x) { STATIC_ASSERT(dim > 0); d[0] = x; }
        void setY(T y) { STATIC_ASSERT(dim > 1); d[1] = y; }
        void setZ(T z) { STATIC_ASSERT(dim > 2); d[2] = z; }

        bool operator==(const Vec<T, dim>& other) const { return d == other.d; }
        bool operator!=(const Vec<T, dim>& other) const { return d != other.d; }

        Vec offset(T x) const { return Vec(d[0] + x); }
        Vec offset(T x, T y) const { return Vec(d[0] + x, d[1] + y); }
        Vec offset(T x, T y, T z) const { return Vec(d[0] + x, d[1] + y, d[2] + z); }

        Vec up(int distance = 1) const { return offset(0, 0, distance); }
        Vec down(int distance = 1) const { return offset(0, 0, -distance); }
        Vec right(int distance = 1) const { return offset(0, distance, 0); }
        Vec left(int distance = 1) const { return offset(0, -distance, 0); }
        Vec forward(int distance = 1) const { return offset(distance, 0, 0); }
        Vec backward(int distance = 1) const { return offset(-distance, 0, 0); }

        T product() const { T ret = 1; for (T v: d) { ret *= v; } return ret; }

    private:
        std::array< T, dim > d;
    };
}

namespace std // Hash function templete for Point class
{
    template< typename T, int dim >
    struct hash<core::Vec< T, dim > >
    {
        std::size_t operator()(const core::Vec< T, dim >& point) const
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

#endif // VEC_H
