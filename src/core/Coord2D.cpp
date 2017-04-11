#include "Coord2D.h"
#include <iostream>

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

bool Coord2D::operator==(const Coord2D& c2)
{
    return ((x==c2.x)&&(y==c2.y));
}

bool Coord2D::operator!=(const Coord2D& c2)
{
    return ((x!=c2.x)||(y!=c2.y));
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

void Coord2D::deplacer(const VecteurM& vect, const float& coeff)
{
    x = (float) vect.get_x() * coeff + x;
    y = (float) vect.get_y() * coeff + y;
}
