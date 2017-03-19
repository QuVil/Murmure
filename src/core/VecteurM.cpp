#include "VecteurM.h"

VecteurM::VecteurM()
{
    x = 0;
    y = 0;
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
