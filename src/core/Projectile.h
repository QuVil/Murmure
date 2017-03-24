#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "VecteurM.h"
#include "Coord2D.h"

class Projectile
{
private:
    int id_projectile;

    float degats;

    VecteurM orientation, resultante;

    Coord2D position, position_old;

public:


};

#endif // PROJECTILE_H_INCLUDED
