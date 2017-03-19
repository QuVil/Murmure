#include "Coord2D.h"

Coord2D::Coord2D()
{
    x = 0;
    y = 0;
}

Coord2D::Coord2D(float a, float b)
{
    x = a;
    y = b;
}

void Coord2D::coord_set(float a, float b)
{
    x = a;
    y = b;
}

void Coord2D::set_x(float a)
{
    x = a;
}

void Coord2D::set_y(float b)
{
    y = b;
}

float Coord2D::get_x() const
{
    return x;
}

float Coord2D::get_y() const
{
    return y;
}
