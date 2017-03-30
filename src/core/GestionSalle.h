#ifndef GESTIONSALLE_H_INCLUDED
#define GESTIONSALLE_H_INCLUDED

#include "Ennemi.h"
#include "VecteurM.h"
#include "Coord2D.h"
#include "Projectile.h"

#include <list>

class GestionSalle
{
private:
    std::list <Ennemi> ennemis;
    std::list <Projectile*> projectiles;
public:
    GestionSalle();

    void change_salle();

    void mettre_a_jour_projectile_perso();

    void ajouter_projectile(Projectile * p);

    Projectile retourne_premier_proj();

    int nombre_projectile();

    bool encore_ennemi();
};

#endif // GESTIONSALLE_H_INCLUDED
