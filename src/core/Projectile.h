#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "VecteurM.h"
#include "Coord2D.h"

class Projectile
{
private:
    int id_projectile;

    int type;

    int degats;

    float vitesse;

    VecteurM orientation;

    Coord2D position;

public:
    Projectile();

    Projectile(const int &p_id, const int &p_type, const int &p_degat, const float &p_vitesse, const VecteurM &p_orientation, const Coord2D &p_position);

    void avancer(const float &vitesse_frame);
};

#endif // PROJECTILE_H_INCLUDED
