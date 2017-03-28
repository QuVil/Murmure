#ifndef GESTIONSALLE_H_INCLUDED
#define GESTIONSALLE_H_INCLUDED

#include "Ennemi.h"
#include "Projectile.h"

#include <list>

class GestionSalle
{
private:
    std::list <Ennemi> ennemis;
    std::list <Projectile> projectiles;
public:

};

#endif // GESTIONSALLE_H_INCLUDED
