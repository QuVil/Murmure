#include "VecteurM.h"

VecteurM::VecteurM()
{
    x = 0;
    y = 0;
}

VecteurM::VecteurM(const float& x2, const float& y2)
{
    x = x2;
    y = y2;
}

VecteurM& VecteurM::operator=(const VecteurM& v2)
{
    x = v2.x;
    y = v2.y;
    return* this;
}

const VecteurM VecteurM::operator+(const VecteurM& v2)
{
    VecteurM v;
    v.x = x + v2.x;
    v.y = y + v2.y;
    return v;
}

void VecteurM::diminuer_inertie(const float& coeff)
{
    x = x* coeff;
    y = y* coeff;
}

void VecteurM::set_x(const float& a)
{
    x = a;
}

void VecteurM::set_y(const float& b)
{
    y = b;
}

float VecteurM::get_x() const
{
    return x;
}

float VecteurM::get_y() const
{
    return y;
}
