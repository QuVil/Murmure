#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "VecteurM.h"
#include "Coord2D.h"
#include "VecteurM.h"

class Projectile
{
private:
    int id_projectile;

    int degats;

    float vitesse;

    VecteurM orientation;

    Coord2D position;

public:

    Projectile();

    Projectile(int id, int deg);

};

#endif // PROJECTILE_H_INCLUDED
