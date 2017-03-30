#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED

#include "Projectile.h"
#include "VecteurM.h"
#include "Coord2D.h"

class Arme
{
private:
    int id_arme;
    int nv_arme;
    int id_projectiles;
    int degats_projectiles;
    int type;
    float vitesse;
    float taille_projectile;

    int munitions_max;
    int munitions_restantes;

public:
    Arme();

    void charger(const int &id, const int &nv);

    void set_id_arme(const int &i);

    void set_nv_arme(const int &i);

    void set_id_projectiles(const int &i);

    void set_degats_projectiles(const int &i);

    void set_munitions_max(const int &i);

    void set_type(const int &i);

    void set_vitesse(const float &v);

    Projectile* tirer(const VecteurM &orientation, const Coord2D &position);

};

#endif // ARME_H_INCLUDED
