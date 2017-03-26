#include "Projectile.h"

Projectile::Projectile()
{
    id_projectile = 1;
    degats = 1;
}

Projectile::Projectile(int id, int deg)
{
    id_projectile = id;
    degats = deg;
}
