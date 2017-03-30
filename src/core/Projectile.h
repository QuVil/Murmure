#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "VecteurM.h"
#include "Coord2D.h"
#include "VecteurM.h"

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

    Projectile(int id, int deg);

    float get_orientation_degre()const;

    Coord2D get_position()const;

    //Projectile& operator = (Projectile proj_2);

    void avancer();
};

#endif // PROJECTILE_H_INCLUDED
