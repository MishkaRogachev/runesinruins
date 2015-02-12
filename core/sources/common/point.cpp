#include "point.h"

using namespace core;

template< typename T, int dim >
Point<T, dim>::Point()
{
    data.fill(0);
}

template< typename T, int dim >
Point<T, dim>::Point(T x):
    data( { x } )
{}

template< typename T, int dim >
Point<T, dim>::Point(T x, T y):
    data( { x, y } )
{}

template< typename T, int dim >
Point<T, dim>::Point(T x, T y, T z):
    data( { x, y, z } )
{}

template< typename T, int dim >
Point<T, dim>::~Point()
{}

template< typename T, int dim >
T& Point<T, dim>::operator[](const int i)
{
    return data[i];
}

template< typename T, int dim >
const T& Point<T, dim>::operator[](const int i) const
{
    return data[i];
}

template< typename T, int dim >
const T& Point<T, dim>::at(int i) const
{
    return data.at(i);
}

template< typename T, int dim >
bool Point<T, dim>::operator==(const Point& other) const
{
    return data == other.data;
}

