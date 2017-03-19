#ifndef VECTEURM_H_INCLUDED
#define VECTEURM_H_INCLUDED

#include "Coord2D.h"

class VecteurM
{
private:
    float x, y;

public:
    VecteurM();

    VecteurM& operator =(const VecteurM &vect2);

    const VecteurM operator +(const VecteurM &v2);

    void diminuer_inertie(const float &coeff);
};

#endif // VECTEURM_H_INCLUDED
