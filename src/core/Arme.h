#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED

#include <vector>
#include "Projectile.h"

class Arme
{
private:

    int id_projectiles;
    int degats_projectiles;

public:
    Arme();

    void tirer(float pos_x, float pos_y);

};

#endif // ARME_H_INCLUDED
