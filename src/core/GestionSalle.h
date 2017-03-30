#ifndef GESTIONSALLE_H_INCLUDED
#define GESTIONSALLE_H_INCLUDED

#include "Ennemi.h"
#include "Projectile.h"

#include <list>

class GestionSalle
{
private:
    std::list <Ennemi> ennemis;
    std::list <Projectile *> projectiles;
public:
    GestionSalle();

    ~GestionSalle();

    void ajouter_projectile(Projectile * p);

    void mise_a_jour_projectiles(const float &vitesse_frame);
};

#endif // GESTIONSALLE_H_INCLUDED
