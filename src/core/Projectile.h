#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "VecteurM.h"
#include "Coord2D.h"

class Projectile
{
private:
    int id_projectile;

    int degats;

    VecteurM orientation, resultante;

    Coord2D position, position_old;

public:

    Projectile();

    Projectile(int id, int deg);

};

#endif // PROJECTILE_H_INCLUDED
