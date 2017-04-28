#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "VecteurM.h"
#include "Coord2D.h"

class Projectile
{
private:
    bool collision;
    int id_projectile;
    int type;
    int degats;

    float vitesse;
    float taille_projectile;
    float angle_orientation;

    VecteurM orientation;

    Coord2D position;

public:
    Projectile();

    Projectile(const int &p_id, const int &p_type, const int &p_degat, const float &p_vitesse, const float &p_taille, const VecteurM &p_orientation, const Coord2D &p_position);

    void avancer(const float &vitesse_frame);

    void set_collision();

    float get_orientation_degre()const;

    float get_orientation_radian()const;

    float get_taille_projectile()const;

    bool get_collision()const;

    Coord2D get_position()const;

    int get_id_projectile()const;
};

#endif // PROJECTILE_H_INCLUDED
